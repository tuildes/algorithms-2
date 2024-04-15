#include <stdio.h>

void hello_world (unsigned int rep) {
	// Caso base: se chegar a 1
	if (rep <= 0)
		return;

	printf ("Ola Mundo! %d\n", rep);
	hello_world (rep-1);
	return;
};

void hello_world_invertido (unsigned int rep, ) {
	// Caso base: se chegar a 1
    if (rep <= 0)
        return;

    printf ("Ola Mundo! %d\n", rep);
    hello_world (rep-1);
    return;

}

int main () {
	unsigned int number;

	scanf("%u", &number);
	hello_world (number);
	hello_world_invertido (number);

	return 0;
};
