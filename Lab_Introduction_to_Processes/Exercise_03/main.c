#include <stdio.h>
#include <unistd.h>

 int main (){
	printf ("Hi\n");
	fork ();
	printf ("One\n");
	fork ();
	printf ("Two pid=%d\n",getpid());
  }
