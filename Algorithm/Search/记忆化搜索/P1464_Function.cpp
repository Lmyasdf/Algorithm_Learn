/* 
题目：Function
https://www.luogu.com.cn/problem/P1464
思路：记忆化降低时间复杂度 
*/
#include<iostream>
using namespace std;
const int N = 25;
long long f[N][N][N];
long long a,b,c;
long long dfs(long long a,long long b,long long c){
    if(a<=0 || b<=0 || c<=0)return 1;
    if(a>20||b>20||c>20)return dfs(20,20,20);
    if(f[a][b][c])return f[a][b][c];
    if(a<b&&b<c){
        f[a][b][c] = dfs(a,b,c-1) + dfs(a,b-1,c-1) - dfs(a,b-1,c);
        return f[a][b][c];
    }
    else{
        f[a][b][c] = dfs(a-1,b,c) + dfs(a-1,b-1,c) + dfs(a-1,b,c-1) - dfs(a-1,b-1,c-1);
        return f[a][b][c];
    }
}
int main(){
    while(cin>>a>>b>>c){
        if(a==-1&&b==-1&&c==-1)break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dfs(a,b,c)<<endl;
    }
}