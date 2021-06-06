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
		if (this->chisl != other.znam)
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
		Fraction Sum, One;
		One.chisl = this->znam;
		One.znam = this->znam;
		Sum = *this + One;
		*this = Sum;
		return *this;
	}

	Fraction& operator ++(int value) //postfix increment
	{
		Fraction Sum, One, Temp(*this);
		One.chisl = this->znam;
		One.znam = this->znam;
		Sum = *this + One;
		*this = Sum;
		return Temp;
	}

	Fraction& operator --() //prefix decrement
	{
		Fraction Difference, One;
		One.chisl = this->znam;
		One.znam = this->znam;
		*this = *this - One;
		return *this;
	}

	Fraction& operator --(int value) //postfix decrement
	{
		Fraction Difference, One, Temp(*this);
		One.chisl = this->znam;
		One.znam = this->znam;
		*this = *this - One;
		return Temp;
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
		int tempB = result.znam = this->znam;
		 			
		if (tempA < 0)tempA *= -1;
			
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

	void print()
	{
		if (chisl / znam > 0)
		{
			int Integer = chisl / znam;
			int  a2 = chisl % znam;
			if (a2 == 0) { cout << tab << Integer << endl; }
			else { cout << tab << Integer << " " << a2 << "/" << znam << endl; }
		}
		else
		{
			cout << tab << "   " << chisl << "/" << znam << endl;
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