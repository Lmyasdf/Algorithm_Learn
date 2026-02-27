#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>
#include<algorithm>
class Person{
public:
    Person(string name,int score){
        this->name  = name;
        this->score  = score;
    }
    string name;
    int score;
};
void set_P(vector<Person>&v,map<int,Person>&m){
    string s = "ABCDEFGHIJKL";
    for(int i=0;i<12;i++){
        Person p("选手",0);
        p.name += s[i];
        v.push_back(p);
    }
    int i = 1;
    for(vector<Person>::iterator it = v.begin();it!=v.end();it++,i++){
        m.insert(pair<int,Person>(10000+i,*it));
    }
}

void menu(){
    cout<<"1.开始演讲比赛"<<endl<<"2.查看往届记录"<<endl<<"3.清空比赛记录"<<endl<<"0.退出比赛程序";
    cout<<endl<<endl<<"请输入您的选择：";
}

void action(int k,int n,const map<int,Person>&m){
    cout<<"第<<"<<k<<">>"<<"轮比赛选手正在抽签"<<endl;
    cout<<"-----------------------"<<endl<<"抽签后顺序如下："<<endl;
    random_shuffle(m.begin(),m.end());
}
int main(){
    map<int,Person>m;
    vector<Person>v;
    set_P(v,m);
    int i,k,n=12;
    cin>>i;
    while(1){
        menu();
        switch(i){
            case 1:
            action(k,n,m);
            k++;
        }
    }
}