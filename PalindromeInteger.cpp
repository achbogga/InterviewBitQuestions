#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
bool Solution::isPalindrome(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A<0) return false;
    vector<int> digits;
    while (A>0) {
        digits.push_back(A%10);
        A = A/10;
    }
    vector<int>::iterator b,e;
    b = digits.begin();
    e = digits.end();
    while(b!=e) {
        if ((*b)!=(*e)) return false;
    }
    return true;
}
