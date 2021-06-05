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

class Fraction   //Описывает простую дробь
{
	int chisl;    //Числитель
	int znam;    //Знаменатель
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

		while (tempA != tempB) // алгоритм Евклида
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
		
		cout << "\n  Введите  числитель  дроби: "; cin >> number; set_chisl(number);
		cout << "  Введите знаменатель дроби: "; cin >> number; set_znam(number);
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
			cout << "  Выберите действие: ";
			cin >> key;
		} while (key < 1 && key > 12);

		switch (key)
		{
		case 1:
			cout << "  Сложение \n"; 
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this + other;	
			cout << "\n  Сумма дробей А и В равна: ";
			break;
		case 2: 
			cout << "  Вычитание \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this - other;
			cout << "\n  Разность дробей А и В равна: ";
			break;
		case 3: 
			cout << "  Умножение \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this * other;
			cout << "\n  Произведение дробей А и В равно: ";
			break;
		case 4: 
			cout << "  Деление \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this / other;
			cout << "\n  Частное дробей А и В равно: ";
			break;
		case 5:
			cout << "  Префиксный инкремент \n";
			Result = *this;
			++Result;
			cout << "\n  Префиксный инкремент числа А равен: ";
			break;
		case 6:
			cout << "  Постфиксный инкремент \n";
			Result = *this;
			Result++;
			cout << "\n  Постфиксный инкремент числа А равен: ";
			break;
		case 7:
			cout << "  Префиксный декремент \n";
			Result = *this;
			--Result;
			cout << "\n  Префиксный декремент числа А равен: ";
			break;
		case 8:
			cout << "  Постфиксный декремент \n";
			Result = *this;
			Result--;
			cout << "\n  Постфиксный декремент числа А равен: ";
			break;
		case 9:
			cout << "  Прибавить - равно \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this += other;
			cout << "\n  Прибавить - равно дробей А и В равно: ";
			break;
		case 10: 
			cout << "  Отнять - равно \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this -= other;
			cout << "\n  Отнять - равно дробей А и В равно: ";
			break;
		case 11: 
			cout << "  Умножить - равно \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this *= other;
			cout << "\n  Умножить - равно дробей А и В равно: ";
			break;
		case 12:
			cout << "  Разделить - равно \n";
			other.FillObject();
			cout << "  B = "; other.print();
			Result = *this /= other;
			cout << "\n  Разделить - равно дробей А и В равно: ";
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
		cout << "  Мы знаем: Вам понравилось пользоваться нашим калькуляторо '2B - Fraction'! \n  Хотите поработать ещё - нажмите любую клавишу.\n  Выход - Esc " << endl;
		Loop = _getch();

	} while (Loop != 27);
}

void menu()
{
	system("CLS");
	cout << " \n\t\t  Калькулятор дробей - 2B - СRUSHER_#1 " << endl;

	string cases[4]
	{
		"  Сложение : + 1        Инкремент  преф (++X): - 5         Плюс -  равно    (+=) : - 9 ",
		"  Вычитание: - 2        Инкремент  пост (X++): - 6         Минус - равно    (-=) : - 10 ",
		"  Умножение: * 3        Декремент  преф (--X): - 7         Умножить - равно (*=) : - 11 ",
		"  Деление  : / 4        Декремент  пост (X--): - 8         Делить  -  равно (/=) : - 12 ",
	};
	cout << delimiter << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << cases[i] << endl;		
	}	
	cout << delimiter << endl;
}