/* 
https://www.luogu.com.cn/problem/P1162
思路：先对边界0dfs，标记出不被包围的0，st为true，最后输出st值不为true的0为2就好了
 */
#include<iostream>
using namespace std;
const int N = 35;
int n;
int a[N][N];
bool st[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void dfs(int x,int y){
    st[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<1||ny<1||nx>n||ny>n||st[nx][ny]||a[nx][ny]==1)continue;
        st[nx][ny] = true;
        dfs(nx,ny);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i][1]==0&&!st[i][1])dfs(i,1);
        if(a[i][n]==0&&!st[i][n])dfs(i,n);
    }
    for(int j=1;j<=n;j++){
        if(a[1][j]==0&&!st[1][j])dfs(1,j);
        if(a[n][j]==0&&!st[n][j])dfs(n,j);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==0&&!st[i][j]){
                cout<<"2 ";
                continue;
            }
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
