#include <iostream>
#include <cstring>
using namespace std;

class Vector
{
private:
	float x, y, z;
	char* _chars;
public:
	Vector() {}
	Vector(float x,float y,float z ,const char*chars)
		:x{x},y{y},z{z},_chars{new char[strlen(chars)+1]}
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}
	Vector(Vector& v)
		:Vector(v.x,v.y,v.z,v._chars)
	{
		strcpy_s(_chars, strlen(v._chars) + 1,v._chars);
		cout << "copy" << endl;
	}
	~Vector()
	{
		delete[]_chars;
	}

	Vector &operator=(Vector& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		delete[]_chars;
		_chars = new char[strlen(v._chars)+1];
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
		return *this;
	}
	friend ostream& operator<<(ostream& os, Vector& v)
	{
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}
	/*friend ostream& operator<<(ostream& os, Vector& v)
	{
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}
	friend istream& operator>>(istream& is, Vector& v)
	{
		is >> v.x >> v.y >> v.z;
		return is;
	}*/
	/*float& operator[](int index)
	{
		if (index < 1)
			return x;
		if (index == 1)
			return y;
		return z;
	}*/

/*	const float operator[](int index)const
	{
		if (index < 1)
			return x;
		if (index == 1)
			return y;
		return z;
	}*/
	
};
/*class String
{
private:
	char* _chars;
public:
	String() {}
	String(const char* chars) :_chars{ new char[strlen(chars) + 1] }
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}
	char& operator[](int index)
	{
		return _chars[index];
	}
};*/


int main()
{
	/*Vector v0{1,2,3};
	cout << v0<<endl;

	Vector v1;
	cin >> v1;
	cout << v1 << endl;*/
	/*Vector v0{1,2,3};
	cout << v0[-1] << endl;
	cout << v0[0] << endl;
	cout << v0[1] << endl;
	cout << v0[2] << endl;

	v0[0] = 100;
	cout << v0[0] << endl;*/

	/*String str{"abc"};
	cout << str[0] << endl;
	cout << str[1] << endl;
	cout << str[2] << endl;
	str[2] = 'd';
	cout << str[2] << endl;*/
	/*int a = 1;
	int b = a;
	int c;
	c = a;*/

	Vector v0{ 1,2,3,"abc"};
	Vector v1 = v0;
	Vector v2;
	v2 = v0;
	cout << v0 << endl;
	cout << v1 << endl;
	cout << v2 << endl;
}