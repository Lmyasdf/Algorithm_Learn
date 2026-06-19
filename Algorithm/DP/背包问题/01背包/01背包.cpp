//https://ac.nowcoder.com/acm/problem/226514
#include<iostream>
using namespace std;
const int N = 1010;
int v[N],w[N];
int f[N][N];//存第i个物品，背包容量j时，装的最大价值
int n,m;
int F[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    //问题一：求背包容量之内的最大价值
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //状态转移方程：存或者不存
            if(j-v[i]>=0)f[i][j] = max(f[i-1][j-v[i]] + w[i],f[i-1][j]);
            else f[i][j] = f[i-1][j];
        }
    }
    cout<<f[n][m]<<endl;

    //问题二：求背包恰好装满的价值
    /* 初始化：初始化为负无穷，这样可以过滤掉没装满的情况只保留恰好装满，
    后面遇到的物品i可以v[i]和当前保留位置v[i-n]相加得到j，存在对应j处，
    然后值为保留值+v[i] */
    for(int j=1;j<=m;j++)f[0][j] = -0x3f3f3f3f;
    //重点：00位置是合法的
    f[0][0] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j>=v[i])f[i][j] = max(f[i-1][j-v[i]] + w[i],f[i-1][j]);
            else f[i][j] = f[i-1][j];
        }
    }
    if(f[n][m]>0)cout<<f[n][m];
    else cout<<"0";

    //一维数组空间优化法
    /* for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            F[j] = max(F[j-v[i]]+w[i],F[j]);
        }
    }
    cout<<F[m]<<endl;

    for(int j=1;j<=m;j++)F[j] = -0x3f3f3f3f;
    F[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            F[j] = max(F[j-v[i]]+w[i],F[j]);
        }
    }
    if(F[m]>0)cout<<F[m];
    else cout<<"0"; */
}