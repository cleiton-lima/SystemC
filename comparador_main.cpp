#include "comparador.cpp"
#include "comparador_tb.cpp"

using namespace sc_core;

int sc_main(int argc, char* argv[])
{
	sc_clock clk("clk", 2, SC_NS);
	sc_signal<sc_uint<8> > A;
	sc_signal<sc_uint<8> > B;
	sc_signal<bool> result;
	
	comparador_tb comparador_tb("comparador_tb");
	comparador_tb.clk(clk);
	comparador_tb.A(A);
	comparador_tb.B(B);
	comparador_tb.result(result);

	comparador comparador("comparador");
	comparador.A(A);
	comparador.B(B);
	comparador.result(result);

	sc_start(100, SC_NS);
}
