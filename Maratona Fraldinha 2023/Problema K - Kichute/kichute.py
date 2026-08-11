# Maratona Fraldinha 2023 - Problema K: Kichute

def solve_kichute():
    N, K = map(int, input().split())
    MOD = 10**9 + 7
    result = pow(N, K, MOD)
    print(result)

solve_kichute()