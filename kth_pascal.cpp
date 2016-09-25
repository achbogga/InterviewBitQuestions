#include<iostream>
#include<vector>
using namespace std;

vector<int> getRow(int A) {
// Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> result;
    //vector< vector<int> > triangle;
    if(A == 0) {
		result.push_back(1);
	}
	else if (A==1) {
		result.push_back(1);
		result.push_back(1);
	}
	else if (A==2) {
		result.push_back(1);
		result.push_back(2);
		result.push_back(1);
	}
	else {
		result.push_back(1);
		vector<int> previous_row = getRow(A-1);
		for (int column = 1;column<A;column++) {
			result.push_back(previous_row[column-1]+previous_row[column]);
		}
		result.push_back(1);
	}
	return result;
}
int main() {
	vector<int> Result = getRow(5);
	for (unsigned int i=0;i<Result.size();i++)
		cout <<Result[i]<<"\n";
	return 0;	
}
