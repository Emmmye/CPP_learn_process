#include "Vector.h"
#include <iostream>
using namespace std;
int main()
{
    Vector v1;
    v1.PushBack(1);
    v1.PushBack(2);
    v1.PushBack(3);
    v1.PushBack(4);
    Vector v2;
    v2 = v1;
    size_t i = 0;
    for(; i < v2.Size();++i)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl;
    //Vector v2(v1);
    return 0;
}
