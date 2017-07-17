#include "systemc.h"

SC_MODULE(dff)
{
	sc_in <bool> din;
	sc_in <bool> clk;
	sc_out <bool> out;

	void implement()
	{
		   out = din;
	}

	SC_CTOR(dff)
	{
		SC_METHOD(implement);
		sensitive_pos << clk; //CLOCK -> MUDANÇA DE SINAL
	}
};