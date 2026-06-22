#include<iostream>
using namespace std;
const int N = 2010;
const int M = 1010;
const int MOD = 1e8;
int a[N];
int f[N][M];//存[1,i]区间内奶牛能力值之和取模F后为j时的总方案数
int main(){
    int n,F;
    cin>>n>>F;
    for(int i=1;i<=n;i++)cin>>a[i];
    //初始化
    f[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<F;j++){
            //安全写法立即取模，以防止在加法过程中数值溢出
            f[i][j] = (f[i-1][j] + f[i-1][((j-a[i]%F)%F+F)%F]) % MOD;
        }
    }
    cout<<f[n][0] - 1;
}