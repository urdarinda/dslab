// Jatin Rungta
// 20144051
// CSE
// program to send an array to child and search for a element and print result in parent
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{

	printf("Jatin Rungta\n20144051\nCSE\n\n");


	//two pipes for sending and recieving simultaneously
	int fd[2],fs[2]; 
	
	//opening both pipes
	pipe(fd);
	pipe(fs);
	
	if(fork()) //parent
	{
		//close reading end
		close(fd[0]);

		//close write end
		close(fs[1]);
		
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
		
		//read result from pipe and print it
		read(fs[0],x,sizeof(x));
		printf("%s",x);
	}
	else //child
	{
		//close write end		
		close(fd[1]);

		//close read end
		close(fs[0]);
		
		//reading size of array, the array and the element sent by parent
		int br[100],n,ele;
		read(fd[0],&n,sizeof(int));
		read(fd[0],br,sizeof(int)*n);
		read(fd[0],&ele,sizeof(ele));
		
		
		//if element found then send "Found" and quit
		for(int i=0;i<n;i++) 
		 if(ele==br[i]){
			write(fs[1],"Found",sizeof("Found"));
			return 0;
		}

		// if here then element is not found so send "Not Found"
		write(fs[1],"Not Found",sizeof("Not Found"));
	
			
	}
}
