# Wall: show most warnigns
# Wstrict-prototypes: warn when function prototypes or definitions omit argument
# types
# ansi: compile according to ANSI standard (c89), accept only code compliant
# with that standard. Enable trigraphs! :)
# -pedantic: show all warnings according to strict ISO C/C++
hello: hello.c
	gcc -Wall -Wstrict-prototypes -ansi -pedantic hello.c -o hello
clean: 
	rm hello
test:
	./hello
