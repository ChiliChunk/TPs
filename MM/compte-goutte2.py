import time

def cpi(N):
	dateDebut = time.time()
	a, b, a1, b1 = 4, 1, 12, 4
	s = ""
	p, q = 1, 3
	while N >= 0:
		print N
		p, q = p+q, q+2
		a, b, a1, b1 = a1, b1, p*a+q*a1, p*b+q*b1
		d, d1 = a//b, a1//b1
		while d == d1 and N >= 0:
			s += str(d)
			N -= 1
			a, a1 = 10*(a%b), 10*(a1%b1)
			d, d1 = a//b, a1//b1

	dateFin = time.time()
	temps = dateFin - dateDebut
	#print s[0] + "," + s[1:] , temps
	return temps

n= 10000000
val = cpi(n)
print("nb iterations: "+str(n))
print ('en '+str(val)+' s')
