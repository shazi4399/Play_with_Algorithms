//
// Created by zhanghao on 2022/4/25.
//

#ifndef INC_03_SELECTION_SORT_DETECT_PERFORMANCE_SELECTIONSORT_H
#define INC_03_SELECTION_SORT_DETECT_PERFORMANCE_SELECTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;


template<typename T>
void selectionSort(T arr[], int n){

    for(int i = 0 ; i < n ; i ++){

        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }
}

#endif //INC_03_SELECTION_SORT_DETECT_PERFORMANCE_SELECTIONSORT_H
