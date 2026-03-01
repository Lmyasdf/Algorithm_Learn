/* 
题目：选数
链接：https://www.luogu.com.cn/problem/P1036
思路：暴力搜索，dfs递归搜出所有组合情况，判断和是否为素数即可
错误: 1.错误使用哈希表。使用哈希表，这样不同数相同和就合并成了一种情况，出错
    2.判断过程在dfs出口处就可以了，不用再创建数组存这些结果最后在main中遍历判断
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int sum = 0,cnt = 0;
int n,k;
vector<int>v,v2;
bool isPrime(long long x){
    if(x<2)return false;
    if(x==2||x==3)return true;
    if(x%2==0||x%3==0)return false;
    for(long long i=5;i*i<=x;i+=6)if(x%i==0||x%(i+2)==0)return false;
    return true;
}
void dfs(int begin){
    if(v2.size()==k){
       for(int i=0;i<k;i++)sum+=v2[i];
       if(isPrime(sum))cnt++;
       sum=0;
       return;
    }
    for(int i=begin;i<n;i++){
        v2.push_back(v[i]);
        dfs(i+1);
        v2.pop_back();
    }
}
int main(){    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    dfs(0);
    cout<<cnt;
}