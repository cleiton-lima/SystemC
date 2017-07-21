#include <systemc.h>

SC_MODULE (registrador) {
	sc_in_clk clock;
	sc_in <bool> opera; // 1 = escrita; 0 = leitura.
	sc_in <bool> clear;
	sc_in < sc_uint<8> > value_in;
	sc_out < sc_uint<8> > value_out;

	sc_uint<8> value;

	void regis(){
		if(opera.read() == 1)
		{	
			if(clear.read() == 1)
				value = 0;
			else
				value = value_in.read();

			value_out.write(0);
		}
		else
		{
			if(clear.read() == 1)
				value = 0;
			else
				value_out.write(value);

		}
	}

	SC_CTOR(registrador){
		SC_METHOD(regis);
		sensitive << clock.pos();
		sensitive << clear, opera;
		
	}
};