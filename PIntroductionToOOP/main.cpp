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
		this->x  = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	/*Point()
	{
		x = y = double();
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1argConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
//#define STRUCT_POINT
#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	cout << "Hello OOP" << endl;
	Point A;	//объявление переменной 'А' типа Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y;
#endif
#ifdef DISTANCE_CHECK

	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(7);
	B.set_y(8);


	cout << "Расстояние от точки 'А' до точки 'В': " << A.distance(B) << endl;
	cout << "Расстояние от точки 'В' до точки 'А': " << B.distance(A) << endl;
	cout << "Расстояние от точки 'А' до точки 'В': " << distance(A, B) << endl;
	cout << "Расстояние от точки 'B' до точки 'A':	 " << distance(B, A) << endl;
#endif
#ifdef CONSTRUCTORS_CHECK
	Point A;		//Конструктор по умолчанию
	A.print();

	Point B = 5;	//Конструктор с одинм параметром
	B.print();

	Point C(8);		//Конструктор с одинм параметром
	C.print();

	Point D(5, 8);	//Конструктор
	D.print();

	Point E = D;
	E.print();
#endif

}