//https://www.luogu.com.cn/problem/P1757
#include<iostream>
#include<vector>
using namespace std;
const int N = 1e3+10;
int f[N][N];
vector<pair<int,int>>g[N];
int cnt;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        cnt = max(cnt,c);
        g[c].push_back({a,b});
    }

    for(int i=1;i<=cnt;i++){
        for(int j=n;j>=0;j--){
            f[i][j] = f[i-1][j];

            for(auto t:g[i]){
                int a = t.first,b = t.second;
                if(j>=a)f[i][j] = max(f[i][j],f[i-1][j-a] + b);
            }
        }
    }
    cout<<f[cnt][n]<<endl;


}