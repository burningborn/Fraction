#include<iostream>
#include<conio.h>
using namespace std;
//using std::cin;
//using std::cout;
//using std::endl;

//using
#define tab "\t"
#define delimiter "\n-----------------------------------------------------------------------------------\n"

void menu();
void Seter();
//void Numbers();

class Fraction   //Описывает простую дробь
{
	int a;    //Числитель
	int b;    //Знаменатель
public:
	int get_a()const
	{
		return a;
	}
	int get_b()const
	{
		return b;
	}
	void set_a(int a)
	{
		this->a = a;
	}
	void set_b(int b)
	{
		this->b = b;
	}

	Fraction(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}

	~Fraction()
	{
		//cout << "Destructor:\t " << this << endl;
	}

	Fraction operator+(const Fraction& other)const
	{
		Fraction result;
		if (this->b != other.b)
		{
			int temp_this_a = this->a;
			int temp_other_a = other.a;
			temp_this_a *= other.b;
			temp_other_a *= this->b;
			result.a = temp_this_a + temp_other_a;
			result.b = this->b * other.b;
		}
		else
		{
			result.a = this->a + other.a;
			result.b = this->b;
		}
		result.simplification();
		return result;
	}

	Fraction operator-(const Fraction& other)const
	{
		Fraction result;
		if (this->b != other.b)
		{
			int temp_this_a = this->a;
			int temp_other_a = other.a;
			temp_this_a *= other.b;
			temp_other_a *= this->b;
			result.a = temp_this_a - temp_other_a;
			result.b = this->b * other.b;
		}
		else
		{
			result.a = this->a - other.a;
			result.b = this->b;
		}
		//result.simplification();
		return result;
	}

	Fraction operator*(const Fraction& other)const
	{
		Fraction result;

		result.a = this->a * other.a;
		result.b = this->b * other.b;

		result.simplification();
		return result;
	}

	Fraction operator/(const Fraction& other)const
	{
		Fraction dividend;
		Fraction divider;
		Fraction result;

		divider.a = other.b;
		divider.b = other.a;
		dividend.a = this->a;
		dividend.b = this->b;
		result = dividend * divider;

		//result.simplification();
		return result;
	}

	Fraction& operator ++() //prefix increment
	{

		Fraction One, Two;

		One.a = this->a;
		One.b = this->b;
		Two.a = this->b;
		Two.b = this->b;

		*this = One + Two;
		return *this;
	}

	Fraction& operator ++(int value) //postfix increment
	{
		Fraction result(*this);
		Fraction One, Two;
		One.a = this->a;
		One.b = this->b;
		Two.a = this->b;
		Two.b = this->b;

		*this = One + Two;
		return result;
	}

	Fraction& operator --() //prefix decrement
	{
		Fraction One, Two;
		One.a = this->a;
		One.b = this->b;
		Two.a = this->b;
		Two.b = this->b;

		*this = One - Two;
		return *this;
	}

	Fraction& operator --(int value) //postfix decrement
	{
		Fraction result(*this);
		Fraction One, Two;
		One.a = this->a;
		One.b = this->b;
		Two.a = this->b;
		Two.b = this->b;

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
		int tempA = result.a = this->a;
		int tempB = result.b = this->b;

		while (tempA != tempB) // алгоритм Евклида
		{
			if (tempA > tempB)swap(tempA, tempB);
			tempB = tempB - tempA;
		}

		result.a /= tempA;
		result.b /= tempA;
		*this = result;
		return *this;
	}



	void print()
	{
		if (a / b > 0)
		{
			int Integer = a / b;
			int  a2 = a % b;
			if(a2==0){ cout << tab << Integer << endl; }
			else { cout << tab << Integer << " " << a2 << "/" << b << endl; }
		}
		else
		{
			cout << tab << "   " << a << "/" << b << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");

	cout << " \n\t ДЕЙСТВИЯ С КЛАССОМ ПРОСТЫХ ДРОБЕЙ " << endl;

	//cout << delimiter << endl;	

	/*cout << "Объект A:\t "; A.print();
	cout << "Объект B: \t"; B.print();
	cout << "Объект D: \t"; D.print();
	D.simplification();
	cout << "Объект D упрощенный: "; D.print();*/

	cout << delimiter << endl;

	menu();

	/*C = A + B; cout << "Сложение : C = A + B "; C.print();
	C = A - B; cout << "Вычитание: C = A - B "; C.print();
	C = A * B; cout << "Умножение: C = A * B "; C.print();
	C = A / B; cout << "Деление  : C = A / B "; C.print();

	cout << delimiter << endl;

	D = ++C; cout << "Инкремент префиксный : D = ++C "; D.print();
	D = C++; cout << "Инкремент постфиксный: D = C++ "; D.print();
	cout << "Инкремент постфиксный: C++ "; C.print();

	cout << delimiter << endl;

	D = --C; cout << "Декремент префиксный : D = --C "; C.print();
	D = C--; cout << "Декремент постфиксный: D = C-- "; D.print();
	cout << "Декремент постфиксный: C--; "; C.print();

	cout << delimiter << endl;

	A += B; cout << "Плюс   -    равно: A += B "; A.print();
	A -= B; cout << "Минус   -   равно: A -= B "; A.print();
	A *= B; cout << "Умножить -  равно: A *= B "; A.print();
	A /= B; cout << "Разделить - равно: A /= B "; A.print();*/
}

void menu()
{
	string cases[12]
	{
		"Сложение : - 1 ",
		"Вычитание: - 2 ",
		"Умножение: - 3 ",
		"Деление  : - 4 ",
		"Инкремент преф: - 5 ",
		"Инкремент пост: - 6 ",
		"Декремент преф: - 7 ",
		"Декремент пост: - 8 ",
		"Декремент пост: - 9 ",
		"Декремент пост: - 10 ",
		"Декремент пост: - 11 ",
		"Декремент пост: - 12 "
	};

	for (int i = 0; i < 12; i++)
	{
		cout << cases[i] << endl;
		if ((i + 1) % 4 == 0)
		{
			cout << "------------------------------" << endl;
		}
	}	

	Fraction A;
	Fraction B;
	Fraction C;
	Fraction D;
	int number = 0;
	cout << "\nвведите  числитель  первого числа: "; cin >> number; A.set_a(number);
	cout << "\nвведите знаменатель первого числа: "; cin >> number; A.set_b(number);
	cout << "\nвведите  числитель  второго числа: "; cin >> number; B.set_a(number);
	cout << "\nвведите знаменатель второго числа: "; cin >> number; B.set_b(number);

	cout << "Выберите действие: " << endl;
	int key = 0;
	cin >> key;

	switch (key)
	{
	case 1: C = A + B;
		break;
	case 2: C = A - B;
		break;
	case 3: C = A * B;
		break;
	case 4: C = A / B;
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9: A += B;
		break;
	case 10: A -= B;
		break;
	case 11: A *= B;
		break;
	case 12:A /= B;
		break;
	default:
		break;
	}
	C.print();
}

void seter()
{
	
	/*int a1 = this->a;
	int b1 = this->b;
	int a2 = other.a;
	int b2 = other.b;*/
	/*
	int a1; cin >> a1;
	this->a = (*this).set_a(a1);
	
	int b1; cin >> b1;
	a.set_b(b1);
	
	int a2; cin >> a2;
	b.set_a(a2);
	
	int b2; cin >> b2;
	b.set_b(b2);*/
}

