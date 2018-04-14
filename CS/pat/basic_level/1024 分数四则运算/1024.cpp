#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>



using namespace std;
using std::string;




int my_stoi (string::iterator begin, string::iterator end, string::size_type n){
	int sum = 0,b = 10, p_m = 1;
	if(*begin == '-'){ p_m = -1; begin++; n--;}
	while(begin!=end){
		int c = *begin - '0', p =round(pow(10,n--)); 
		sum += c*p;
		begin++;
	}
	return sum*p_m;
}

int GCD(int a,int b){
	if(b==0){
		return a;
	}else{
		return GCD(b,a%b);
	}
}

int GCDG(int a, int b){
	return a*b/GCD(a,b);
}

void print_f(const vector<int> &a){
	if(a[0]==0){
		cout<<'0';
		return;
	}
	cout<<'*' <<a[1]<<'*'<<a[0] <<endl;
	if( a[1]==0 )
	{
		cout<<"Inf";
		return;
	}
	if(a[0]*a[1]<0){cout<<"(-";}
	int i = a[0]/a[1];
	int top  = a[0]%a[1];
	
	
	if(i!=0){ cout<<abs(i); }
	if(i!=0 && top!=0){
		cout<<' ';
	}
	
	if( top !=0 ){
		int g = GCD(top,a[1]);
		cout<< abs( top/g )<< '/' << abs( a[1]/g );
	}
	if(a[0]*a[1]<0){cout<<')';}
}

void print_ff(const vector<int> &a, const vector<int> &b, const vector<int> &res, char c){
	print_f(a);
	cout<<' '<<c<<' ';
	print_f(b);
	cout<<" = ";
	print_f(res);
	cout<<endl;
}

void a_plus_b(const vector<int> &a, const vector<int> &b){
	int g = GCDG(a[1],b[1]);
	vector<int> res ;
	int res_t = a[0]*(g/a[1]) + b[0]*(g/b[1]);
	res.push_back( res_t );
	res.push_back( g );
	
	print_ff(a,b,res,'+');
}
void a_minus_b(const vector<int> &a, const vector<int> &b){
	int g = GCDG(a[1],b[1]);
	vector<int> res ;
	int res_t = a[0]*(g/a[1]) - b[0]*(g/b[1]);
	res.push_back( res_t );
	res.push_back( g );
	
	print_ff(a,b,res,'-');
}
void a_times_b(const vector<int> &a, const vector<int> &b){
	vector<int> res ;
	int res_t = a[0]*b[0];
	int res_b = a[1]*b[1];
	res.push_back( res_t );
	res.push_back( res_b );
	
	print_ff(a,b,res,'*');
}
void a_divide_b(const vector<int> &a, const vector<int> &b){
	vector<int> res ;
	//if(b[0]/b[1] == 0){
		//res.push_back(1);
		//res.push_back(0);
		//print_ff(a,b,res,'/');
	//}else{
		int res_t = a[0]*b[1];
		int res_b = a[1]*b[0];
		//cout<<res_t <<"   "<<res_b<<endl;
		res.push_back( res_t );
		res.push_back( res_b );
	
	
		print_ff(a,b,res,'/');
		
	//}
	
}

void  sto_nd(vector<int> &vec,string s){
	string::size_type n =s.find("/");
	int n_a1 = n-1,n_a2 = s.size()-n-2;
	int a1 = my_stoi(s.begin(),s.begin()+n,n_a1);
	int a2 = my_stoi(s.begin()+n+1,s.end(),n_a2);
	vec.push_back(a1);	
	vec.push_back(a2);
}
 




int main(){
	string s_a="",s_b="";
	vector<int> a,b;
	std::cin>>s_a>>s_b;
	sto_nd(a,s_a);
	sto_nd(b,s_b);
	a_plus_b(a,b);
	a_minus_b(a,b);
	a_times_b(a,b);
	a_divide_b(a,b);

	return 0;
}