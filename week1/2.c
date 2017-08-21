// Jatin Rungta
// 20144051
// CSE
// program to send 2 matrix to child and print their sum in the parent
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
	
	if(fork())  //parent
	{
		//close reading end
		close(fd[0]);

		//close write end
		close(fs[1]);
		
		//matrix of size n*m
		int n=5,m;
		printf("Enter n and m : ");
		scanf("%d%d",&n,&m);

		//two arrays of size m*n 
		int ar[n][m],br[n][m];

		//user input of both matrix
		printf("Enter elements first matrix: ");
		for(int i=0;i<n;i++) 
			for(int j=0;j<m;j++) 
				scanf("%d",&ar[i][j]);

		
		printf("Enter elements second matrix: ");
		for(int i=0;i<n;i++) 
			for(int j=0;j<m;j++) 
				scanf("%d",&br[i][j]);


		//send size of matrix
		write(fd[1],&n,sizeof(n));
		write(fd[1],&m,sizeof(m));
		
		//send both matrix
		write(fd[1],ar,n * m * sizeof(int));
		write(fd[1],br,n * m * sizeof(int));
		

		//sum matrix
		int xr[n][m];
	
		read(fs[0],xr,sizeof(int)*n*m);

		//printing sum matrix
		printf("The sum matrix is : \n");
		for(int i=0;i<n;i++) { 
			for(int j=0;j<m;j++) 
				printf("%d ",xr[i][j]);
			printf("\n");
		}
	}
	else  //child
	{
		//close write end
		close(fd[1]);

		//close read end
		close(fs[0]);
		
		int n,m;
		//read size of matrix
		read(fd[0],&n,sizeof(int));
		read(fd[0],&m,sizeof(int));
		
		//declaring two matrices of size m*n 
		int ar[n][m],br[n][m];

		//read both matrices
		read(fd[0],ar,sizeof(int)*n*m);
		read(fd[0],br,sizeof(int)*n*m);
		

		//store sum of both matrix in first matrix
		for(int i=0;i<n;i++) 
			for(int j=0;j<m;j++)
				ar[i][j]+=br[i][j]; 	
		
		//send sum matrix to parent
		write(fs[1],ar,sizeof(int)*n*m);
	
			
	}
}

