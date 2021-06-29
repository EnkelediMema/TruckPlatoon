// Bully algorithm for advanced embedded system project

#include<stdio.h>
#include<stdlib.h>
#define TRUCK 7

int platoon[TRUCK], num, flag[TRUCK];
int election(int place);

int main()
{
	int i=0,max=-1,place=-1,crash=-1,elect=-1,j=0;
	printf("Enter the number of trucks in the platoon:\t");
	scanf("%d",&num);
	printf("Enter the priorities of each trucks in the platoon in order to determine the platoon's Leader:\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&platoon[i]);
		if(platoon[i]>max)
		{
			max = platoon[i];
			place = i;
		}
	}
	printf("The current Platoon Leader is: %d\n",platoon[place]);
	printf("Enter the truck that crashed:\t");
	scanf("%d",&crash);

	for(i=0;i<num;i++)
		if(crash == platoon[i])
			flag[i] = 1;

	printf("\nEnter the truck that starts election:\n");
	scanf("%d",&elect);

	for(i=0;i<num;i++)
		if(elect==platoon[i])
			place = i;

	place = election(place);
	printf("\nThe current Leader of the platoon is truck: %d\n",platoon[place]);

	for(i=0;i<num;i++)
	{
		if(i!=place && platoon[i]<platoon[place])
			printf("\nVictory message from truck %d to truck %d\n",platoon[place],platoon[i]);
	}
	return 0;
}

int election(int place)
{
	int i;
	for(i=0;i<num;i++)
	{
		if(platoon[i]>platoon[place])
			printf("\nElection message sent from truck %d to truck %d\n",platoon[place],platoon[i]);
		else
			flag[i]=1;
	}

	for(i=0;i<num;i++)
	{
		if(flag[i]!=1&&platoon[i]>platoon[place])
		{
			printf("\nTakeover message sent from truck %d to truck %d\n",platoon[i],platoon[place]);
			flag[place]=1;
		}
	}
	for(i=0;i<num;i++)
	{
		if(flag[i]==0)
			place = election(i);
	}
	return place;
}
