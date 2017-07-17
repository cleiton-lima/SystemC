#include "dff.h"

using namespace sc_core;

int sc_main(int argc, char** argv)
{
	sc_signal<bool> sclk;
	sc_signal<bool> sin;
	sc_signal<bool> sout;

	dff var("Nome");
	var.clk(sclk);
	var.din(sin);
	var.out(sout);

	sclk = 0;
	sin = 0;
	cout<<"Saída: "<<sout<<endl;

	sc_start(1, SC_NS);

	sclk = 1;
	sin = 1;
	sc_start(1, SC_NS);
	cout<<"Saída: "<<sout<<endl;

	

	sclk = 0;
	sin = 1;
	sc_start(1, SC_NS);
	cout<<"Saída: "<<sout<<endl;

	

	sclk = 0;
	sin = 0;
	sc_start(1, SC_NS);
	cout<<"Saída: "<<sout<<endl;

	

	return 0;
}