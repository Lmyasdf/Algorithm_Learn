/* 
题目：验证栈序列
https://www.luogu.com.cn/problem/P4387
思路：先用两个数组存序列，然后边入栈边判断，最后判断栈是否为空（即是否两个序列匹配）

 */
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
const int N = 1e5+10;
int a[N],b[N];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        stack<int>st;
        int j=1;
        for(int i=1;i<=n;i++){
            st.push(a[i]);
            while(!st.empty()&&b[j]==st.top()&&j<=n){
                st.pop();
                j++;
            }
        }
        if(st.empty())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}