/*  
    题目：木块问题
    链接：https://www.luogu.com.cn/problem/UVA101
    思路：理性模拟，注意细节
    错误及注意事项：
        1.索引越界。忽略了移动a后a前一个元素的ne值要改为-1，这个前提还要判断pre[a]是不是-1（即是不是最底下的木块）
        2.非法情况check的判断不完整。只检查了a是否在b上方，忘了检查b是否在a上，重叠是相互的
        3.赋值和判断符号因为马虎，混淆了
*/
#include<iostream>
#include<vector>
#include<string>
const int N = 30;
int ne[N],pre[N];
using namespace std;
void Back(int a){//把a上清空，放回原位置
    if(ne[a]==-1)return;
    int i=ne[a];
    while(i!=-1){
        int temp = ne[i];
        pre[i] = -1;
        ne[i] = -1;
        i=temp;
    }
    ne[a] = -1;
}
bool Check(int a,int b){//判断是否重堆，如果a和b出现重叠就是非法情况
    bool flag = false;
    int tmpa=a,tmpb=b;
    while(tmpa!=-1){
        if(tmpa == tmpb)flag=true;
        tmpa = ne[tmpa];
    }
    return flag;
}
void Push(int a,int b){//a连接b后
    //找到b最上方的元素temp
    int temp = b;
    while(ne[temp]!=-1)temp = ne[temp];
    //把a及以上放b上
    ne[temp] = a;
    pre[a] = temp;
}
int main(){
    int n;
    cin>>n;
    string op1,op2;
    for(int i=0;i<n;i++){//初始化
        pre[i] = -1;
        ne[i] = -1;
    }
    int a,b;
    while(cin>>op1){
        if(op1=="quit")break;
        cin>>a>>op2>>b;
        if(a==b)continue;
        if(Check(a,b)||Check(b,a))continue;
        if(op1=="move"){
            Back(a);
            if(op2=="onto"){//b上归位，a放b上
                if(pre[a]!=-1)ne[pre[a]] = -1;
                Back(b);
                ne[b] = a;
                pre[a] = b;
            }
            else{//a放b最上
                if(pre[a] != -1) ne[pre[a]] = -1;//忘了重置a前面元素的ne再去push a to b
                Push(a,b);
            }
        }
        else if(op1=="pile"){//a及以上放b上
            if(pre[a]!=-1)ne[pre[a]] = -1;
            if(op2=="onto")Back(b);//b上归位
            Push(a,b);
        }
    }
    for(int i=0;i<n;i++){//输出答案
        cout<<i<<":";
        if(pre[i]==-1){
            int t = i;
            while(t!=-1){
                cout<<" "<<t;
                t = ne[t];
            }
        }
        cout<<endl;
    }

}