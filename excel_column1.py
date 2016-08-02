class Solution:
	def convertToTitle(self,A):
		i = 0
		Temp = A
		result = []
		while(Temp>26):
			result.append(chr((Temp%26)+65))
			Temp //= 26
		result.append(chr(Temp+65))
		result = ''.join(result)
		result = result[::-1]
		return str(result)

#main

S = Solution()
print (S.convertToTitle(52))
