import numpy as np
my_str = input().split(' ')

# MZJAWXU XMJYAUZ
row = len(my_str[0]) + 1
col = len(my_str[1]) + 1
arr = np.zeros((row, col), dtype=int)
route = np.zeros((row, col), dtype=str)
# print(arr)

for i in range(1, row):
    for j in range(1, col):
        if my_str[0][i - 1] == my_str[1][j - 1]:
            arr[i][j] = arr[i - 1][j - 1] + 1
            route[i][j] = "I" #從左上取得
        else:
            if arr[i][j - 1] >= arr[i - 1][j]:
                arr[i][j] = arr[i][j - 1]
                route[i][j] = "L" #從左方取得
            else:
                arr[i][j] = arr[i - 1][j]
                route[i][j] = "U" #從上方取得

row = len(my_str[0])
col = len(my_str[1])
cnt = 0
ans = ''
max_len = arr[row][col]

def LCS_str(row, col, cnt, ans, max_len):
    if cnt == max_len:
        reverse = ''
        for i in ans:
            reverse = i + reverse
        print("LCS(共同子序列) is", reverse)
        return

    if route[row][col] == 'I': #從左上取得
        ans += my_str[0][row - 1] + ''
        cnt += 1
        LCS_str(row - 1, col - 1, cnt, ans, max_len)
    
    elif route[row][col] == 'L': #從左方取得
        LCS_str(row, col - 1, cnt, ans, max_len)

    else: #從上方取得
        LCS_str(row - 1, col, cnt, ans, max_len)

LCS_str(row, col, cnt, ans, max_len)

print("\n動態規劃table:")

print("    ", end=" ")  
for i in my_str[1]:
    print("", i, end=" ")

print("")  

# 輸出表格
for i in range(0, row + 1):
    head = True
    for j in range(0, col + 1):
        if i - 1 >= 0 and head:
            print(my_str[0][i-1] + " ", arr[i][j], end=" ")
            head = False
        elif i == 0 and head:
            print("  ", end=" ")
            print(arr[i][j], end=" ")
            head = False
        else:
            print("", arr[i][j], end=" ")

    print("")    
# print(arr)