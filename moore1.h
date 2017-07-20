#include "systemc.h"

SC_MODULE(moore1){
	sc_in<bool> a, clk, reset;

	sc_out<bool> z;

	enum state_type {s0, s1, s2, s3};

	sc_signal<state_type> moore_state;

	void pcr_moore(){
		if(reset)
			moore_state = s0;
		else
			switch (moore_state){
				case s0: z = 1; moore_state = a ? s0 : s2; break;
				case s1: z = 0; moore_state = a ? s0 : s2; break;
				case s2: z = 0; moore_state = a ? s2 : s3; break;
				case s3: z = 1; moore_state = a ? s1 : s3; break;
			}

			cout << moore_state<<endl;
		}

		SC_CTOR(moore1){
			SC_METHOD (pcr_moore);
			sensitive<< clk;
		}
	};