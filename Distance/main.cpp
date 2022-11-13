#include<iostream>

using namespace std;

class Point
{
	double y, y1, y2;
	double x, x1, x2;
	double dist;
public:
	double get_x() const
	{
		return x;
	}
	double get_x1() const
	{
		return x1;
	}
	double get_x2() const
	{
		return x2;
	}
	double get_y() const
	{
		return y;
	}
	double get_y1() const
	{
		return y1;
	}
	double get_y2() const
	{
		return y2;
	}
	double get_dist() const
	{
		return dist;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_x1(double x1)
	{
		this->x1 = x1;
	}
	void set_x2(double x2)
	{
		this->x2 = x2;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	void set_y1(double y1)
	{
		this->y1 = y1;
	}
	void set_y2(double y2)
	{
		this->y2 = y2;
	}
	void set_dist(double dist)
	{
		this->dist = dist;
	}
};

double Distance(Point A, double x, double y);
double Distance(Point A, double x1, double y1, double x2, double y2);
void main()
{
	setlocale(LC_ALL, "");
	Point A;
	double x, y;
	double x1, x2, y1, y2;
	A.set_x(1);
	A.set_x1(2);
	A.set_x2(3);
	A.set_y(4);
	A.set_y1(5);
	A.set_y2(6);
	
	y = A.get_y();
	y1 = A.get_y1();
	y2 = A.get_y2();
	x = A.get_x();
	x1 = A.get_x1();
	x2 = A.get_x2();

	Distance(A, x, y);
	Distance(A, x1, y1, x2, y2);

}
double Distance(Point A, double x, double y)
{
	A.set_dist(sqrt(x*x+y*y));
	return A.get_dist();
}
double Distance(Point A, double x1, double y1, double x2, double y2)
{
	A.set_dist(sqrt(x1 * x2 - 2 * x1 * x2 + x2 * x2 + y1 * y1 - 2 * y1 * y2 + y2 * y2));
	return A.get_dist();
}