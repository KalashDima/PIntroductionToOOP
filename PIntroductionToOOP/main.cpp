#include<iostream>

using namespace std;

class Point
{
	double y;
	double x;
	double dist;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	double get_dist() const
	{
		return dist;
	}
	void set_x(double x)
	{
		this->x  = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	void set_x(double dist)
	{
		this->dist = dist;
	}
};
//#define STRUCT_POINT
void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl;
#ifdef STRUCT_POINT

	Point A;	//объявление переменной 'А' типа Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y;
#endif

	Point A;
	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << "\t" << A.get_y();
}