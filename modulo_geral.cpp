#include "mux1.cpp"

SC_MODULE(nand_maior)
{
	sc_in<bool > A;
	sc_in<bool > B;
	sc_out<bool> result;

	sc_signal<bool> s1,s2;

	nand nand1, nand2, nand3;

	SC_CTOR(nand_maior): nand1("s1"), nand2("s2"), nand3("x"){
		nand1.A(A);
		nand1.B(B);
		nand1.result(s1);

		nand2.A(A);
		nand2.B(B);
		nand2.result(s2);

		nand3.A(s1);
		nand3.B(s2);
		nand3.result(result);
	}

	
}