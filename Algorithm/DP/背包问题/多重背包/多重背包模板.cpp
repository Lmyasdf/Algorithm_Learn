//https://ac.nowcoder.com/acm/problem/235950
#include<iostream>
using namespace std;
const int N = 110;
int n,m;
//f:存[1，i]号物品中总重量小于等于j的最优价值
int f[N][N],v[N],w[N],x[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>x[i]>>w[i]>>v[i];
    //三重for循环遍历
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            //注意这层：遍历i号物品的选取数目，取最优
            for(int k=0;k<=x[i]&&k*w[i]<=j;k++){
                f[i][j] = max(f[i][j],f[i-1][j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<f[n][m];
}
/* 
    空间优化版本，删除第一维
    int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>x[i]>>w[i]>>v[i];
    //三重for循环遍历
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            //注意这层：遍历i号物品的选取数目，取最优
            for(int k=0;k<=x[i]&&k*w[i]<=j;k++){
                f[j] = max(f[j],f[j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<f[m];
} 
    */