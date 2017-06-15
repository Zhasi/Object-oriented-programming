#include<iostream>
#include <algorithm>

using namespace std;

size_t length(size_t);
size_t pad(size_t, size_t);

class Decimal
{
public:
	Decimal(int, size_t = 0);

	Decimal sum(const Decimal&)const;

	Decimal diff(const Decimal&);
	bool equals(const Decimal&);
	bool isLessThan(const Decimal&);
	void print() const;

private:
	int wholePart;
	size_t decimalPart;
};

size_t length(size_t number)
{
	size_t len = 0;
	while (number)
	{
		number /= 10;
		++len;
	}

	return len;
}

size_t pad(size_t number, size_t countZeros)
{
	if (!number) return number;

	for (size_t i = 1; i <= countZeros; ++i)
	{
		number *= 10;
	}

	return number;
}

Decimal::Decimal(int whole, size_t dec)
	: wholePart(whole), decimalPart(dec)
{}

void Decimal::print() const
{
	cout << wholePart << '.' << decimalPart << endl;
}

Decimal Decimal::sum(const Decimal& right) const
{
	size_t leftLength = length(decimalPart);
	size_t rightLength = length(right.decimalPart);

	size_t maxLength = std::max(leftLength, rightLength);

	size_t leftDecPart = pad(decimalPart, maxLength - leftLength);
	size_t rightDecPart = pad(right.decimalPart, maxLength - rightLength);

	size_t resultDecPart = leftDecPart + rightDecPart;
	size_t resultWholePart = wholePart + right.wholePart;

	if (length(resultDecPart) > maxLength)
	{
		size_t pow10 = pow(10, maxLength);

		resultWholePart += resultDecPart / pow10;
		resultDecPart = resultDecPart % pow10;
	}

	return Decimal(resultWholePart, resultDecPart);
}

Decimal Decimal::diff(const Decimal& b)
{
	Decimal c(wholePart, decimalPart);
	if (wholePart > b.wholePart)
	{
		c.wholePart = wholePart - b.wholePart;
		c.decimalPart =decimalPart - b.decimalPart;
	}
	else
	{
		c.wholePart = b.wholePart - wholePart;
		c.decimalPart =b.decimalPart -decimalPart;
	}
	return c;
}

bool Decimal::equals(const Decimal& b)
{
	if (wholePart == b.wholePart && decimalPart == b.decimalPart)
		return true;
		return false;
}

bool Decimal::isLessThan(const Decimal& b)
{
	if (wholePart > b.wholePart)
		return false;
	return true;
}

int main()
{
	Decimal d1(12, 999);
	Decimal d2(6, 999);

	Decimal sumD = d1.sum(d2);
	sumD.print();
	Decimal diffd = d1.diff(d2);
	diffd.print();

	cout<<d1.equals(d2)<<endl;
	
	cout<<d1.isLessThan(d2);

	system("pause");
	return 0;

}