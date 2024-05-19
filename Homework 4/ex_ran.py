import random

while True:
    a = random.randint(10**300, 10**310)
    s = random.randint(10**300, 10**310)
    d = random.randint(10**300, 10**310)
    l = random.randint(10**300, 10**310)
    if a+s+d > l:
        break
with open("ex-in.txt", "w") as f:
    f.write(f"{a}\n+\n{s}\n+\n{d}\n-\n{l}\n=\nSTOP\n\n\n\nAns: {a+s+d-l}")
