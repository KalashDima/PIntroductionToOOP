#include<iostream>

using namespace std;

#define WIDTH 27
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
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "SingleArgumentConstructor:" << this << endl;
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
	void to_proper()
	{
		if (numerator > denominator)
		{
			integer += numerator / denominator;
			numerator %= denominator;
		}
	}
	void to_improper() 
	{
		if (integer)
		{
			numerator += integer * denominator;
			integer = 0;
		}
	}

	void reduce()
	{
		int numerator = abs(this->numerator);
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
		int nod = numerator + denominator;
		this->denominator /= nod;
		this->numerator /= nod;
	}
	void common_denominator(Fraction B)
	{
		to_proper();
		B.to_proper();
		set_numerator(this->numerator * B.denominator);
		set_denominator(this->denominator);


	}


	Fraction operator+(Fraction B) 
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
		C.to_proper();
		C.reduce();
		if (C.get_integer() < 0)
			C.set_numerator(C.get_numerator() * (-1));
		return Fraction(C);
		to_proper();
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
	}
	
	void print()
	{
		to_proper();
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
	cout << "Введите десятичную дробь: ";	cin >> desitichnayaDrob;
	chislitel = simple.chislitel(desitichnayaDrob);
	znamenatel = simple.znamenatel(desitichnayaDrob);
	int nod = simple.NOD(chislitel, znamenatel);
	simple.set_num(chislitel / nod);
	simple.set_denom(znamenatel / nod);
	simple.simpleDrob(simple);

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

	Fraction A(2, 3, 6);
	Fraction B(10, 8, 12);
	Fraction C = A - B;
	C.print();
	++C;
	C.print();
	C++;
	C.print();
	C *= A;
	C.print();
	
	if (A == B)
		A.print();


	/*A.print();
	B.print();
	A.reduce();
	B.reduce();
	A.print();
	B.print();*/
}