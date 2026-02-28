/* 
    题目：枚举序列
    链接：https://www.luogu.com.cn/problem/B3623
 */

#include<iostream>
#include<vector>
using namespace std;
const int N = 15;
int st[N];
vector<int>v;
int n,k;
void dfs(){
    if(v.size()==k){
        for(int a:v)cout<<a<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i] = 1;//标记这个数是否选择过
            v.push_back(i);
            dfs();
            v.pop_back();
            st[i] = 0;
        }
    }
}
int main(){
    cin>>n>>k;
    dfs();
}