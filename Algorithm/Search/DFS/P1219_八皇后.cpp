/* 
题目：八皇后
https://www.luogu.com.cn/problem/P1219
错误：v不需要手动清空，在回溯算法中，v 的维护是靠 push（选择前） 和 pop（撤销时） 自动完成的，不需要手动清空。
 */
#include<iostream>
#include<vector>
using namespace std;
const int N = 15;
bool col[N],st1[N*2],st2[N*2];//标记不能放置的列和两条对角线
vector<int>v;
vector<vector<int>>ret;
int n;
int count=0;
void dfs(int row){
    if(row>n){
        count++;
        if(count<=3){
            for(int a:v)cout<<a<<" ";
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!col[i]&&!st1[i-row+n]&&!st2[row+i]){//判断能否放置
            v.push_back(i);
            col[i] = true;
            st1[i-row+n] = true;
            st2[row+i] = true;
            dfs(row+1);
            //恢复现场
            v.pop_back();
            col[i] = false;
            st1[i-row+n] = false;
            st2[row+i] = false;
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
    cout<<count;
}