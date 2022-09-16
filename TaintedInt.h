/*****************************************************************//**
 * \file   TaintedInt.h
 * \brief  Contains class TaintedInt. 
 *			
 * \author Chenbo Zhang
 * \date   September 2022
 *********************************************************************/
#pragma once

#include <iostream>
#include <type_traits>


class TaintedInt;

/**
 * \brief A class behave like integer but with a tainted method to mark the int even after calculations. 
 * TaintedInt can be involved into calculations just like an int number; 
 * It can be set as "tainted". 
 * In any calculation, if any input TaintedInt is "tainted", the output TaintedInt will be Tainted too. 
 */
class TaintedInt 
{
public:
	/**
	 * Constructor with default args.
	 * 
	 * \param i The value of taintedInt
	 * \param b The tainted status of taintedInt, 1 for tainted, default 0
	 */
	TaintedInt(int i = 0, bool b = 0) : tint(i), btainted(b) {}


	// -------------------------------------------------- //
	// ------Here goes assignment operator overload------ //
	// -------------------------------------------------- //
	/**
	 * Assignment operator overload.
	 * 
	 * \param int The input number need to be assign to taintedInt
	 * \return TaintedInt Itself by reference
	 */
	TaintedInt& operator= (const int);

	/**
	 * Assignment operator overload.
	 *
	 * \param TaintedInt The input TaintedInt that needs to be copied
	 * \return TaintedInt Itself by reference
	 */
	TaintedInt& operator= (const TaintedInt&);


	// -------------------------------------------------- //
	// ------   Here goes plus operator overload   ------ //
	// -------------------------------------------------- //
	/**
	 * Template method overloading plus operator.
	 * 
	 * \tparam T Input NUMBER need to be added to TaintedInt, not safe with other input types
	 * \return New TaintedInt with added up value
	 */
	template <typename T>
	TaintedInt operator+ (const T) const;

	/**
	 * Template method overloading left plus operator.
	 *
	 * \tparam T Input NUMBER on the left needed to be added to TaintedInt, not safe with other input types
	 * \param TaintedInt& TaintedInt itself on the right
	 * \return New TaintedInt with added up value
	 */
	template <typename T>
	friend TaintedInt operator +(const T, const TaintedInt&);

	/**
	 * Overload plus operator to add with TaintedInt. 
	 * Will get tainted status if one of the input is tainted
	 * 
	 * \param TaintedInt Tainted int that need to be added
	 * \return New TaintedInt with added up value
	 */
	TaintedInt operator+ (const TaintedInt&) const;

	/**
	 * Unary plus overload.
	 * 
	 * \return itself
	 */
	TaintedInt operator+ () const;


	// -------------------------------------------------- //
	// ------   Here goes minus operator overload  ------ //
	// -------------------------------------------------- //
	/**
	 * Template method overloading minus operator.
	 *
	 * \tparam T Input NUMBER need to be minus from TaintedInt, not safe with other input types
	 * \return New TaintedInt with minused  value
	 */
	template <typename T>
	TaintedInt operator- (const T) const;

	/**
	 * Template method overloading left minus operator.
	 *
	 * \tparam T Input NUMBER on the left needed to be minus from, not safe with other input types
	 * \param TaintedInt& TaintedInt itself on the right
	 * \return New TaintedInt with minus up value
	 */
	template <typename T>
	friend TaintedInt operator -(const T, const TaintedInt&);

	/**
	 * Overload minus operator to minus with TaintedInt.
	 * Will get tainted status if one of the input is tainted
	 *
	 * \param TaintedInt Tainted int that need to be minused
	 * \return New TaintedInt with minused value
	 */
	TaintedInt operator- (const TaintedInt&) const;

	/**
	 * Unary minus overload.
	 *
	 * \return itself
	 */
	TaintedInt operator- () const;


	// -------------------------------------------------- //
	// ------ Here goes multiply operator overload ------ //
	// -------------------------------------------------- //
	/**
	 * Template method overloading multiply operator.
	 *
	 * \tparam T Input NUMBER need to be multiply to TaintedInt, not safe with other input types
	 * \return New TaintedInt with multiplied value
	 */
	template <typename T>
	TaintedInt operator* (const T) const;

	/**
	 * Template method overloading left multiply operator.
	 *
	 * \tparam T Input NUMBER on the left needed to be multiply to TaintedInt, not safe with other input types
	 * \param TaintedInt& TaintedInt itself on the right
	 * \return New TaintedInt with multiplied value
	 */
	template <typename T>
	friend TaintedInt operator *(const T, const TaintedInt&);

	/**
	 * Overload multiply operator to multiply with TaintedInt.
	 * Will get tainted status if one of the input is tainted
	 *
	 * \param TaintedInt Tainted int that need to be multiplied
	 * \return New TaintedInt with multiplied value
	 */
	TaintedInt operator* (const TaintedInt&) const; // multiply by tainted int


	// -------------------------------------------------- //
	// ------  Here goes divide operator overload  ------ //
	// -------------------------------------------------- //
	/**
	 * Template method overloading divide operator.
	 *
	 * \tparam T Input NUMBER need to divide TaintedInt, not safe with other input types
	 * \return New TaintedInt with divided value
	 */
	template <typename T>
	TaintedInt operator/ (const T) const;

	/**
	 * Template method overloading left divide operator.
	 *
	 * \tparam T Input NUMBER on the left needed to be divide by TaintedInt, not safe with other input types
	 * \param TaintedInt& TaintedInt itself on the right
	 * \return New TaintedInt with divided value
	 */
	template <typename T>
	friend TaintedInt operator /(const T, const TaintedInt&);

	/**
	 * Overload divide operator to divide by TaintedInt.
	 * Will get tainted status if one of the input is tainted
	 *
	 * \param TaintedInt Tainted int that need to be divided
	 * \return New TaintedInt with divided value
	 */
	TaintedInt operator/ (const TaintedInt&) const; // multiply by tainted int
	

	// -------------------------------------------------- //
	// ------   Here goes member-access overload   ------ //
	// -------------------------------------------------- //
	/**
	 * Overload address-of operator to get tainted status.
	 * 
	 * \return bool 1 for tained. 0 for not.
	 */
	bool operator& (); // returns true iff tainted
	/**
	 * Overload indirection operator to only get value of TaintedInt.
	 * 
	 * \return int value of TaintedInt
	 */
	int operator* (); // Dereference return the int number
	

	// -------------------------------------------------- //
	// ------   Here goes in/decrement overload    ------ //
	// -------------------------------------------------- //
	/**
	 * Prefix increment by 1.
	 */
	TaintedInt& operator++ (); // prefix
	/**
	 * Postfix increment by 1.
	 */
	TaintedInt operator++ (int); // postfix



	// -------------------------------------------------- //
	// --------   Here goes typecast overload    -------- //
	// -------------------------------------------------- //
	/**
	 * operator double: implicit cast TaintedInt to double. Tainted status will be lost.
	 * 
	 * \return double TaintedInt value
	 */
	//operator double() const;

	/**
	 * operator double: implicit cast TaintedInt to T. Tainted status will be lost.
	 *
	 * \return T TaintedInt value
	 */
	template <typename T>
	operator T() const;

	// out stream overload
	friend std::ostream& operator<<(std::ostream&, const TaintedInt&);


	// -------------------------------------------------- //
	// ---Here goes interaction with private property---- //
	// -------------------------------------------------- //
	/**
	 * get private value tint.
	 * 
	 * \return int value
	 */
	int getNumber() const { return tint; }

	/**
	 * set private value tint.
	 * 
	 * \param i value to be set
	 */
	void setNumber(const int i) { tint = i; }

	/**
	 * get private value btainted.
	 *
	 * \return bool tainted status
	 */
	bool checkTainted() const { return btainted; }

	/**
	 * set private value btainted.
	 *
	 * \param b tainted status to be set
	 */
	void setTaint(const bool b = 1) { btainted = b; }		// for call by object

	/**
	 * \brief static method to set TaintedInt tainted.
	 */
	static void taint(TaintedInt& t) { t.setTaint(); } // for static call by class name 

private:
	int tint; // value of taintedInt
	bool btainted; // tainted status of taintedInt, 0 for untainted
};

template<typename T>
inline TaintedInt TaintedInt::operator+(const T num) const
{
	TaintedInt temp (this->getNumber() + num);
	temp.setTaint(this->checkTainted());
	return temp;
}

template<typename T>
inline TaintedInt operator+(const T num, const TaintedInt& tint)
{
	TaintedInt temp = tint;
	temp.setNumber(tint.getNumber() + (int)num);
	return temp;
}

template<typename T>
inline TaintedInt TaintedInt::operator-(const T num) const
{
	TaintedInt temp(this->getNumber() - num);
	temp.setTaint(this->checkTainted());
	return temp;
}

template<typename T>
inline TaintedInt operator-(const T num, const TaintedInt& tint)
{
	TaintedInt temp = tint;
	temp.setNumber((int)num - tint.getNumber());
	return temp;
}

template<typename T>
inline TaintedInt TaintedInt::operator*(const T num) const
{
	TaintedInt temp = *this;
	temp.setNumber(temp.getNumber() * num);
	return temp;
}

template<typename T>
inline TaintedInt operator*(const T num, const TaintedInt& tint)
{
	TaintedInt temp = tint;
	temp.setNumber((int)num * tint.getNumber());
	return temp;
}

template<typename T>
inline TaintedInt TaintedInt::operator/(const T num) const
{
	TaintedInt temp = *this;
	temp.setNumber(temp.getNumber() / num);
	return temp;
}
template<typename T>
inline TaintedInt operator/(const T num, const TaintedInt& tint)
{
	TaintedInt temp = tint;
	temp.setNumber((int)num / tint.getNumber());
	return temp;
}

template<typename T>
inline TaintedInt::operator T() const
{
	return (T)this->getNumber();
}
