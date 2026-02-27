/* 
    解法二：原地合并，空间复杂度更小的合并方法
    思路： 在原nums1数组中操作，利用逆向遍历，把nums1和nums2最大的值放nums1后，如此
    循环，当其中一个数组全遍历完后，把剩下的数组中的元素全部存入到nums1后
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1;//i、j都指向各自数组的最后一个元素处
        int cur = n+m-1;//该指针指向合并后的最后一个元素处
        while(i>=0&&j>=0){//大的赋nums1
            if(nums2[j]>=nums1[i])nums1[cur--] = nums2[j--];
            else nums1[cur--] = nums1[i--];
        }
        while(j>=0) nums1[cur--] = nums2[j--];
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