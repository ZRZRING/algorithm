from cyaron import *
#def f():
#     x = randint(1,100)
#     if(x>=5):
#         return True
#     else:
#         return False


#1-3 道路长度都是0，宝物的重量都是1
for i in range(1,4):
    test_data = IO(file_prefix="traveler" + str(i), disable_output=False)
    n = 991
    m = 991-1;
    W = randint(1,1000)
    test_data.input_writeln(n,m,W)
    for j in range(n):
        wi = 1
        vi = randint(1,1000)
        test_data.input_writeln(wi,vi)
    G = Graph.chain(n,self_loop = False, repeated_edges = False,weight_limit=(0,0),directed=True)
    test_data.input_writeln(G.to_str(shuffle=True))
    test_data.output_gen("E:\c++\对拍\g.exe")


#4-6 村落是一条1~n的直线，道路长度都是0
for i in range(4,7):
    test_data = IO(file_prefix="traveler" + str(i), disable_output=False)
    n = 992
    m = 992-1;
    W = randint(1,1000)
    test_data.input_writeln(n,m,W)
    for j in range(n):
        wi = randint(1,1000)
        vi = randint(1,1000)
        test_data.input_writeln(wi,vi)
    G = Graph.chain(n,self_loop = False, repeated_edges = False,weight_limit=(0,0),directed=True)
    test_data.input_writeln(G.to_str(shuffle=True))
    test_data.output_gen("E:\c++\对拍\g.exe")


# 7-9道路长度都是0，宝物的重量都是1
for i in range(7,10):
    test_data = IO(file_prefix="traveler" + str(i), disable_output=False)
    n = 993
    m = 993-1;
    W = randint(1,1000)
    test_data.input_writeln(n,m,W)
    for j in range(n):
        wi = 1
        vi = randint(1,1000)
        test_data.input_writeln(wi,vi)
    G = Graph.graph(n, m, self_loop = False, repeated_edges = False,weight_limit=(0,0),directed=True)
    test_data.input_writeln(G.to_str(shuffle=True))
    test_data.output_gen("E:\c++\对拍\g.exe")

#10-13 道路长度都是0
for i in range(10,14):
    test_data = IO(file_prefix="traveler" + str(i), disable_output=False)
    n = 994
    m = 994-1;
    W = randint(1,1000)
    test_data.input_writeln(n,m,W)
    for j in range(n):
        wi = randint(1,1000)
        vi = randint(1,1000)
        test_data.input_writeln(wi,vi)
    G = Graph.graph(n, self_loop = False, repeated_edges = False,weight_limit=(0,0),directed=True)
    test_data.input_writeln(G.to_str(shuffle=True))
    test_data.output_gen("E:\c++\对拍\g.exe")


# 14-16 村落是一条直线
for i in range(14,17):
    test_data = IO(file_prefix="traveler" + str(i), disable_output=False)
    n = 995
    m = 995-1;
    W = randint(1,1000)
    test_data.input_writeln(n,m,W)
    for j in range(n):
        wi = randint(1,1000)
        vi = randint(1,1000)
        test_data.input_writeln(wi,vi)
    G = Graph.chain(n, self_loop = False, repeated_edges = False,weight_limit=(0,1000),directed=True)
    test_data.input_writeln(G.to_str(shuffle=True))
    test_data.output_gen("E:\c++\对拍\g.exe")


# 17−20 NONE
for i in range(17,21):
    test_data = IO(file_prefix="traveler" + str(i), disable_output=False)
    n = 996
    m = randint(995,1000);
    W = randint(1,1000)
    test_data.input_writeln(n,m,W)
    for j in range(n):
        wi = 1
        vi = randint(1,1000)
        test_data.input_writeln(wi,vi)
    G = Graph.graph(n, m,self_loop = False, repeated_edges = False,weight_limit=(1,1000),directed=True)
    test_data.input_writeln(G.to_str(shuffle=True))
    test_data.output_gen("E:\c++\对拍\g.exe")

# for i in range(1,2):
#     s = ""
#     test_data = IO(file_prefix="lock2", disable_output=False)
#     n = 201
#     test_data.input_writeln(n)
#     for j in range(n):
#         if j == 0 or j == n-1:
#             s = s + "100"
#             if(j!=n-1):
#                 s+=" "
#             continue
#         s = s+str(randint(1, 200))
#         if j!=n-1:
#             s+=" "
#     test_data.input_writeln(s)
#     print(test_data.output_gen("E:\c++\对拍\g.exe"))

# s = "";
# test_data = IO(file_prefix="test", disable_output=False)
# n = 8
# test_data.input_writeln(n)
# for i in range(n):
#     s = s+str(randint(1, 300))
#     if i!=n:
#         s+=" "
# test_data.input_writeln(s)
# test_data.output_gen("E:\c++\对拍\g.exe")


#print((int(100000000000000000000)*int(100000000000000000000))%int(100000000000000000007))

# for i in range(1,11):
#     test_data = IO(file_prefix="math00"+str(i), disable_output=False)
#     if i == 10:
#         test_data.input_writeln(100000000000000000000,100000000000000000000)
#         test_data.output_writeln(49)
#         continue
#     a = randint(1000000000, 100000000000000000000)
#     b = randint(1000000000, 100000000000000000000)
#     test_data.input_writeln(a, b)
#     test_data.output_writeln(int(a*b)%int(100000000000000000007))
# s = input()
# nums = s.split()
# print(int(nums[0])*int(nums[1])%100000000000000000007)