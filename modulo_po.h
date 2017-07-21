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
	sc_out<sc_uint<8> > troco;
	sc_out<sc_uint<8> > refri;

	somador_bool somador;
	comparador comp;
	subtrator subt;
	mult1 m1;
	mult1 m2;
	registrador registrador1;
	mux mu1;
	mux mu2;

	//sinais do somador
	sc_signal<sc_uint<8> > valor_in;
	sc_signal<sc_uint<8> > valor_parcial;
	sc_signal<sc_uint<8> > soma_result;
	
	//sinais do comparador
	sc_signal<bool> saida;

	//sinais do subtrator
	sc_signal<sc_uint<8> > valor_refri;
	sc_signal<sc_uint<8> > sub_result;

	//MULTIPLEXADORES COM OS VALORES DOS REFRIGERANTES
	sc_signal<sc_uint<8> > valor_25;
	sc_signal<sc_uint<8> > valor_50;
	sc_signal<sc_uint<8> > valor_1;
	sc_signal<sc_uint<8> > valor_2;
	sc_signal<sc_uint<8> > valor_5;
	sc_signal<sc_uint<8> > valor_0;

	//MULTIPLEXADORES COMS OS NOMES DOS REFRIGERANTES
	sc_signal<sc_uint<8> > refri_t1;
	sc_signal<sc_uint<8> > refri_t2;
	sc_signal<sc_uint<8> > refri_t3;
	sc_signal<sc_uint<8> > refri_t4;
	sc_signal<sc_uint<8> > refri_t5;
	sc_signal<sc_uint<8> > refri_nulo;


	sc_signal<sc_uint<8> > zero;


	SC_CTOR(po) : somador("somador"), comp("comparador"), subt("subtrator"), m1("mult1"), m2("mult2"), registrador1("registrador1"),
		mu1("mux1"), mu2("mux2")
	{
		//SOMADOR
		somador.A(valor_in);
		somador.B(valor_parcial);
		somador.result(soma_result);

		//COMPARADOR
		comp.result(saida);
		comp.A(valor_parcial);
		comp.B(valor_refri);

		//SUBTRATOR
		subt.A(valor_refri);
		subt.B(valor_parcial);
		subt.result(sub_result);

		//MUX1 COM OS VALORES SETADOS
		valor_25 = 25;
		valor_50 = 50;
		valor_1 = 1;
		valor_2 = 2;
		valor_5 = 5;
		valor_0 = 0;

		//MUX1 PEGANDO OS VALORES POR MEIO DO SELETOR
		m1.seletor(sv);
		m1.A(valor_25);
		m1.B(valor_50);
		m1.C(valor_1);
		m1.D(valor_2);
		m1.E(valor_5);
		m1.nulo(valor_0);
		m1.result(valor_in);

		//MUX2 COM OS VALORES SETADOS
		refri_t1 = 1;
		refri_t2 = 2;
		refri_t3 = 3;
		refri_t4 = 4;
		refri_t5 = 5;
		refri_nulo = 0;

		//MUX2 PEGANDO OS VALORES POR MEIO DO SELETOR
		m2.seletor(st);
		m2.A(refri_t1);
		m2.B(refri_t2);
		m2.C(refri_t3);
		m2.D(refri_t4);
		m2.E(refri_t5);
		m2.nulo(refri_nulo);
		m2.result(valor_refri);
		//MUX1 PEQUENO
		zero = 0;
		mu1.A(zero);
		mu1.B(sub_result);
		mu1.seletor(so);
		mu2.result(troco);

		mu2.A(zero);
		mu2.B(valor_refri);
		mu2.seletor(so);
		mu2.result(refri);

		registrador1.clock(clk);
		registrador1.opera(ew);
		registrador1.clear(cr);
		registrador1.value_in(soma_result);
		registrador1.value_out(valor_parcial);


	}

};