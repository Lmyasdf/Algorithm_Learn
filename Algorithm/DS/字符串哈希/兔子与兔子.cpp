#include<iostream>
using namespace std;
typedef unsigned long long ULL;
const int P = 131;
const int N = 1e6+10;
ULL p[N],f[N];
string s;
void myhash(string s){
    p[0] = 1;
    for(int i=1;i<=s.size();i++){
        f[i] = f[i-1]*P + s[i-1];
        p[i] = p[i-1]*P;
    }
}
ULL gethash(int l,int r){
    return f[r] - f[l-1]*p[r-l+1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>s>>n;
    myhash(s);
    for(int i=1;i<=n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(gethash(a,b) == gethash(c,d))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}