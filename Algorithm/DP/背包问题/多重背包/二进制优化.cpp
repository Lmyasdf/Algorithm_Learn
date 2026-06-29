#include<iostream>
using namespace std;
const int N = 110 * 5;
int f[N],w[N],v[N];
int pos;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        //把数量按照二进制拆分
        int t = 1;
        while(x>=t){
            pos++;
            w[pos] = t * y;
            v[pos] = t * z;
            x -= t;
            t *= 2;
        }
        if(x){
            pos++;
            w[pos] = x * y;
            v[pos] = x * z;
        }
        
    }
    for(int i=1;i<=pos;i++){//注意是遍历到pos不是n了
        for(int j=m;j>=w[i];j--){
            f[j] = max(f[j],f[j-w[i]] + v[i]);
        }
    }
    cout<<f[m];
}