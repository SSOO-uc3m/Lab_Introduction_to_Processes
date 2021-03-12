#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main () {
	int i,pid;
	for (i=1; i<=2; i++){
		pid = fork();
		if ( pid==0) {
			printf ("I am the child %d\n", i);
			exit(0); 
		}
	}
}