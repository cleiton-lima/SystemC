#include "modulo_po.h"

int sc_main(int argc, char* argv[])
{
	//entrada
	sc_signal<bool> ew;
	sc_signal<bool> cr;
	sc_signal<sc_uint<8> > sv;
	sc_signal<sc_uint<8> > st;
	sc_signal<bool> so;
	sc_clock clk("teste");

	//saída
	sc_signal<bool> ok;
	sc_signal<sc_uint<8> > troco;
	sc_signal<sc_uint<8> > refri;

	po po_projeto ("maquina_refri");

	po_projeto.ew(ew);
	po_projeto.cr(cr);
	po_projeto.sv(sv);
	po_projeto.st(st);
	po_projeto.so(so);
	po_projeto.clk(clk);

	po_projeto.ok(ok);
	po_projeto.troco(troco);
	po_projeto.refri(refri);

	ew = 1;
	cr = 0;
	sv = 5;
	st = 2;
	so = 1;
	
	sc_start();


}