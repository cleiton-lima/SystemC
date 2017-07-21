#include "systemc.h"

SC_MODULE(subtrator)
{
	sc_in<sc_uint<8> > A;
	sc_in<sc_uint<8> > B;
	sc_out<sc_uint<8> > result;
	
	sc_uint<8> aux;

	void test_sub(){
		
		aux = A.read() - B.read();

		result.write(aux);
	}

	SC_CTOR(subtrator)
	{
		SC_METHOD(test_sub);
		sensitive << A << B; 
	}
};