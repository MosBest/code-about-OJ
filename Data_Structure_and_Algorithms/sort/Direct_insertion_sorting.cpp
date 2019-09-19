

/*
插入排序　－－－　直接插入排序算法
数组data长度为n,假设现在处理到i,则data[0~ i-1]　都已经排好序，
现在只需将data[i]从data[i-1]到data[i]方向，依次比较，然后插入。
*/


#include <iostream>

using namespace std;

void Direct_Insert_Sort(auto &data, int length);//直接插入排序
void print(auto &a, int length);

int main(int, char**){
    //答案: 1,1,2,2, 2,4, 6,6,7,21,23,213
    int data[] = {1,2,6,21,6,2,213,7,4,2,1,23};
    int length = 12;
    print(data, length);

    Direct_Insert_Sort(data, length);


    print(data, length);
    return 1;
}

void Direct_Insert_Sort(auto &data, int length){


    for(int i = 0; i < length-1; i++ ){
        //对于每一个data[i+1]

        //让data[i+1]的值从data[i]到data[0]依次比较
        int j = i;
        for(; j >=0; j--){
            if(data[i+1] < data[j]){
                continue;
            }
            break;
        }


        ++j;//得到data[i+1]应该插入的下标为j


        if(j == i+1)
            continue;//如果 j == i+1 表明data[i+1]不用动
        else
        {
            //否则data[j+1]到data[i]的值依次向后移动一位
            //然后把data[i+1]的值给data[j]
            int result = data[i+1];
            for(int k = i; k >=j; k--){
                data[k+1] = data[k];
            }
            data[j] = result;
        }
    }

}

void print(auto &a, int length){
    std::cout << std::endl;
    for(int i = 0; i < length; i++){
        std::cout << a[i] << " " ;
    }

}

