#include "moore1.h"

int sc_main(int argc, char* argv[]){
	sc_signal<bool> a;
	sc_signal<bool> reset;
	sc_clock clock("clock");

	sc_signal<bool> saida;

	moore1 aux("maquina");
	aux.a(a);
	aux.reset(reset);
	aux.clk(clock);
	aux.z(saida);

	a = 1;
	sc_start(1,SC_NS);

	a = 0;
	sc_start(1,SC_NS);

	a = 1;
	sc_start(1,SC_NS);

	a = 0;
	sc_start(1,SC_NS);

}

