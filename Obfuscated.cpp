#include "TaintedInt.h"


void printarray(TaintedInt tt[]);

void obfs(std::string ins) {
	unsigned x = 0, a, i = 1, j = 0, t[64];
	TaintedInt tt[64];
	for (int itr = 0; itr < 64; itr++)
	{
		tt[itr] = t[itr];
	}
	for (int itr = 0; itr < 10; itr++) // first 10 tainted
	{
		TaintedInt::taint(tt[itr]);
	}
	printarray(tt);
	//for (srand(0); i;)
	//	j = j ? --i < 1 && a >> 8 ? 0 : (putchar(i ? (int)t[j] : a), i++) ? t[j] = t[--i] + 1, i > 2 ? rand() % (i - 2) + 2 : 1 : 0
	//	: (26 > ((a = (++x < ins.length() ? ins.at(x) : EOF)) | 32) - 97 || 1 == a >> 7) && i < 64 ? t[i + ins.length()] = t[i++] = a + t[0], 0 : 1;
	for (srand(0); i;)
		j = j ? --i < 1 && a >> 8 ? 0 : (putchar(i ? (int)tt[j] : a), i++) ? tt[j] = tt[--i] + 1, i > 2 ? rand() % (i - 2) + 2 : 1 : 0
		: (26 > ((a = (++x < ins.length() ? ins.at(x) : EOF)) | 32) - 97 || 1 == a >> 7) && i < 64 ? tt[i + ins.length()] = tt[i++] = a + tt[0], 0 : 1;
	printarray(tt);
}

void printarray(TaintedInt tt[])
{
	std::cout << std::endl;
	for (int i = 0; i < 64; i++)
	{
		std::cout << i  << "\t\t\t" << tt[i] << std::endl;
	}
}