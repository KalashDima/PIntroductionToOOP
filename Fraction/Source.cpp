#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;
using std::cout;
using std::cin;
using std::endl;


class Fraction;
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
ostream& operator<<(ostream& os, const Fraction& obj);
istream& operator>>(istream& is, Fraction& obj);
#define WIDTH 27
#define delimiter "\n------------------------------------------------\n"
class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//				constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;

		cout.width(WIDTH);
		cout << std::left <<"DefaultConstructor:" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "SingleArgumentConstructor:" << this << endl;
	}
	Fraction(double decimal)
	{
		integer = trunc(decimal);
		float n_temp = decimal - trunc(decimal);
		float temp1 = decimal - trunc(decimal);
		int d_n = 0;
		do 
		{
			n_temp *= 10;
			temp1 *= 10;
			int temp = temp1;
			temp1 -= temp;
			d_n++;
		} while (temp1);
		numerator = n_temp;
		denominator = pow(10, d_n);
		reduce();
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;

	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	~Fraction()
	{
		cout.width(WIDTH);
		cout << std::left << "Destructor:" << this << endl;
	}

	//				methods:
	Fraction& to_proper()
	{
		if (numerator > denominator)
		{
			integer += numerator / denominator;
			numerator %= denominator;
		}
		if (integer && numerator < 0)
			numerator *= -1;
		return *this;
	}
	Fraction& to_improper() 
	{
		if (integer)
		{
			numerator += integer * denominator;
			integer = 0;
		}
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		/*int numerator = abs(this->numerator);
		int denominator = abs(this->denominator);
		while (numerator != 0 && denominator != 0) 
		{
			if (numerator > denominator) {
				numerator = numerator - denominator;
			}
			else {
				denominator = denominator - numerator;
			}
		}
		int nod = numerator + denominator;*/
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int nod = more;
		this->denominator /= nod;
		this->numerator /= nod;
		return *this;
	}

	void common_denominator(Fraction B)
	{
		to_proper();
		B.to_proper();
		set_numerator(this->numerator * B.denominator);
		set_denominator(this->denominator);


	}

	//				operators
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout.width(WIDTH);
		cout << std::left << "CopyAssignment:" << this << endl;
		return *this;
	}
	
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	//				Type-cast operator
	explicit operator int()const
	{
		return integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}
	
	/*Fraction operator+(Fraction B)
	{
		Fraction C;
		to_improper();
		B.to_improper();
		C.set_numerator(this->numerator * B.denominator + B.numerator * this->denominator);
		C.set_denominator(this->denominator * B.denominator);
		C.to_proper();
		C.reduce();
		return Fraction(C);
		to_proper();
	}
	Fraction operator-(Fraction B)
	{
		Fraction C;
		to_improper();
		B.to_improper();
		C.set_numerator(this->numerator * B.denominator - B.numerator * this->denominator);
		C.set_denominator(this->denominator * B.denominator);
		to_proper();
		C.to_proper();
		B.to_proper();
		C.reduce();
		if (C.get_integer() < 0)
			C.set_numerator(C.get_numerator() * (-1));
		return Fraction(C);
	}
	Fraction operator*(Fraction B)
	{
		Fraction C;
		to_improper();
		B.to_improper();
		C.set_numerator(this->numerator * B.numerator);
		C.set_denominator(this->denominator * B.denominator);
		C.to_proper();
		C.reduce();
		if (C.get_integer() < 0)
			C.set_numerator(C.get_numerator() * (-1));
		return Fraction(C);
		to_proper();
	}
	Fraction operator/(Fraction B)
	{
		Fraction C;
		to_improper();
		B.to_improper();
		C.set_numerator(this->numerator * B.denominator);
		C.set_denominator(this->denominator * B.numerator);
		C.to_proper();
		C.reduce();
		if (C.get_integer() < 0)
			C.set_numerator(C.get_numerator() * (-1));
		return Fraction(C);
		to_proper();
	}

	Fraction operator++()
	{
		if (integer == 0)
		{
			if (numerator < 0)
				set_numerator(get_integer() + get_numerator());
			else
				set_integer(get_integer() + 1);
		}
		else
		{
			if (integer < 0)
			{
				set_integer(get_integer() + 1);
				if (integer == 0)
					set_numerator(get_numerator() * (-1));
			}
			else
				set_integer(get_integer() + 1);
		}
		return 0;
	}
	Fraction operator++(int a)
	{
		if (integer == 0)
		{
			if (numerator < 0)
				set_numerator(get_integer() + get_numerator());
			else
				set_integer(get_integer() + 1);
		}
		else
		{
			if (integer < 0)
			{
				set_integer(get_integer() + 1);
				if (integer == 0)
					set_numerator(get_numerator() * (-1));
			}
			else
				set_integer(get_integer() + 1);
		}
		return 0;
	}
	Fraction operator--()
	{
		if (integer == 0)
		{
			if (numerator < 0) 
			{
				set_integer(get_integer() + (-1));
				set_numerator(get_numerator() * (-1));
			}
			else
				set_numerator(get_numerator() + (-1));
		}
		else
		{
			if (integer > 0)
			{
				set_integer(get_integer() + (-1));
			}
			else
				set_integer(get_integer() + (-1));
		}
		return 0;
	}
	Fraction operator--(int a)
	{
		if (integer == 0)
		{
			if (numerator < 0)
			{
				set_integer(get_integer() + (-1));
				set_numerator(get_numerator() * (-1));
			}
			else
				set_numerator(get_numerator() + (-1));
		}
		else
		{
			if (integer > 0)
			{
				set_integer(get_integer() + (-1));
			}
			else
				set_integer(get_integer() + (-1));
		}
		return 0;
	}
	
	Fraction operator=(Fraction C)
	{
		this->integer = C.get_integer();
		this->numerator = C.get_numerator();
		this->denominator = C.get_denominator();
		return Fraction(C);
	}

	Fraction operator+=(Fraction C)
	{
		to_improper();
		C.to_improper();
		set_numerator(this->numerator * C.denominator + C.numerator * this->denominator);
		set_denominator(this->denominator * C.denominator);
		to_proper(); 
		if (get_integer() < 0)set_numerator(get_numerator() * (-1));
		reduce();
		return 0;
	}
	Fraction operator-=(Fraction C)
	{
		to_improper();
		C.to_improper();
		set_numerator(this->numerator * C.denominator - C.numerator * this->denominator);
		set_denominator(this->denominator * C.denominator);
		to_proper();
		if (get_integer() < 0)set_numerator(get_numerator() * (-1));
		reduce();
		return 0;
	}
	Fraction operator*=(Fraction C)
	{
		to_improper();
		C.to_improper();
		set_numerator(this->numerator * C.numerator);
		set_denominator(this->denominator * C.denominator);
		to_proper();
		if (get_integer() < 0)set_numerator(get_numerator() * (-1));
		reduce();
		return 0;
	}
	Fraction operator/=(Fraction C)
	{
		to_improper();
		C.to_improper();
		set_numerator(this->numerator * C.denominator);
		set_denominator(this->denominator * C.numerator);
		to_proper();
		if (get_integer() < 0)set_numerator(get_numerator() * (-1));
		reduce(); 
		return 0;
	}
	
	bool operator==(const Fraction &C)
	{
		double first = this->integer + this->numerator / this->denominator;
		double second = C.integer + C.numerator / C.denominator;
		if (first == second)return true;
		else return false;
		to_proper();
	}
	bool operator!=(const Fraction &C)
	{
		double first = this->integer + this->numerator / this->denominator;
		double second = C.integer + C.numerator / C.denominator;
		if (first != second)return true;
		else return false;
		to_proper();
	}
	bool operator>(const Fraction &C)
	{
		double first = this->integer + this->numerator / this->denominator;
		double second = C.integer + C.numerator / C.denominator;
		if (first > second)return true;
		else return false;
		to_proper();
	}
	bool operator<(const Fraction &C)
	{
		double first = this->integer + this->numerator / this->denominator;
		double second = C.integer + C.numerator / C.denominator;
		if (first > second)return true;
		else return false;
		to_proper();
	}
	bool operator>=(const Fraction &C)
	{
		double first = this->integer + this->numerator / this->denominator;
		double second = C.integer + C.numerator / C.denominator;
		if (first >= second)return true;
		else return false;
		to_proper();
	}
	bool operator<=(const Fraction &C)
	{
		double first = this->integer + this->numerator / this->denominator;
		double second = C.integer + C.numerator / C.denominator;
		if (first <= second)return true;
		else return false;
		to_proper();
	}*/
	
	void print()
	{
		/*to_proper();
		reduce();*/
		reduce();
		if (integer) cout << integer << " ";
		if (numerator) {
			cout << numerator << "/" << denominator;
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
};
//class Drob
//{
//	int numerator;
//	int denomenator;
//
//public:
//	int get_num() const
//	{
//		return numerator;
//	}
//	int get_denom() const
//	{
//		return denomenator;
//	}
//
//	void set_num(int x)
//	{
//		this->numerator = x;
//	}
//	void set_denom(int y)
//	{
//		if(y == 0)
//		this->denomenator = y;
//	}
//	
//	void simpleDrob(Drob simple)
//	{
//		cout << numerator << "/" << denomenator << endl;
//	}
//	int chislitel(double desitich) 
//	{
//		int chisl = 0;
//		while (desitich > 0)
//		{
//			desitich *= 10;
//			chisl += desitich;
//			chisl *= 10;
//			while (desitich >= 1)
//			{
//				desitich--;
//			}
//		}
//		return chisl / 10;
//	}
//	int znamenatel(double desitich)
//	{
//		int znam = 0;
//		int temp = 0;
//		while (desitich > 0)
//		{
//			desitich *= 10;
//			while (desitich >= 1)
//			{
//				desitich--;
//			}
//			temp++;
//		}
//		return pow(10, temp);
//	}
//	unsigned int NOD(int chis, int znam)
//	{
//		chis = abs(chis);
//		znam = abs(znam);
//		while (chis != znam) {
//			if (chis > znam) {
//				chis = chis - znam;
//			}
//			else {
//				znam = znam - chis;
//			}
//		}
//		return chis + znam;
//	}
//};
//#define Fraction_Doma

//#define CONSTRUCTOR_CHECK
//#define INCREMENT_CHECK
//#define IOSTREAM_OPERATOR_CHECK
//#define TYPE_CONVERSION_BASICS
void main()
{
	
	setlocale(LC_ALL, "");
#ifdef Fraction_Doma
	int chislitel, znamenatel;
	Drob simple;
	double desitichnayaDrob;
	simple.set_num(15);
	simple.set_denom(38);
	simple.simpleDrob(simple);
	cout << "¬ведите дес€тичную дробь: ";	cin >> desitichnayaDrob;
	chislitel = simple.chislitel(desitichnayaDrob);
	znamenatel = simple.znamenatel(desitichnayaDrob);
	int nod = simple.NOD(chislitel, znamenatel);
	simple.set_num(chislitel / nod);
	simple.set_denom(znamenatel / nod);
	simple.simpleDrob(simple);

	/*Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A / B;
	C.print();
	A *= B;
	A.print();
	A /= B;
	A.print();*/
	/*A.print();
	B.print();*/
	
	/*++C;
	C.print();
	C++;
	C.print();
	C *= A;
	C.print();*/
	/*
	if (A == B)
		A.print();*/ 


	/*A.print();
	B.print();
	A.reduce();
	B.reduce();
	A.print();
	B.print();*/
#endif
#ifdef CONSTRUCTOR_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	D.to_improper();
	D.print();

	D.to_proper();
	D.print();
#endif 
#ifdef INCREMENT_CHECK
	for (Fraction i(1, 2); i.get_integer() < 10; i++) {
		i.print();
	}
#endif // INCREMENT_CHECK
#ifdef IOSTREAM_OPERATOR_CHECK
	Fraction A(50, 70, 83);
	cout << "¬ведите простую дробь: ";
	cin >> A;
	cout << delimiter << endl;
	cout << A << endl;
	cout << delimiter << endl;
#endif
#ifdef TYPE_CONVERSION_BASICS
	int a = 2;
	double b = 3;
	int c = d;
	int d = round(4.49);
	cout << d << endl;
#endif

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A(2, 3, 4);
	cout << A << endl;
	int b = (int)A;
	cout << b << endl;

	double a = (double)A;
	cout << a << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER


	Fraction A = 1.03;
	cout << A << endl;



}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	left.set_denominator(left.get_denominator() * right.get_denominator());
	right.set_denominator(left.get_denominator());
	return Fraction
	{
		left.get_numerator() + right.get_numerator(),
		left.get_denominator() + right.get_denominator()
	}.to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	left.set_denominator(left.get_denominator() * right.get_denominator());
	right.set_denominator(left.get_denominator());
	return Fraction
	{
		left.get_numerator() - right.get_numerator(),
		left.get_denominator()
	}.to_proper();
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction res;
	res.set_numerator(left.get_numerator() * right.get_numerator());
	res.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*Fraction res
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	res.to_proper();
	return res;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper();*/
	return left * right.inverted();
}

ostream& operator<<(ostream& out, const Fraction& obj)
{
	if (obj.get_integer())out << obj.get_integer() << " ";
	if (obj.get_numerator())
		out << obj.get_numerator() << "/" << obj.get_denominator();
	else 
		if(obj.get_integer() == 0) out << 0;
	return out;
}
istream& operator>>(istream& in, Fraction& obj)
{
	/*int integer; cin >> integer;
	int numerator; cin >> numerator;
	int denominator; cin >> denominator;
	obj(integer, numerator, denominator);*/
	int number[3] = {};
	const int SIZE = 256;
	char buffer[SIZE] = {};
	char delimiters[] = " /()";
	in.getline(buffer, SIZE);
	int n = 0;
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = atoi(pch);
	}
	//for (int i = 0; i < n; i++) cout << number[i] << "\t"; cout << endl;
	obj = Fraction();
	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2:
		obj.set_numerator(number[0]);
		obj.set_denominator(number[1]);
		break;
	case 3:
		obj.set_integer(number[0]);
		obj.set_numerator(number[1]);
		obj.set_denominator(number[2]);
	}
	return in;
}
