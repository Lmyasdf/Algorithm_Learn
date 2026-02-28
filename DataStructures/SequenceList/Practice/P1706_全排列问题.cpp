/* 
    题目：全排列问题
    链接：https://www.luogu.com.cn/problem/B3623
 */
#include<iostream>
#include<vector>
using namespace std;
const int N = 15;
int st[N];
int n;
vector<int>v;
void dfs(){
    for(int i=1;i<=n;i++){
        if(v.size()==n){
            for(int a:v)printf("%5d",a);
            cout<<endl;
            return;
        }
        if(!st[i]){
            st[i] = 1;
            v.push_back(i);
            dfs();
            st[i] = 0;
            v.pop_back();
        }
    }
}
int main(){
    cin>>n;
    dfs();
}