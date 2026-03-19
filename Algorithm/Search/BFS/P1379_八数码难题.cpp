/* 
题目： 八数码难题
https://www.luogu.com.cn/problem/P1379
思路：重点在于二维下标和一维下标的转化，找到一维的0位置，变成二维
     然后找二维0的相邻位置二维下标，变成一维，然后在字符串中swap
     这样就避免了频繁string转二维数组再二维数组转string
错误：bfs中的找0一维位置pos，要找设的队头t，而不是s
     ret 少赋值了一位数5
 */

#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
const int n = 3;
unordered_map<string,int>dist;
string s;
string ret = "123804765";
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
void bfs(){
    queue<string>q;
    q.push(s);
    while(q.size()){
        string t = q.front();
        q.pop();
        int pos = 0;
        while(t[pos]!='0')pos++;//找到0的一维下标

        //将pos变为二维下标
        int x = pos/n;
        int y = pos%n;

        //遍历所有方向，去交换
        for(int i=0;i<4;i++){
            string ns = t;
            //待交换位置的二维下标
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0&&ny>=0&&nx<n&&ny<n){
                int newpos = nx*n + ny;//变一维
                swap(ns[newpos],ns[pos]);
                if(dist.count(ns))continue;
                dist[ns] = dist[t] + 1;
                q.push(ns);
                //出口
                if(ns == ret)return;
            }
        }
    }

}

int main(){
    cin>>s;
    bfs();
    cout<<dist[ret];
}