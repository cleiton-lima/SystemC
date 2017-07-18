#include <systemc.h>
using namespace sc_core;

SC_MODULE(ports_arrays){
  sc_in<sc_uint<2> > a[4];
  sc_in<sc_uint<2> > b[4];
  sc_out<sc_uint<3> > out[4];

  void body(){
    for(int i = 0; i < 4; ++i){
      out[i].write(a[i].read() + b[i].read());
    }
  }

  void print_result(){
    cout << "Tempo: " << sc_time_stamp() << " Resultado: ";
    for(int i = 0; i < 4; ++i){
      cout << out[i] << " ";
    }
    cout << endl;
  }

  SC_CTOR(ports_arrays){
    SC_METHOD(body);
    for(int i = 0; i < 4; ++i){
      sensitive << a[i] << b[i];
    }
    

    SC_METHOD(print_result);
    for(int i = 0; i < 4; ++i){
      sensitive << out[i];
    } 
  }
 };

 int sc_main(int argc, char* argv[]){
  sc_signal<sc_uint<2> > a[4];
    sc_signal<sc_uint<2> > b[4];
    sc_signal<sc_uint<3> > out[4];

  ports_arrays port("PORTS_ARRAYS");
  for(int i = 0; i < 4; ++i){
      port.a[i](a[i]);
    port.b[i](b[i]);
    port.out[i](out[i]);
    }
  
  sc_start(1, SC_NS);
  a[0] = 1;a[1] = 1;a[2] = 1;a[3] = 0;
  b[0] = 1;b[1] = 0;b[2] = 1;b[3] = 1;
  
  sc_start(1, SC_NS);
  a[0] = 1;a[1] = 1;a[2] = 0;a[3] = 1;
  b[0] = 0;b[1] = 1;b[2] = 1;b[3] = 1;

  sc_start(2, SC_NS);
  
  cout << "Tempo de Simulação: " << sc_time_stamp() << endl;

 }