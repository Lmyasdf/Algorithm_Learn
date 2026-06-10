//https://www.luogu.com.cn/problem/P1057
#include<iostream>
using namespace std;
const int N = 40;
int f[N][N];//存第m步走到第n位有几种走法
int main(){
    int n,m;
    cin>>n>>m;
    f[1][2] = 1;
    f[1][n] = 1;
    for(int i=2;i<=m;i++){
        //推导状态转移方程，左右相加即为下一步该点的走法数
        f[i][n] = f[i-1][1] + f[i-1][n-1];
        f[i][1] = f[i-1][2] + f[i-1][n];
        for(int j=2;j<=n-1;j++){
            f[i][j] = f[i-1][j-1] + f[i-1][j+1];
        }
    }
    cout<<f[m][1];
}