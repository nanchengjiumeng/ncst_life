#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct Moon_cake{
	double repertory=0;
	double price = 0;
	double  unit_price = 0;
	double get_price(double a){
		double res = 0;
		if(a){
			res = (a/repertory)*price;	
		}
		return res;
	}
	void get_unit_price(){
		unit_price=price/repertory;
	}
};
bool moon_cmp(Moon_cake a,Moon_cake b){
	return a.unit_price>b.unit_price;
}
void sort_moons(Moon_cake a[],unsigned n){
	sort(a,a+n,moon_cmp);
}

int main(){
	Moon_cake a,b,c;
	unsigned  moon_kind =0;
	double qd=0;
	double max_return=0;
	std::cin>>moon_kind>>qd;
	Moon_cake moons[moon_kind];
	for(int i =0; i < moon_kind; i++){
		std::cin>>moons[i].repertory;
	}
	for(int i =0; i < moon_kind; i++){
		std::cin>>moons[i].price;
		moons[i].get_unit_price();
	}
	sort_moons(moons,moon_kind);
	
	int moon_i=0;
	while(qd){
		if(qd>=moons[moon_i].repertory){
			max_return += moons[moon_i].price;
			qd-=moons[moon_i].repertory;
		}else{
			max_return += moons[moon_i].get_price(qd);
			qd=0;
		}
		moon_i++;
		if(moon_i==moon_kind)break;
	}
	
	printf("%.2f",max_return);
	return 0;
}