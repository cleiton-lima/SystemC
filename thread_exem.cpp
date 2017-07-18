#include "systemc.h"

SC_MODULE (first_counter){
	sc_in_clk clock;
	sc_in<bool> reset;
	sc_in<bool> enable;
	sc_out<sc_uint<4> counter_out;

	sc_uint<4> count;

	void incr_count(){
		while(true){
			wait();
			cout<<"@" << sc_time_stamp() <<
			" :: Counter Value "<<counter_out.read()<<endl;
		}
	}

	SC_CTOR(first_counter){
		SC_THREAD(incr_count);
		sensitive << clock.pos();

		SC_THREAD(print_count);
		sensitive << counter_out;
	}
}