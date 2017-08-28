#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
pthread_mutex_t lock1,lock2;
void *t1(void* arg)
{
	pthread_mutex_lock(&lock1);
	//sleep(1);
	printf("hread 1\n");
	sleep(1);
printf("hread 1\n");
printf("hread 11\n");
	pthread_mutex_lock(&lock2);
	while(1)
	{
		sleep(1);
		printf("hread 1\n");
	}
	pthread_mutex_unlock(&lock1);
	pthread_mutex_unlock(&lock2);
	
}
void *t2(void* arg)
{
	pthread_mutex_lock(&lock2);
	//sleep(1);
	printf("hread 2\n");
	sleep(1);
	printf("hread 2\n");
	printf("hread 2\n");
	pthread_mutex_lock(&lock1);
	while(1)
	{
		sleep(1);
		printf("hread 2\n");
	}
	pthread_mutex_unlock(&lock2);
	pthread_mutex_unlock(&lock1);
	
}
int main()
{
	pthread_t l1,l2;
	pthread_mutex_init(&lock1, NULL);
	pthread_mutex_init(&lock2, NULL);
	pthread_create(&l1,0,t1,0);
	pthread_create(&l2,0,t2,0);
	pthread_join(l1,0);
	pthread_join(l2,0);
	return 0;
}
