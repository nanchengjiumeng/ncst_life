#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct list_ele{
	std::string address= "";
	int data = -1;
	std::string next= "";
};



int main(){
	vector<list_ele> list;
	std::string start = "";
	int l_n = -1, r_size = -1;
	std::cin>>start>>l_n>>r_size;
	std::string address="",next="";
	int data=-1;
	list_ele *ele;
	for(int i = 0; i<l_n; i++){
		ele = new list_ele();
		std::cin>>ele->address>>ele->data>>ele->next;
		list.push_back(*ele);
	}
	
	
	std::vector<list_ele>::iterator begin = list.begin(),end = list.end();	
	std::vector<list_ele> out_list;
	while(start!="-1"){
		//cout<<start<<"***********\n";
			while(begin->address!=start){
				begin++;
			}
			out_list.push_back(*begin);
			start = begin->next; 
			begin = list.begin();
	}
	//cout<<"what?\n";
	l_n = out_list.size() ;
	begin = out_list.begin();
	end = begin;
	int group = l_n/r_size;
	int remain = l_n%r_size;
	for(int i =0; i<group;i++){
		end = end + r_size-1;
		while(end>=begin){
			std::cout<<end->address<<' '<<end->data<<' '<<end->next<<std::endl;
			end--;
		}
		begin= begin+r_size;
	}
	for(int i = 0; i<remain ;i++){
		std::cout<<begin->address<<' '<<begin->data<<' '<<begin->next<<std::endl;
		begin++;
	}

	
	
	
	return 0;
}