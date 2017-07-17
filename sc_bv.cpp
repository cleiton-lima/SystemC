#include <systemc.h>

int sc_main (int argc, char* argv[])
{
	sc_bv<8> data_bus;
	sc_bv<16> addr_bus;
	bool paraty;

	data_bus = "00001011";
	cout << "Value of data data_bus: " << data_bus << endl;

	addr_bus.range(7,0) = data_bus;
	cout << "Value of addr_bus: " << addr_bus << endl;

	addr_bus.range(0,7) = data_bus;
	cout << "Value of addr_bus: " << addr_bus << endl;

	addr_bus[10] = "1";
	cout << "Value of addr_bus: " << addr_bus << endl;

	paraty = "1";
	cout << "Value of paraty: " << paraty << endl;

	return 1; 
}