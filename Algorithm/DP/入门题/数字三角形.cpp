//https://www.luogu.com.cn/problem/P1216
#include<iostream>
using namespace std;
const int N = 1e3+10;
int a[N][N],f[N][N];//1.定义状态，到达该点的最大权值
int F[N];
int main(){
    int r;
    cin>>r;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
            //3.初始化
            if(i==1&&j==1){
                f[i][j] = a[i][j];
                continue;
            }
            //2.推导状态转移方程 4.确定填表顺序 5.确定最终结果
            f[i][j] = a[i][j] + max(f[i-1][j-1],f[i-1][j]);
        }
    }
    /* 
    //解法2：空间优化，用一维数组来滚动存状态
    for(int i=1;i<=r;i++){
        for(int j=i;j>=1;j--){//逆向遍历列，从后往前去更新F数组
            F[j] = a[i][j] + max(F[j-1],F[j]);
        }
    } 
    //最后仅需要遍历F数组找最大值即可
    */
    int ret = 0;
    for(int j=1;j<=r;j++){
        ret = max(ret,f[r][j]);
    }
    cout<<ret;
}