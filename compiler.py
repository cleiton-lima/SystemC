#!/usr/bin/env python

import sys
import os

if sys.argv.__len__() > 2:
	os.environ["SYSTEMC_HOME"] = os.environ["HOME"]+"/system231/"
	executavel = " "+sys.argv[-1]+" "
	fonte=" "

	for arq in sys.argv[1:-1]:
		fonte+= (arq+" ")

	command="g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o"+ executavel + fonte + "-lsystemc -lm"
	print command
	os.system(command)
else:
	print "Argumentos insuficientes"
