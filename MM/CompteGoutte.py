import math

def CompteGoutte (nb):
	nb = nb + 8
	a = 10000
	b = 0
	c = 1 + math.floor(nb * 3.32)
	d = 0
	e = 0
	g = 0
	v = 0
	val = ""
	f = []

	while(b<=c):
		b+=1
		f.append(math.floor(a / 5))
	while (c > 0):
		g = 2 * c
		d = 0
		b = c
		while (b > 0):
			z=int(b)
			d =d+ f[z] * a
			g=g-1;
			f[z] = d % g
			d = math.floor (d / g)
			g=g-1
			b=b-1
			if (b != 0):
				d *= b
		c -= 14
		v = int(e + math.floor (d / a))
		v = str(v)
		if (v < 1000):
			v = "0" + v
		if (v < 100):
			v = "0" + v
		if (v < 10):
			v = "0" + v
		if (v < 1):
			v = "0" + v
		val += v
		e = d % a
	chaine = ""
	i=1
	j=1
	val = val[1:]
	return val
