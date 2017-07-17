#include <systemc.h>

int sc_main(int argc, char* argv[])
{
	bool enable;
	bool read_en;

	enable = 1;
	cout << "Value of enable: " << enable << endl;

	read_en = enable;
	cout << "Value of read_en " << enable << endl;
}