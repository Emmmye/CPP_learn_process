#pragma once

// 1.传统写法  踏实
// 2.现代写法  剥削

//class String
//{
//public:
//	String(const char* str)
//		:_str(new char[strlen(str)+1])
//	{
//		strcpy(_str, str);
//	}
//
//	// s2(s1)
//	String(const String& s)
//		:_str(new char[strlen(s._str)+1])
//	{
//		strcpy(this->_str, s._str);
//	}
//
//	// s1 = s3 -> s1.operator=(&s1, s3)
//	String& operator=(const String& s)
//	{
//		if (&s != this)
//		{
//			char* tmp = new char[strlen(s._str)+1];
//			strcpy(tmp, s._str);
//			delete[] _str;
//
//			_str = tmp;
//		}
//
//		return *this;
//	}
//
//	~String()
//	{
//		delete[] _str;
//		_str = NULL;
//	}
//
//	char* c_str()
//	{
//		return _str;
//	}
//
//private:
//	char* _str;
//};
//
//void TestString()
//{
//	String s1("hello");
//	char* str1 = "hello";
//	cout<<sizeof(s1)<<endl;
//	cout<<sizeof(str1)<<endl;
//	
//	String s2(s1);
//
//	cout<<s1.c_str()<<endl;
//	cout<<s2.c_str()<<endl;
//	
//	String s3("world!!!!!!!!!!!!!!!!!!!!!");
//
//	s1 = s3;
//	s1 = s1;
//	cout<<s1.c_str()<<endl;
//	cout<<s3.c_str()<<endl;
//}

//class String
//{
//public:
//	String(const char* str)
//		:_str(new char[strlen(str)+1])
//	{
//		strcpy(_str, str);
//	}
//
//	// s2(s1)
//	String(const String& s)
//		:_str(NULL)
//	{
//		String tmp(s._str);
//		swap(_str, tmp._str);
//	}
//
//	// s1 = s3
//	//String& operator=(const String& s)
//	//{
//	//	if (this != &s)
//	//	{
//	//		String tmp(s._str);
//	//		swap(this->_str, tmp._str);
//	//	}
//
//	//	return *this;
//	//}
//
//	// s1 = s3
//	String& operator=(String s)
//	{	
//		swap(this->_str, s._str);
//
//		return *this;
//	}
//
//	
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = NULL;
//		}
//	}
//
//	char* c_str()
//	{
//		return _str;
//	}
//
//private:
//	char* _str;
//};
//
//void TestString()
//{
//	String s1("hello");
//	String s2(s1);
//
//	cout<<s1.c_str()<<endl;
//	cout<<s2.c_str()<<endl;
//
//	String s3("world!!!!!!!!!!!!!!!!!!!!!");
//
//	s1 = s3;
//	//s1 = s1;
//	cout<<s1.c_str()<<endl;
//	cout<<s3.c_str()<<endl;
//}

class String
{
public:
	String(const char* str = "")
		:_size(strlen(str))
		,_capacity(_size)
	{
		_str = new char[_size+1];

		strcpy(_str, str);
	}

	// s1.Swap(s2)
	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	// s2(s1)
	String(const String& s)
		:_str(NULL)
	{
		String tmp(s._str);
		this->Swap(tmp);
	}

	// s1 = s3
	String& operator=(String s)
	{	
		//swap(this->_str, s._str);
		this->Swap(s);

		//s.Swap(*this);

		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}

	void Reserve(size_t n)
	{
		Expand(n);
	}

	void Resize(size_t n);

	void Expand(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n+1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;

			_capacity = n;
		}
	}

	void PushBack(char ch)
	{
		/*if (_size == _capacity)
		{
			Expand(_capacity*2);
		}

		_str[_size] = ch;
		_str[_size+1] = '\0';
		++_size;*/
		Insert(_size, ch);
	}

	void Append(const char* str)
	{
		size_t len = strlen(str);
		if (_size+len > _capacity)
		{
			/*size_t newcapacity = _capacity*2;
			while (newcapacity < _size+len)
			{
				newcapacity *= 2;
			}*/

			Expand(_size+len);
		}

		strcpy(_str+_size, str);
		_size += len;

		//Insert(_size, str);
	}

	void Insert(size_t pos, char ch)
	{
		assert(pos <= _size);

		if (_capacity == _size)
		{
			Expand(_capacity*2);
		}

		int end = _size;
		while (end >= (int)pos)
		{
			_str[end+1] = _str[end];
			--end;
		}

		_str[pos] = ch;
		++_size;
	}

	void Insert(size_t pos, const char* str);


	// s1 += "world";
	String& operator+=(const char* str)
	{
		this->Append(str);
		return *this;
	}

	// s1 += s2
	String operator+=(const String& s)
	{
		//this->Append(s._str);
		*this += s._str; // this->operator+=(this, s._str);

		return *this;
	}

	// s1 + "hello"
	String operator+(const char* str)
	{
		String ret(*this);
		ret.Append(str);
		return ret;
	}

	//String s = s1 + "hello";
	//String s;
	//s = s1 + "hello";

	// s1 + s2
	String operator+(const String s)
	{
		return *this + s._str;
	}

	void PopBack();
	void Erase(size_t pos, size_t len);

	size_t Size()
	{
		return _size;
	}

	size_t Capacity()
	{
		return _capacity;
	}

	bool Empty()
	{
		return _size == 0;
	}

	char& operator[](size_t pos)
	{
		return _str[pos];
	}

	size_t Find(char ch);
	size_t Find(const char* sub);

	bool operator<(const String& s);
	bool operator<=(const String& s);
	bool operator>(const String& s);
	bool operator>=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);

	char* c_str()
	{
		return _str;
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

void TestString1()
{
	//String s1("hello");
	//String s2(s1);
	//String s3("xxxxxxxxxxxxxxxx");

	////swap(s1, s3);
	////s1.Swap(s3);

	//cout<<s1.c_str()<<endl;
	//cout<<s3.c_str()<<endl;

	/*String s1("hello");
	cout<<s1[0]<<endl;
	s1[0] = 'x';

	cout<<s1.c_str()<<endl;

	for (size_t i = 0; i < s1.Size(); ++i)
	{
		cout<<s1[i]<<" ";
	}
	cout<<endl;*/

	String s1("hello");
	/*s1.PushBack(' ');
	s1.Append("world");
	
	s1.Insert(5, ' ');
	s1.Insert(0, '!');*/

	s1 += " world";

	cout<<s1.c_str()<<endl;

	String s3("!!!!!!");
	s1 += s3;
	cout<<s1.c_str()<<endl;
}

void TestString2()
{
	char buffer[128];
	size_t n = 1000000;
	String s1;
	s1.Reserve();
	for (size_t i = 0; i < n; ++i)
	{
		itoa(i, buffer, 10);
		s1 += buffer;
	}

	//cout<<s1.c_str()<<endl;
}
