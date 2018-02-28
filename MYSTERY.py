from sys import stdin
a = stdin.readlines()
for i in a:
    n = int(i)
    if n == 0:
        print(0)
    else:
        x=0
        while n%2 == 0:
            n //= 2
            x += 1
        print(2**x)
