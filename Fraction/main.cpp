#include<iostream>
using namespace std;
//using std::cin;
//using std::cout;
//using std::endl;

#define tab "\t"
#define delimiter "\n-----------------------------------------------------------------------------------\n"

class Fraction   //Описывает простую дробь
{
	 int chisl;    //Числитель
	 int b;    //Знаменатель
public:
	 int get_a()const
	{
		return chisl;
	}
	 int get_b()const
	{
		return b;
	}
	void set_a(int a)
	{
		this->chisl = a;
	}
	void set_b(int b)
	{
		this->b = b;
	}
					
	Fraction(int a = 0, int b = 0)
	{		
		this->chisl = a;
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
			int temp_this_a = this->chisl;
			int temp_other_a = other.chisl;
			temp_this_a *= other.b;
			temp_other_a *= this->b;
			result.chisl = temp_this_a + temp_other_a;
			result.b = this->b * other.b;
		}
		else
		{
			result.chisl = this->chisl + other.chisl;
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
			int temp_this_a = this->chisl;
			int temp_other_a = other.chisl;
			temp_this_a *= other.b;
			temp_other_a *= this->b;
			result.chisl = temp_this_a - temp_other_a;
			result.b = this->b * other.b;
		}
		else
		{
			result.chisl = this->chisl - other.chisl;
			result.b = this->b;
		}
		result.simplification();
		return result;
	}

	Fraction operator*(const Fraction& other)const
	{
		Fraction result;
		
			result.chisl = this->chisl * other.chisl;
			result.b = this->b * other.b;

			result.simplification();
		return result;
	}

	Fraction operator/(const Fraction& other)const
	{
		Fraction dividend;
		Fraction divider;
		Fraction result;

		divider.chisl = other.b;
		divider.b = other.chisl;
		dividend.chisl = this->chisl;
		dividend.b = this->b;
		result = dividend * divider;

		//result.simplification();
		return result;
	}

	Fraction& operator ++() //prefix increment
	{
		
		Fraction One, Two;

		One.chisl = this->chisl;
		One.b = this->b;
		Two.chisl = this->b;
		Two.b = this->b;
		
		*this = One + Two;
		return *this;
	}

	Fraction& operator ++(int value) //postfix increment
	{
		Fraction result(*this);
		Fraction One, Two;
		One.chisl = this->chisl;
		One.b = this->b;
		Two.chisl = this->b;
		Two.b = this->b;

		*this = One + Two;
		return result;
	}

	Fraction& operator --() //prefix decrement
	{
		Fraction One, Two;
		One.chisl = this->chisl;
		One.b = this->b;
		Two.chisl = this->b;
		Two.b = this->b;

		*this = One - Two;
		return *this;
	}

	Fraction& operator --(int value) //postfix decrement
	{
		Fraction result(*this);
		Fraction One, Two;
		One.chisl = this->chisl;
		One.b = this->b;
		Two.chisl = this->b;
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
	
	Fraction& simplification ()
	{		
		Fraction result;	
		int tempA = result.chisl = this->chisl;
		int tempB = result.b = this->b;
		 			
		if (tempA < 0)tempA *= -1;
			
			while (tempA != tempB) // алгоритм Евклида
			{
				if (tempA > tempB)swap(tempA, tempB);
				tempB = tempB - tempA;
			}
		result.chisl /= tempA;
		result.b /= tempA;
		*this = result;
		return *this;
	}

	void print()
	{
		if (chisl / b > 0)
		{
			int Integer = chisl / b;
			int  a2 = chisl % b;
			if (a2 == 0) { cout << tab << Integer << endl; }
			else { cout << tab << Integer << " " << a2 << "/" << b << endl; }
		}
		else
		{
			cout << tab << "   " << chisl << "/" << b << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");

	cout << " \n\t ДЕЙСТВИЯ С КЛАССОМ ПРОСТЫХ ДРОБЕЙ " << endl;

	cout << delimiter << endl;

	Fraction A(3, 5);
	Fraction B(2, 3);
	Fraction C(0, 0);
	Fraction D(5, 10);

	cout << "Объект A:\t "; A.print();
	cout << "Объект B: \t"; B.print();
	cout << "Объект D: \t"; D.print();
	D.simplification();
	cout << "Объект D упрощенный: "; D.print();

	cout << delimiter << endl;	

	C = A + B; cout << "Сложение : C = A + B "; C.print();
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
	A /= B; cout << "Разделить - равно: A /= B "; A.print();	
}