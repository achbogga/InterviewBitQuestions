def Dec2Bin(N):
	return int(bin(N)[2:])

def solution(N):
	B = bin(N)[2:]
	if (len(B)<=2):
		return 0;
	else:
		Gaps = []
		Flag_for_ones = False
		count = 0
		for i in range(len(B)):
			if( ((B[i])=='1') and (not(Flag_for_ones)) ):
				Flag_for_ones = True
			elif( ((B[i])=='0') and (Flag_for_ones) ):
				count +=1
			elif( ((B[i])=='1') and (Flag_for_ones) ):
				Gaps.append(count)
				count = 0
		if (len(Gaps) == 0):
			return 0
		else:
			return max(Gaps)

#main
print (solution(8))
