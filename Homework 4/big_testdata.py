import random
# 控制位數，操作資料量
# for i in range(1,6):
#     ans = 0
#     now = 0
#     ans_str = ""
#     a = random.randint(10**300, 10**301-1)
#     ans += a
#     ans_str += f"{a}\n"
#     n = 10**i
#     print(f"Start {n} data")
#     while True:
#         if now % (n//10) == 0 and now != 0:
#             print(f"Done {now//(n//10)}0%")
#         if now >= n:
#             break
#         a = random.randint(10**300, 10**301-1)
#         c = random.choice(["+", "-"])
#         if c == "+":
#             ans += a
#             ans_str += f"+\n{a}\n"
#         else:
#             if ans - a < 0:
#                 ans += a
#                 ans_str += f"+\n{a}\n"
#             else:
#                 ans -= a
#                 ans_str += f"-\n{a}\n"
#         now += 1
#     an = open(f"input_data/in{10**i}ans.txt", "w")
#     an.write(f"Ans: {ans}\n")
#     f = open(f"input_data/in{10**i}.txt", "w")
#     f.write(f"{ans_str}=\nSTOP")
#     f.close()
#     an.close()
#     print(f"input_data/in{10**i}.txt")


for i in range(1,2):
    ans = 0
    now = 0
    ans_str = ""
    a = random.randint(10**i, 10**(i+1)-1)
    ans += a
    ans_str += f"{a}\n"
    n = 10**5
    print(f"Start {n} data")
    while True:
        if now % (n//10) == 0 and now != 0:
            print(f"Done {now//(n//10)}0%")
        if now >= n:
            break
        a = random.randint(10**i, 10**(i+1)-1)
        c = random.choice(["+", "-"])
        if c == "+":
            ans += a
            ans_str += f"+\n{a}\n"
        else:
            if ans - a < 0:
                ans += a
                ans_str += f"+\n{a}\n"
            else:
                ans -= a
                ans_str += f"-\n{a}\n"
        now += 1
    an = open(f"input_data/{10**i}in_ans.txt", "w")
    an.write(f"Ans: {ans}\n")
    f = open(f"input_data/{10**i}in.txt", "w")
    f.write(f"{ans_str}=\nSTOP")
    f.close()
    an.close()
    print(f"input_data/{10**i}in.txt")

