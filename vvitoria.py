# coding: utf-8
# Rodrigo Farias de Macêdo

testes = 0
output = []
x = int(raw_input())
while x != 0:
	testes += 1
	J = 0
	Z = 0
	output.append("Teste " + str(testes))
	for i in range(x):
		dep = raw_input().split()
		J = int(dep[0]) + J
		Z = Z + int(dep[1])
		output.append(J - Z)
	x = int(raw_input())

for i in range(len(output)):
	if type(output[i]) == type("as"):
		print 
	print output[i]
