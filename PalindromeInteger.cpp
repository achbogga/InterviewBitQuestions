#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
bool isPalindrome(int A1) {
	long A = (long)A1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A<0) return false;
    vector<long> digits;
    while (A>0) {
        digits.push_back(A%10);
        A = A/10;
    }
    vector<long>::iterator b,e;
    b = digits.begin();
    e = digits.end()-1;
    for(unsigned int i=0;i<digits.size()/2;i++) {
		cout<<"\n *b: "<<*b<<"\n *e: "<<*e<<endl;
        if ((*b)!=(*e)) return false;
        b++;
        e--;
    }
    return true;
}

int main() {
	cout<<"\n"<<isPalindrome(2147447412)<<"\n";
	return 0;
}
