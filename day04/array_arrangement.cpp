#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int> > ret;
    void _permute(vector<int>& num, int index)
    {
        int n = num.size();
        if(index >= n){
            ret.push_back(num);
            return;

        }
        for(int i = index; i < n; ++i){
            swap(num[i], num[index]);
            _permute(num,index+1);
            swap(num[index], num[i]);
        }
    }

    vector<vector<int> > permute(vector<int>& num)
    {
        _permute(num,0);
        return ret;
    }
};


int main()
{
    vector<vector<int> > ret;
    Solution so;
    vector<int> num;
    int i = 1;
    for(; i <= 3 ; ++i)
    {
        num.push_back(i);
    }
    ret = so.permute(num);
    for(i = 0; i < ret.size(); ++i)
    {
        int j = 0;
        for(; j < ret[0].size(); ++j)
        {
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
//    for(i = 0; i < ret.size(); ++i)
//    {
//        cout<<ret[i]<<endl;
//    }
}
