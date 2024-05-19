#!/usr/bin/python3
import sys
while True:
	try:
		num1 = int(input())
		num2 = int(input())
		print(num1, "+", num2, "=", num1 + num2)
		print(len(str(num1)), "\t\t\t",len(str(num2)), file=sys.stderr)
	except:
		break

