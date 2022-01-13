#include<stdio.h>
#include<stdlib.h>

struct match
{
	char ch;
	int r;
};

struct player
{
	char pname[100];
	char tname[100];
	struct match m[14];
};

int main()
{
	int n;
	printf("Enter the number of players: ");
	scanf("%d",&n);
	struct player *ob=(struct player*)malloc(n*sizeof(struct player));
	for(int i=0;i<n;i++)
	{
		printf("Enter the name of the player %d: ",(i+1));
		fflush(stdin);
		scanf("%s",&ob[i].pname);
		printf("Enter the name of the team: ");
		fflush(stdin);
		scanf("%s",&ob[i].tname);
		for(int j=0;j<14;j++)
		{
			fflush(stdin);
			printf("Enter y if the player played match %d: ",(j+1));
			fflush(stdin);
			scanf("%c",&ob[i].m[j].ch);
			if(ob[i].m[j].ch=='y' || ob[i].m[j].ch=='Y')
			{
				printf("Enter the runs scored in match %d: ",(j+1));
				fflush(stdin);
				scanf("%d",&ob[i].m[j].r);
			}
			else
			{
				ob[i].m[j].r=-1;
			}
		}
	}
	int k;
	printf("Enter the match to find the player with the highest run score: ");
	scanf("%d",&k);
	int max=ob[0].m[k-1].r;
	int pos=0;
	for(int i=1;i<n;i++)
	{
		if(ob[i].m[k-1].r>max)
		{
			max=ob[i].m[k-1].r;
			pos=i;
		}
	}
	printf("Name of the player with highest score in match %d: %s\n",k,ob[pos].pname);
	printf("Team of the player with highest score in match %d: %s\n",k,ob[pos].tname);
	printf("Highest score in match %d: %d\n",k,max);
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<14;j++)
		{
			if(ob[i].m[j].ch=='y' || ob[i].m[j].ch=='Y')
			{
				count++;
			}
		}
		printf("Number of matches played by player %d: %d\n",(i+1),count);
		count=0;
	}
	return 0;
}
	