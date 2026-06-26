#include<iostream>
using namespace std;
const int N = 110;
int n,m;
int f[N][N],v[N],w[N],x[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>x[i]>>w[i]>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=0;k<=x[i]&&k*w[i]<=j;k++){
                f[i][j] = max(f[i][j],f[i-1][j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<f[n][m];
}