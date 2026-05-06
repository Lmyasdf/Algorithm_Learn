/* https://www.luogu.com.cn/problem/P2024
注意：多关系维护，所有关系都需要进行un，判断非法时候也要全面 */
#include<iostream>
using namespace std;
const int N = 5e4+10;
int fa[3*N];
int n,k;
int ret;
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void un(int x,int y){
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}
bool ch(int x,int y){
    return find(x) == find(y);
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=3*n;i++)fa[i] = i;
    while(k--){
        int op,x,y;
        cin>>op>>x>>y;
        if(x>n||y>n){
            ret++;
            continue;
        }
        if(op==1){
            if(ch(x,y))continue;
            if(ch(x+n,y)||ch(x+2*n,y)){
                ret++;
                continue;
            }
            un(x,y);
            un(x+n,y+n);
            un(x+2*n,y+2*n);
        }
        else{
            if(ch(x+n,y))continue;
            if(x==y||ch(x,y)||ch(x+2*n,y)){
                ret++;
                continue;
            }
            
            un(x+n,y);
            un(x,y+2*n);
            un(x+2*n,y+n);
        }
    }
    cout<<ret;
}