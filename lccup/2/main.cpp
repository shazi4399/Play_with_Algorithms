//
// Created by zhanghao on 2022/4/23.
//

#include "main.h"
#include <iostream>
#include <vector>
using  namespace  std;


int xunhuansearch(vector<int>& A, int n, int target)
{
    if(n<=0)
        return -1;
    int left = 0, right = n-1;
    while(left<=right)
    {
        int mid = left + ((right-left)/2);
        if(A[mid] == target)
            return mid;

        if(A[left] <= A[mid])//转折点在右半边
        {
            if(A[left] <= target && target < A[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else //转折点在左半边
        {
            if(A[mid] < target && target <= A[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}


int main(){
    vector<int> arr;
    int num;
    int n;
    while(cin >> n){
        if(getchar() != '\n')
            arr.push_back(n);
        else
            break;
    }
    cin>>num;
    int left = 0,right = arr.size()-1;
    int ans = xunhuansearch(arr, arr.size(), num);
    if(ans == -1)
        cout<< "false";
    else
        cout<< "true";
    return 0;
}