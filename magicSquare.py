# coding: utf-8
# Rodrigo Farias de Macêdo

line1 = map(int, raw_input().split())
line2 = map(int, raw_input().split())
line3 = map(int, raw_input().split())

s1 = line1[1]+line1[2]
s2 = line2[0]+line2[2]
s3 = line3[1]+line3[0]

lmax = s1
if s2 > s1:
	lmax = s2
	if s3 > s2:
		lmax = s3
elif s3 > s1:
	lmax = s3
line1[0] = lmax - s1
line2[1] = lmax - s2
line3[2] = lmax - s3

while (line1[0] + line2[1] + line3[2]) < lmax:
	line1[0] += 1
	line2[1] += 1
	line3[2] += 1
	lmax += 1
print line1[0] , line1[1] , line1[2]
print line2[0] , line2[1] , line2[2]
print line3[0] , line3[1] , line3[2]