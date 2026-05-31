#include<iostream>
using namespace std;
const int N = 1e5;
int fa[N],d[N];
void init(int n){
    for(int i=1;i<=n;i++){
        fa[i] = i;
        d[i] = 0;
    }
}

int find(int x){
    if(fa[x] == x) return x;
    int t = find(fa[x]);//递归更新父节点
    d[x] += d[fa[x]];//加上更新后的d父值
    return fa[x] = t;//路径压缩
}

void un(int x,int y,int w){
    int fx = find(x),fy = find(y);
    if(fx != fy){
        fa[fx] = fy;
        d[fx] = d[y] + w - d[x]; 
    }
}
int query(int x,int y){
    int fx = find(x),fy = find(y);
    if(fx != fy)return -1;
    return d[y] - d[x];
}
int main(){
    init(6);
    un(1,2,2);
    un(3,2,1);
    un(6,5,3);
    un(5,4,0);
    un(5,2,7);
    cout<<"fa[5] = "<<find(5)<<endl;
    cout<<"fa[4] = "<<find(4)<<endl;
    cout<<"5~2 = "<<query(5,2)<<endl;
}