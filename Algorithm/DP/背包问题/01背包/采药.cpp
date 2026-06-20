//https://www.luogu.com.cn/problem/P1048
//难度：?
#include<iostream>
using namespace std;
int T,m;
int f[110][1010];
int t[110],w[110];
int main(){
    cin>>T>>m;
    for(int i=1;i<=m;i++)cin>>t[i]>>w[i];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=T;j++){
            //遍历每个位置时有两种情况：取与不取
            if(t[i]<=j)f[i][j] = max(f[i-1][j],f[i-1][j-t[i]]+w[i]);
            else f[i][j] = f[i-1][j];
        }
    }
    cout<<f[m][T];
}