#include "systemc.h"

SC_MODULE(mealy1){
	sc_in<bool> clk, reset, a;

	sc_out<bool> z;

	enum state_type {S0=0xE, S1=0xD, S2=0xB, S3=0x7};

	sc_signal<state_type> mealy_state, next_state;

	void prc_state();
	void prc_output();

	SC_CTOR(mealy1){
		SC_METHOD (prc_state);
		sensitive_neg << clk;
		sensitive_pos << reset;

		SC_METHOD(prc_output);
		sensitive << mealy_state << a;
	}
};