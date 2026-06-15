//https://www.luogu.com.cn/problem/P1004
/* 总结：本题使用三维dp数组，两种路径同时进行，通过枚举所有i1 i2情况
    可以实现遍历所有点的目的，通过数组第一位来保证步数相同，两路径同步
    进行然后考虑四种情况（i1 i2分别有两种情况：右、下）,找到最优解，
    然后判断路径是否相同，分情况更新f值
错误：先考虑了贪心思路，先dp一遍，然后把最优路径的数变为0，再dp一遍
    但是这样做会漏掉数，费时费力还不对
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
const int N = 15;
int f[2*N][N][N];//三维dp数组来存走多少步，某位置两种路径的最优和
int a[N][N];
int main(){
    int n;
    cin>>n;
    int x,y,c;
    while(cin>>x>>y>>c && x){
        a[x][y] = c;
    }
    
    for(int s=2;s<=2*n;s++){//步数，保证1 2同步移动
        //遍历所有点
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=n;i2++){
                int j1 = s - i1;
                int j2 = s - i2;
                if(j1<=0||j1>n||j2<=0||j2>n)continue;
                int t = f[s-1][i1][i2];
                t = max(t,f[s-1][i1][i2-1]);
                t = max(t,f[s-1][i1-1][i2]);
                t = max(t,f[s-1][i1-1][i2-1]);
                if(i1 == i2){
                    f[s][i1][i2] = t + a[i1][j1];
                }
                else{
                    f[s][i1][i2] = t + a[i1][j1] + a[i2][j2];
                }
            }
        }
    }
    cout<<f[2*n][n][n]<<endl;
}