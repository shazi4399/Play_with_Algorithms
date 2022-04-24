//
// Created by zhanghao on 2022/4/23.
//

#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;

template<typename T>
void selectionSort(T arr[],int n ){
    for(int i = 0 ; i < n; i++){
        int minIndex = i;
        for(int j = i + 1; j < n;j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}

int main(){
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(a,10);
    for(int i = 0 ; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout<<endl;

    Student d[4] = {{"小明",90},{"小红",100},{"小刚",101},{"小兰",100}};
    selectionSort(d,4);
    for(int i = 0 ; i < 4; i++){
        cout << d[i];
    }
    cout<<endl;
}

