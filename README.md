# Int-Tracker

## Content
- [Int-Tracker](#int-tracker)
  - [Content](#content)
  - [Brief](#brief)
  - [How to use](#how-to-use)
    - [Example](#example)
  - [Files](#files)

## Brief
A cpp class defines a TaintedInt class. It behaves like a int but can be marked "tainted" and follow through all calculation process. You can use this to mark and track int variables.

## How to use

### Example
The [Obfuscated.cpp](Obfuscated.cpp) is a example of using TaintedInt class. 

The original version of the code is like this:  
``` c++
for (srand(0); i;)
	j = j ? --i < 1 && a >> 8 ? 0 : (putchar(i ? (int)t[j] : a), i++) ? t[j] = t[--i] + 1, i > 2 ? rand() % (i - 2) + 2 : 1 : 0	: (26 > ((a = (++x < ins.length() ? ins.at(x) : EOF)) | 32) - 97 || 1 == a >> 7) && i < 64 ? t[i + ins.length()] = t[i++] = a + t[0], 0 : 1;
```

It is a code from international obfuscated c code contest, and is nearly impossible to tell what it is doing.

With the tracker, for example, we can track the first 10 number from array `t[]` and see how they end up changing the values in array `t[]`.

``` console
0                       -858993460 [tainted] 
1                       -858993460 [tainted]
2                       -858993460 [tainted]
3                       -858993460 [tainted]
4                       -858993460 [tainted]
5                       -858993460 [tainted]
6                       -858993460 [tainted]
7                       -858993460 [tainted]
8                       -858993460 [tainted]
9                       -858993460 [tainted]     
```

This shows how this class track numbers and the calculation they involved.

## Files
The header file [TaintedInt.h](TaintedInt.h) is well documented and explained. 

Here is part of the documentation:
``` c++
/**
 * \brief A class behave like integer but with a tainted method to mark the int even after calculations. 
 * TaintedInt can be involved into calculations just like an int number; 
 * It can be set as "tainted". 
 * In any calculation, if any input TaintedInt is "tainted", the output TaintedInt will be Tainted too. 
 */
class TaintedInt 
{
    ...
    /**
	 * Template method overloading left plus operator.
	 *
	 * \tparam T Input NUMBER on the left needed to be added to TaintedInt, not safe with other input types
	 * \param TaintedInt& TaintedInt itself on the right
	 * \return New TaintedInt with added up value
	 */
	template <typename T>
	friend TaintedInt operator +(const T, const TaintedInt&);
    ...
}
```

The implementatin is in [TaintedInt.cpp](TaintedInt.cpp).

The [main.cpp](main.cpp) is a simple testfile integrated with [Obfuscated.cpp](Obfuscated.cpp).