#include <systemc.h>

SC_MODULE (signal_bind) {
  sc_in<bool> clock;

  void do_test() {
    wait();
    cout << "@" << sc_time_stamp() <<endl;
    wait();
    wait();
    cout << "@" << sc_time_stamp() <<endl;
    wait();
    wait();
    cout << "@" << sc_time_stamp() <<endl;
    wait();
    sc_stop();
  }

  SC_CTOR(signal_bind) {
    SC_CTHREAD(do_test,clock);
  }
}; 

int sc_main (int argc, char* argv[]) {
  sc_clock clock ("my_clock");

  signal_bind object("SIGNAL_BIND");
  object.clock(clock);
  
  sc_start(1,SC_NS);
  cout<< "Fim do sc_start(1): "
            << sc_time_stamp() <<endl;
  
  sc_start(3,SC_NS);
  cout<< "Fim do sc_start(3): "
            << sc_time_stamp() <<endl;
  
  sc_start();
  cout<< "Fim do sc_start(): "
            << sc_time_stamp() <<endl;
  return 0;
}
