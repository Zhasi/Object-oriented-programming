#include <iostream>
#include<cmath>

using namespace std;

class Figure
{
public:
	virtual double perimeter() const = 0;

	virtual double area() const = 0;

	virtual ~Figure()
	{}

private:

};

class Triangle :public Figure
{
public:
	void setA(double a)
	{
		this->a = a;
	}

	void setB(double b)
	{
		this->b = b;
	}

	void setC(double c)
	{
		this->c = c;
	}
	
	Triangle(double a, double b, double c) :a(1), b(2), c(2)
	{
		if (a + b > c && a + c > b && b + c > a)
		{
			this->setA(a);
			this->setB(b);
			this->setC(c);
		}
	}

	virtual ~Triangle()
	{}
	
	virtual double perimeter() const
	{
		double P;
		if (a + b > c && a + c > b && b + c > a)
			P = a + b + c;
		return P;
	}

	virtual double area() const
	{
		double s;
		double p = perimeter() / 2;
		if (a + b > c && a + c > b && b + c > a)
			s = sqrt(p*(p- a)*(p- b)*(p - c));
		return s;
	}


private:
	double a, b, c;

};

#define PI 3.14159
class Circle :public Figure
{
public:
	void setR(double r)
	{
		this->r = r;
	}

	Circle(double r) :r(1)
	{
		setR(r);
	}

	virtual ~Circle()
	{}

	virtual double perimeter() const
	{
		double C;
		C = 2 * r*PI;
		return C;
	}

	virtual double area() const
	{
		double A;
		A = PI*r*r;
		return A;
	}

private:
	double r;

};
int main()
{ 
	Figure** figures = new Figure*[4];
	figures[0] = new Circle(3);
	figures[1] = new Triangle(3, 4, 5);
	figures[2] = new Circle(4);
	figures[3] = new Triangle(4, 5, 6);

	for (int i = 0; i < 4; i++)
	{
		cout << "The perimeter is" << figures[i]->perimeter() << "The area is" << figures[i]->area() << endl;
	}

	for (int i = 0; i < 4; i++)
	{
		delete figures[i];
	}

	delete[] figures;

	system("pause");
	return 0;
}

