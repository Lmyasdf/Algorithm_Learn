/*
 * 题目：283. 移动零
 * 链接：https://leetcode.cn/problems/move-zeroes/
 * 描述：给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 要求：必须在原数组上操作，不能拷贝额外数组。
 */

 #include<iostream>
 #include<vector>
 using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur=-1,i=0;
        while(i<nums.size()){
            if(nums[i]!=0)swap(nums[++cur],nums[i]);
            i++;
        }
    }
};
int main(){
    Solution a;
    vector<int>nums = {0,1,0,3,12};
    a.moveZeroes(nums);
    for(int i:nums)cout<<i<<" ";
    return 0;
}