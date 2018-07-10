#include "myString.h"
void Test()
{
    MyString s1("hello");
    MyString s2(s1);
    MyString s3 = s2;
    s3.PushBack('a');
    s3.PushBack('b');
    s3.Append("hello");
    s3 += "hellp";
    s3.Erase(0,5);
    s3.PopBack();
    s3.Insert(0,"hellooooo");
    s3 = s1 + s2;
    std::cout<<s1.c_str()<<std::endl;
    std::cout<<s2.c_str()<<std::endl;
    std::cout<<s3.c_str()<<std::endl;
}

int main()
{
    Test();
    return 0;
}
