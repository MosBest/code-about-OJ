/*
插入排序－－－折半插入排序
折半插入排序　是　直接插入排序的改进版。折半插入排序其实就是 == 直接插入排序　＋　二分查找
其中: 直接插入排序的讲解　见代码直接插入排序Direct_insertion_sorting.cpp
不同的是，折半插入排序将直接插入排序中data[i+1]从data[i]到data[0]一一比较部分，改为用　二分查找的方法处理(因为data[0]到data[i]是有序的)
*/

#include <iostream>

using namespace std;

void print(auto &data, int length); // 打印


/** @brief  折半插入排序 a algorithm about sorting using binary search
@param data : the citing of array or vector.
@param length: the length of data
*/
void binary_insertion_sort(auto &data, int length);


/** @brief 二分查找算法
@param data: the citing of array or vector.
@param element: the length of data
@ begin_i:  the beginning of the range of data that you want to search
@ end_i: the endding of the range of data that you want to search
*/
int my_binary_search(auto &data, auto element, int begin_i, int end_i);

int main(int, char**){
    //答案: 1,1,2,2, 2,4, 6,6,7,21,23,213
    int data[] = {1,2,6,21,6,2,213,7,4,2,1,23};
    int length = 12;
    print(data, length);

    binary_insertion_sort(data, length);

    print(data, length);
    return 1;
}

void binary_insertion_sort(auto &data, int length){
    //从index = 0 遍历到到 length-2
    for(int i = 0; i < length-1; i++){
        //返回data[i+1]应该插在位置j上
        int j = my_binary_search(data, data[i+1], 0, i);

        //如果j就是i+1,则位置不动
        if( j == i+1)
            continue;

        //否则，data[j+1~i]都向后移动一位,然后把element(即data[i+1]) 放在　data[j] 上
        auto element = data[i+1];
        for(int k = i; k>=j; k--){
            data[k+1] = data[k];
        }
        data[j] = element;
    }
}

//二分查找函数
int my_binary_search(auto &data, auto element, int begin_i, int end_i){

    //如果左边的index > 右边的index ,　则报错
    if(begin_i > end_i){
        throw "begin >= end";
        return -1;
    }

    //如果左边的index ＝＝ 右边的index，表示搜寻范围就一个点
    if(begin_i == end_i){
        //如果element小于data[begin_i]，则在begin_i处插入,否则在begin_i＋1处插入
        if(element <= data[begin_i])
            return begin_i;
        else
            return begin_i + 1;
    }

    int j = -1;
    //如果是　左边的index ～～　右边的index
    //则不断二分，直到end_i = begin_i + 1,退出循环
    while(end_i - begin_i != 1){
        j = (end_i + begin_i) / 2;
        if(element > data[j]){
            begin_i = j;
        }
        else if(element < data[j]){
            end_i = j;
        }
        else if(element == data[j]){
            return j;
        }
    }

    //　处理end_i = begin_i + 1的情况
    j = (end_i + begin_i) / 2;
    if(element <= data[j])
        return j;
    else{
        if(element > data[j+1])
            return j+2;
        else
            return j+1;
    }
}

void print(auto &data, int length){
    std::cout << std::endl;
    for(int i = 0; i < length; i++){
        std::cout << data[i] << " ";
    }
}
