#include<iostream>

using namespace std;
class Drob
{
	int numerator;
	int denomenator;

public:
	int get_num() const
	{
		return numerator;
	}
	int get_denom() const
	{
		return denomenator;
	}

	void set_num(int x)
	{
		this->numerator = x;
	}
	void set_denom(int y)
	{
		this->denomenator = y;
	}
	void simpleDrob(Drob simple)
	{
		cout << numerator << "/" << denomenator << endl;
	}
	int chislitel(double desitich) 
	{
		int chisl = 0;
		while (desitich > 0)
		{
			desitich *= 10;
			chisl += desitich;
			chisl *= 10;
			while (desitich >= 1)
			{
				desitich--;
			}
		}
		return chisl / 10;
	}
	int znamenatel(double desitich)
	{
		int znam = 0;
		int temp = 0;
		while (desitich > 0)
		{
			desitich *= 10;
			while (desitich >= 1)
			{
				desitich--;
			}
			temp++;
		}
		return pow(10, temp);
	}
	unsigned int NOD(int chis, int znam)
	{
		chis = abs(chis);
		znam = abs(znam);
		while (chis != znam) {
			if (chis > znam) {
				chis = chis - znam;
			}
			else {
				znam = znam - chis;
			}
		}
		return chis + znam;
	}
};
void main()
{
	setlocale(LC_ALL, "");
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
	simple.set_num(chislitel/nod);
	simple.set_denom(znamenatel/nod);
	simple.simpleDrob(simple);

}