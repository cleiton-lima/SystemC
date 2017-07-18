#include "systemc.h"

SC_MODULE (first_counter)
{
	sc_in_clk clock;
	sc_in<bool> reset;
	sc_in<bool> enable;
	sc_out<sc_unit<4> > counter_out;

	sc_uint<4> count;

	void incr_count ()
	{
		if (reset.read() == 1){
			count = 0;
			counter_out.write(count);
		} else if (enable.read() == 1){
			count = count + 1;
			counter_out.write(count);
		}
	}

	void print_count(){
		cout<<"@" << sc_time_stamp() << " :: Counter Value "<<counter_out.read()<<endl;		
	}

	SC_CTOR(first_counter){
		SC_METHOD(incr_count);
		sensitive << reset;
		sensitive << clock.pos();

		SC_METHOD(print_count);
		sensitive << counter_out;
	}
}