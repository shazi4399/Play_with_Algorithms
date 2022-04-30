//
// Created by zhanghao on 2022/4/25.
//
#include <vector>
#include <iostream>
using namespace std;
// 我们的第一版bubbleSort
template<typename T>
void bubbleSort( T arr[] , int n){

    for(int i = 0; i < n;i++){
        for(int j = 0 ; j < n-1-i;j++){
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
    return ;
//    bool swapped;
//
//    do{
//        swapped = false;
//        for( int i = 1 ; i < n ; i ++ )
//            if( arr[i-1] > arr[i] ){
//                swap( arr[i-1] , arr[i] );
//                swapped = true;
//
//            }
//
//        // 优化, 每一趟Bubble Sort都将最大的元素放在了最后的位置
//        // 所以下一次排序, 最后的元素可以不再考虑
//        n --;
//
//    }while(swapped);
}

int main(){
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    bubbleSort(arr,10);
    for(int i = 0 ; i < 10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}