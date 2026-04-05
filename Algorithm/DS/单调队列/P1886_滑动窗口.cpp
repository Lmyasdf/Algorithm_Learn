//https://www.luogu.com.cn/problem/P1886
//错误：访问队列元素之前要先判断队列是否空(q.size())
//思路：1.弹出队内不符合单调性元素 2.判断过期  3.插入新元素  4.输出结果
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
const int N = 1e6+10;
int a[N];
int n,k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    deque<int>q;
    for(int i=1;i<=n;i++){
        while(q.size() && a[q.back()]>=a[i])q.pop_back();
        if(q.size()&&i-q.front()==k)q.pop_front();
        q.push_back(i);
        if(i>=k&&q.size())cout<<a[q.front()]<<" ";
    }
    cout<<endl;
    q.clear();
    for(int i=1;i<=n;i++){
        while(q.size() && a[q.back()]<=a[i])q.pop_back();//弹出不符合单调性元素
        if(q.size()&&i-q.front()==k)q.pop_front();//删除过期元素
        q.push_back(i);//插入新元素
        if(i>=k&&q.size())cout<<a[q.front()]<<" ";//输出结果
    }
}