#include <iostream>
#include <math.h>
#define MAX 100005

using namespace std;

void print_address(long int a){
	if(a==-1){
		cout<<-1;
		return;
	}
	if(a<10000){
		cout<<'0';
	}
	if(a<1000){
		cout<<'0';
	}
	if(a<100){
		cout<<'0';
	}
	if(a<10){
		cout<<'0';
	}
	cout<<a;
	return;
}
void print_f(long int start, long int data, long int next){
	print_address(start);
	std::cout<<' '<<data<<' ';
	print_address(next);
	std::cout<<endl;
}

int main()
{
	long int data[MAX]  ={0},next[MAX]={-1},pre[MAX]={-1};
	long int start, n,K=0,i=0,next_i,m;
	long int cur_a, next_a, cur_d;
	std::cin>>start>>n>>K;
	for(;i<n;i++){
		std::cin>>cur_a>>cur_d>>next_a;
		data[cur_a]=cur_d;
		next[cur_a]=next_a;
		if(next_a>=0){
			pre[next_a]= cur_a;
		}
		
	}
	i=0,n=0;
	next_i=start;
	while(next_i!=-1){
		n++;
		next_i = next[next_i];
	}
	long int c = n/K;
	//std::cout<<c<<std::endl;
	while(start!=-1){
		if(c){
			i=1;
			while(i<K){
				start = next[start];
				i++;
			}
			next_i = next[start];
			while(i>0){
				
				if(i==1){
					print_f(start, data[start],next_i);
					start = next_i;
				}else{
					print_f(start, data[start], pre[start]);
					start= pre[start];
				}
				i--;
			}		
			c--;
		}else{
			print_f(start, data[start], next[start]);
			start= next[start];
		}
		
	}
	
	return 0;
}