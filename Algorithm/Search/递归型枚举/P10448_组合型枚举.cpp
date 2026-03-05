/* 
    题目：组合性枚举
    链接：https://www.luogu.com.cn/problem/P10448
    思路：用vector数组存序列，重点在于按照字典序升序要求，
    用for遍历后面可能插入的数即【begin，n】
 */
#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<int>v;
void dfs(int begin){
    if(v.size()==m){//序列数目够就输出
        for(int a:v)cout<<a<<" ";
        cout<<endl;
        return;
    }
    for(int i=begin;i<=n;i++){
        v.push_back(i);//更新序列
        dfs(i+1);
        v.pop_back();//回溯，回归原来序列
    }
}
int main(){
    cin>>n>>m;
    dfs(1);
}