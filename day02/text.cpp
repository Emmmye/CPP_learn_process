#include <iostream>
using namespace std;


class Date{
private:
    int GetMonthDay(int year,int month)
    {
        int monthday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(month == 2 && (year % 4 == 0 || year % 100 == 0 || year % 400 == 0))
        {
            monthday[2] += 1;
        }
        return monthday[month];
    }
public:
    void GetDate(int year,int month,int day)
    {
        if(year < 1900 || month < 1 || month > 12 )
        {
            return;
        }
        _year = year;
        _month = month;
        if(day < 0 || day > GetMonthDay(year,month))
        {
            cout<<"日期错误"<<endl;
        }
        else
        {
            cout<<"日期正确"<<endl;
        }
        _day = day;
    }
    void show()
    {
        cout<<_year<<'-'<<_month<<'-'<<_day<<endl;
    }
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date _p1;
    _p1.GetDate(2018,6,31);
    _p1.show();
    Date _p2;
    _p2.GetDate(1997,9,17);
    _p2.show();
    return 0;
}
