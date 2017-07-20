#include "systemc.h"

SC_MODULE(moore1){
	sc_in<bool> a, clk, reset;

	sc_out<bool> z;

	enum state_type {s0, s1, s2, s3};

	sc_signal<state_type> moore_state;

	void pcr_moore();

	SC_CTOR(moore1){
		SC_METHODE (pcr_moore);
		sensitive_pos << clk;
	}
};