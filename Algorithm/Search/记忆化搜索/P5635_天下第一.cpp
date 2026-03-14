#include<iostream>
using namespace std;
const int N = 1e4+10;
char f[N][N];
int T,p;
char dfs(int a,int b){
    if(a==0)return f[a][b] = '1';
    if(b==0)return f[a][b] = '2';

    if(f[a][b])return f[a][b];
    f[a][b] = '3';//标记这个ab对遍历过了，再遇到时候就返回平局
    
    f[a][b] = dfs((a+b)%p,(a+2*b)%p);
    return f[a][b];
}
int main(){
    cin>>T>>p;
    while(T--){
        int a,b;
        cin>>a>>b;
        int ret = dfs(a,b);
        if(ret == '1' || ret == '2')cout<<ret-'0'<<endl;
        else cout<<"error"<<endl;
    }
}