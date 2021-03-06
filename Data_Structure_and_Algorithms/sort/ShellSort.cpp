/*
希尔排序---插入排序更高级版

希尔排序是插入排序更更高级版

对于普通的插入排序有两点特性：
1. 当序列的个数比较少时，直接插入排序效率高。
    这个好理解，个数比较少，那么插入的次数也就少了。
2. 如果序列本身就是基本有序，那么直接插入排序效率高。
    因为如果序列基本有序，则每个元素在排序时就待在原处，即大部分的插入操作不会执行，效率自然就高。

希尔排序算法思想：

    上面已经讲解了当普通插入排序满足了那两个特性(序列个数少，序列本身基本有序)时，插入排序效率会很高。
    但是，在实际场景中，这两个特性过于苛刻，现实场景中的序列　多半是中/大规模数据且无序，怎么办？？？

    毛爷爷说，没有条件，就创造条件。

    创造条件1：对中/大规模序列进行分组，分割成若干个子序列，从而得到小规模数据。
        注意: 这里分割序列成若干子序列，并不是分块式分割，而是跳跃式分割。
        分块式分割:　比如分为三个子序列　data[0~m], data[m+1~n], data[n+1~q]
        跳跃式分割: 跳跃式分割是跳跃取值组成子序列的。比如每隔２个跳跃，比如分为三个子序列,即分块为　data[0, 3, 6, 9, 12, 15], data[1, 4, 7, 10, 13, 16], data[2, 5, 8, 11, 14, 17]

        https://www.cnblogs.com/chengxiao/p/6104371.html　此链接很好的理解跳跃式分割。

        我们用的是　跳跃式分割。为什么是用跳跃式分割呢？
        因为我们要让整个序列都基本有序。基本有序是，整个序列虽然依然无序，但是小的值普遍在左边，大的值依然在右边(假如最终要求从小到大排序)。
        分块式分割无法实现这个要求，其左边的元素和右边的元素无法组成子序列，子序列排序后，排在左边的特大值依然在左边，排在右边的特小值依然在右边。
        而跳跃式分割可以实现这个要求。跳跃式分割是跳跃取值组成子序列的。这样就可以使得哪怕最左边的元素和最右边的元素依然组成子序列。


    创造条件2：对跳跃式分割得到的子序列分别进行直接插入排序，则可以让整个序列都基本有序。再对全体记录进行一次直接插入排序。
        注意:只是基本有序时。


    跳跃式分割中　跳跃的间隔gap 的选取？？？
    一般的，只进行一次　跳跃式分割划分子序列 + 子序列进行插入排序　是无法达到整个序列基本有序　的要求的。
    要求不断循环，假设序列长度为Ｎ.
    先取gap = N/2, 然后执行　跳跃式分割划分子序列 + 子序列进行插入排序，　
    然后gap = gap/2,然后执行　跳跃式分割划分子序列 + 子序列进行插入排序，
    不断循环... ...
    最终一定可以得到gap = 1, 这个时候就是处理整个序列了，对整个序列进行一次直接插入排序，即可完成排序算法。

综上所述：
希尔排序算法思想 = 不断循环 跳跃式分割划分子序列 + 子序列进行插入排序
假设序列长度为Ｎ
    for(int gap = N/2; gap>=1 ;gap = gap/2)
    {跳跃式分割划分子序列 + 子序列进行插入排序}
    注意：
        这里的　跳跃式分割划分子序列 + 子序列进行插入排序，按照我们的理解　应该是
        对整个序列进行分割，然后对第一个子序列进行插入排序，然后对第二个子序列进行插入排序，然后对第三个子序列进行插入排序 ... ...
        但是，在实际代码中，并不是这样做的。实际的操作是：
        index　从gap下标开始，依次遍历循环到数组最右端
        那么每一次 index到一个点data[index]，就会遇到一个另一个子序列( ...data[index-3*gap], data[index-2*gap], data[index-gap], data[index],　data[index+gap], data[index+2*gap] ...)，
        其中( ...data[index-3*gap], data[index-2*gap], data[index-gap])　已经排好序，然后将data[index]　插入　( ...data[index-3*gap], data[index-2*gap], data[index-gap])中
        然后index = index + 1
        此时　则data[index]在又是另一个子序列，然后对点data[index]插入排序到自己的子序列中。
        不断循环。
        也就是说，实际代码中，并不是将某子序列全部都排序后再处理下一个子序列，而是每次仅仅处理当前子序列的某一个值(data[index]),然后进入下一个子序列的某个值，也就是
        说子序列是不断交替进行的。
        https://www.cnblogs.com/youzhibing/p/4889037.html 此链接可以很好的理解子序列插入排序的过程。

        我觉得这种方法效率应该和我们普通想法的效率应该一样高，就是不知道为什么实际中要这样处理。

        我们就按着实际处理方法来呗。

希尔排序算法伪代码：
void SellSort(auto &data, int length){
    // 一次跳跃分割还不够，不要多次重复，而且每次的分割的gap要求不同
    // 跨度 gap 从　length/2, 不断减小，最终为1, 当gap为１时，就是最终对整个序列排序

    for(int gap = length/2; gap>=1; gap = gap/2){

        // 对于每一次gap跳跃分割，处理gap开始　到　length　的每一个点，每相邻的两个点的子序列其实在不同的
        for(int index = gap; index <length; index++){

            //data[index] 位于子序列  ( ...data[index-3*gap], data[index-2*gap], data[index-gap], data[index],　data[index+gap], data[index+2*gap] ...)中
            //其中( ...data[index-3*gap], data[index-2*gap], data[index-gap])部分已经排好序了
            //所以该函数将data[index]在( ...data[index-3*gap], data[index-2*gap], data[index-gap])中进行插入排序
            insert(data,index,gap);
        }
    }
}

*/

#include <iostream>

using namespace std;

void print(auto &data, int length); // 打印


/** @brief  希尔排序 a algorithm about sorting
@param data : the citing of array or vector.
@param length: the length of data
*/
void SellSort(auto &data, int length);

/** @brief  数组跳跃式插入排序 a algorithm about sorting
data[index] 位于子序列  ( ...data[index-3*gap], data[index-2*gap], data[index-gap], data[index],　data[index+gap], data[index+2*gap] ...)中
其中( ...data[index-3*gap], data[index-2*gap], data[index-gap])部分已经排好序了
所以该函数将data[index]在( ...data[index-3*gap], data[index-2*gap], data[index-gap])中进行插入排序，排序的方式类似于　冒泡排序。

@param data : the citing of array or vector.
@param index: the data that you want to inset
@param gap: Jump interval

*/
void jump_insert_sort(auto &data, int index, int gap);
int main(){
    //答案: 1,1,2,2, 2,4, 6,6,7,21,23,213
    int data[] = {1,2,6,21,6,2,213,7,4,2,1,23};
    int length = 12;

    print(data, length);

    SellSort(data, length);

    print(data, length);
}


void SellSort(auto &data, int length){
    // 一次跳跃分割还不够，不要多次重复，而且每次的分割的gap要求不同
    // 跨度 gap 从　length/2, 不断减小，最终为1, 当gap为１时，就是最终对整个序列排序
    for(int gap = length/2; gap >= 1; gap = gap/2){

        // 对于每一次gap跳跃分割，处理gap开始　到　length　的每一个点，每相邻的两个点的子序列其实在不同的
        for(int index = gap; index <= length-1; index++){

            //该函数将data[index]在( ...data[index-3*gap], data[index-2*gap], data[index-gap])中进行插入排序，排序的方式类似于　冒泡排序。
            jump_insert_sort(data,index,gap);
        }
    }
}

void jump_insert_sort(auto &data, int index, int gap){
    //类似于冒泡排序
    //要插的值是data[index]
    //插入到序列 ( ...data[index-3*gap], data[index-2*gap], data[index-gap])　中
    for(int j = index - gap; j >=0; j = j-gap){

        if(data[index] < data[j]){
            auto a = data[index];
            data[index] = data[j];
            data[j] = a;
        }
        index = j;
    }
}

void print(auto &data, int length){
    std::cout << std::endl;
    for(int i = 0; i < length; i++){
        std::cout << data[i] << " ";
    }
}
