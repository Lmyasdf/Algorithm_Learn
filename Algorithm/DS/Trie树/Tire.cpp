#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int N = 3e6+10;
int tree[N][70],p[N],e[N];
int idx;

int calch(char c){//错误1：没有错开索引，全都是0开始~某个数
    if(c>='a'&&c<='z')return c-'a';
    else if(c>='A'&&c<='Z')return c-'A'+26;
    else return c-'0'+52;
}

void insert(string &s){
    int cur = 0;
    p[cur]++;
    for(auto c:s){
        int cal = calch(c);
        if(tree[cur][cal]==0)tree[cur][cal]=++idx;
        cur = tree[cur][cal];
        p[cur]++;
    }
    e[cur]++;
}

int find_pre(string &s){
    int cur = 0;
    for(auto c:s){
        int cal = calch(c);
        if(tree[cur][cal] == 0)return 0;
        cur = tree[cur][cal];
    }
    return p[cur];
}
//高效重置
void re(){
    for(int i=0;i<=idx;i++){
        p[i] = 0;
        e[i] = 0;
        memset(tree[i], 0, sizeof(tree[i])); 
    }
    idx = 0;//错误2:忘记重置idx
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        re();
        int n,q;
        cin>>n>>q;
        string s;
        for(int i=1;i<=n;i++){
            cin>>s;
            insert(s);
        }
        for(int i=1;i<=q;i++){
            cin>>s;
            cout<<find_pre(s)<<endl;
        }
        
    }
}