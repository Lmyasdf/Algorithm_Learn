//https://www.nowcoder.com/practice/38ae72379d42471db1c537914b06d48e?tpId=230&tqId=39755&ru=/exam/oj
#include<iostream>
using namespace std;
const int N =510;
int a[N][N];
int f[N][N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(i==1&&j==1)f[i][j] = a[i][j];
            else if(i==1){
                f[i][j] = a[i][j] + f[i][j-1];
            }
            else if(j==1){
                f[i][j] = f[i-1][j] + a[i][j];
            }
            else f[i][j] = min(f[i-1][j],f[i][j-1]) + a[i][j];
        }
    }
    cout<<f[n][m]<<endl;

}