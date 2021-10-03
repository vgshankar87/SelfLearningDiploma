#include<dos.h>
#include<graphics.h>
union REGS i,o;
struct SREGS s;
int cursor[32]={
		0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,
                0x0000,0x0000,0x0000,0x0000,

		0x1e00,0x1200,0x1200,0x1200,
		0x13ff,0x1249,0x1249,0xf249,
		0x9001,0x9001,0x9001,0x8001,
		0x8001,0x8001,0xffff,0xffff
		};
main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"");

gotoxy(10,1);
printf("Press Any Key To Exit");
changecursor(cursor);
showmouseptr();
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
changecursor(int *shape)
{
i.x.ax=9;
i.x.bx=0;
i.x.cx=0;
i.x.dx=(unsigned)shape;
segread(&s);
s.es=s.ds;
int86x(0x33,&i,&i,&s);
}