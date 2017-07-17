#include "systemc.h"

SC_MODULE(somador)
{
	sc_in<sc_uint<8> > a;
	sc_in<sc_uint<8> > b;
	sc_out<sc_uint<8> > result;

	sc_unit<8> aux;

	void test_sum()
	{
		aux = a.read() + b.read();

		result.write(aux);
	}

	SC_CTOR(somador)
	{
		SC_METHOD(test_sum);
		sensitive << a << b;
	}
};