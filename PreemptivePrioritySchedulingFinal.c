#include<stdio.h>

struct process
{
      int arrivalTime,turnAT,status,burstTime, completionTime, waitingTime,processID,priority;
};

struct process p[10];

int n;

void performPriority(int burstTime)
{
	int t = 0, large;
	float wt = 0, tt = 0, averageWt, averageTt; 

	p[9].priority = -1;
	printf("\nProcess Id\tArrival Time\tService Time\tPriority\tWaiting Time");
	for(t = p[0].arrivalTime; t < burstTime;)
	{
		large=9;		
		for(int i = 0; i < n; i++)
		{
			if(p[i].arrivalTime <= t && p[i].status != 1 && p[i].priority > p[large].priority)
			{
				large = i;
			}
		}

		t = t + p[large].burstTime;
		p[large].completionTime = t;
		p[large].waitingTime = p[large].completionTime - p[large].arrivalTime - p[large].burstTime;
		p[large].turnAT = p[large].completionTime - p[large].arrivalTime;
		p[large].status = 1;
		wt = wt + p[large].waitingTime;
		tt = tt + p[large].turnAT;
		
		printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d",p[large].processID,p[large].arrivalTime, p[large].burstTime, p[large].priority, p[large].waitingTime);
	}


	averageWt = wt / n;
	averageTt = tt / n;
	printf("\n\nAverage waiting time:\t%f\n", averageWt);
	printf("Average Turnaround Time:\t%f\n", averageTt);

}

void arrivalSorting()
{
      struct process temp;
      for(int i = 0; i < n - 1; i++)
      {
            for(int j = i + 1; j < n; j++)
            {
                  if(p[j].arrivalTime < p[i].arrivalTime)
                  {
                        temp = p[i];
                        p[i] = p[j];
                        p[j] = temp;
                  }
            }
      }
}

int main()
{

      printf("\n________________________________________________________________________________\n");
      printf("\n\t\t\tPreemptive Priority Scheduling \n");
      printf("__________________________________________________________________________________\n");
      printf("\nEnter Total Number of Processes To Be Created:\t\t");
      scanf("%d", &n);

      int st=0;

      for(int i = 0; i < n; i++)
      {
            printf("\nEnter the details for Process P%d:\n\n",i+1);
            
            printf("Enter Arrival Time:\t");
            scanf("%d", &p[i].arrivalTime );
            
	    printf("Enter Service Time:\t");
            scanf("%d", &p[i].burstTime);
       

	    printf("Enter Priority:\t");
            scanf("%d", &p[i].priority);

            p[i].processID=i+1;

	    p[i].status = 0;
            st = st + p[i].burstTime;
      }
      
      arrivalSorting();
      performPriority(st);
      return 0;
}
