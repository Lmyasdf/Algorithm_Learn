//https://www.luogu.com.cn/problem/P16238
//通过改变一个区间内的值（固定变化量），使最终匹配目标的位置最多
/* 思路：本题考察最大字段和及前缀和
1.转化为差值数组。

2.发现操作等价于：区间内选一个 k 达成达标，区间外保留原本达标的。

*3.推出目标：总达标数 = 原本达标数 + (区间内满足 d[i]==k 的数量 - 区间内原本达标数量)。

4.于是问题变成在 +1/-1/0 序列上找最大子段和。

5.利用差值分组 + 前缀和 + Kadane 的稀疏版本做到 O(n)。 */
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
const int N = 2e5+10;
int a[N],b[N],c[N],d[N];
int zero_cnt;
int pre[N];
vector<int>v;
//当想用二维数组存类<数,索引>关系时，由于数可能为负，所以可以考虑用哈希表
unordered_map<int,vector<int>>m;//存差值对应的索引位置<差值，存索引的数组>
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        d[i] = b[i] - a[i];

        if(d[i])m[d[i]].push_back(i);
        zero_cnt += (d[i]==0);
    }
    //构建统计0数量的前缀和数组
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1] + (d[i]==0);//统计0（已达到理想）数量的前缀和
    }
    int maxret = zero_cnt;//初始化最大值为0总数目，即不调整时候的达理想数
    //核心：
    for(auto &x : m){//遍历非0的d值
        auto &p = x.second;//对应索引数组
        //最大子段和模板
        int cur = 1;
        int best = 1;
        for(int i=1;i<p.size();i++){
            //区间[L,R]中0计算方法：pre[R] - pre[L-1]
            int zero = pre[p[i]-1] - pre[p[i-1]];//注意这个区间，不去包含端点
            cur = max(1,cur+1-zero);//重置 or 累加(+区间端点，-区间内0个数)
            best = max(best,cur);//更新最优解
        }
        maxret = max(maxret,best+zero_cnt);//结果 = 总d零数 + (调整后理想数 - 影响的d零数) 
    }

    cout<<maxret;
}
