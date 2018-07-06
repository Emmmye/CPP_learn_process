#include <iostream>
#include <string>
#include <map>
using namespace std;
void count_str(string str)
{
    map<char, int> s;
    string ret;
    size_t i = 0;
    for(i = 0; i < str.size(); ++i)
    {
        if(s.find(str[i]) != s.end())
            s[str[i]]++;
        else
            s.insert(make_pair(str[i],1));
    }
    map<char,int>::iterator it = s.begin();
    for(i = 0; i < s.size(); ++i)
    {
        cout<<it->first<<it->second;
        ret.push_back(it->first);
        ret.push_back(it->second);
        ++it;
    }
    cout << endl;
}

int main()
{
    string s;
    cin >> s;
    count_str(s);
    return 0;
}
