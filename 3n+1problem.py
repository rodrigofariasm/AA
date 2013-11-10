# coding: utf-8
# Rodrigo Farias de Macêdo
def cycleLength(x):
	z = 1
	while(x != 1 ):
		if x%2 == 0:
			x = x/2
		else:
			x = 3*x +1
		z += 1
	return z


entrada = raw_input()
while(entrada != ""):
	entrada = entrada.split()
	x = int(entrada[0])
	y = int(entrada[1])
	max = 0

	for i in range(x, y, 1):
		a = cycleLength(i)
		if a > max:
			max  = a
	print x, y, max
	entrada = raw_input()


