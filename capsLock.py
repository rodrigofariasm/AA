# coding: utf-8
# Rodrigo Farias de Macêdo

entrada = raw_input()
if len(entrada) == 1 and entrada.lower() == entrada:
	entrada =  entrada.upper()
elif(entrada.upper() == entrada ):
	entrada =  entrada.lower()
elif len(entrada) != 1 and entrada[1:].upper() == entrada[1:] and entrada[0:1] == entrada[0:1].lower():
	entrada =  entrada[0:1].upper() + entrada[1:].lower()
print entrada