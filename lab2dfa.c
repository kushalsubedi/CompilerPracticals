//WAP in C that recognizes strings over  Sum={a,b}is such that they are in the form of aab*
//l={aab,aabbb,aabbbbbbbb .......}

#include<stdio.h>
#include<string.h>

int main()
{
	char w[100];
	int state=1, i=0;
	char c;
	do{
	
	printf("\n Enter a string:\n ");
	fgets(w,sizeof(w),stdin);
	while(w[i]!='\0')
	{
		switch(state)
		{case 1:
			c=w[i++];
			if (c=='a')
			{
				state=2;
			}
			else if (c=='b')
			{
				state=4;
				
			}
			else{
			}
			break;
		case 2:
				c=w[i++];
			if (c=='a')
			{
				state=3;
			}
			else if (c=='b')
			{
				state=4;
				
			}
			else{
			}
			break;
		case 3:
				c=w[i++];
			if (c=='a')
			{
				state=4;
			}
			else if (c=='b')
			{
				state=3;
				
			}
			else{
			}
			break;
		case 4:
				c=w[i++];
			if (c=='a')
			{
				state=4;
			}
			else if (c=='b')
			{
				state=4;
				
			}
		
			break;
	
			
		}
		
	}
	
	if(state==3)
	{
		printf("\n Accepted");
	}
	else{
			printf("\n Rejected");
	}
	
	
	printf("\n Do you wanna continue? [enter-yes|| n-no]");
	c=getchar();
	fflush(stdin);
	if(c=='n')
	{
		break;
	}
	}while(1);
	
	
}
