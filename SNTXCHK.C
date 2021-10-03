#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void createnode();
void processline();

struct info
{
	int lineno;
	unsigned char character;
};

struct stack
{
	struct info node;
	struct stack *pop;
};

struct stack *newnode;
struct stack *tos;

void push(struct info nod)
{
	createnode();
	newnode->pop=tos;
	tos=newnode;
	tos->node.lineno=nod.lineno;
	tos->node.character=nod.character;

}

struct info pop()
{
	struct info temp;
	struct stack *ftemp;
	temp.lineno=tos->node.lineno;
	temp.character=tos->node.character;
	ftemp=tos;
	tos=tos->pop;
	free(ftemp);
	return temp;
}

void createnode()
{
	newnode=(struct stack *)malloc(sizeof(struct stack));
	newnode->pop=NULL;
	newnode->node.lineno=0;
	newnode->node.character='\0';
}

char line[256];
int lineno=1;

int main()
{
	FILE *fptr;
	int ctr;
	char fname[11];

	clrscr();
	printf("\nEnter the file to be checked :");
	scanf("%s",fname);

	fptr=fopen(fname,"r");
	if(fptr==NULL)
	{
		printf("\nFile doesnt exist");
		return 0;
	}

	for(ctr=0;ctr<256;ctr++)
	{
		line[ctr]=fgetc(fptr);
		if(line[ctr]==EOF)
		{
		line[ctr++]='\n'; line[ctr]=NULL;
		processline();
		return 0;
		}
		else if(line[ctr]=='\n')
		{
			line[++ctr]=NULL;
			processline();
			lineno++;
			line[0]=NULL;
			ctr=-1;
		}
	}
	getch();
	return 0;
}

void processline()
{
	int ctr,ctr1,ctr2;
	struct info temp;
	char openchar[4]="({[";
	char closechar[4]=")}]";
	for(ctr=0;line[ctr]!=NULL;ctr++)
	{
		if(strchr(openchar,line[ctr]))
		{
			temp.lineno=lineno;
			temp.character=line[ctr];
			push(temp);
		}
		else if(strchr(closechar,line[ctr]))
		{
			temp=pop();
			for(ctr1=0;ctr1<4;ctr1++)
			{
				if(openchar[ctr1]==temp.character)
				break;
			}
			for(ctr2=0;ctr2<4;ctr2++)
			{
				if(closechar[ctr2]==line[ctr])
				break;
			}
			if(ctr1!=ctr2)
			printf("\n%c missing in line number %d",closechar[ctr1],lineno);

		}

	}


}