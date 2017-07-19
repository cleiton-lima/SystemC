#include "systemc.h"
using namespace sc_core;


SC_MODULE(nand)
{
	sc_in<bool > A;
	sc_in<bool > B;
	sc_out<bool> result;
	
	bool aux;

	void test_nand(){
		
		aux = !(A.read() & B.read());

		result.write(aux);
	}

	SC_CTOR(nand)
	{
		SC_METHOD(test_nand);
		sensitive << A << B; 
	}
};
