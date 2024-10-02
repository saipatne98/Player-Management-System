
#include<stdio.h>
#include<string.h>


typedef struct Player
{
	int jerseyNo;
	char name[20];
	int matches;
	int runs;
	int wickets;
}Player;

int searchPlayer(Player*);
void displayPlayer(Player*);
void displayOnePlayer(Player*, int);
void storePlayer(Player*);
void updatePlayer(Player*);
void removePlayer(Player*);
void displayTop(Player*);
void maxruns(Player*);
void miniruns(Player*);
void maxWickets(Player*);
void minWickets(Player*);
int cnt=0;
void main()
{ 

    Player p[10];
    
   p[0].jerseyNo=1;  strcpy(p[0].name,"sachin");   p[0].matches=100;  p[0].runs=100;  p[0].wickets=143;  cnt++;
   p[1].jerseyNo=2;  strcpy(p[1].name,"virat");    p[1].matches=49;   p[1].runs=200;  p[1].wickets=142;  cnt++;
   p[2].jerseyNo=3;  strcpy(p[2].name,"kapil");    p[2].matches=50;   p[2].runs=300;  p[2].wickets=100;  cnt++;                 
   	printf("\n\n>>>>>>>>>>>>>>>>>  PlAYER MANAGEMENT SYSTEM  <<<<<<<<<<<<<<<<<<<<");
   	displayPlayer(p);
 	
int choice;
   
	do
	{
			int r;
		
		   	printf("\n\n>>>>>>>>>>>>>>>>>  PlAYER MANAGEMENT SYSTEM  <<<<<<<<<<<<<<<<<<<<");
		printf("\nEnter your choice below :\n1.Store Player Data\n2.Display Player Data\n3.search Plyer\n4.Update Player Data\n5.Remove Player\n6.Display Top Players\n0.Press 0 to Exit");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			storePlayer(p);
		    displayPlayer(p);
			break;
			
				
			case 2:
			displayPlayer(p);
			break;
			
			case 3:
		
		    r=searchPlayer(p);
		    if(r!=-1)
		    {
		    displayOnePlayer(p,r);
		    }
		    else
		   	printf("\n******Player Not Found*******");
			break;
			
			case 4:
			updatePlayer(p);
			break;
			
			case 5:
			removePlayer(p);
			break;
			
			case 6:
			displayTop(p);
			break;
		}
		
		
	}while(choice!=0);
	    printf("\n----------------THANK YOU----------------------------------");
}

void storePlayer(Player* p)
{
	printf("\nEnter the Details");
	printf("\nJersey Number__");
	scanf("%d",&p[cnt].jerseyNo);
	
	printf("Name__");
	fflush(stdin);
	gets(p[cnt].name);
	
	printf("Matches Played__");
	scanf("%d",&p[cnt].matches);
	
	printf("Runs__");
	scanf("%d",&p[cnt].runs);
	
	printf("Wickets__");
	scanf("%d",&p[cnt].wickets);
	
	printf("\n------Player Details Added Succesfully------");
	cnt++;

}

void displayPlayer(Player* p)
{
	
	printf("\n\n-----------------CURRENT PLAYER DATA-------------------");
	printf("\nJersey No.\tNAME\tMATCHES\tRUNS\tWICKETS");
	int i;
	for(i=0;i<cnt;i++)
	{
	printf("\n%d\t\t%s\t%d\t%d\t%d",p[i].jerseyNo,p[i].name,p[i].matches,p[i].runs,p[i].wickets);	
	}
}

void displayOnePlayer(Player* p, int i)
{
	printf("\nJersey No.\tNAME\tMATCHES\tRUNS\tWICKETS");
	printf("\n%d\t\t%s\t%d\t%d\t%d",p[i].jerseyNo,p[i].name,p[i].matches,p[i].runs,p[i].wickets);
}

void updatePlayer(Player* p)
  {
  	int jn;
  	printf("\nEnter the jersey number of the player__");
  	scanf("%d",&jn);
 	                
  	
  	
  	 int i,flag=0;
  	for(i=0;i<=cnt;i++)
  	{
  		if(p[i].jerseyNo==jn)
  		{
  		
		  {
			  printf("Enter Matches__");
			  scanf("%d",&p[i].matches);
				printf("enter Runs__");
				scanf("%d",&p[i].runs);
			    printf("Enter Wickets__");
				scanf("%d",&p[i].wickets) ;   
				
			
		  }
		  flag=1;
		  printf("\n---------Player data Updated Successfully--------");
		  displayPlayer(p); 
		}
		
	 }
	  if(flag==0)
		printf("\nPlayer not Exists\n");
		
	  
  }
  
  
int  searchPlayer(Player* p)
  {
  	int choice;
  	printf("Enter your Choice\n1.Search By Jersey Number\n2Search By Name__");
  	scanf("%d",&choice);
  	if(choice==1 || choice==2)
  	{
  		if(choice==1)
  		{
  		   printf("\nEnter the jersey Number to Search__");
			 int jn,flag=0;
			 scanf("%d",&jn);
			 int i;
			 for(i=0;i<=cnt;i++)
			 {
			 	if(p[i].jerseyNo==jn)
			 	{
			 		
			 		return i;
			 		flag=1;
				 }
			}	
			
			if(flag==0)
			{
				return -1;
			}
		  }
		  
		  
		  if(choice==2)
		  {  
		  int i,flag=0;
		  char nm[20];
		  printf("Enter the name of the player to search__");
		  fflush(stdin);
		  gets(nm);
		  
		  for(i=0;i<=cnt;i++)
	       {
	       	if (strcasecmp(nm,p[i].name)==0)
	       	{
	       			printf("******Player Found*******");
			 			printf("\nJersey No.\tNAME\tMATCHES\tRUNS\tWICKETS");
			 		printf("\n%d\t\t%s\t%d\t%d\t%d",p[i].jerseyNo,p[i].name,p[i].matches,p[i].runs,p[i].wickets);	
			 		flag=1;
			}
			
			
			   
		   }
		   if(flag==0)
			{
				printf("\n******Player Not Found*******");	
			}
           }

  }
}

void removePlayer(Player* p)
{
	int i;
	int r=searchPlayer(p);
	
	if(r!=-1)
	{
		for(i=r;i<=cnt;i++)
		{
			p[i]=p[i+1];	
		}
		cnt--;
			printf("-------Player removed Successfully-------");
		displayPlayer(p);
	}
	else
		printf("\n-------Player Not Found------");

}

void displayTop(Player* p)
{
	printf("\n\nChoose Top Players On Basis of Below\n1.Maximum runs\n2.Minimum runs\n3.maximum Wickets\n4.minimum Wickets");
     int choice;
	 scanf("%d",&choice);
	 if(choice==1)
	 {
	 	maxruns(p);
	 	printf("\n--------------Players With Maximum Runs---------");
	 	displayPlayer(p);
	 } 
	 
	 if(choice==2)
	 {
	 	miniruns(p);
	 	printf("\n--------------players with minimum Runs----------");
	 	displayPlayer(p);
	  }
	 else if(choice==3)
	 {
	 	maxWickets(p);
	 	printf("\n-----------------Players with Max wickets------------");
	 	displayPlayer(p);
	   }  
	   
	 else if(choice==4)
	 {
	 	minWickets(p);
	 	printf("\n------------------Players With Minimum Wickets-----------");
	 	displayPlayer(p);
	   }  
     
     
}

void maxruns(Player* p)
{
	int i,j;
	int max=p[0].runs;
	for(i=0;i<cnt-1;i++)
	{
		 for(j=0;j<cnt-1;j++)
		 {
		   
		   if(p[j].runs<p[j+1].runs)	
		   {
		    Player temp=p[j];
		    p[j]=p[j+1];
		    p[j+1]=temp;
		   }
		 }
	}
}

void miniruns(Player* p)
{
	int i,j;
	
	for(i=0;i<cnt-1;i++)
	{
		for(j=0;j<cnt-1;j++)
		{
			if(p[j].runs>p[j+1].runs)
			{
			Player temp=p[j];
			p[j]=p[j+1];
			p[j+1]=temp;
			}
		}
	}
}


void maxWickets(Player* p)
{
	int i,j;
	for(i=0;i<cnt-1;i++)
	{
		for(j=0;j<cnt-1;j++)
		{
			if(p[j].wickets<p[j+1].wickets)
			{
				Player temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}


void minWickets(Player* p)

{
	int i,j;
	for(i=0;i<cnt-1;i++)
	{
		for(j=0;j<cnt-1;j++)
		{
			if(p[j].wickets>p[j+1].wickets)
			{
				Player temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}


