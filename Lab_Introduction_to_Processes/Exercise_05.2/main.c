#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>  

int main(int argc, char *argv[]){
	int pid;
	char file[80];

	if (argc < 2){
		printf("Usage: exec-command <command>\n");
		exit(-1);
	}
	
	pid=fork();
	if(pid==0){ //create a child
        printf ("Child created, is going to execute the command\n");
		// output redirection
        close(STDOUT_FILENO);
		sprintf(file, "out-%s.txt",argv[1]);
        open(file,O_RDWR|O_CREAT,0660);
       // Execute command
        execvp (argv[1], &argv[1]);
        printf ("ERROR, this line is online executed if the execvp call fail\n");
	}
	
	wait(NULL);
	printf ("end parent process\n");
  
	exit(0);
 } //close main
