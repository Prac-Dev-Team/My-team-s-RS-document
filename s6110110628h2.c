#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h> 
int check_sequence(int Sn);
int main ( int argc, char *argv[] ){
    int i = 0, val, x, j;
    pid_t pid;

    printf("my pid is = %d, my parent pid is = %d\n",getpid(),getppid());

    x = atoi(argv[1]);

    do{ 
        pid = fork();

        if(pid < 0) {
            fprintf(stderr,"Fork Failed");
            exit(-1);
        } else if (pid == 0) {
            printf("Child: %d :", getpid());
            for(j=0;j<x;j++){
		    val = check_sequence(j);
		    printf("%d ",val);
	    }
		    printf("\n");
            exit(0); 
        } else  {
            wait(NULL);
        }
        i++;
    } while (i < 4);

	printf("Goodbye.\n");

    return 0;
}

int check_sequence(int Sn){
	if(Sn>=0 && Sn<=3){
		switch(Sn){
			case 0 : return 1;break;
			case 1 : return 1;break;
			case 2 : return 2;break;
			case 3 : return 2;break;
			default : break;
		}
	}
	else if(Sn > 3 && Sn%3==0){
		return check_sequence(Sn-1);
	}
	else{
		return (check_sequence(Sn-2)*2)-1;
	}
}