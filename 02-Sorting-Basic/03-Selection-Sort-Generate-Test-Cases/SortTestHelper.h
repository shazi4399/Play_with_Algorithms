//
// Created by zhanghao on 2022/4/23.
//

#ifndef INC_02_SELECTION_SORT_USING_TEMPLATE_SORTTESTHELPER_H
#define INC_02_SELECTION_SORT_USING_TEMPLATE_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{
    //生成n个元素的随机数组，每个元素的随机范围为[rangeL,rangeR)
    int* generateRandomArray(int n ,int rangeL,int rangeR){
        assert(rangeL <= rangeR);

        int* arr= new int[n];
        srand(time(NULL));
        for(int i = 0 ; i < n; i++){
            arr[i] = (rand()%(rangeR - rangeL +1)) + rangeL;
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[],int n ){
        for(int i = 0 ; i < n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
};

#endif //INC_02_SELECTION_SORT_USING_TEMPLATE_SORTTESTHELPER_H
