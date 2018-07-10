#pragma once
#include <iostream>
#include <string.h>
#include <assert.h>
class MyString{
public:
    MyString(const char* str = "")
        :_size(strlen(str))
        ,_capacity(_size)
    {
        _str = new char[strlen(str) + 1];
        strcpy(_str,str);
    }
    void Swap(MyString& s)
    {
        std::swap(_str,s._str);
        std::swap(_size,s._size);
        std::swap(_capacity,s._capacity);
    }
    MyString(const MyString& s)
        :_str(NULL)
    {
        MyString tmp(s._str);
        Swap(tmp);
    }
    MyString& operator=(const MyString& s)
    {
        MyString tmp(s._str);
        Swap(tmp);
        return *this;
    }

    void Reserve(size_t n)
    {
        Expand(n);
    }
    void Resize(size_t n )
    {
        Expand(n);
        _size = _capacity;
    }

    //增
    MyString& Insert(size_t pos, const char ch)
    {
        assert(pos <= _size);
        if(_size >= _capacity)
        {
            Expand(_capacity*2);
        }
        int end = _size;
        while(end >= (int)pos)
        {
            _str[end+1] = _str[end];
            --end;
        }
        _str[pos] = ch;
        ++_size;
        return *this;
    }
    MyString& Insert(size_t pos, const char* str)
    {
        int len = strlen(str);
        if(_size >= _capacity)
        {
            Expand(_size+len);
        }
        int end = _size;
        while(end >= (int)pos)
        {
            _str[end+len] = _str[end];
            end--;
        }
        memcpy(&_str[pos],str,len);
        _size += len;
        return *this;
    }
    MyString& PushBack(const char ch)
    {
        return Insert(_size,ch);
    }
    MyString& Append(const char* str)
    {
        return Insert(_size,str);
    }
    MyString& operator+=(const char* str)
    {
        return Insert(_size,str);
    }
    MyString& operator+=(const MyString& s)
    {
        return Insert(_size,s._str);
    }
    MyString operator+(const char* str)
    {
        MyString s(_str);
        s += str;
        return s;
    }
    MyString operator+(const MyString& s)
    {
        MyString s1(_str);
        s1 += s;
        return s1;
    }
    //删
    MyString& PopBack()
    {
        if(_size > 0)
        {
            _str[_size-1] = _str[_size]; 
            --_size;
        }
        return *this;
    }
    MyString& Erase(size_t pos, size_t len)
    {
        assert(pos + len <= _size);
        int end = pos+len;
        while(end <= (int)_size)
        {
            _str[pos++] = _str[end++];
        }
        _size -= len;
        
        return *this;
    }
    
    //查
    char& operator[](size_t pos)
    {
        assert(pos <= _size);
        return _str[pos];
    }
    bool Empty()
    {
        return _size == 0;
    }
    size_t Size()
    {
        return _size;
    }
    size_t Capacity()
    {
        return _capacity;
    }
    size_t Find(const char ch)
    {
        size_t i = 0;
        for(; i < _size; ++i)
        {
            if(_str[i] == ch)
                return i;
        }
        return i; 
    }
    size_t Find(const char* str)
    {
        size_t i = 0;
        for(; i < _size; ++i)
        {
            size_t j = 0;
            size_t n = i;
            while(_str[n] == str[j] && n < _size && j < strlen(str))
            {
               n++,j++; 
            }
            if(j == strlen(str))
                return i;
        }
        return i;
    }

    //改
    bool operator>(const MyString& b)
    {
        int count = 0;
        size_t i = 0;
        while(_str[i] != '\0' && b._str[i] != '\0')
        {
            count += _str[i] - b._str[i];
            i++;
        }
        return count > 0;
    }
    bool operator>=(const MyString& b)
    {
        return *this > b || *this == b;
    }
    bool operator<(const MyString& b)
    {
        return !(*this >= b);
    }
    bool operator<=(const MyString& b)
    {
        return !(*this > b);
    }
    bool operator==(const MyString& b)
    {
        size_t i = 0;
        while(_str[i] != '\0' && b._str[i] != '\0')
        {
            if(_str[i] == b._str[i])
                i++;
            else 
                return false;
        }
        return i == _size && i == b._size;
    }
    bool operator!=(const MyString& b)
    {
        return !(*this == b);
    }
    char* c_str()
    {
        return _str;
    }
    //析构函数
    ~MyString()
    {
        if(_str){
            delete[] _str;
            _str = NULL;
        }
    }
private:
    void Expand(size_t n)
    {
        if(n > _capacity){
            char* tmp = new char[n+1];
            strcpy(tmp,_str);
            std::swap(tmp,_str);
            delete[] tmp;;
            _capacity = n;
        }
    }
private:
    char* _str;
    size_t _size;
    size_t _capacity;
};

