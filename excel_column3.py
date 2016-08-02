class Solution:
	def convertToTitle(self,A):
		div = A
		string = ""
		temp = 0
		while(div>0):
			module = (div-1)%26
			string = chr(65+module)+string
			div = (div-module)//26
		
		return string

#main

S = Solution()
print (S.convertToTitle(52))
