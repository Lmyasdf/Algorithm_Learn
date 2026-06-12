//https://www.luogu.com.cn/problem/P1541
//错误: 1. ijkl遍历没从0开始而是1
//      2. t的更新逻辑错误，误以为像其他题一样把前1~4步的f值累加到          
//         该位置,本题是要寻找最优解，并不是找最大和
#include<iostream>
using namespace std;
const int N = 45;
//每一维存的是n步的卡片数，f存的是分别用这些卡片得到的最大值
int f[N][N][N][N];
int a[360];
int cnt[5];//存每张卡片共有多少
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    f[0][0][0][0] = a[1];
    //枚举所有卡片使用情况
    //状态转移方程，找到使用1~4步卡片到该点的opsf
    //该情况的最优f值就是前1-4步的opsf+a[p]
    for(int i=0;i<=cnt[1];i++){
        for(int j=0;j<=cnt[2];j++){
            for(int k=0;k<=cnt[3];k++){
                for(int l=0;l<=cnt[4];l++){
                    int p = 1+i+2*j+3*k+4*l;
                    int &t = f[i][j][k][l];
                    
                    //这里因为必须要ijkl大于0才能去访问减一位，所以逐步判断
                    //而不是直接判断i-1 j-1 k-1 l-1 哪个值更大
                    if(i) t = max(t,f[i-1][j][k][l]+a[p]);
                    if(j) t = max(t,f[i][j-1][k][l]+a[p]);
                    if(k) t = max(t,f[i][j][k-1][l]+a[p]);
                    if(l) t = max(t,f[i][j][k][l-1]+a[p]);
                }
            }
        }
    }
    cout<<f[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
}