//https://www.luogu.com.cn/problem/P1551
#include<iostream>
using namespace std;
const int N = 5e3+10;
int fa[N];
int x,y;
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void un(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx==fy)return;
    fa[fx] = fy;
}
bool ch(int x,int y){
    return find(x) == find(y);
}
int main(){
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)fa[i] = i;
    while(m--){
        cin>>x>>y;
        un(x,y);
    }
    while(p--){
        cin>>x>>y;
        if(ch(x,y))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}