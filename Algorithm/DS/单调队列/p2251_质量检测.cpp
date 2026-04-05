#include<iostream>
#include<deque>
using namespace std;
const int N = 1e5+10;
int a[N];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    deque<int>q;
    for(int i=1;i<=n;i++){
        while(q.size()&&a[q.back()]>=a[i])q.pop_back();
        if(q.size()&&i-q.front()==m)q.pop_front();
        q.push_back(i);
        if(q.size()&&i>=m)cout<<a[q.front()]<<endl;
    }
}