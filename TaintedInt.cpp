#include "TaintedInt.h"


TaintedInt& TaintedInt::operator=(const int i) 
{
	this->setNumber(i);
	return *this;
}

TaintedInt& TaintedInt::operator=(const TaintedInt& t) 
{
	this->setNumber(t.getNumber());
	this->setTaint(t.checkTainted());
	return *this;
}

TaintedInt TaintedInt::operator+ (const TaintedInt& t)  const
{
	TaintedInt temp(this->getNumber() + t.getNumber());
	temp.setTaint(this->checkTainted());
	return temp;
}

TaintedInt TaintedInt::operator+() const
{
	return *this;
}

TaintedInt TaintedInt::operator-(const TaintedInt& t) const
{
	TaintedInt temp = *this;
	temp.setNumber(temp.getNumber() - t.getNumber());
	return temp;
}

TaintedInt TaintedInt::operator-() const
{
	TaintedInt temp = *this;
	temp.setNumber( - temp.getNumber());
	return temp;
}

TaintedInt TaintedInt::operator*(const TaintedInt& t) const
{
	TaintedInt temp = *this;
	temp.setNumber(temp.getNumber() * t.getNumber());
	if (!temp.checkTainted())
		temp.setTaint(t.checkTainted()); // if left not tainted check if right tainted
	return temp;
}

TaintedInt TaintedInt::operator/(const TaintedInt& t) const
{
	TaintedInt temp = *this;
	temp.setNumber(temp.getNumber() / t.getNumber());
	if (!temp.checkTainted())
		temp.setTaint(t.checkTainted()); // if left not tainted check if right tainted
	return temp;
}

bool TaintedInt::operator&()
{
	return this->checkTainted();
}

int TaintedInt::operator*()
{
	return this->getNumber();
}

TaintedInt& TaintedInt::operator++()
{
	this->setNumber(this->getNumber() + 1);
	return *this;
}

TaintedInt TaintedInt::operator++(int)
{
	TaintedInt temp = *this;
	++* this;
	return temp;
}

//TaintedInt::operator double() const
//{
//	return (double)(this->getNumber());
//}

std::ostream& operator<<(std::ostream& os, const TaintedInt& t)
{
	if (t.checkTainted())
		os << t.getNumber() << " [tainted] ";
	else
		os << t.getNumber();
	return os;
}

TaintedInt operator +(const int i, const TaintedInt& t)
{
	TaintedInt temp = t;
	temp.setNumber(t.getNumber() + i);
	return temp;
}

TaintedInt operator+(const double num, const TaintedInt& t)
{
	TaintedInt temp = t;
	temp.setNumber(t.getNumber() + (int)num);
	return temp;
}

TaintedInt operator+(const float num, const TaintedInt& t)
{
	TaintedInt temp = t;
	temp.setNumber(t.getNumber() + (int)num);
	return temp;
}

TaintedInt operator+(const unsigned num, const TaintedInt& t)
{
	TaintedInt temp = t;
	temp.setNumber(t.getNumber() + (int)num);
	return temp;
}

TaintedInt operator*(const int i, const TaintedInt& t)
{
	TaintedInt temp = t;
	temp.setNumber(t.getNumber() * i);
	return temp;
}
