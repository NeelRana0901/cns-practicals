#include<stdio.h>
#include<conio.h>
#include<math.h>
int gcd(int a,int h)
{
  int temp;
    while (1)
    {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }  
}

void main()
{
  int n,p,q,t,e,d,mlen,c,m,q1,a[3],b[3],temp[3],i;
  
  printf("Enter the 1st prime number(p): ");
  scanf("%d",&p);

  printf("\nEnter the 2nd prime number(q): ");
  scanf("%d",&q);

  n = p * q;

  printf("\nSo the value of n(n=p*q) = %d",n);

  t = (p-1) * (q-1);
  printf("\nEuler Totient's value (phi(n)) = %d",t);

  printf("\nEnter e (such that it is relatively prime to phi(n)): ");
  scanf("%d",&e);
  
  a[0]=1;
  a[1]=0;
  a[2]=t;
  
  b[0]=0;
  b[1]=1;
  b[2]=e;
  
  
  while(b[2]!=1 && b[2]!=0)
  {
      q1 = a[2]/b[2];
      
      temp[0]=a[0]-(q1*b[0]);
      temp[1]=a[1]-(q1*b[1]);
      temp[2]=a[2]-(q1*b[2]);
      
      a[0]=b[0];
      a[1]=b[1];
      a[2]=b[2];
      
      b[0]=temp[0];
      b[1]=temp[1];
      b[2]=temp[2];
      
  }
  
  if(b[2]==0)
  {
      printf("\nDecryption key not possible as inverse does not exist");
  }
  if(b[2]==1)
  {
      if(b[1]>0)
      {
        d=b[1];
        printf("\nDecryption key of %d = %d",e,b[1]);
      }
      if(b[1]<0)
      {
        d=t+b[1];
        printf("\nDecryption key of %d = %d",e,e+b[1]);
      }
  }
  
  printf("\nEnter the msg length(M): ");
  scanf("%d",&mlen);
  
  //c = pow(mlen,e);
  //c = fmod(c,n);
  
  c=mlen;
  for(i=2;i<=e;i++)
  {
  	c=(c*mlen)%n;
  }
  
  printf("Cipher Text(C): %d",c);
  
  m=c;
  for(i=2;i<=d;i++)
  {
  	m=(m*c)%n;
  }

  
  printf("\nOriginal Message(M): %d",m);
  
  getch();
}