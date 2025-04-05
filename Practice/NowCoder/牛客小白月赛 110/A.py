n = int(input())
print(f"{chr((n-1)//500+65)}{(n-1)%500+1:03}")