/* 
题目：数的划分
https://www.luogu.com.cn/problem/P1025
思路：暴力搜索，然后画树，进行冗余剪枝和可行性剪枝
 */
#include<iostream>
using namespace std;
int n,k;
int ret=0,path=0;
void dfs(int pos,int begin){
    if(pos>k){
        if(path == n)ret++;
        return;
    }
    //引入begin，冗余剪枝
    for(int i=begin;i<=n;i++){
        if(path+i*(k-pos+1)>n)return;//可行性剪枝
        path += i;
        dfs(pos+1,i);
        path -= i;
    }

}
int main(){
    cin>>n>>k;
    dfs(1,1);
    cout<<ret;
}