// Jatin Rungta
// 20144051
// CSE
// program to send an array to child and search for a element and print result in parent using single pipe
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{

	printf("Jatin Rungta\n20144051\nCSE\n\n");


	//pipe for sending and recieving simultaneously
	int fd[2]; 
	
	//opening both pipes
	pipe(fd);

	
	if(fork()) //parent
	{
		
		//array of size n and element
		int n=5,ele;
		printf("Enter no of elements in array: ");
		scanf("%d",&n);		
		int ar[n];

		//scanning array and element
		printf("Enter elements : ");
		for(int i=0;i<n;i++) scanf("%d",&ar[i]);
		printf("Enter element to be searched : ");
		scanf("%d",&ele);

		//send size of array , the actual array and the element
		write(fd[1],&n,sizeof(n));
		write(fd[1],ar,sizeof(ar));
		write(fd[1],&ele,sizeof(ele));
		

		//result buffer
		char x[10];
		wait(0);
		//read result from pipe and print it
		read(fd[0],x,sizeof(x));
		printf("%s",x);
	}
	else //child
	{
		
		//reading size of array, the array and the element sent by parent
		int br[100],n,ele;
		read(fd[0],&n,sizeof(int));
		read(fd[0],br,sizeof(int)*n);
		read(fd[0],&ele,sizeof(ele));
		
		
		//if element found then send "Found" and quit
		for(int i=0;i<n;i++) 
		 if(ele==br[i]){
			write(fd[1],"Found",sizeof("Found"));
			return 0;
		}

		// if here then element is not found so send "Not Found"
		write(fd[1],"Not Found",sizeof("Not Found"));
	
			
	}
}
