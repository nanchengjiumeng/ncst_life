#include <iostream>
#include <algorithm>
#define MAXSIZE 100004
 
using namespace std;
long long int num[MAXSIZE]={0};

long long int judge_list(long long int num[], long long int n,long long int p){
    long long int  maxCnt=1,iMin,iMax,c;
	for(iMin = 0; iMin<n; iMin++){
		c = num[iMin]*p;
		cout<<num<<'*'<<num+1<<'*'<<num+n<<'8'<<num[n-1]<<endl;
		iMax = upper_bound(num+iMin+1,num+n,c)-num;
		maxCnt = max(maxCnt,iMax - iMin);
	}
    return maxCnt;
}
 
int main(){
    long long int n, p, i;

    std::cin>> n >> p;
    i = 0;
    while(i<n){
        std::cin>>num[i];
        ++i;
    }
    sort(num, num+n);

    std::cout<< judge_list(num,n,p);

    return 0;
}