#include<iostream>
#include<cstring>
using namespace std;
int F[35];

class Solution {
public:
    int dfs(int n){
        if(F[n]!=-1)return F[n];
        if(n==0||n==1)return n;
        F[n] = dfs(n-1) + dfs(n-2);
        return F[n];
    }
    int fib(int n) {
        memset(F,-1,sizeof(F));
        return dfs(n);
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    cout<<s.fib(n);
}