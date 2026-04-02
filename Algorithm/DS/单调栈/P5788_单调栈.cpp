#include<iostream>
#include<stack>
using namespace std;
const int N = 3*1e6;
int a[N],ret[N];
int n;
void test(){
    stack<int>st;
    for(int i=n;i>=1;i--){
        while(st.size()&&a[st.top()]<=a[i])st.pop();
        if(st.size())ret[i] = st.top();
        st.push(i);
    }
    for(int i=1;i<=n;i++){
        cout<<ret[i]<<" ";
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    test();
}