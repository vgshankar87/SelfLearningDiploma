main()
{
int year, day, month, rem, leaprem, x, y, z, i, jan1, feb2, mar3, apr4, may5, jun6, jul7, aug8, sep9, oct10, nov11;
char a;
jan1 = mar3 = may5 = jul7 = aug8 = oct10 = 31;
apr4 = jun6 = sep9 = nov11 = 30;

clrscr();

do
	{
printf("\n\nEnter A Date AFTER 1 1 1910\nSeperate dd mm yyyy By A SPACE\n");
scanf("%d %d %d",&day, &month, &year);
i = z = x = year - 1900;
y = x % 4;
x = x - y;
leaprem = x / 4;
z = z + leaprem;
rem = z % 7;
y = i % 4;
if(y != 0)
	{
	rem = rem + 1;
	feb2 = 28;
	}
else
	{
	feb2 = 29;
	}
x = day;
if(month >= 2)
	x += jan1;
if(month >= 3)
	x += feb2;
if(month >= 4)
	x += mar3;
if(month >= 5)
	x += apr4;
if(month >= 6)
	x += may5;
if(month >= 7)
	x += jun6;
if(month >= 8)
	x += jul7;
if(month >= 9)
	x += aug8;
if(month >= 10)
	x += sep9;
if(month >= 11)
	x += oct10;
if(month >= 12)
	x += nov11;
x = x-1;
x = x % 7;
rem = rem + x;
if(rem > 7)
rem =  rem - 7;

printf("\nThe Day %d-%d-%d Is ", day, month, year);

if(rem == 1)
printf("MONDAY");

if(rem == 2)
printf("TUESDAY");

if(rem == 3)
printf("WEDNESDAY");

if(rem == 4)
printf("THURSDAY");

if(rem == 5)
printf("FRIDAY");

if(rem == 6)
printf("SATURDAY");

if(rem == 7)
printf("SUNDAY");
printf("\n\nTry Again ?  (Y/N) : ");
scanf("%s", &a);
	} while(a == 'y' || a == 'Y');
}
