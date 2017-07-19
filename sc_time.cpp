#include <systemc.h>

int sc_main (int argc, char* argv[]) {
	sc_set_time_resolution(1,SC_MS);	//Alterando a resolucao para 1 ms
	sc_time t1(1,SC_SEC);				//1 seg = 1000 ms
	sc_time t2(0.1,SC_SEC);				//0.1 seg = 100 ms
	sc_time t3(1,SC_MS);				//1 ms
	sc_time t4(1,SC_US);				//1 micseg = 10^-3 ms
	sc_time t5(1001,SC_US);				//1001 micseg = 1.001 ms
	sc_time t6;							//Construtor vazio, considera-se 0 segundos

	std::cout <<"Valor do t1 -> "<< t1 << std::endl;
	std::cout <<"valor do t2 -> "<< t2 << std::endl;
	std::cout <<"valor do t3 -> "<< t3 << std::endl;
	std::cout <<"valor do t4 -> "<< t4 << std::endl;
	std::cout <<"valor do t5 -> "<< t5 << std::endl;
	std::cout <<"valor do t6 -> "<< t6 << std::endl;

	return 0;
}