/* 2026蓝桥杯省B_LQ聚合
https://www.luogu.com.cn/record/276920288
核心：通过遍历每个Q与前面已知L数目聚合来更新结果，即mret+=l;
思路：遍历字符串，遇到每个？时分析改L还是Q，找最优ret
    记录：已经遍历的L数目l、还没遍历的？数目sumr、还没遍历的Q数目sumq
    这样就可以每走一步就更新一下结果：
    1.当遍历L时 只需要把l++
    2.当遍历Q时 mret+=前面已知的l即可
    3.当遍历?时 \
        比较: 当改L时，假设后面问号全是Q（贪心），加上后面未遍历的Q，与此L聚合数目
            和当改Q时，Q与前面已知的所有L聚合数
        进而得到最优解
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
long long mret,l;
long long sumq,sumr;
int main(){
    int n;
    vector<char>v;
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        v.push_back(c);
        if(c=='Q')sumq++;
        else sumr++;
    }
    for(int i=0;i<n;i++){
        if(v[i]=='L'){//当遍历L
            l++;
        }
        else if(v[i]=='Q'){//当遍历Q
            mret += l;
            sumq--;
        }
        else{//当遍历？
            sumr--;
            if(sumq+sumr>l){//比较后面？+ Q多还是前面L多，可以得出当前？改成什么
                l++;
                
            }
            else{
                mret += l;
            }
        }
    }
    cout<<mret<<endl;
}