#include<stdio.h>
main()
{
long int totd=0;
int d,i,c,m,y,mon[]={31,28,31,30,31,30,31,31,30,31,30,31},x=0;
char a[1];
do
{
clrscr();
printf("\n\t\tEnter Day   : ");
scanf("%d",&d);
if(d>31)
	{
	printf("\n\t\tError in Input !!!");
	x=1;
	getch();
	}
if(x==1) break;

printf("\n\t\tEnter Month : ");
scanf("%d",&m);
if(((m>12||d>mon[m-1])&&m!=2)||(m==2&&d>29))
	{
	printf("\n\t\tError in Input !!!");
	x=1;
	getch();
	}
if(x==1) break;

printf("\n\t\tEnter Year  : ");
scanf("%d",&y);
if((y%4==0 && d>29 && m==2)||(y%4!=0 && d>28))
	{
        printf("\n\t\tError in Input !!!");
	getch();
	x=1;
	}
if(x==1) break;

for(i=1;i<y;i++)
	{
	totd+=365;
	if(i%4==0) totd++;
	}

if(y%4==0) mon[1]=29;

for(i=0;i<m-1;i++)
	totd+=mon[i];
textcolor(4);
printf("\n\n\t\t     ");
cprintf("SUN   ");
textcolor(5);
cprintf("MON   TUE   WED   THU   FRI   SAT");
printf("\n\t\t     ");

for(c=0;c<(totd%7);c++)
	printf("      ");

textcolor(3);

for(i=1;i<=mon[m-1];i++)
	{
	if(c%7==0)
	{
	textcolor(4);
	printf("\n\t\t     ");
	}
	if(i==d) textcolor(-6);
	cprintf("%3d   ",i);
	textcolor(3);
	c++;
	}
getch();
printf("\n\n\t\tDo You Want To Continue ? (Y/N) : ");
scanf("%s",&a);
}
while(a[0]=='Y'||a[0]=='y');
}