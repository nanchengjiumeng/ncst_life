#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define List_Max 100000

struct ln{
	int address =-1;
	int data = -1;
	int next = -1;
	ln *next_n  = NULL;
};
void printf_address(int a){
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
}

int main(){
	//int lds[List_Max]={-1};
	int data= -1;
	int l_start = -1, ci_n = 0, r_n = 0;
	cin >> l_start >> ci_n >> r_n;
	vector<ln> list;
	ln *ln_;
	for(int i = 0; i<ci_n ; i++){
		ln_ = new ln();
		cin >> ln_->address >> ln_->data >> ln_->next;
		list.push_back(*ln_);
		ln_=NULL;
	}
	

	
	vector<ln>::iterator begin= list.begin(),end = list.end();
	vector<ln>::iterator list_begin= list.begin(),list_end = list.end();
	
	
	vector< ln > o_list;
	while( l_start > -1 ){
		while( begin->address != l_start )
			begin++;
		o_list.push_back(*begin);
		l_start = begin->next;
		begin = list_begin;
	}
	int o_len = o_list.size();
	ln *p_start = &(o_list[0]);
	int o_g = o_len/r_n;
	int o_r = o_len%r_n;
	int o_f = 0;
	int p2 =0;
	if(o_g)
		o_f = r_n-1;
		p_start = &(o_list[o_f]);
		p2 = o_f;
	for(int i =0;i<o_g;i++){
		for( int j = 0; j < r_n; j++ ){
			if(j == r_n-1){
				if(o_len>p2+1) o_list[p2-j].next_n = &(o_list[p2+1]);
			}else{
				o_list[p2-j].next_n = &(o_list[p2-j-1]);
			}	
		}
		if(i<o_g-1)
			p2 = p2+r_n;
		else 
			p2++;
	}
	for(int i =0; i<o_r;i++){
		if(p2+i<o_len-1){
				o_list[p2+i].next_n = &(o_list[p2+i+1]);
		}
	}
	
	int no_address =-1;
	while(p_start){
		printf_address(p_start->address);
		cout<<' '<< p_start->data<<' ';
		p_start = p_start->next_n;
		if(p_start){
			printf_address(p_start->address);
			cout<<endl; 
		}else{
			cout<< no_address <<endl;
		}
		
	}
	
	return 0;
}