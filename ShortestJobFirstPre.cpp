#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>
int main()
{
	printf("\n\t\t<---------Welcome to Dheeraj's Project...!----------------->\n");
	printf("\n********************************************************************");
	printf("\n*********************************************************************");
	int fd, arr[100];
    char buf[20];
	printf("\nEnter your name:");
	char userName[20];
	scanf("%s", &userName);
	printf("\nWelcome %s", userName);
	printf("\nEnter 1 to Log In and any other to exit");
	int logIn;
	scanf("%d", &logIn);
	if(logIn == 1){
    	fd = open("Process1.txt", O_CREAT |  O_RDWR);
    	if(fd == NULL)
    	{
    		printf("error");
        	printf("\nThe process is exploited"); //If the file fails to open
        	exit(1);
    	}
    	write(fd, "23_12_3_-4_3_-3_4",11 );
    	close(fd);
    	fd = open("Process1.txt", O_RDONLY);
    	if(fd == -1)
    	{
    	    printf("\nThe process is exploited"); //If the file fails to open
    	}
    	read(fd, buf, 18); //Reading the values into buffer character array
    	printf("\nThe buf :%s ", buf);
    	int burstTime[10];
    	int i, n, j, tat = 0, wTime = 0, temp;
    	int _atat=0, _awt=0;
    	float atat=0, awt=0;
    	char *p;
    	p = strtok(buf, "_"); //extracting the particular piece of text just like split function
    	i=0;
    	while(p != NULL )
    	{
    		int temp = atoi(p);
    		if(temp>0)
    	    burstTime[i]=temp; //Converting the character to integer value
    	    else burstTime[i]=0;
        	p = strtok(NULL,"_");
    	    i++;
    	}
    	close(fd);
    	for(i=0;i<5;i++) // sorting the values according to burst time of the resp processes
    	{
    	    for(j=0;j<5;j++)
    	    {
    	        if(burstTime[j] > burstTime[i])
    	        {
    	            temp = burstTime[j];
        	        burstTime[j] = burstTime[i];
        	        burstTime[i] = temp;
        	    }
        	}
    	}	
    	printf("\nPid\t\t\t Bt\t\t\t Wt\t\t\t tAT\t\t\t");
    	for(i=0;i<5;i++) //executing and calculating the values of waiting time and turn around time
    	{
    	    tat = burstTime[i] + wTime;
    	    printf("\n%d\t\t\t %d\t\t\t %d\t\t\t %d\t\t\t ", i+1,burstTime[i], wTime, tat);
    	    _atat = _atat + tat;
    	    _awt += wTime;
    	    wTime = wTime + burstTime[i];
    	}
    	awt = (float)_awt/5;
    	atat = (float)_atat/5;
    	printf("\nThe average waiting time for the system is %f:",awt);
    	printf("\nThe average turn around time for the system is %f:", atat);
    	printf("\nThanks for using Dheeraj's project");
    	printf("\nHave a nice day %s", userName);
		}
		else
		{
			printf("\nThanks for Using Dheeraj's project");
			printf("\nHave a nice day %s", userName);
		}
	time_t t;
	time(&t);
	printf("\n\n\t\t\tYou have logged into the system is %s", ctime(&t));
}

