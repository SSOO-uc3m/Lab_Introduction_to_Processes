#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

const int NUM_CHILD = 5;
const int NUM_GRAND_SON = 3;

int main (){
	int i,j,pid;
	
	for (i=1; i<=NUM_CHILD; i++){
		
		pid=fork ();  //parent process create child process
		
		if ( pid==0){
			
			printf ("Child %d ( pid=%d)\n",i,getpid());
			
			for (j=1; j<=NUM_GRAND_SON; j++){
				
				pid=fork ();  //child process create 'grandson' process
				
				if (pid==0){
					printf (" Grandson %d ( pid=%d) from child %d (pid=%d)\n", j,getpid(),i,getppid());
					exit (0);  // grandson finish
				}
			}
			
			for (j=1; j<=NUM_GRAND_SON; j++){  // Child processes wait wait their child (grandsons) until they finish
				wait (NULL);			
			}
			
			exit (0); //child exit
		} // end if childs
		
	} //end creating childs 
  
  for (i=1; i<=NUM_CHILD; i++){  //The parent wait their child until they finish
  
     wait (NULL);
  }
  
   exit (0); //parent exit
   
 }

