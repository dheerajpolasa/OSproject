#include<stdio.h>
#include<stdlib.h>
#define N 3
#define QMax 20
struct process
{
	int pid;
	char process_name;
	int burstTime;
	int burstTimew;
	int priority;
	int arrivalTime;
}proc[N];
process ready_queue[QMax];
int rear = -1;
int front = -1;
void display();
bool check(process a, process b);
void insert(process a);
void displayReady();
void performPriority();
void sorting();
int main()
{
	char userName[20];
	int choice;
	printf("\n---------------------------------------------------------------");
	printf("\n\t\t\tWelcome to the world of Scheduling........");
	printf("\n----------------------------------------------------------------");
	
	printf("\nBefore starting with the project\nWe generally consider this:");
	printf("\nEnter your name:");
	scanf("%s",&userName);
	printf("\nWithout any further, Let's begin");
	printf("\nEnter 1 to start and any other to exit..!");
	scanf("%d", &choice);
	
	if(choice == 1)
	{
	//	printf("\nEnter the no of processes:");
		int ch;
	
	
	
		for(int i=0; i<N; i++)
		{
			printf("\nEnter the arrival time: ");
			scanf("%d", &proc[i].arrivalTime);
			printf("\nEnter the burst Time:");
			scanf("%d", &proc[i].burstTime);
			printf("\nEnter the priority:");
			proc[i].burstTimew = proc[i].burstTime;
			scanf("%d", &proc[i].priority);
			proc[i].pid = i+1;
			proc[i].process_name = (char)(i+97);
			
		}
	
		while(ch!=3)
		{
			printf("\n\n\n\t\t\tWhat do you want..?");
			printf("\n1.Display the direct o/p\n2.Perform Priority Scheduling\n3.Exit\n");
			scanf("%d", &ch);
			switch(ch)
			{
				case 1:display();break;
				case 2:performPriority();break;
				case 3:printf("\nThank you %s for using our project..!", userName);exit(1);break;
				default:printf("Choose option Wisely:");break;
			}
		}	
	
	}
	else
	{
		printf("\nTry, some other time...!");
		printf("\nThank you %s for visiting our site..", userName);
	}
}
void display()
{
	for(int i=0; i<N; i++)
	{
		printf("\n-------------------------------------------------------");
		printf("\n\t\t\tThe process name is : %c", proc[i].process_name);
		printf("\n\n-----------------------------------------------------");
		printf("\nThe process id is: %d", proc[i].pid);
		printf("\nThe burst time is: %d", proc[i].burstTime);
		printf("\nThe arrival time is: %d", proc[i].arrivalTime);
		printf("\nThe priority is; %d", proc[i].priority);		
	}
}
void displayReady()
{
	printf("Waiting times:\n\n");
	for(int i=0;i<N;i++)
	{
		printf("\nthe waiting time is %d",ready_queue[i].burstTime);
	}
}
void performPriority()
{
	printf("\n\n\nt\t\tUnder construction:::>>>>>>");
	sorting();
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(proc[j].arrivalTime == i)
			{
				insert(proc[j]);
			}
		}
		if(check(ready_queue[rear],ready_queue[rear+1]))
		{
			ready_queue[rear].burstTime -= i;
		}		
		else
		{
			ready_queue[rear+1].burstTime--;
		}
		
	}
	display();
	displayReady();
}
void sorting()
{
      struct process temp;
      int i, j;
      for(i = 0; i < N - 1; i++)
      {
            for(j = i + 1; j < N; j++)
            {
                  if(proc[i].arrivalTime > proc[j].arrivalTime)
                  {
                        temp = proc[i];
                        proc[i] = proc[j];
                        proc[j] = temp;
                  }
            }
      }
}
void insert(process a)
{
	if(rear == QMax -1)
	printf("Over flow");
	else
	{
		rear = rear +1;
		ready_queue[rear] = a;
	}
}
bool check(process a, process b)
{
	if(a.priority>b.priority)
	return true;
	else
	return false;
}
