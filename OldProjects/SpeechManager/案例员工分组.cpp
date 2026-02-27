#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
using namespace std;

class Person{
public:
    void create(string n,int w){
        this->name = n;
        this->wage = w;
    }
    string name;
    int wage;
};
void createworker(vector<Person>&v){
    string s = "ABCDE";
    for(int i=0;i<5;i++){
        Person p;
        p.name = "Ô±¹¤";
        p.name+=s[i];
        p.wage = rand()%10000+10000;
        v.push_back(p);
        // vector<Person>::iterator it = v.begin()+i;
        // cout<<(*it).name;
    }
}
void fenzu(vector<Person>&v,multimap<int,Person>& m){
    int n;
    vector<Person>::iterator it = v.begin();
    for(vector<Person>::iterator it = v.begin();it!=v.end();it++){
        n = rand()%3;
        m.insert(pair<int,Person>(n,*it));
    } 
}

void Print(multimap<int,Person>& m){

    int count = m.count(0);
    int n = 0;
    for(multimap<int,Person>::iterator f = m.find(0);n<count;f++,n++){
        cout<<(*f).second.name<<" "<<(*f).second.wage<<" 0"<<endl;
    }
    count = m.count(1);
    n = 0;
    for(multimap<int,Person>::iterator f = m.find(1);n<count;f++,n++){
        cout<<(*f).second.name<<" "<<(*f).second.wage<<" 1"<<endl;
    }
    count = m.count(2);
    n = 0;
    for(multimap<int,Person>::iterator f = m.find(2);n<count;f++,n++){
        cout<<(*f).second.name<<" "<<(*f).second.wage<<" 2"<<endl;
    }
    
}
int main(){
    srand((unsigned int)time(NULL));
    vector<Person>v;
    createworker(v);
    multimap<int,Person>m;
    fenzu(v,m);
    Print(m);
}