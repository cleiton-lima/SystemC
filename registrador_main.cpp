#include "systemc.h"
#include "registrador_clock.h"
#include "registrador_tb.h"


int sc_main(int argc, char* argv[])
{
	sc_clock clk("clk", 2, SC_NS);
	sc_signal<bool> clear;
	sc_signal<bool> opera;
	sc_signal<sc_int<8> > value_in;
	sc_signal<sc_int<8> > value_out;

	registrador_tb registrador_tb1("REGISTRADOR_TB");
	registrador_tb1.clock(clk);
	registrador_tb1.clear(clear);
	registrador_tb1.opera(opera);
	registrador_tb1.value_in(value_in);
	registrador_tb1.value_out(value_out);


	registrador registrador1("REGISTRADOR");
	registrador1.clock(clk);
	registrador1.clear(clear);
	registrador1.opera(opera);
	registrador1.value_in(value_in);
	registrador1.value_out(value_out);

	sc_start(100, SC_NS);

}