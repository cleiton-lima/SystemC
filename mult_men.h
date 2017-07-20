#include "systemc.h"
using namespace sc_core;

SC_MODULE(mult1)
{
	sc_in<sc_uint<8> > A;
	sc_in<sc_uint<8> > B;
	
	

	void test_selet(){
		switch (seletor){
			case(1):
				result.write(A);
				break;

			default:
				result.write(B);
				break;
		}
		
	}

	SC_CTOR(mult1)
	{
		SC_METHOD(test_selet);
		sensitive << seletor; 
	}
};
