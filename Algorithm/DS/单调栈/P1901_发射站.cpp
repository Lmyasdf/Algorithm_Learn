/* https://www.luogu.com.cn/problem/P1901
思路：左右开弓，利用单调栈左右分别找最近最高，把i的发射值加到最高塔的ret中
错误：索引混乱，逻辑错误。错误让i去接收最高塔的能量，完全反了 */
#include<iostream>
#include<stack>
using namespace std;
const long long N = 1e6;
long long h[2*N],e[2*N];
long long ret[2*N];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i]>>e[i];
    }
    stack<int>st;
    for(int i=1;i<=n;i++){
        while(st.size() && h[st.top()]<=h[i])st.pop();
        if(st.size())ret[st.top()] += e[i];
        st.push(i);
    }
    stack<int>st2;
    for(int i=n;i>=1;i--){
        while(st2.size() && h[st2.top()]<=h[i])st2.pop();
        if(st2.size())ret[st2.top()] += e[i];
        st2.push(i);
    }
    long long maxret=0;
    for(int i=1;i<=n;i++){
        maxret = maxret>ret[i]?maxret:ret[i];
    }
    cout<<maxret;
    
}