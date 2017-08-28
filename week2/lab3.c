#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
pthread_mutex_t lock;
void *r(void *arg)
{
pthread_mutex_lock(&lock);
printf("Read Function\n");

FILE *fp=fopen("file.txt","r");
fseek(fp, 0, SEEK_SET);
int ch;
while(1)
{
ch=fgetc(fp);
if(ch==EOF)
break;
else
printf("%c", ch);
}
printf("\n");

pthread_mutex_unlock(&lock);
 fclose(fp);

}



void *w(void *arg)
{
pthread_mutex_lock(&lock);
printf("write Function\n");
char buffer[100]="writing hello\n";
FILE *fp=fopen("file.txt","w");

 fwrite(buffer, strlen(buffer)+1, 1, fp);

 fclose(fp);
  pthread_mutex_unlock(&lock);
}


void *a(void *arg)
{
pthread_mutex_lock(&lock);
printf("Append Function\n");
char buffer[100]="appending world\n";
FILE *fp=fopen("file.txt","a");
  fwrite(buffer, strlen(buffer) + 1, 1, fp);

 fclose(fp);
   pthread_mutex_unlock(&lock);
}
int main()
{

pthread_t one, two, th;
if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
pthread_create(&one, NULL, r, NULL);
pthread_create(&two, NULL, w, NULL);
pthread_create(&th, NULL, a, NULL);

pthread_join(one,NULL);
pthread_join(two,NULL);
pthread_join(th,NULL);
pthread_mutex_destroy(&lock);


}
