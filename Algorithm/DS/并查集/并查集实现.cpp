#include<iostream>
using namespace std;
const int N = 2e5+10;
int fa[N];
int n,m;
int z,x,y;
int find(int x){
    // if(x=fa[x])return x;
    // return fa[x] = find(fa[x]);
    return x==fa[x]?x:fa[x] = find(fa[x]);
}
void un(int x,int y){
    int fx = find(x);
    int fy = find(y);
    fa[fx] =fy;//注意这里是赋值一个父节点！！
}
bool ch(int x,int y){
    return find(x) == find(y);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i] = i;
    for(int i=1;i<=m;i++){
        cin>>z>>x>>y;
        if(z==1)un(x,y);
        else if(z==2){
            if(ch(x,y))cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
}