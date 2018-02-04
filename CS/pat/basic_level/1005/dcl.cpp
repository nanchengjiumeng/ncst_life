#include <iostream>

using namespace std;



struct stu{
	int n;
	int d;
	int c;
	int l;
};

void swap(stu *a,stu *b){
	stu c;
	c.n=b->n;
	c.d=b->d;
	c.c=b->c;
	c.l=b->l;
	b->n=a->n;
	b->d=a->d;
	b->c=a->c;
	b->l=a->l;
	a->n=c.n;
	a->d=c.d;
	a->c=c.c;
	a->l=c.l;
}

int sort(stu info[],int len,int L,int H){
	int end=len-1;
	for(int i=0;i<=end;i++ ){
		if(info[i].d < L || info[i].c < L){
			info[i].l=5;
			swap(info[i],info[end--]);
			i--;
			if(end==0){return 0;};
		}else{
			if(info[i].d>=H && info[i].c>=H){
					info[i].l=0;
			}else if(info[i].d>=H && info[i].c<H){
					info[i].l=1;
			}else if(info[i].d>=info[i].c){
					info[i].l=2;
			}else{
					info[i].l=3;
			}
		}
	}
	for(int i =0;i<=end;i++){
			for(int j =i+1;j<=end;j++)	{
				if(info[i].l>info[j].l){
					swap(&info[i],&info[j]);
				}else if(info[i].l==info[j].l){
					if(info[i].d+info[i].c<info[j].d+info[j].c){
						swap(&info[i],&info[j]);
					}else if(info[i].d+info[i].c==info[j].d+info[j].c){
						if(info[i].d<info[j].d){
							swap(&info[i],&info[j]);
						}	
					}	
				}
			}
	}
	return end;
};
void callback(int info[],int a,int b){
	
}

int main(){
	// N:the number of students;
	// L:minimum score
	// H:priority 
	int N,L,H;
	cin >> N >> L >> H;
	
	
	//[number,morality,talent]
	stu info[N];
	int i = 0;
	while(i<N){
		cin >> info[i].n >> info[i].d >> info[i].c;
		i++;
	}
	int end = sort(info,N,L,H);
	cout << end+1 << '\n';
	for(int i=0;i<=end;i++){
		cout << info[i].n << ' ' << info[i].d <<' ' <<info[i].c;
		if(i+1<=end){
			 cout<<'\n';
		}else{
			cout<<'*';
		}
	}
	
	return 0;
}