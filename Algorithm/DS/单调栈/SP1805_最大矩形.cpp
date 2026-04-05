#include<iostream>
#include<stack>
using namespace std;
const int N = 1e6+10;
int n;
long long a[N];
long long ret;
int l[N],r[N];
void test(){
    stack<int>sl;
    stack<int>sr;
    //找左近小
    for(int i=1;i<=n;i++){
        while(sl.size()&&a[sl.top()]>=a[i])sl.pop();
        if(sl.size())l[i] = sl.top();
        else l[i] = 0;
        sl.push(i);
    }
    //找右近小
    for(int i=n;i>=1;i--){
        while(sr.size()&&a[sr.top()]>=a[i])sr.pop();
        if(sr.size())r[i] = sr.top();
        else r[i] = n+1;
        sr.push(i);
    }
}
int main(){
    
    while(cin>>n){
        if(n==0)return 0;
        ret = 0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        test();
        for(int i=1;i<=n;i++){
            ret = max(ret,a[i]*(r[i]-l[i]-1));
        }
        cout<<ret<<endl;
    }

}