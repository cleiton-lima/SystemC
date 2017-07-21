#include "systemc.h"


SC_MODULE(mult1)
{
	sc_in<sc_uint<8> > A;
	sc_in<sc_uint<8> > B;
	sc_in<sc_uint<8> > C;
	sc_in<sc_uint<8> > D;
	sc_in<sc_uint<8> > E;
	sc_in<sc_uint<8> > nulo;
	sc_in<sc_uint<8> > seletor;
	sc_out<sc_uint<8> > result;
	

	void test_selet(){
		switch (seletor.read()){
			case(1):
				result.write(A);
				break;
			case(2):
				result.write(B);
				break;
			case(3):
				result.write(C);
				break;
			case(4):
				result.write(D);
				break;
			case(5):
				result.write(E);
				break;
			default:
				result.write(nulo);
				break;
		}
		
	}

	SC_CTOR(mult1)
	{
		SC_METHOD(test_selet);
		sensitive << seletor; 
	}
};
