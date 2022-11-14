#include <iostream>
using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector(){}
	Vector(float x, float y, float z) :x{ x },y{y},z{z}{}

	Vector operator+(Vector v)
	{
		return Vector{ x + v.x,y + v.y,z + v.z };
	}
	Vector operator-(Vector v)
	{
		return Vector{ x - v.x,y - v.y,z - v.z };//이항연산자 -
	}
	Vector operator+()//단항 연산자+
	{
		return Vector{ +x,+y,+z };
	}
	Vector operator-()
	{
		return Vector{ -x,-y,-z };
	}
	float operator*(const Vector& v)const
	{
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}
	Vector operator*(float n)const
	{
		return Vector{ x * n,y * n,z * n };
	}
	Vector operator/(float n)const//이항연산자/
	{
		return Vector{ x / n,y / n,z / n };
	}
	Vector& operator++()
	{
		++x;
		++y;
		++z;
		return *this;
	}
	Vector& operator++(int)
	{
		Vector temp= *this;
		++x;
		++y;
		++z;
		return  temp;
	}
	void print()
	{
		cout << x << " " << y << " " << z << endl;
	}
};
int main()
{
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	Vector v2 = v0 + v1;//이항연산자+
	v2.print();//1 3 5

	Vector v3 = -v1;//단항연산자-
	v3.print();

	float v4 = v0 * v1;//이항연산자*
	cout << v4 << endl;

	Vector v5 = v1 * 3.0f;
	v5.print();

	Vector v6 = ++v1;
	v6.print();
	Vector v7 = v1++;
	v7.print();
	v1.print();
}