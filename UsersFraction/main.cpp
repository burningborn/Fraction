#include<iostream>
#include<conio.h>
using namespace std;
//using std::cin;
//using std::cout;
//using std::endl;

//using
#define tab "\t"
#define delimiter "\n----------------------------------------------------------------------------------------\n"

void menu();
void Seter();
//void Numbers();

class Fraction   //��������� ������� �����
{
	int chisl;    //���������
	int znam;    //�����������
public:
	int get_chisl()const
	{
		return chisl;
	}
	int get_znam()const
	{
		return znam;
	}
	void set_chisl(int chisl)
	{
		this->chisl = chisl;
	}
	void set_znam(int znam)
	{
		this->znam = znam;
	}

	Fraction(int chisl = 0, int znam = 0)
	{
		
		this->chisl = chisl;
		this->znam = znam;
	}

	~Fraction()
	{
		//cout << "Destructor:\t " << this << endl;
	}

	//Fraction& operator= (const Fraction& other)
	//{
	//	
	//	this->chisl = other.chisl;
	//	this->znam = other.znam;
	//	return *this;
	//}

	Fraction operator+(const Fraction& other)const
	{
		Fraction result;
		if (this->znam != other.znam)
		{
			int temp_this_chisl = this->chisl;
			int temp_other_chisl = other.chisl;
			temp_this_chisl *= other.znam;
			temp_other_chisl *= this->znam;
			result.chisl = temp_this_chisl + temp_other_chisl;
			result.znam = this->znam * other.znam;
		}
		else
		{
			result.chisl = this->chisl + other.chisl;
			result.znam = this->znam;
		}
		result.simplification();
		return result;
	}

	Fraction operator-(const Fraction& other)const
	{
		Fraction result;
		if (this->znam != other.znam)
		{
			int temp_this_chisl = this->chisl;
			int temp_other_chisl = other.chisl;
			temp_this_chisl *= other.znam;
			temp_other_chisl *= this->znam;
			result.chisl = temp_this_chisl - temp_other_chisl;
			result.znam = this->znam * other.znam;
		}
		else
		{
			result.chisl = this->chisl - other.chisl;
			result.znam = this->znam;
		}
		result.simplification();
		return result;
	}

	Fraction operator*(const Fraction& other)const
	{
		Fraction result;

		result.chisl = this->chisl * other.chisl;
		result.znam = this->znam * other.znam;

		result.simplification();
		return result;
	}

	Fraction operator/(const Fraction& other)const
	{
		Fraction dividend;
		Fraction divider;
		Fraction result;

		divider.chisl = other.znam;
		divider.znam = other.chisl;
		dividend.chisl = this->chisl;
		dividend.znam = this->znam;
		result = dividend * divider;

		//result.simplification();
		return result;
	}

	Fraction& operator ++() //prefix increment
	{

		Fraction One, Two;

		One.chisl = this->chisl;
		One.znam = this->znam;
		Two.chisl = this->znam;
		Two.znam = this->znam;

		*this = One + Two;
		return *this;
	}

	Fraction& operator ++(int value) //postfix increment
	{
		Fraction result(*this);
		Fraction One, Two;
		One.chisl = this->chisl;
		One.znam = this->znam;
		Two.chisl = this->znam;
		Two.znam = this->znam;

		*this = One + Two;
		return result;
	}

	Fraction& operator --() //prefix decrement
	{
		Fraction One, Two;
		One.chisl = this->chisl;
		One.znam = this->znam;
		Two.chisl = this->znam;
		Two.znam = this->znam;

		*this = One - Two;
		return *this;
	}

	Fraction& operator --(int value) //postfix decrement
	{
		Fraction result(*this);
		Fraction One, Two;
		One.chisl = this->chisl;
		One.znam = this->znam;
		Two.chisl = this->znam;
		Two.znam = this->znam;

		*this = One - Two;
		return result;
	}

	Fraction operator +=(const Fraction& other)
	{
		*this = *this + other;
		(*this).simplification();
		return *this;
	}

	Fraction operator -=(const Fraction& other)
	{
		*this = *this - other;
		(*this).simplification();
		return *this;
	}

	Fraction operator *=(const Fraction& other)
	{
		*this = *this * other;
		(*this).simplification();
		return *this;
	}

	Fraction operator /=(const Fraction& other)
	{
		*this = *this / other;
		(*this).simplification();
		return *this;
	}

	Fraction& simplification()
	{
		Fraction result;
		int tempA = result.chisl = this->chisl;
		int tempB = result.znam = this->znam;

		while (tempA != tempB) // �������� �������
		{
			if (tempA > tempB)swap(tempA, tempB);
			tempB = tempB - tempA;
		}

		result.chisl /= tempA;
		result.znam /= tempA;
		*this = result;
		return *this;
	}

	Fraction& FillObject()
	{
		int number = 0;
		
		cout << "\n  �������  ���������  �����: "; cin >> number; set_chisl(number);
		cout << "  ������� ����������� �����: "; cin >> number; set_znam(number);
		return *this;
	}

	void print()
	{
		if (chisl / znam > 0)
		{
			int Integer = chisl / znam;
			int  a2 = chisl % znam;
			if(a2==0){ cout << tab << Integer << endl; }
			else { cout << tab << Integer << " " << a2 << "/" << znam << endl; }
		}
		else
		{
			cout << tab << "   " << chisl << "/" << znam << endl;
		}
	}

	Fraction& action(Fraction& other)
	{
		Fraction Result;
			int key = 1;
		do
		{
			cout << "  �������� ��������: ";
			cin >> key;
		} while (key < 1 && key > 12);

		switch (key)
		{
		case 1:
			cout << "  �������� \n"; 
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this + other;	
			cout << "\n  ����� ������ � � � �����: ";
			break;
		case 2: 
			cout << "  ��������� \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this - other;
			cout << "\n  �������� ������ � � � �����: ";
			break;
		case 3: 
			cout << "  ��������� \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this * other;
			cout << "\n  ������������ ������ � � � �����: ";
			break;
		case 4: 
			cout << "  ������� \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this / other;
			cout << "\n  ������� ������ � � � �����: ";
			break;
		case 5:
			cout << "  ���������� ��������� \n";
			Result = *this;
			++Result;
			cout << "\n  ���������� ��������� ����� � �����: ";
			break;
		case 6:
			cout << "  ����������� ��������� \n";
			Result = *this;
			Result++;
			cout << "\n  ����������� ��������� ����� � �����: ";
			break;
		case 7:
			cout << "  ���������� ��������� \n";
			Result = *this;
			--Result;
			cout << "\n  ���������� ��������� ����� � �����: ";
			break;
		case 8:
			cout << "  ����������� ��������� \n";
			Result = *this;
			Result--;
			cout << "\n  ����������� ��������� ����� � �����: ";
			break;
		case 9:
			cout << "  ��������� - ����� \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this += other;
			cout << "\n  ��������� - ����� ������ � � � �����: ";
			break;
		case 10: 
			cout << "  ������ - ����� \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this -= other;
			cout << "\n  ������ - ����� ������ � � � �����: ";
			break;
		case 11: 
			cout << "  �������� - ����� \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this *= other;
			cout << "\n  �������� - ����� ������ � � � �����: ";
			break;
		case 12:
			cout << "  ��������� - ����� \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this /= other;
			cout << "\n  ��������� - ����� ������ � � � �����: ";
			break;
		default:
			break;
		}
		return Result;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");

	Fraction A;
	Fraction B;
	Fraction C;
	char Loop = 28;
	
	do
	{
		menu();
		A.FillObject();
		cout << "  A = "; A.print();
		C = A.action(B);
		C.print();
		cout << delimiter << endl;
		cout << "  �� �����: ��� ����������� ������������ ����� ������������ '2B - Fraction'! \n  ������ ���������� ��� - ������� ����� �������.\n  ����� - Esc " << endl;
		Loop = _getch();

	} while (Loop != 27);
}

void menu()
{
	system("CLS");
	cout << " \n\t\t  ����������� ������ - 2B - �RUSHER_#1 " << endl;

	string cases[4]
	{
		"  �������� : + 1        ���������  ���� (++X): - 5         ���� -  �����    (+=) : - 9 ",
		"  ���������: - 2        ���������  ���� (X++): - 6         ����� - �����    (-=) : - 10 ",
		"  ���������: * 3        ���������  ���� (--X): - 7         �������� - ����� (*=) : - 11 ",
		"  �������  : / 4        ���������  ���� (X--): - 8         ������  -  ����� (/=) : - 12 ",
	};
	cout << delimiter << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << cases[i] << endl;		
	}	
	cout << delimiter << endl;
}