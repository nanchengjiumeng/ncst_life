#include <iostream>
#include <string>
using namespace std;

string theSame(string &a,string &b){
	string s = "";
	int n = a.size();
	char c;
	int  ix =-1,iy=-1;
	for(int i = 0;i<n;i++){
		c = a[i];
		if(ix >=0){
			if(((c>='0' && c<='9')||(c>=65 && c<=78)) && a[i]==b[i]){
				iy=i;
				break;
				}
		}else{
			if(c>=65 && c<=71 && a[i]==b[i]){
				ix=i;
			} 
		}
	}   
	s=s+a[ix]+a[iy];
	return s;
}
int theSameIndex(string &a,string &b){
	int index=-1;
	int n = a.size();
	int m = b.size();
	char c;
	for(int i = 0;i<n;i++){
		c=a[i];
		if(c>='a' && c<='z' &&a[i]==b[i]){
			index=i;
			break;
		}
				
	}    
	return index;
}
int dateForm(string &a,int i){
	string week[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int w = a[0]-'A';
	if(a[1]>=65){
		int o = a[1]-'A'+10;
		cout << week[w] << ' ' << o <<':';
	}else{
		int o = a[1];
		cout << week[w] << " 0" << o-48 <<':';
	}
	

	if(i<10){
		cout << '0' << i;
	}else{
		cout << i;
	}
	return 0;
}

int main(){
	string s,s1,s2,s3,s4;	
	int index;
	cin >> s1 >> s2 >> s3 >> s4 ;
	
	s= theSame(s1,s2);
	index=theSameIndex(s3,s4);
	dateForm(s,index);
	
	return 0;
}