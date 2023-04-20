#include<stdio.h>
#include<string.h>
#include<conio.h>

void main()
{      char a[20],b[20];
	char str[20][20]={{'\0'}};
	int depth,i,j,k=0;
	clrscr();
	printf("Enter the String:");
	gets(a);
	printf("Enter the depth:");
	scanf("%d",&depth);

	for(i=0;i<strlen(a);i++)
	{
	 str[i%depth][i]=a[i];

	}
       for(i=0;i<depth;i++)
       {
		for(j=0;j<strlen(a);j++)
		{
		  if(str[i][j]!=NULL)
		  {
	       //	  printf("%c\t",str[i][j]);
		 b[k]=str[i][j];
		  k++;
		  }

		}

       }
       b[k]='\0';
	printf("----------------Encrpyted Message-------------\n");
	puts(b);


      getch();
}