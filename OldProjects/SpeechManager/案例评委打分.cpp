#include<iostream>
using namespace std;
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<stdlib.h>
#include<time.h>
class Person{
public:
    Person(string n,int s){
        this->name = n;
        this->score = s;
    }
    string name;
    int score;
};
int main(){
    int sum;
    srand((unsigned int) time(NULL));
    Person a("张三",0);
    Person b("李四",0);
    vector<Person> v;
    deque<int> d1;
    deque<int> d2;
    v.push_back(a);
    v.push_back(b);
    for(int a=0;a<=9;a++){
        int judge= rand()%10+1;
        d1.push_back(judge);
    }
    for(int a=0;a<=9;a++){
        int judge= rand()%10;
        d2.push_back(judge);
    }
    sort(d1.begin(),d1.end());
    d1.pop_front();
    d1.pop_back();
    for(deque<int>::iterator k=d1.begin();k!=d1.end();k++){
        sum+=*k;
        cout<<*k<<" ";
    }
    cout<<"平均分为："<<sum/8.0<<endl;


}