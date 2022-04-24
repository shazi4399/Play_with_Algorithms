//
// Created by zhanghao on 2022/4/24.
//

#include "binarySearch.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target)
    {
        if(n<=0)
            return -1;
        int left = 0, right = n-1;
        while(left<=right)
        {
            int mid = left + ((right-left)/2);
            if(A[mid] == target)
                return mid;

            if(A[left] <= A[mid])//转折点在右半边,转折点左边一定是有序的。
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

public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int m = nums[0].size();
        unordered_map<int,int> mymap(m);
        int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < m; i++){
            mymap[nums[0][i]]++;
        }
        for(int i = 1 ; i < n;i++){
            for(int j = 0 ; j < nums[i].size();j++){
                if(!mymap.count(nums[i][j]))
                    continue;
                mymap[nums[i][j]]++;
            }
        }
        for(auto it:mymap){
            if(it.second == n){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    int find_rotate_index(vector<int> & nums) {
        int left = 0,right = nums.size()-1;
        //数组本身有序，非循环有序
        if (nums[left] < nums[right]){
            return 0;
        }
        while (left <= right) {
            int mid = (right - left)/2 + left;
            if (nums[mid] > nums[mid + 1]){
                return mid + 1;
            }else {
                if (nums[mid] < nums[left]){
                    right = mid - 1;
                } else{
                    left = mid + 1;
                }
            }
        }
        return 0;
    }
    //biSearch函数 ，找到返回索引节点，找不到返回-1；
    int biSearch(vector<int> nums,int left,int right,int target){
        if(left > right) return -1;
        while(left <= right){
            int mid = (right - left)/2 + left;
            if(nums[mid] == target)
                return mid;
            else{
                if(nums[mid] < target){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        //如果最终没有找到
        return -1;
    }
    int mybiSearch(vector<int> nums,int target){
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) return nums[0]==target?0:-1;
        //查找循环有序数组的分界点，此时的rotate_index 是整个数组最小值的索引
        int rotate_index = find_rotate_index(nums);
            // 分界点就是targe，直接返回
        if(nums[rotate_index] == target){
            return rotate_index;
        }
            //如果rotate_index == 0,说明 原数组不是循环的，就是正常的有序数组
        if(rotate_index == 0){
            return biSearch(nums,0,n-1,target);
        }

        //如果目标值小于数组第一个元素，则在分界点右边数组查找
        if (target < nums[0]){
            // search in the right side
            return biSearch(nums,rotate_index, n - 1,target);
        }
        //如果目标值大于数组第一个元素，则在分界点左边数组查找
        return biSearch(nums,0, rotate_index,target);
    }

};
int main(){
//    int arr[10] = {4,4,4,5,6,1,2,3,3,3,};
//    int ans = Solution().search(arr,10,3);
//    cout<<ans<<endl;

//    vector<vector<int>> a = {{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};
//    vector<int> myans = Solution().intersection(a);
//    for(auto i:myans){
//        cout<<i<<" ";
//    }
//    cout<<endl;

    vector<int> arr = {4,5,6,1,2,3};
    int target = 6;
    int index = Solution().mybiSearch(arr,target);
    cout<<index<<endl;

    return 0;
}
