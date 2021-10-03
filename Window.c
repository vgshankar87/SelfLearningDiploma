#include<dos.h>
#include<graphics.h>
union REGS i,o;
main()
{
int gd=DETECT,gm,maxx,maxy,x,y,a,b,c,d,j,k,button,sm,f;
initgraph(&gd,&gm,"");
maxx=getmaxx();
maxy=getmaxy();
k=2;
j=sm=0;


setfillstyle(1,DARKGRAY);
bar(0,0,maxx,maxy);
setfillstyle(1,7);
setcolor(15);
bar(0,maxy-20,maxx,maxy);
rectangle(0,maxy-20,maxx,maxy);
setcolor(BLACK);
outtextxy(6,466,"START");
rectangle(1,maxy-19,50,maxy-1);
setcolor(8);
rectangle(1,maxy-19,49,maxy-2);



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

while(!kbhit())
	{
   getmousepos(&button,&x,&y);
   if(button!=0)
	{
     setfillstyle(1,7);
     setcolor(15);
     bar(0,maxy-20,maxx,maxy);
     rectangle(0,maxy-20,maxx,maxy);
     setcolor(BLACK);
     outtextxy(6,466,"START");
     rectangle(1,maxy-19,50,maxy-1);
     setcolor(8);
     rectangle(1,maxy-19,49,maxy-2);
     setfillstyle(1,8);
     bar(0,0,maxx,maxy-22);
	}
   if(x<50 && y>(maxy-19) && button==1)
	{
     hidemouseptr();
     setfillstyle(1,LIGHTGRAY);
     bar(0,maxy-20,maxx,maxy);
     rectangle(0,maxy-20,maxx,maxy);
     setcolor(BLACK);
     outtextxy(7,467,"START");
     rectangle(1,maxy-19,50,maxy-1);
     setcolor(8);
     rectangle(2,maxy-18,50,maxy-1);
     delay(500);
     setfillstyle(1,LIGHTGRAY);
     bar(1,250,120,maxy-22);
     setcolor(15);
     rectangle(1,250,120,maxy-22);
     setcolor(BLACK);
     rectangle(2,251,119,maxy-23);
     setcolor(8);
     rectangle(3,252,118,maxy-24);
     setcolor(BLACK);
     outtextxy(20,maxy-40,"ShutDown..");
     line(2,maxy-50,118,maxy-50);
     setcolor(15);
     line(2,maxy-48,118,maxy-48);
     showmouseptr();
     sm=f=1;
	}
   getmousepos(&button,&x,&y);

     while(sm==1 && f==1 && x>2 && x<118 && y>maxy-50 && y<maxy-24)
	{
	hidemouseptr();
	setfillstyle(1,BLUE);
	bar(3,maxy-46,117,maxy-25);
	setcolor(BLACK);
	outtextxy(20,maxy-40,"ShutDown..");
	showmouseptr();
	getmousepos(&button,&x,&y);
	f++;
	j=1;
	}
     while(sm==1 && f>1 && (x<2 || x>118 || y<maxy-50 || y>maxy-24))
	{
	hidemouseptr();
	setfillstyle(1,LIGHTGRAY);
	bar(3,maxy-46,117,maxy-25);
	setcolor(BLACK);
	outtextxy(20,maxy-40,"ShutDown..");
	showmouseptr();
	getmousepos(&button,&x,&y);
	f=1;
	}
     getmousepos(&button,&x,&y);
     if(button!=0 && f>1 && x>2 && x<118 && y>maxy-50 && y<maxy-24)
	{
	exit();
	}
   if(button!=0 && (x>50 || y<(maxy-19)))
	{
     hidemouseptr();
     setfillstyle(1,7);
     bar(0,maxy-20,maxx,maxy);
     rectangle(0,maxy-20,maxx,maxy);
     setcolor(BLACK);
     outtextxy(6,466,"START");
     rectangle(1,maxy-19,50,maxy-1);
     setcolor(8);
     rectangle(1,maxy-19,49,maxy-2);
     setfillstyle(1,8);
     bar(0,0,maxx,maxy-22);
     j=2;
     sm=0;
     showmouseptr();
     	}

   if(button==2)
	{
     hidemouseptr();
     getmousepos(&button,&x,&y);
     setcolor(15);
     c=x;
     a=x+103;
     b=y+200;
     setfillstyle(1,7);
     bar(c,y,a,b);
     rectangle(c,y,a,b);
     d=y;
     line(c,y+21,a,y+21);
     setcolor(8);
     line(c,y+22,a,y+22);
     setcolor(BLACK);
     outtextxy(c+20,y+8,"  EXIT");
     k=0;j=1;
     showmouseptr();
     delay(10000);
	}
     getmousepos(&button,&x,&y);

     while(x>c && x<a && y>d && y<d+21)
	{
      if(k==0 && j!=2)
		{
      hidemouseptr();
      setfillstyle(1,BLUE);
      bar(c+1,d+1,a-1,d+20);
      setcolor(BLACK);
      outtextxy(c+20,d+8,"  EXIT");
      k=1;
      showmouseptr();
		}
      if(button!=0 && j!=2 && (x>c && x<a && y>d && y<d+21))
		{
	 exit();
		}
      getmousepos(&button,&x,&y);
	}
    while(k==1 && j!=2 && ((x<c || x>a) || (y<d || y>d+21)))
	{
     hidemouseptr();
     setfillstyle(1,7);
     bar(c+1,d+1,a-1,d+20);
     setcolor(BLACK);
     outtextxy(c+20,d+8,"  EXIT");
     showmouseptr();
     k=0;
	}
   }
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
}
