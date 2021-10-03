main()
{
int n,i,k,x;
clrscr();
printf("\t\t\tPrime Numbers\n");
printf("\tEnter A Range <:> ");
scanf("%d",&x);
printf("\t\tThe Prime Numbers Upto %d Are ,\n",x);

n=1;
while(n<=x)
  {
  i=1;
  k=0;
  while(i<=n)
	{
	if(n%i==0) k++;
	i++;
	}
  if(k==2) printf("%d \t",n);
  n++;
  }
getch();
}