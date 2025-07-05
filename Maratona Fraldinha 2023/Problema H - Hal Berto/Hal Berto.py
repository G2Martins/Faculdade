# Maratona Fraldinha 2023 - Problema H: Hal Berto

def get_primes(limit):
    primes = []
    is_prime = [True] * (limit + 1)
    if limit >= 0:
        is_prime[0] = False
    if limit >= 1:
        is_prime[1] = False
    for p in range(2, limit + 1):
        if is_prime[p]:
            primes.append(p)
            for multiple in range(p * p, limit + 1, p):
                is_prime[multiple] = False
    return primes

def solve_hal_berto():
    M = int(input())
    
    # Max prime needed: The problem states p <= 100. The 100th prime is 541.
    # N up to 10^9. We need primes up to 100 or primes that are factors of N up to N itself.
    # The p in HB-p refers to the *number* of primes to use, not the prime value itself.
    # So if p=2, we use prime 1 (2) and prime 2 (3).
    # If p=100, we use the first 100 primes.
    # The largest prime factor of N can be N itself if N is prime.
    # However, N must be representable *only* by the first 'p' primes.
    # So we need a list of primes up to sqrt(10^9) approx 31622 if N is not prime.
    # But more simply, we need primes up to 10^9 to check if a prime factor is too large.
    # The constraints are p <= 100, N <= 10^9.

    # Let's precompute primes up to the 100th prime, which is 541.
    # This list will be sufficient to check if a prime factor is beyond the 'p' limit.
    all_primes = get_primes(541) # 541 is the 100th prime number.

    for _ in range(M):
        p, N = map(int, input().split())
        
        if N == 1: 
            print("Sim")
            print(*([0] * p))
            continue

        exponents = [0] * p
        temp_N = N
        possible = True

        for i in range(p):
            current_prime = all_primes[i]
            while temp_N % current_prime == 0:
                exponents[i] += 1
                temp_N //= current_prime
        
        if temp_N == 1: 
            print("Sim")
            print(*exponents)
        else:
            print("Nao")

solve_hal_berto()