//https://www.luogu.com.cn/problem/P2918
#include<iostream>
#include<cstring>
using namespace std;
const int N = 110;
const int H = 5e4+10;
int f[N][H];//1~i个物品中，重量大于等于j，最小花费
int p[N],c[N];
int main(){
    int n,h;
    cin>>n>>h;
    /* 初始化注意：状态转移用了 f[i][max(j-p[i], 0)]，
    它依赖的是「当前行（第 i 行）左侧」的数据，而不是上一行。
    因此需要初始化整个f 而不是第一行就行 */
    memset(f,0x3f,sizeof(f));
    f[0][0] = 0;
    for(int i=1;i<=n;i++)cin>>p[i]>>c[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=h;j++){
            //状态转移方程：存或者不存
            /* 
            找存和不存两种情况的最小值，注意j-p[i]为负数也是合法的，
            当i位置的重量已经大于j了，那就可以只取i位置的物品了，所以
            就可以用f[i][0]+c[i]
            */
            f[i][j] = min(f[i-1][j],f[i][max(j-p[i],0)]+c[i]);
        }
    }
    cout<<f[n][h];
}