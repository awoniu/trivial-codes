fi = 0.61803398
ans_list = [0 for x in range(0,100)]
ans_list[0] = 1
ans_list[1] = fi
for i in range(0,100):
  ans = fi**i
  if(i>1):
    ans_list[i] = ans_list[i-2] - ans_list[i-1]
  print(i, ":  ", ans-ans_list[i])

