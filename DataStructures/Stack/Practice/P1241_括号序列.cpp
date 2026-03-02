/* 
题目：括号序列
https://www.luogu.com.cn/problem/P1241
思路：利用栈容器，存左括号下标，而不是存这个符号，因为用flag标记时会不准确而出错
遍历序列，右括号进入判断，判断和栈顶是否匹配，然后用flag标记出没有匹配的括号，最后
输出时根据flag标记，把无配对的括号补全
 */
#include<iostream>
#include<stack>
#include<string>
using namespace std;
const int N =1e2+10;
bool flag[N];//标记是否存在与之匹配的括号
string s;
stack<int>st;//存下标

bool check(char c){//检查是否和栈顶所存的下标对应的括号相匹配
    if((c==')'&&s[st.top()]=='(')||(c==']'&&s[st.top()]=='['))return true;
    return false;
}

int main(){
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='[')st.push(i);//存左括号下标
        else{
            if(!st.empty()&&check(s[i])){//右括号进判断，判断和栈顶对应左括号是否匹配
                flag[i] = true;
                flag[st.top()] = true;
                st.pop();
            }
        }
    }
    for(int i=0;i<s.length();i++){
        if(!flag[i]){
            if(s[i]=='('||s[i]==')')cout<<"()";
            else cout<<"[]";
        }
        else cout<<s[i];
    }
}