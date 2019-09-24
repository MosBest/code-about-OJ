/**
二分查找
前提是　原列表必须有序
*/

#include <iostream>

using namespace std;

/**
二分查找

key: 查找的列表
block: key的长度
K: 待查找的元素
*/
int my_binary_search(auto &key,int length, int K);


int main(int, char**){
    int key[]={1, 1, 1, 3, 3 ,5, 5 ,6, 6 ,7 , 8, 9, 13, 13, 15, 123, 321, 23121};
    int length = 18;
    int K = 9;

    int index = my_binary_search(key, length, K);
    std::cout << "K is found" << std::endl;
    return 1;
}


int my_binary_search(auto &key,int length, int K){
    if(K > key[length-1] || K < key[0] ){
        throw "K is not in key";
        return -1;
    }

    int begin_prt = 0;
    int end_prt = length -1;
    int index = (begin_prt + end_prt) / 2;

    //不断递归更新 begin_prt,　end_prt, 直到begin_prt,　end_prt相邻
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

    //当begin_prt,　end_prt相邻时
    if(key[begin_prt] == K)
        return begin_prt;
    if(key[end_prt] == K)
        return end_prt;

    throw "k not in list";
    return -1;
}

