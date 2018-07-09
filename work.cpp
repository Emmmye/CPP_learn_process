#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
// int Test1()
// {
//     char proi[5][20] = {"网络","计算机","物联网","电信","自动化"};
//     int i = 0;
//     int count = 0;
//     for(; i < 5 ; ++i)
//     {
//         int j = 0;
//         for(; j < 5; ++j)
//         {
//             int n = 0;
//             for(; n < 5 ; n++)
//             {
//                 if(i != j && i != n && n != j)
//                     printf("%d:%s,%s,%s\n",++count,proi[i],proi[j],proi[n]);
//             }
//         }
//     }
//     return 0;
// }
// 
// void Test2(int n , int k)
// {
//     int i = 0;
//     int arr[n];
//     for(; i < n ; ++i)
//     {
//         arr[i] = i+1;
//     }
//     int _k = 1;
//     for(; _k <= k; ++_k)
//     {
//         for(i = 0 ; i < n ; ++i)
//         {
//             if((i + 1) % _k == 0)
//             {
//                 if(arr[i] == i + 1)
//                 {
//                     arr[i]++;
//                 }else if(arr[i] == i + 2)
//                 {
//                     arr[i]--;
//                 }
//             }
//         }
//     }
//     for(i = 0 ; i < n ; ++i)
//     {
//         if(arr[i] == i + 2){
//             printf("%d ",i+1);
//         }
//     }
//     printf("\n");
// }
// 
// void Test3(int animals, int legs, int wings)
// {
//     int max_zhizhu = legs/8, max_chan = legs/6,max_qingting = wings/2;
//     int i = 0;
//     for(; i < max_zhizhu; ++i)
//     {
//         int j = 0;
//         for(; j < max_qingting; ++j)
//         {
//             int n = 0;
//             for(; n < max_chan; ++n)
//             {
//                 if((i + j + n) == animals)
//                 {
//                     if(n*6 + j*6 + i*8 == legs && n + j*2 == wings)
//                     {
//                         printf("%d %d %d\n",i,j,n);
//                         return;
//                     }
//                 }
//             }
//         }
//     }
//     printf("Input error\n");
//     return;
// }
int IsPalin(string & ans)
{
    return ans == string(ans.rbegin(),ans.rend());
}

string Test4(int number)
{
    int step = 2;
    string ret;
    string::iterator it;
    for(; step <= 16; step++)
    {   
        int i = number%step;
        int j = number/step;
        string ans;
        while(j != 0)
        {
            if(i >= 10)
                ans += ('A'+(i-10));
            else
                ans.append(to_string(i));
            i = j%step;
            j = j/step;
        }
            ans.append(to_string(i));
            reverse(ans.begin(),ans.end());
            int _ret = IsPalin(ans);
            if(_ret){
                ret.append(to_string(step));
                ret.append(" ");
            }
            for(it=ans.begin();it!=ans.end();it++)
                cout<<*it;
            cout<<endl;
    }
    return ret;
}
int main()
{
//    Test1();
//     int n , k;
//     scanf("%d%d",&n,&k);
//     Test2(n,k);
//     int i,j,n;
//     scanf("%d%d%d",&i,&j,&n);
//     Test3(i,j,n);
    string cur = Test4(17);
    cout<<cur<<endl;
    return 0;
}
