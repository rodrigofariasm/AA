# coding: utf-8
# Rodrigo Farias de Macêdo

entrada = raw_input().split()
A  = float(entrada[0])
G  = float(entrada[1])
RA  = float(entrada[2])
RG  = float(entrada[3])

if ((RG/G) >= (RA/A)):
	print "G"
else:
	print "A"