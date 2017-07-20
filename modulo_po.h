#include "somador_bool.h"
#include "comparador.h"
#include "subtrator.h"
#include "mult1.h"
#include "registrador_clock.h"
#include "mux.h"

SC_MODULE(po){
	sc_in<bool> ew;
	sc_in<bool> cr;
	sc_in<sc_uint<8> > sv;
	sc_in<sc_uint<8> > st;
	sc_in<bool> so;
	sc_in<bool> clk;

	sc_out<bool> ok;
	sc_out<sc_uint> > troco;
	sc_out<bool> refri;

	somador_bool somador;
	comparador comp;
	subtrator subt;
	mult1 m1;
	mult2 m2;
	registrador_clock registrador1;
	registrador_clock registrador2;
	mux mu1;
	mux mu2;

	//sinais do somador
	sc_signal<sc_uint<8> > valor_in;
	sc_signal<sc_uint<8> > valor_parcial;
	sc_signal<sc_uint<8> > sona_result;
	
	//sinais do comparador
	sc_signal<bool> saida;

	//sinais do subtrator
	sc_signal<sc_uint<8> > valor_refri;
	sc_signal<sc_uint<8> > sub_result;

	//OBS: CRIAR OS SINAIS PROS MULTIPLEXADORES

	SC_CTOR(po) : somador("somador"), comp("comparador"), subt("subtrator"), m1("mult1"), m2("mult2"), registrador1("registrador1"), registrador2("registrador2"),
		mu1("mux1"), mu2("mux2")
	{

	}

}