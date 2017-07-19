#include "systemc.h"

SC_MODULE(stim)
{
    sc_in<bool> Clk;
    sc_out<bool> A, B;

    void StimGen()
    {
        A.write(false);
        B.write(false);
        wait();
        A.write(false);
        B.write(true);
        wait();
        A.write(true);
        B.write(false);
        wait();
        A.write(true);
        B.write(true);
        wait();
        sc_stop();
    }

    SC_CTOR(stim)
    {
        cout << "Constructing STIM:  " << name() << endl;
        SC_THREAD(StimGen);
        sensitive << Clk.pos();
    }
};