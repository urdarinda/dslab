#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
pthread_mutex_t lock;
pthread_mutex_t lockwr;
int readc=0;
void *read(void* arg)
{
	pthread_mutex_lock(&lock);
//	readc++;
//	if(readc==1)
//		pthread_mutex_lock(&lockwr);	
//	pthread_mutex_unlock(&lock);
	File *ftpr;
	fptr=fopen("ab.txt","r");

	int val= (int)arg;
	int i=0;	
	while(i++<5)
	{
		sleep(1);
		fscanf
		printf("reading %d\n",val);
	}
//	pthread_mutex_lock(&lock);
//	readc--;
//	if(readc==0)
//		pthread_mutex_unlock(&lockwr);
	
	pthread_mutex_unlock(&lock);
}
void *write(void* arg)
{
//	pthread_mutex_lock(&lockwr);
	pthread_mutex_lock(&lock);
	int val= (int)arg;
	int i=0;	
	while(i++<5)
	{
		sleep(1);
		printf("writing %d\n",val);
	}
//	pthread_mutex_unlock(&lockwr);
	pthread_mutex_unlock(&lock);
}
void *append(void* arg)
{
//	pthread_mutex_lock(&lockwr);
	pthread_mutex_lock(&lock);
	int val= (int)arg;
	int i=0;	
	while(i++<5)
	{
		sleep(1);
		printf("writing %d\n",val);
	}
//	pthread_mutex_unlock(&lockwr);
	pthread_mutex_unlock(&lock);
}
int main()
{
	//pthread_t id[5];
	//pthread_t wr[5];
	pthread_t wr;
	pthread_t rd;
	pthread_t ap;
	pthread_mutex_init(&lock, NULL);
	//pthread_mutex_init(&lockwr, NULL);
	//int nr=5,nw=2;
	//for(int j=0;j<nr;j++)
	{

		pthread_create(&rd,0,read,(void*) 1);
	//	if(j<nw)
			pthread_create(&wr,0,write,(void*) 2);
		pthread_create(&ap,0,append,(void*) 3);
		pthread_join(wr,0);
		pthread_join(ap,0);
		pthread_join(rd,0);
		//pthread
		//pthread_join(id[i],0);
	}
/*
	for(int j=0;j<nw;j++)
	{

		//_join(id[i],0);
	}
	
	
	for(int j=0;j<nr;j++)
	{

		//pthread_create(&id[i],0,read,(void*) j);
		pthread_join(id[j],0);
	}
	for(int j=0;j<nw;j++)
	{

		//pthread_create(&id[i],0,read,(void*) j);
		pthread_join(wr[j],0);
	}
*/
	 pthread_mutex_destroy(&lock);
	return 0;
}
