# coding: utf-8
# Rodrigo Farias de Mac�do

input1 = map(int, raw_input().split())
input2 = map(int, raw_input().split())
input2.sort()
clone = input2[:]
maximo = 0
minimo = 0
for i in range(input1[0]):
	maximo += input2[input1[1]-1]
	input2[input1[1]-1] -= 1
	minimo += clone[0]
	clone[0] -= 1
	if clone[0] == 0:
		del clone[0]
	input2.sort()
	clone.sort()

print maximo, minimo
