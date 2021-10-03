/*       	     This Program Is Written By V.Gowri Shankar
     Hi My Friend,
	I am A Student Of Diploma in Computer Engineering
	2nd yr in PSG Polytechnic College
	In Peelamedu,Coimbatore.
	I Have Decided To Improve This Program And Submit
	This As A MINI PROJECT In My College.
Requests For My Dear Friend:-
	* Though You Modify/Distribute This Program,
	Please Don't Remove This Comment.
	* If You Modify This Program,Im Eager To See Your Talents.
	So,You Kindly Send The Modified Program To My Email Address Specified Below.
	* Comments/Suggestions can Also Be Sent To Me Through E-mail.
			Thankyou.
				=====================================
				|	V.GowriShankar              |
				|	2nd Yr DCE,                 |
				|	PSG Polytechnic College,    |
				|	Peelamedu,                  |
				|	Coimbatore.                 |
				|E-mail - vgshankar87@sify.com      |
				===================================== */
#include<dos.h>
#include<graphics.h>
union REGS i,o;
main()
{
int gd=DETECT,gm,maxx,choice,maxy,x,y,a,b,c,d,button;
choice=1;
while(choice!=5)
{
clrscr();
printf("\n\n\t\t\t");
textcolor(-3);
cprintf("Draw It !!! - By V.Gowri Shankar");
textcolor(50);
printf("\n\n\t\tRight Click While Drawing To Return To This Menu");
printf("\n\n\t\t\t1.FreeHand\n\n\t\t\t2.Line\n\n\t\t\t3.Rectangle");
printf("\n\n\t\t\t4.Ellipse\n\n\t\t\t5.Exit\n\n\n\tEnter Your Choice -=- ");
scanf("%d",&choice);
initgraph(&gd,&gm,"");
maxx=getmaxx();
maxy=getmaxy();

rectangle(0,0,maxx,maxy);
setviewport(1,1,maxx-1,maxy-1,1);
if(initmouse()==0)
  {
  closegraph();
  restorecrtmode();
  printf("\nMouse Driver Not Installed");
  exit();
  }
restrictmouseptr(1,1,maxx-1,maxy-1);
showmouseptr();

 switch(choice)
 {
case 1 :
getmousepos(&button,&x,&y);
while(button!=2)
  {
   getmousepos(&button,&x,&y);
   while(button==1)
   {
    hidemouseptr();
    a=x;
    b=y;
    getmousepos(&button,&x,&y);
    while(button==1)
       {
       line(a,b,x,y);
       a=x;
       b=y;
       getmousepos(&button,&x,&y);
       }
    showmouseptr();
    }
  }
   break;

case 2 :
getmousepos(&button,&x,&y);
while(button!=2)
  {
   getmousepos(&button,&x,&y);
   while(button==0)
     {
     getmousepos(&button,&x,&y);
     a=x;
     b=y;
     }
   while(button==1)
   {
   getmousepos(&button,&x,&y);
   c=x;
   d=y;
   }
   hidemouseptr();
   line(a,b,c,d);
   showmouseptr();
  }
  break;


case 3:
getmousepos(&button,&x,&y);
while(button!=2)
  {
   getmousepos(&button,&x,&y);
   while(button==0)
     {
     getmousepos(&button,&x,&y);
     a=x;
     b=y;
     }
   while(button==1)
   {
   getmousepos(&button,&x,&y);
   c=x;
   d=y;
   }
  hidemouseptr();
  rectangle(a,b,c,d);
   showmouseptr();
   }
  break;


case 4:
getmousepos(&button,&x,&y);
while(button!=2)
  {
   getmousepos(&button,&x,&y);
   while(button==0)
     {
     getmousepos(&button,&x,&y);
     a=x;
     b=y;
     }
   while(button==1)
   {
   getmousepos(&button,&x,&y);
   c=x;
   d=y;
   }
   hidemouseptr();
   ellipse((a+c)/2,(b+d)/2,0,360,(c-(a+c)/2),(d-(b+d)/2));
   showmouseptr();
   }
   break;
case 5: break;

default:
     {
     setcolor(GREEN);
     hidemouseptr();
     outtextxy(240,240,"ERROR IN YOUR CHOICE");
     showmouseptr();
     getch();
      }
}
closegraph();
restorecrtmode();
}
clrscr();
printf("\n\n\n\n\n\n");
printf("\n\t\t\t======================================");
printf("\n\t\t\t|\tV.GowriShankar               |");
printf("\n\t\t\t|\t2nd Yr DCE,                  |");
printf("\n\t\t\t|\tPSG Polytechnic College,     |");
printf("\n\t\t\t|\tPeelamedu,                   |");
printf("\n\t\t\t|\tCoimbatore.                  |");
printf("\n\t\t\t|  E-mail - vgshankar87@sify.com     |");
printf("\n\t\t\t======================================");
getch();
}

initmouse()
{
i.x.ax=0;
int86(0x33,&i,&o);
return(o.x.ax);
}
showmouseptr()
{
i.x.ax=1;
int86(0x33,&i,&o);
}
restrictmouseptr(int x1,int y1,int x2,int y2)
{
i.x.ax=7;
i.x.cx=x1;
i.x.dx=x2;
int86(0x33,&i,&o);
i.x.ax=8;
i.x.cx=y1;
i.x.dx=y2;
int86(0x33,&i,&o);
}
getmousepos(int *button,int *x,int *y)
{
i.x.ax=3;
int86(0x33,&i,&o);
*button=o.x.bx;
*x=o.x.cx;
*y=o.x.dx;
}
hidemouseptr()
{
i.x.ax=2;
int86(0x33,&i,&o);
}