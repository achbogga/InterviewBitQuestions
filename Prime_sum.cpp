#include<iostream>
#include<math.h>
#include<cstdlib>
#include<climits>
#include<vector>
using namespace std;

//A function to check if a given number is prime or not?
__int64 power(int a, int n, int mod)
{
 __int64 power=a,result=1;

 while(n)
 {
  if(n&1) 
   result=(result*power)%mod;
  power=(power*power)%mod;
  n>>=1;
 }
 return result;
}

bool witness(int a, int n)
{
 int t,u,i;
 __int64 prev,curr;

 u=n/2;
 t=1;
 while(!(u&1))
 {
  u/=2;
  ++t;
 }

 prev=power(a,u,n);
 for(i=1;i<=t;++i)
 {
  curr=(prev*prev)%n;
  if((curr==1)&&(prev!=1)&&(prev!=n-1)) 
   return true;
  prev=curr;
 }
 if(curr!=1) 
  return true;
 return false;
}

inline bool IsPrime( int number )
{
 if ( ( (!(number & 1)) && number != 2 ) || (number < 2) || (number % 3 == 0 && number != 3) )
  return (false);

 if(number<1373653)
 {
  for( int k = 1; 36*k*k-12*k < number;++k)
  if ( (number % (6*k+1) == 0) || (number % (6*k-1) == 0) )
   return (false);

  return true;
 }

 if(number < 9080191)
 {
  if(witness(31,number)) return false;
  if(witness(73,number)) return false;
  return true;
 }


 if(witness(2,number)) return false;
 if(witness(7,number)) return false;
 if(witness(61,number)) return false;
 return true;

 /*WARNING: Algorithm deterministic only for numbers < 4,759,123,141 (unsigned int's max is 4294967296)
   if n < 1,373,653, it is enough to test a = 2 and 3.
   if n < 9,080,191, it is enough to test a = 31 and 73.
   if n < 4,759,123,141, it is enough to test a = 2, 7, and 61.
   if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11.
   if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13.
   if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.*/
}

// A function to print all the primes until a given number n
vector<int> Give_Primes_until_n(int n) {
    vector<int> primes;
    primes.push_back(2);
    for(int i=3; i < n; i++)
    {
        bool prime=true;
        for(unsigned int j=0;j<primes.size() && primes[j]*primes[j] <= i;j++)
        {
            if(i % primes[j] == 0)
            {
                prime=false;
                break;
            }
        }
        if(prime) 
        {
            primes.push_back(i);
            //cout << i << " ";
        }
    }
    return primes;
}

//A function to return a pair from a given array which sums up to a given number
vector< vector<int> > Give_Pair(vector<int> arr,int sum)
{
	vector< vector<int> > Results;
	int len = arr.size(); 
	int i = 0;
    int j = len -1;
    while( i < j){
		while((arr[i] + arr[i]) <= sum && i < j)
        {
			if((arr[i] + arr[i]) == sum) {
				vector<int> result;
                result.push_back(arr[i]);
                result.push_back(arr[i]);
                Results.push_back(result);
                //return Results;
            }
            i++;
		}
		i=0;
        while((arr[i] + arr[j]) <= sum && i < j)
        {
            if((arr[i] + arr[j]) == sum) {
				vector<int> result;
                result.push_back(arr[i]);
                result.push_back(arr[j]);
                Results.push_back(result);
                //return Results;
            }
            i++;
        }
        j--;
        while((arr[i] + arr[j]) >= sum && i < j)
        {
            if((arr[i] + arr[j]) == sum) {
				vector<int> result;
                result.push_back(arr[i]);
                result.push_back(arr[j]);
                Results.push_back(result);
                //return Results;
            }
            j--;
        }
    }
    return Results;
}

vector<int> primesum(int A) {
	vector<int> result;
	vector<int> primes = Give_Primes_until_n(A);
    vector< vector<int> > Results = Give_Pair(primes, A);
    if (!Results.size())
    return result;
    else {
		result = Results[0];
		for (unsigned int i=0; i<Results.size();i++)
			for (unsigned int j=0; j<Results[i].size();j++)
				if ( (Results[i][0]<result[0]) || ( (Results[i][0]==result[0]) && (Results[i][1]<result[1]) ) ) {
					//IT means that the result needs to be swapped with this entry.
					result = Results[i];
				}
	return result;
	}
}

vector< vector<int> > primesum1(int A) {
	vector<int> primes = Give_Primes_until_n(A);
    vector< vector<int> > Results = Give_Pair(primes, A);
    return Results;
}

int main() {
	//primesum1
	vector< vector<int> > primes = primesum1(10);
	for (unsigned int i=0; i<primes.size();i++)
		for (unsigned int j=0; j<primes[i].size();j++)
			cout<<primes[i][j]<<"\n";
			
	/*vector<int> primes = primesum(10);
	for (unsigned int i=0; i<primes.size();i++)
		cout<<primes[i]<<"\n";
	*/
	return 0;
}
