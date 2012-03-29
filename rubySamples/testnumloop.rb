#!/usr/bin/env ruby
# -*- encoding : utf-8 -*-

def newLine()
	print "\n"
end


a=[1,2,3]
a.each{ |b| print "num " + b.to_s + "\n"}

num=10

(num - 1).downto(0) { |x| print x.to_s }
newLine

num=0
num.upto(3) { |x| print x.to_s }
newLine

