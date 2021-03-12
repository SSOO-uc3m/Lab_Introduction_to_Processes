#include <stdio.h>
#include <unistd.h>

int main () {
	int x=0,pid;
	pid=fork (); /*Child process is created */
	if (pid == 0){ 
		printf ("I am the son\n"); /* Written by the child on the screen*/
		printf ("By daddy; x=%d, pid=%d ppid=%d\n",x,getpid(), getppid()); 
	}
	else { 
		/* without sleep () parent could ends before the child, 
		 * it will show that the new parent of the child is process 1 (init). 
		 * That is because, when the parent dies, init adopts the child so that it does not become a zombie.
*/
		sleep(1);
		printf ("I am the father\n"); /* Written by the parent on the screen*/
		printf ("Adios padre; x=%d, pid=%d ppid=%d\n",x,getpid(), getppid()); 
  }
} 
