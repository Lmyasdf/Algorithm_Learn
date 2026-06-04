#include<iostream>
#include<string>
using namespace std;
const int N = 1e6+10;
int tree[N][26],p[N],e[N];
bool st[N];
int idx;
void insert(string &s){
    int cur = 0;
    p[0]++;
    for(auto c:s){
        int path = c - 'a';
        if(tree[cur][path]==0)tree[cur][path] = ++idx;
        cur = tree[cur][path];
        p[cur]++;
    }
    e[cur]++;
}

void find(string &s){
    int cur = 0;
    for(auto c : s){
        int path = c-'a';
        if(tree[cur][path]==0){
            cout<<"WRONG"<<endl;
            return;
        }
        cur = tree[cur][path];
    }
    if(e[cur]==0){
        cout<<"WRONG"<<endl;
        return;
    }
    if(!st[cur]&&e[cur]>0){
        cout<<"OK"<<endl;
        st[cur] = true;
    }
    else cout<<"REPEAT"<<endl;
}
int main(){
    int n;
    cin>>n;
    string s;
    while(n--){
        
        cin>>s;
        insert(s);
    }
    int m;
    cin>>m;
    while(m--){
        cin>>s;
        find(s);
    }
}