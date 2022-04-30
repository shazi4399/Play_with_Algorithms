//
// Created by zhanghao on 2022/4/30.
//

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

int __partition(vector<int> & arr ,int l ,int r){
    int v = arr[l];

    int j = l;
    for(int i = l + 1; i <= r; i++){
        if(arr[i] < v){
            j++;
            swap(arr[j],arr[i]);
        }
    }

    swap(arr[l],arr[j]);
    return j;
}

void __quickSort(vector<int>& arr,int l,int r){
    if(l >= r){
        return ;
    }

    int p = __partition(arr,l,r);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}

void quickSort(vector<int> & arr){
    int n = arr.size();
    __quickSort(arr,0,n-1);
}

int main(){
    vector<int>vec = {3,7,52,1,4,6,8,453,2,34};
    quickSort(vec);
    for(auto & i:vec){
        cout<< i << " ";
    }
    cout<<endl;
    return 0;
}