#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (){
	int i,pid;
 
	for (i=0; i<5; i++){
		pid=fork ();
		if ( pid==0){
			printf ("Child %d ( pid=%d)\n",i+1,getpid());
		exit (0); //return(0);
    }
		else; 
		// parent process has nothing more to do
  }	
  
	sleep(10);

    // to see zombies process execute ps -el | grep 'Z'
    

    // The parent ends without waiting for their child that become horphan (zombies)
    return 0;

    /* If the parent process die having zombies in the process table, they will be addopted by init,
	 * init will execute periodically the call wait() to eliminate zombie process that it has addopted
	 */
}

