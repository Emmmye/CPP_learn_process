#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<string> ret;
    void generateP(string sub,int l,int r)
    {
        string look = sub;
        if(l>r)
            return ;
        if(l>0)
            generateP(sub+"(",l-1,r);
        if(r>0)
            generateP(sub+")",l,r-1);
        if(l==0 && r==0)
        {
            ret.push_back(sub);
            return ;

        }
    }
    vector<string> generateParenthesis(int n) {
              generateP("",n,n);
              return ret;
    }
};

int main()
{
    string s;
    Solution so;
    so.generateParenthesis(4);
    s = accumulate(so.ret.begin(),so.ret.end(),s);
    cout<<s<<endl;
}
