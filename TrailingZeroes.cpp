#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
long long factorial(int n) {
	long long result = 1;
	for (int i=n;i>0;i--) {
		result*=(long long)i;
	}
	return result;
}
int trailingZeroes(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count = 0;
    long long F = factorial(A);
    while((F%10)==0){
		count++;
		F /= 10;
	}
	return count;
}
int intlog(double base, double x) {
    return (int)(log(x) / log(base));
}
int trailingZeroc(int A) {
	int count = 0;
	for(int i=1;i<=intlog(5,A);i++) {
		count += floor(A/pow(5,i));
	}
	return count;
}
int main() {
	for(int i=1;i<50;i++){
		cout<<"\n"<<i<<" : "<<factorial(i)<<" : "<<(i/5)<<" : "<<trailingZeroc(i)<<"\n";
	}
	return 0;
}
