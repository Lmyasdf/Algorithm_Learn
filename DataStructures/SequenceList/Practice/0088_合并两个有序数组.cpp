/*
 * 题目：88. 合并两个有序数组 (merge)
 * 链接：https://leetcode.cn/problems/merge-sorted-array/
 * 思路：
 * 解法一：利用辅助数组 (归并排序核心步骤)
 * 1. 定义两个指针 i, j 分别指向 nums1 和 nums2 的开头。
 * 2. 比较两个数组的元素，谁小就谁进辅助数组 arr。
 * 3. 处理剩余元素：将没遍历完的数组直接拼接到 arr 后面。
 * 4. 拷贝回原数组：将 arr 的内容写回 nums1。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int i = 0, j = 0;
        // int arr[200]; // 辅助数组
        // int cur = 0;  // 指向辅助数组的当前位置

        // // 1. 比较并放入辅助数组
        // while (i < m && j < n) {
        //     if (nums1[i] < nums2[j]) {
        //         arr[cur++] = nums1[i++];
        //     } else {
        //         arr[cur++] = nums2[j++];
        //     }
        // }

        // // 2. 判断哪个数组还有剩余
        // while (i < m) arr[cur++] = nums1[i++];
        // while (j < n) arr[cur++] = nums2[j++];

        // // 3. 把辅助数组的值赋回 nums1
        // for (int k = 0; k < m + n; k++) {
        //     nums1[k] = arr[k];
        // }
        int i=0,j=0;
        int arr[m+n+10];//辅助数组
        int cur = 0;
        while(i<m&&j<n){
            if(nums1[i]<=nums2[j]) arr[cur++] = nums1[i++];
            else arr[cur++] = nums2[j++];
        }
        //判断哪个数组还有剩余
        while(i<m)arr[cur++] = nums1[i++];
        while(j<n)arr[cur++] = nums2[j++];
        //把辅助数组中的数据赋值回nums1
        for(int k=0;k<m+n;k++){
            nums1[k] = arr[k];
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution sol;
    sol.merge(nums1, 3, nums2, 3);

    for (int x : nums1) cout << x << " "; 
    return 0;
}