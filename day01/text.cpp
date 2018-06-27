//命名空间

// #include<iostream>
// 
// namespace my{
//     namespace your{
//     int i = 1;
//     }
// }
// 
// 
// int main()
// {
//     std::cout<<my::your::i<<std::endl;
//     return 0;
// }

//函数重载
//#include <iostream>
//using namespace std;
//
//void FF(int i)
//{
//    cout<<i<<endl;
//}
//void FF(char c)
//{
//    cout<<c<<endl;
//}
//
//int main()
//{
//    FF('c');
//    return 0;
//}

//引用
// #include<iostream>
// using namespace std;
// int & FF( int i)
// {
//     cout<<i<<endl;
//     i++;
//     static int c = i;
//     return c;
// }
// 
// int main()
// {
//     int i = 1;
//     int &a = FF(i);
//     cout<<a<<endl;
//     return 0;
// }

//缺省参数
#include<iostream>
using namespace std;

void FF(int i ,int j = 1)
{
    cout<<i+j<<endl;
}

int main()
{
    FF(2);
    return 0;
}
