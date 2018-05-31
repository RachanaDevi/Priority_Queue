#include<stdio.h>
#define max 5


struct data
{
	char job[max];
	int ord,prt;
};

struct pqueue
{
	struct data d[max];
	int front,rear;
};
struct data del( struct pqueue *q);
void add( struct pqueue *pq, struct data dt);
int main()
{
	struct pqueue q;
	struct data dt,temp;
	int i,j;
	i=j=0;
	q.front=q.rear=-1;
	printf("\nEnter job and its priority:\n");
	printf("\nLower number highest priority\n");
	for(i=0;i<max;i++)
	{
		printf("\nEnter the job:");
		scanf("%s",dt.job);
		printf("\nEnter the Priority:");
		scanf("%d",&dt.prt);
		dt.ord++;
		add(&q,dt);
	}


	printf("\nJob will be removed in following order\n");
	printf("\nJob \t Priority");
	for(i=0;i<max;i++)
	{
		temp=del(&q);
		printf("\n%s \t%d",temp.job,temp.prt);
	}
	
}



void add(struct pqueue *pq,struct data dt)
{
	struct data tmp;
	int i,j;
	if(pq->rear==max-1)
	{
		printf("\nQueue is full!!\n");
	}
	
	else if((pq->front==-1)&&(pq->rear==-1))
	{
		pq->front=pq->rear=0;
		pq->d[pq->rear]=dt;
	}
	
	else
	{
		pq->rear++;
		pq->d[pq->rear]=dt;
		for(i=pq->front;i<=pq->rear;i++)
		{
			for(j=i+1;j<=pq->rear;j++)
			{
				if(pq->d[i].prt>pq->d[j].prt)
				{
					tmp=pq->d[i];
					pq->d[i]=pq->d[j];
					pq->d[j]=tmp;
				}
				
				else if(pq->d[i].prt==pq->d[j].prt)
				{
					if(pq->d[i].ord>pq->d[j].ord)
					{
						tmp=pq->d[i];
						pq->d[i]=pq->d[j];
						pq->d[j]=tmp;
					}
				}
			}
		}
		
	}
}


struct data del(struct pqueue *q)//its data type is struct
{
  struct data t;
  if(q->front==-1)
  {
  	printf("\nEmpty\n");
  	
  }
  t=q->d[q->front];
  if(q->front==q->rear)
  {
  	q->front=q->rear=-1;
  }
  
  else
  {
  	q->front++;
  }

return t;	
}


