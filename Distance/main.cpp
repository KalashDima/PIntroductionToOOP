#include<iostream>

using namespace std;

class Point
{
	double y;
	double x;

public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}

	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
};

double Distance(Point A, Point B);

void main()
{
	setlocale(LC_ALL, "");
	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(7);
	B.set_y(8);

	cout << "Расстояние от 'А' до 'В': " << A.distance(B) << endl;
	cout << "Расстояние от точки 'А' до точки 'В': " << distance(A, B) << endl;
}
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}