import re

f =open('txt')
lines=f.readlines()
f.close

filex = open('txt1','a')

for x in lines:
	x = x.replace("//"," ")
	y = x.split(" ")
	z = "f" + " " + y[1] + " " + y[3] + " " + y[5] + "\n"
	filex.write(z)

