//https://www.luogu.com.cn/problem/P1002
#include<iostream>
using namespace std;
const int N = 30;
long long f[N][N];//´íÎó:ÒªÓÃlong long
int a[N][N];
int main(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1+=2;
    y1+=2;
    x2+=2;
    y2+=2;
    a[x2][y2]=1;
    a[x2-1][y2-2]=1;
    a[x2-1][y2+2]=1;
    a[x2-2][y2-1]=1;
    a[x2-2][y2+1]=1;
    a[x2+1][y2-2]=1;
    a[x2+1][y2+2]=1;
    a[x2+2][y2-1]=1;
    a[x2+2][y2+1]=1;
    f[2][1] = 1;
    for(int i=2;i<=x1;i++){
        for(int j=2;j<=y1;j++){
            if(!a[i][j])f[i][j] = f[i-1][j] + f[i][j-1];
        }
    }
    cout<<f[x1][y1];
}