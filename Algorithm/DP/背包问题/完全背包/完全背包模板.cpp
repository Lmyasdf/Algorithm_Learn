#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e3+10;
int f[N][N];//1~i个物品，体积恰好j时的最大价值
int v[N],w[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j>=v[i])f[i][j] = max(f[i-1][j],f[i][j-v[i]]+w[i]);
            else f[i][j] = f[i-1][j];
        }
    }
    cout<<f[n][m]<<endl;
    memset(f,-0x3f,sizeof(f));
    f[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j>=v[i])f[i][j] = max(f[i-1][j],f[i][j-v[i]]+w[i]);
            else f[i][j] = f[i-1][j];
        }
    }
    if(f[n][m]<0)cout<<0;
    else cout<<f[n][m];
}