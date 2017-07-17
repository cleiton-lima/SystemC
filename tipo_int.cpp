#include <systemc.h>

int sc_main (int argc, char* argv[])
{
	sc_int<1> bit_size = 0;
	sc_int<4> nibble_size = 1;
	sc_int<8> byte_size = 2;
	sc_int<32> dword_size = 3;

	dword_size++;
	cout << "Value of dword_size: " << dword_size << endl;

	byte_size += nibble_size;
	cout << "Value of byte size: " << byte_size << endl;

	bit_size = dword_size[2];
	cout << "Value of bit_size: " << bit_size << endl;

	nibble_size =  dword_size.range(4,1);
	cout << "Value of nibble_size: " << nibble_size << endl;

	dword_size = (byte_size, byte_size, byte_size, byte_size); //juntando bytes um do lado do outro
	cout << "Value of dword_size: " << dword_size << endl;

	return 1;
}