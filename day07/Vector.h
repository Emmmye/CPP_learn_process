#pragma once
#include <iostream>
#include <string.h>
typedef int VectType;

class Vector{
public:
    Vector()
    :_start(NULL)
    ,_finish(NULL)
    ,_endCapacity(NULL)
    {}
    void Swap(Vector v)
    {
        std::swap(_start,v._start);
        std::swap(_finish,v._finish);
        std::swap(_endCapacity,v._endCapacity);
        std::cout<<1111<<std::endl;
    }
    Vector(const Vector& v)
    {
        size_t size = v.Size();
        size_t capacity = v.Capacity();
        _start = new VectType[sizeof(VectType)*capacity];
        memcpy(_start,v._start,size*sizeof(VectType));
        _finish = _start + size;
        _endCapacity = _start + capacity;
    }
    Vector& operator=(const Vector& v)
    {
        Swap(v);
        std::cout<<"swap success"<<std::endl;
        return *this;
    }
    ~Vector()
    {
        if(_start)
        {
            delete[] _start;
        }
        _start = _finish = _endCapacity = NULL;
    }
    void PushBack(VectType cur)
    {
        size_t size = Size();
        size_t capacity = Capacity();
        if(size >= capacity)
        {
            int n = 0;
            if(capacity == 0)
                n = 3;
            Expand(2 * capacity + n);
        }
        *_finish = cur;
        _finish++;
    }
    size_t Size() const{
        return _finish - _start;
    }
    size_t Capacity() const{
        return _endCapacity - _start;
    }
    VectType operator[](size_t index)
    {
        if(index >= Size())
        {
            return npos;
        }
        return _start[index];
    }
private:
    void Expand(size_t n)
    {
        if(n > Capacity())
        {
            size_t size = Size();
            VectType* _new = new VectType[sizeof(VectType) * n];
            memcpy(_new,_start,size*sizeof(VectType));
            delete[] _start;
            _start = _new;
            _finish = _start + size;
            _endCapacity = _start + n;
        }
    }
private:
    VectType *_start;
    VectType *_finish;
    VectType *_endCapacity;
    VectType npos = -1;
};
