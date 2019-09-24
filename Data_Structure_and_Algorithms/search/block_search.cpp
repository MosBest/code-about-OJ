/** 分块查找

分块查找又称为索引顺序查找。

大体可以分为两步:
1. 分块＋建立索引表
    首先将列表分成若干个块（子表）
        要求:列表相邻的元素组成一个块,比如列表data分为以下三个块data[0~a], data[a+1~b], data[b+1~n]
        要求:每块中元素不必有序，即块内无序，但 块与块之间有序（即下一个块中最小的元素必大于上一个块中所有的元素）。

    然后建立索引表，
        其中每个索引项对应一个块，且每个索引项记录每块的起始位置，和每块中关键字(或最小关键字)。
        根据分块时的要求可知，索引表是按关键字有序排列的。

2. 查找
    比如待查关键字为K
（1）首先，对索引表进行顺序查找法或折半查找法，从而确定K在哪个块。
（2）进一步用顺序查找法，在相应块内查找关键字为 K的元素。

所以，分块查找的关键不是如何查找，而是怎么对列表分块，怎么对块建立索引。
观看一些博客，都没有讲解怎么分块和建立索引，而仅仅实现分块查找。

没有想到好的建表的方法，所以这里假设表已经建好了
http://data.biancheng.net/view/56.html
*/

#include <iostream>
#include <vector>

using namespace std;

/**
分块　并　建立索引表
该函数还没有实现功能
a: 原列表
length: 列表a的长度
table: 将会把建立的索引表保存在table中
block: 块的个数，即table的长度
*/
void build_table(auto &a,int length,auto &table,int block);

/**
块查找，即 索引表的二分查找　和　块的顺序查找

a: 原列表
length: 列表a的长度
table: 将会把建立的索引表保存在table中
block: 块的个数，即table的长度
K: 待查找的元素
*/
void block_search(auto &a,int length,auto &table,int block, int K);

/**
二分查找

key: 查找的列表
block: key的长度
K: 待查找的元素
*/
int my_binary_search(auto &key,int block, int K);

typedef struct{
    int key = -1;
    int address = -1;
}IndexTable;


int main(int, char**){

    int a[]={22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53};
    int length = 18;
    constexpr int block = 3;

    //分块+建表
    IndexTable table[block];
    build_table(a, length, table, block);

    //查找
    //print(a, length);

    int K = 123;
    block_search(a, length, table, block, K);

    //print(a, length);

    return -1;
}

//分块并建立索引表
void build_table(auto &a,int length,auto &table,int block){
        table[0].key=22;table[0].address=0;
        table[1].key=48;table[1].address=6;
        table[2].key=86;table[2].address=12;
}

//块查找
void block_search(auto &a,int length,auto &table,int block, int K){
    //在索引表中用二分查找　得到Ｋ属于哪个块
    std::vector<int> key;
    for(int i = 0; i < block; i++){
        key.push_back(table[i].key);

    }
    int j = my_binary_search(key, block, K);

    //在对应的块中查找Ｋ的位置
    int begin_index = table[j].address;
    int end_index;
    if(j == block-1)
        end_index = length-1;
    else
        end_index = table[j+1].address - 1;

    std::cout << "j: " << j << "  begin_index: " << begin_index << "  end_index: " << end_index  << std::endl;
    for(int index = begin_index; index <= end_index; index++){
        if(a[index] == K){
            std::cout << "K  is found " << std::endl;
            break;
        }
    }

    throw "K is not in list";

}

//二分查找
int my_binary_search(auto &key,int block, int K){
    if(K > key[block-1]){
        throw "K is not in table";
        return -1;
    }
    if(K < key[0] ){
        return 0;
    }

    int begin_prt = 0;
    int end_prt = block -1;
    int index = (begin_prt + end_prt) / 2;
    std::cout << "begin_prt: " << begin_prt << "  end_prt: " << end_prt  << "  index: " << index << std::endl;
    while(end_prt - begin_prt != 1){
        if(key[index] == K)
            return index;

        if(key[index] < K){
            begin_prt = index;
            index = (begin_prt + end_prt) / 2;
        }
        else{
            end_prt = index;
            index = (begin_prt + end_prt) / 2;
        }
    }
    std::cout << "begin_prt: " << begin_prt << "  end_prt: " << end_prt << std::endl;
    if(key[begin_prt] >= K)
        return begin_prt;
    else
        return end_prt;
}
