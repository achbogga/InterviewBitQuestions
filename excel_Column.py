class Solution:
    def titleToNumber(self, A):
		result = 0
		for i in range(len(A)):
			result += pow (26, int(A[i]-'A'))
		return result

Solution S;
print (S.titleToNumber('AA'))
