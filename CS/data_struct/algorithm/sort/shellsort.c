#include <stdio.h> 
#include<stdlib.h>
#define MAX 255 
int R[MAX]; 

void ShellPass(int d, int n) 
{
	// One pass of shell sort, d is the current pass increment        ϣ�������е�һ������ d Ϊ��ǰ���� 
	int i,j; 
	for(i=d+1;i<=n;i++)	//The subscript begins with Zero        �±���㿪ʼ /*��R[d+1����n]�ֱ������鵱ǰ�������� */ 
	{
		if(R[i]<R[i-d]) 
		{ 
			R[0]=R[i];j=i-d;								/* R[0] ֻ���ݴ浥Ԫ�������ڱ�  */ 
			
			do 
			{												/*  ����R[i]�Ĳ���λ��  */ 
				R[j+d]=R[j];								/*  ���Ƽ�¼  */ 
				j=j-d;										/*  ����ǰһ��¼ */ 
			
			}while(j>0&&R[0]<R[j]); 
			
			R[j+d]=R[0];									 /* ���� R[i]����ȷ��λ����  */ 
		}
	}
} 
 
void  Shell_Sort(int n) 
{
	int i;
	//int increment = n; //��ʽ����                            ������ֵ���� n>0 
	int increment = 5;   //��������
	do 
	{ 
		//increment=increment/3+1;   //��ʽ����                 ����һ����
		ShellPass(increment,n);                                //һ������Ϊincrement ��Shell��������
		printf("The result sequence after sort by the increment of %d\n",increment);
		
		for(i=1;i<=n;i++)
		{
			printf("%4d",R[i]);
		}
		printf("\n");
		
		increment = increment - 2;   //��������

	}
	//while(increment>1);    //��ʽ����
	while(increment>=1);     //��������
} 
 
void main() 
{ 
    int i,n; 
    //clrscr(); 
 /*   puts("Please input the amount of the sequence:"); 
    scanf("%d",&n);
    
	if(n<=0||n>MAX) 
    { 
        printf("n must more than 0 and less than %d.\n",MAX); 
        exit(0); 
    } 
    puts("Please input the elements one by one:"); 
    
	for(i=1;i<=n;i++) 
	{
        scanf("%d",&R[i]); 
	}*/
	int a[] = {49,38,65,97,76,13,27,49,55,04};

	for (i=1;i<=10;i++)
	{
		R[i] = a[i-1];
	}
	n=10;
    puts("The sequence you input is:"); 

    for(i=1;i<=n;i++)
	{
        printf("%4d",R[i]);
	}
	printf("\n");

    Shell_Sort(n); 

    puts("\nThe sequence after shell_sort is:"); 
    for(i=1;i<=n;i++)
	{
        printf("%4d",R[i]); 
	}
	puts("\n");
    system("pause");
  
}
