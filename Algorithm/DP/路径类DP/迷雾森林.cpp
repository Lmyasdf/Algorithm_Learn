//https://ac.nowcoder.com/acm/problem/53675
#include<iostream>
using namespace std;
const int N = 3010;
const int p = 2333;
int f[N][N],a[N][N];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    f[n][0] = 1;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(a[i][j]==0)f[i][j] = (f[i+1][j] + f[i][j-1])%p;
        }
    }
    cout<<f[1][m]<<endl;
}