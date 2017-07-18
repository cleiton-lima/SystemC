#include "systemc.h"
using namespace sc_core;

SC_MODULE(comparador)
{
	sc_in<sc_uint<8> > A;
	sc_in<sc_uint<8> > B;
	sc_out<bool> result;
	
	bool aux;

	void test_comp(){
		
		aux = A.read() == B.read();

		result.write(aux);
	}

	SC_CTOR(comparador)
	{
		SC_METHOD(test_comp);
		sensitive << A << B; 
	}
};
