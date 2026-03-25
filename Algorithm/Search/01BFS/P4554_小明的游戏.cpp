#include<iostream>
#include<deque>
#include<cstring>
using namespace std;
const int N = 510;
int n,m,x1,y_1,x2,y2;
int dist[N][N];
char c[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs(){
    if(x1==x2&&y_1==y2)return;
    deque<pair<int,int>>q;
    q.push_back({x1,y_1});
    memset(dist,-1,sizeof(dist));
    dist[x1][y_1] = 0;
    while(q.size()){
        pair<int,int>t = q.front();
        q.pop_front();
        if(t.first==x2&&t.second == y2)return;
        for(int i=0;i<4;i++){
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if(nx>=0&&ny>=0&&nx<n&&ny<m){
                int w = (c[t.first][t.second] == c[nx][ny]?0:1);
                if(dist[nx][ny]==-1){
                    dist[nx][ny] = dist[t.first][t.second] + w;
                    if(w==1)q.push_back({nx,ny});
                    else q.push_front({nx,ny});
                }
                else if(dist[t.first][t.second]+w<dist[nx][ny]){
                    dist[nx][ny] = dist[t.first][t.second] + w;
                }
            }
        
        }
    }
}
int main(){
    while(cin>>n>>m,n&&m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        cin>>x1>>y_1>>x2>>y2;
        bfs();
        cout<<dist[x2][y2]<<endl;
    }
    
}