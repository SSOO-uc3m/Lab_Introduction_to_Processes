#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int pid;
	
	if (argc < 2){
		printf("Usage: exec-command <command>\n");
		exit(-1);
	}
	
	pid=fork();
	if(pid==0){ //create a child
        printf ("Child created, is going to execute the command\n");
       // Execute command
        execvp (argv[1], &argv[1]);
        printf ("ERROR, this line is online executed if the execvp call fail\n");
	}
	
	wait(NULL);
	printf ("end parent process\n");
  
	exit(0);
 } //close main