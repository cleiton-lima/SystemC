#include "systemc.h"


SC_MODULE(somador_bool)
{
	sc_in<sc_uint<8> > A;
	sc_in<sc_uint<8> > B;
	sc_out<sc_uint<8> > result;
	
	sc_uint<8> aux;

	void test_sum(){
		
		aux = A.read() + B.read();

		result.write(aux);
	}

	SC_CTOR(somador_bool)
	{
		SC_METHOD(test_sum);
		sensitive << A << B; 
	}
};