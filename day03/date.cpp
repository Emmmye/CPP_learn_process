#include <iostream>
using namespace std;


class Date{
public:
    Date(int year = 1900 ,int month = 1,int day = 1)//构造函数
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
    Date(const Date& d)//拷贝构造函数
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    //运算符重载函数
    //  < 
    bool operator<(const Date& d)//因为类成员函数都有一个隐含的this指针
    {
        if(_year < d._year)
        {
            return true;
        }
        else if(_year == d._year)
        {
            if(_month < d._month)
            {
                return true;
            }
            else if(_month == d._month)
            {
                if(_day < d._day)
                {
                    return true;
                }
            }
        }
        return false;
    }
    //  >
    bool operator>(const Date& d)
    {
        if(_year > d._year)
        {
            return true;
        }
        else if(_year == d._year)
        {
            if(_month > d._month)
            {
                return true;
            }
            else if(_month == d._month)
            {
                if(_day > d._day)
                {
                    return true;
                }
            }
        }
        return false;
    }
    // <=
    bool operator<=(const Date& d)
    {
        if(_year < d._year)
        {
            return true;
        }
        else if(_year == d._year)
        {
            if(_month < d._month)
            {
                return true;
            }
            else if(_month == d._month)
            {
                if(_day < d._day)
                {
                    return true;
                }else if(_day == d._day)
                {
                    return true;
                }
            }
        }
        return false;
    }
    //  >=
    bool operator>=(const Date& d)
    {
        if(_year > d._year)
        {
            return true;
        }
        else if(_year == d._year)
        {
            if(_month > d._month)
            {
                return true;
            }
            else if(_month == d._month)
            {
                if(_day > d._day)
                {
                    return true;
                }else if(_day == d._day)
                {
                    return true;
                }
            }
        }
        return false;
    }
    // ==
    bool operator==(const Date& d)
    {
        if(_year == d._year && _month == d._month && _day == d._day)
            return true;
        return false;
    }
    // !=
    bool operator!=(const Date& d)
    {
        if(_year == d._year && _month == d._month && _day == d._day)
            return false;
        return true;
    }
    //  -(两个日期相减,得到一个天数)
    int operator -(const Date& d2)
    {
        if(*this < d2)
        {
            return 0;
        }
        int sum = 0;
        Date d1(_year,_month,_day);
//        while(d1 != d2)
//        {
//            if(d1._day > d2._day)
//            {
//                sum = sum + d1._day - d2._day;
//                d1._day =  d2._day;
//                continue;
//            }
//            if(d1._month == 1)
//            {
//                d1._day += GetMonthDay(d1._year,12);
//                d1._month = 12;
//                d1._year -= 1;
//            }else
//            {
//                d1._day = d1._day + GetMonthDay(d1._year,d1._month-1);
//                d1._month -= 1;
//            }
//        }
        while(1)
        {
            if(d1._year == d2._year && d1._month == d2._month)
            {
                sum = d1._day - d2._day;
                break;
            }else
            {
                if(d1._month == 1)
                {
                    d1._day += GetMonthDay(d1._year,12);
                    d1._month = 12;
                    d1._year -= 1;
                }else
                {
                    d1._day += GetMonthDay(d1._year,d1._month -1);
                    d1._month -= 1;
                }
            }
        }
        return sum;
    }
    // + (加上一个天数，得到一个新的日期)
    void operator +(const int day)
    {
        if(day == 0)
        {
            return;
        }else if(day < 0)
        {
            *this - (-day);
        }
        _day += day;//先把天数全加到_day上，然后向月份，年份依次进位
        while(1)
        {
            int monthday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            if((_year % 4 == 0 && _year % 100 != 0 )|| _year % 400 == 0)
            {
                monthday[2] += 1;
            }
            if(_month > 0 && _month < 13 && _day > 0 && _day < monthday[_month])
            {
                break;
            }
            if(_month == 12)
            {
                _day -= monthday[12];
                _month = 1;
                _year += 1;
            }else
            {
                _day -= monthday[_month];
                _month += 1;
            }
        }
    }
    // - (减上一个天数，得到一个新的日期)
    void operator -(const int day)
    {
        if(day == 0)
        {
            return;
        }else if(day < 0)
        {
            *this + -day;
        }
        while(_day < day)
        {
            if(_month == 1)
            {
                _day += GetMonthDay(_year,12);
                _month = 12;
                _year -= 1;
            }else
            {
                _day += GetMonthDay(_year,_month-1);
                _month -= 1;
            }
        }
        _day -= day;
        return;
    }
    // = 赋值运算符重载
    void operator=(const Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    void show()
    {
        cout<<_year<<'-'<<_month<<'-'<<_day<<endl;
    }
private:
    int GetMonthDay(int year,int month)
    {
        int monthday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(month == 2 && ((year % 4 == 0 && year % 100 != 0 )|| year % 400 == 0))
        {
            monthday[2] += 1;
        }
        return monthday[month];
    }
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date _p1(2019,7,4);
    _p1.show();
    Date _p2(2018,7,4);
    _p2.show();
     _p1 = _p2;
    _p1.show();
    return 0;
}
