//http://luogu.com.cn/problem/P1077
//多重背包求方案数模板问题
#include<iostream>
using namespace std;
const int P = 1e6+7;
const int N = 110;
int f[N][N],a[N],n,m;//存0~i盆花，恰好花总数目为j时的方案数
int F[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    f[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            //当前i位不选，去i-1位恰好j取数
            f[i][j] = f[i-1][j];
            for(int k=1;k<=j&&k<=a[i];k++){
                //选1盆到a[i]盆的情况累加
                f[i][j] = (f[i][j] + f[i-1][j-k]) % P;
            }
        }
    }
    
    cout<<f[n][m]<<endl;

/*  //空间优化版本：
    F[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=1;k<=a[i]&&k<=j;k++){
                F[j] = (F[j] + F[j-k]) % P;
            }
        }
    }
    cout<<F[m];
*/
    
}
