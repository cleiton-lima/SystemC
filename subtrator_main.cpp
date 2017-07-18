#include "subtrair.cpp"
#include "subtrator_tb.cpp"

using namespace sc_core;

int sc_main(int argc, char* argv[])
{
	sc_clock clk("clk", 2, SC_NS);
	sc_signal<sc_uint<8> > A;
	sc_signal<sc_uint<8> > B;
	sc_signal<sc_uint<8> > result;
	
	somador_tb somador_tb("SOMADOR_TB");
	somador_tb.clk(clk);
	somador_tb.A(A);
	somador_tb.B(B);
	somador_tb.result(result);

	somador somador("SOMADOR");
	somador.A(A);
	somador.B(B);
	somador.result(result);

	sc_start(100, SC_NS);
}
