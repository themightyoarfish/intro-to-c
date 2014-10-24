#
# Einfuehrung in die Programmiersprache C++
#
# Makefile fuer Aufgabe 2 (easter)
#

CC              = gcc
INFILE          = years.in
OUTFILE         = easter_dates.out
CORRECT_OUTFILE = correct_easter_dates.out


easter: easter.o
	$(CC) easter.o -o bin/easter

easter.o: src/easter.c
	$(CC) -Wall -Wstrict-prototypes -ansi -pedantic -c src/easter.c

test:
	./easter < $(INFILE) > $(OUTFILE)
	./run_test $(OUTFILE) $(CORRECT_OUTFILE)

check:
	./c_style_check.py easter.c



