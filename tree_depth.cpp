#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class btree {
	vector<T> postTC;
	vector<T> preTC;
	vector<T> inTC;
	btree *root;
	public:
		bool is_empty() {
			if (root == NULL)return true;
			else return false;
		}
};
int main() {
	btree <int> int_tree;
	cout<<endl<<int_tree.is_empty()<<endl;
	return 0; 
}
