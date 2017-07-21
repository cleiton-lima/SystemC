#include "systemc.h"

SC_MODULE(mux)
{
	sc_in<sc_uint<8> > A;
	sc_in<sc_uint<8> > B;
	sc_in<bool> seletor;
	sc_out<sc_uint<8> > result;
	

	void test_selet(){
		switch (seletor.read()){
			case(1):
				result.write(A);
				break;

			default:
				result.write(B);
				break;
		}
		
	}

	SC_CTOR(mux)
	{
		SC_METHOD(test_selet);
		sensitive << seletor; 
	}
};
