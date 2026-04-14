/* https://www.luogu.com.cn/problem/P1892
思路：根据关系拓展出新的域，然后并查集分关系组
      注意un操作一定要让初始域作为父节点 */
#include<iostream>
using namespace std;
const int N = 1e3+10;
int fa[N*2];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void un(int x,int y){//让朋友域作为父节点，最后结果遍历1~n即可
    int fx = find(x);
    int fy = find(y);
    fa[fy] = fx;
}
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)fa[i] = i;
    while(m--){
        char op;
        int x,y;
        cin>>op>>x>>y;
        if(op=='E'){
            un(x,y+n);
            un(y,x+n);
        }
        else{
            un(x,y);
        }
    }
    int count = 0;
    for(int i=1;i<=n;i++){
        if(fa[i]==i)count++;
    }
    cout<<count;

}