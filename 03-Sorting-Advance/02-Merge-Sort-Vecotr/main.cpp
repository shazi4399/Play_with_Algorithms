//
// Created by zhanghao on 2022/4/25.
//
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void __merge(vector<T> & arr,int l,int mid,int r){
    vector<T> aux(r-l+1);
    for(int i = l ;i <=r;i++){
        aux[i-l] = arr[i];
    }
    int i = l,j = mid+1;
    for(int k = l; k <= r;k++){
        if(i > mid){
            arr[k] = aux[j-l];j++;
        }else if(j >r){
            arr[k] = aux[i-l];i++;
        }else if(aux[i-l] < aux[j-l]){
            arr[k] = aux[i - l];i++;
        }else{
            arr[k] = aux[j-l];j++;
        }
    }
}

template<typename T>
void __mergeSort(vector<T> & arr,int l,int r ){
    if(l >= r)
        return;
    int mid = (r-l)/2 +l;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    __merge(arr,l,mid,r);
}

template<typename T>
void mergeSort(vector<T> & arr,int n){
    __mergeSort(arr,0,n-1);
};

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,44,3};
    mergeSort(arr,15);
    for(int i :arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}