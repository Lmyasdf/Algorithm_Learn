#include<iostream>
using namespace std;
const int N = 110;
int f[N][N],a[N][N];
int n,m;
int ret = 0;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int dfs(int x,int y){
    int max =1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=1&&ny>=1&&nx<=n&&ny<=m&&a[nx][ny]>a[x][y]){
            max++;
            f[nx][ny] = dfs(nx,ny);
        }
    }
    return f[x][y];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ret=max(dfs(i,j),ret);
        }
    }
    cout<<ret;
}