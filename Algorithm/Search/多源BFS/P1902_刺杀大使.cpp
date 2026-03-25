#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
const int N = 1e3+10;
int a[N][N];
bool st[N][N];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool bfs(int mid){
    if(n==1)return true;
    memset(st,false,sizeof(st));
    queue<pair<int,int>>q;
    for(int j=1;j<=m;j++){
        q.push({1,j});
        st[1][j] = true;
    }
    while(q.size()){
        pair<int,int>t = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!st[nx][ny]&&a[nx][ny]<=mid){
                st[nx][ny] = true;
                if(nx==n)return true;
                q.push({nx,ny});
            }
        }
    }
    return false;

}
int main(){
    cin>>n>>m;
    int l=0,r=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            r = max(r,a[i][j]);
        }
    }
    
    while(l<r){
        int mid = (l+r)/2;
        if(bfs(mid))r=mid;//bfs×öÅÐ¶Ï
        else l = mid+1;
    }
    cout<<r;
}