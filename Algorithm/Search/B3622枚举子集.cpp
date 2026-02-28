/* 
    题目：枚举子集
    链接：https://www.luogu.com.cn/problem/B3622
    思路：利用DFS遍历，因为题目要求按字典序输出，所以优先遍历N情况
    本题重点在于全局变量path的使用和dfs函数的参数 
*/
#include<iostream>
#include<string>
using namespace std;
int n;
string path;
void dfs(int pos){
    //退出递归
    if(pos>n){
        cout<<path<<endl;
        return;
    }
    //不选
    path += 'N';
    dfs(pos+1);
    path.pop_back();
    //选
    path += 'Y';
    dfs(pos+1);
    path.pop_back();

}
int main(){
    cin>>n;
    dfs(1);
}
