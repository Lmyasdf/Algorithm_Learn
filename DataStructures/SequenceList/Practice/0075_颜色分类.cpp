/*
 * 题目：75. 颜色分类 (荷兰国旗问题)
 * 链接：https://leetcode.cn/problems/sort-colors/
 * 思路：
 * 将数组分成三个区间：
 * - [0, left]      存储 0 (全部置于左侧)
 * - [left+1, i-1]  存储 1 (保持不动)
 * - [right, n-1]   存储 2 (全部置于右侧)
 * 技巧：
 * 使用三指针：i 负责从左向右扫描，left 维护 0 的边界，right 维护 2 的边界。
 * 遇到 0 则与 left+1 交换，遇到 2 则与 right-1 交换。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=-1,r=nums.size(),i=0;
        while(i<r){
            if(nums[i]<1)swap(nums[++l],nums[i++]);
            else if(nums[i]==1)i++;
            else{
                swap(nums[--r],nums[i]);
            }
        }
    }
};

int main() {
    Solution s;
    vector<int>nums = {2,0,2,1,1,0};
    s.sortColors(nums);
    for(int i:nums)cout<<i<<" ";
    return 0;
}