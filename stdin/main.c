#include "stdio.h"
#include "string.h"
#include "unistd.h"

void printCli (int argc, char *argv[]);
void printStdin (void);

void main (int argc, char *argv[]) {
	if (isatty (fileno(stdin)) == 1) {
		printf ("Is a tty\n");
	}
	else {
		printf ("It is stdin\n");
		printStdin ();
	}
	printCli (argc, argv);
}

void printCli (int argc, char *argv[]) {
	printf ("Cli args\n");
	for (int i = 0; i < argc; i++) {
		printf ("%s ", argv[i]);
	}
}

void printStdin (void) {
	char caracter;
	while ((caracter = getchar()) != EOF) {
		printf ("%c", caracter);
	}
}
