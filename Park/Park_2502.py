D, K = map(int, input().split())

dp = [1, 1, 2]
for i in range(3, D):   # 피보나치 수열
    dp.append(dp[i-1]+dp[i-2])

# 공식이 나옴스...
# K = dp[D-3] * A + dp[D-2] * B

a = 1
while True:
    if (K - a*dp[D-3]) % dp[D-2] == 0:
        b = (K-a*dp[D-3]) // dp[D-2]
        if a < b:
            print(f'{a}\n{b}')
            break
    
    a += 1

