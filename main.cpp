#include <iostream>
#include <string>
#include "TaintedInt.h"

void obfs(std::string ins);

int main(int argc, char* argv[]) {
	TaintedInt taintedInt0 (2);
	TaintedInt taintedInt1 = 3;
	TaintedInt taintedInt2 = 4;
	TaintedInt taintedInt3 = 5;

	int i0 = 2;
	int i1 = 3;

	std::cout << "i0  =\t" << i0 << std::endl;
	std::cout << "i1  =\t" << i1 << std::endl;
	std::cout << "taintedInt0  =\t" << taintedInt0 << std::endl;
	std::cout << "taintedInt1  =\t" << taintedInt1 << std::endl;
	std::cout << "taintedInt0 + i0  =\t" << taintedInt0 + i0 << std::endl;
	std::cout << "taintedInt0 + 0.3  =\t" << taintedInt0 + 0.3 << std::endl;
	std::cout << "taintedInt1 - i1  =\t" << taintedInt1 - i1 << std::endl ;
	std::cout << "taintedInt1 - 0.3  =\t" << taintedInt1 - 0.3 << std::endl;
	std::cout << "-taintedInt1  =\t" << - taintedInt1 << std::endl << std::endl;

	TaintedInt::taint(taintedInt0);
	taintedInt1.setTaint();
	std::cout << "taintedInt0  =\t" << taintedInt0 << std::endl;
	std::cout << "taintedInt1  =\t" << taintedInt1 << std::endl;
	std::cout << "i0 + i1  =\t" << i0 + i1 << std::endl;
	std::cout << "taintedInt0 + i1  =\t" << taintedInt0 + i1 << std::endl;
	std::cout << "*taintedInt0 + i1  =\t" << *taintedInt0 + i1 << std::endl << std::endl;

	std::cout << "taintedInt0  =\t" << taintedInt0 << std::endl;
	std::cout << "taintedInt0 ++  =\t" << taintedInt0++ << std::endl;
	std::cout << "+ taintedInt0  =\t" << +taintedInt0 << std::endl;
	std::cout << "++ taintedInt0  =\t" << ++taintedInt0 << std::endl;
	std::cout << "taintedInt0 * taintedInt1 =\t" << taintedInt0 * taintedInt1 << std::endl;
	std::cout << "taintedInt0 * i0 =\t" << taintedInt0 * i0 << std::endl;
	std::cout << "(2 - 3) + taintedInt0 * 0 =\t" << (2 - 3) + taintedInt0 * 0 << std::endl;
	std::cout << "(2 - 3) + 6 * taintedInt0 =\t" << (2 - 3) + 6 * taintedInt0 << std::endl;
	std::cout << "0.3 + taintedInt0 =\t" << 0.3 + taintedInt0 << std::endl;

	std::cout << "log2((double)taintedInt0) =\t" << log2((double)taintedInt0) << std::endl;
	std::cout << "(double)taintedInt0 =\t" << (double)taintedInt0 << std::endl;
	std::cout << "(float)taintedInt0 * 0.3 =\t" << (float)taintedInt0 * 0.3 << std::endl;
	std::cout << "(taintedInt0 = taintedInt0) =\t" << (taintedInt0 = taintedInt0) << std::endl << std::endl;


	std::string str = "70682198: EC500 is awesome!";
	//std::cout << str << std::endl;
	obfs(str);
	std::cout << str << std::endl;
	
}

