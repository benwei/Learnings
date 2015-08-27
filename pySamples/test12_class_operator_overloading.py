#!/usr/bin/env python
# tested with Python version
# 2.7.6 osx 10.10.4,
# 3.4.0 ubuntu 14.04
class Score:
	def __init__(self, name, score):
		self.score = int(score)
		self.name = name

	def __add__(self, x):
		return Score(self.name+"+"+x.name,self.score + x.score)

	def __sub__(self, x):
		return Score(self.name+"-"+x.name,self.score - x.score)

	def __eq__(self, x):
		if self.score == x.score:
			return True
		return False

	def __str__(self):
		return str(self.score)

	def __gt__(self, x):
		if self.score > x.score:
			return True
		return False

	def __lt__(self, x):
		if self.score < x.score:
			return True
		return False

	def __ge__(self, x):
		if self == x:
			return True
		elif self > x:
			return True
		else:
			return False
	def __repr__(self):
		return "Score(\"%s\", %d)" % (self.name, self.score)

	def hex(self):
		return format(self.score,'x')

def compare(a, b):
	if (a == b):
		print("%s == %s" % (repr(a), repr(b)))
	elif (a > b):
		print("%s > %s" % (repr(a), repr(b)))
	else:
		print("%s < %s" % (repr(a), repr(b)))

def main():

	a = Score('a', 10)
	b = Score('b', 20)
	c = Score('c', 10)
	d = Score('d', 99)

	compare(a, b)
	compare(c, a)

	print("%s + %s = %s" % (repr(a), repr(b), a+b))
	print("%s - %s = %s" % (repr(a), repr(b), a-b))
	print("%s.hex() = %s" %(repr(d), d.hex()))

if __name__ == "__main__":
	main()
