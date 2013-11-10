# coding: utf-8
# Rodrigo Farias de Macêdo

entrada = raw_input().split()
n = int(entrada[0])
k = int(entrada[1])
entrada2 = raw_input().split()

passa = 0
i = 0

assert(len(entrada2) == n)

while(i < n and int(entrada2[i]) >= int(entrada2[k-1]) and int(entrada2[i]) > 0):
	passa += 1
	i += 1
print passa
