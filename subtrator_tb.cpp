#include "systemc.h"

SC_MODULE(somador_tb)
{
	sc_in<bool>	clk;
	sc_out<sc_uint<8> > A;
	sc_out<sc_uint<8> > B;
	sc_in<sc_uint<8> > result;

	void test(){
		cout << "here!1" << endl;
	    A.write(10);
	    B.write(10);
	    wait();
	    wait();

		cout << "here!2" << endl;
	    A.write(5);
	    B.write(4);
	    wait();
	    wait();
		
		cout << "here!3" << endl;
	    A.write(10);
	    B.write(8);
	    wait();
	    wait();
		
		cout << "here!4" << endl;
	    A.write(3);
	    B.write(2);
	    wait();
	    wait();

		cout << "here!5" << endl;
	    A.write(10);
	    B.write(2);
	    wait();
	    wait();

		cout << "here!6" << endl;
	    A.write(20);
	    B.write(8);
	    wait();
	    wait();

		cout << "here!7" << endl;
	    A.write(10);
	    B.write(2);
	    wait();

	    sc_stop();
	}

	void print_result(){
		cout << ">>Result: " << result << "\tTime: " << sc_time_stamp() << endl;
	}
	
	SC_CTOR(somador_tb)
	{
		SC_THREAD(test);
		sensitive << clk.pos();

		SC_METHOD(print_result);
		sensitive << result;
	}
};
