#include <systemc.h>
using namespace sc_core;

SC_MODULE(ports_access){
  sc_in<bool> a;
  sc_in<bool> b;
  sc_in<bool> en;
  sc_out<sc_lv<2> > out;

  void body(){
  	if(en.read() == 1){
  		out.write(a.read() + b.read());
  	}
  }

  void print_result(){
  	cout << ">>Resultado: " << out << "\tTempo: " << sc_time_stamp() << endl;
  }

  SC_CTOR(ports_access){
  	SC_METHOD(body);
  		sensitive << a << b << en;

  	SC_METHOD(print_result);
  		sensitive << out;
  }
 };

 int sc_main(int argc, char* argv[]){
 	sc_signal<bool> a;
 	sc_signal<bool> b;
 	sc_signal<bool> en;
 	sc_signal<sc_lv<2> > out;

 	ports_access port("PORT");
 	port.a(a);
 	port.b(b);
 	port.en(en);
 	port.out(out);

 	sc_start(1, SC_NS);
 	a = 1;
 	b = 0;
 	en = 1;
 	sc_start(1, SC_NS);
 	a = 1;
 	b = 1;
 	en = 1;
 	sc_start(1, SC_NS);
 	a = 1;
 	b = 0;
 	en = 1;
	sc_start(2, SC_NS);
 	
	cout << "Tempo de Simulação: " << sc_time_stamp() << endl;

 }