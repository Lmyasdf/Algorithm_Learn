//https://www.luogu.com.cn/problem/P1164
//难度：??
#include<iostream>
using namespace std;
const int N = 110;
int w[N];
int f[10010];//存前i位中恰好价值j有多少种取法
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];
    f[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            f[j] += f[j-w[i]];   
        }
    }
    cout<<f[m];
}