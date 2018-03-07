#include <stdio.h> 
#include<stdlib.h>
#define MAX 255 
int R[MAX]; 

void ShellPass(int d, int n) 
{
	// One pass of shell sort, d is the current pass increment        希尔排序中的一趟排序， d 为当前增量 
	int i,j; 
	for(i=d+1;i<=n;i++)	//The subscript begins with Zero        下标从零开始 /*将R[d+1．．n]分别插入各组当前的有序区 */ 
	{
		if(R[i]<R[i-d]) 
		{ 
			R[0]=R[i];j=i-d;								/* R[0] 只是暂存单元，不是哨兵  */ 
			
			do 
			{												/*  查找R[i]的插入位置  */ 
				R[j+d]=R[j];								/*  后移记录  */ 
				j=j-d;										/*  查找前一记录 */ 
			
			}while(j>0&&R[0]<R[j]); 
			
			R[j+d]=R[0];									 /* 插入 R[i]到正确的位置上  */ 
		}
	}
} 
 
void  Shell_Sort(int n) 
{
	int i;
	//int increment = n; //公式计算                            增量初值，设 n>0 
	int increment = 5;   //构造增量
	do 
	{ 
		//increment=increment/3+1;   //公式计算                 求下一增量
		ShellPass(increment,n);                                //一趟增量为increment 的Shell插入排序
		printf("The result sequence after sort by the increment of %d\n",increment);
		
		for(i=1;i<=n;i++)
		{
			printf("%4d",R[i]);
		}
		printf("\n");
		
		increment = increment - 2;   //构造增量

	}
	//while(increment>1);    //公式计算
	while(increment>=1);     //构造增量
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
