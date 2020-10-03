def gcd(m,n):
    if n==0 :
        return m
    else:
        return gcd(n,m%n)


a=int(input("Enter positiev no.1: "))
b=int(input("Enter positiev no.2: "))

g=gcd(a,b)
print("GCD is:",g)

