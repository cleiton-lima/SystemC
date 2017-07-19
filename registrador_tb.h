#include <systemc.h>

SC_MODULE(registrador_tb)
{
	sc_in_clk clock;
	sc_out <bool> opera; // 1 = escrita; 0 = leitura.
	sc_out <bool> clear;
	sc_out < sc_int<8> > value_in;
	sc_in < sc_int<8> > value_out;

	void test_regis()
	{
		cout << "--Armazenando o valor 10." << endl;
		opera.write(1);
		clear.write(0);
		value_in.write(10);
		wait();
		wait();

		cout << "--Lendo o valor armazenado." << endl;
		opera.write(0);
		clear.write(0);
		value_in.write(10); //Aqui pode colocar qualquer valor, ja que nessa operação essa porta não tem utilidade.
		wait();
		wait();

		cout << "--Zerando o registrador." << endl;
		opera.write(0); // Aqui pode ser 0 ou 1, tanto faz.
		clear.write(1);
		value_in.write(10); //Aqui pode colocar qualquer valor.
		wait();
		wait();

		cout << "--Lendo novamente o registrador após ele ser zerado." << endl;
		opera.write(0); 
		clear.write(0);
		value_in.write(10); //Aqui pode colocar qualquer valor.
		wait();
		sc_stop();	
	}

	void print_registrador()
	{
		if(opera == 0)
			cout << ">>>>>Valor armazenado: " << value_out << "\tTime: " << sc_time_stamp() << endl;
	}

	SC_CTOR(registrador_tb)
	{
		SC_THREAD(test_regis);
		sensitive << clock.pos();

		SC_METHOD(print_registrador);
		sensitive << value_out;
	}
};
	