# Maratona Fraldinha 2023 - Problema E: Enxugando Gelo no Sol

def solve_enxugando_gelo():
    N = int(input())
    MOD = 10**9 + 7

    # The number of ways to distribute 3 prizes among M participants
    # is M * (M-1) * (M-2).
    # M starts at 3 for the first edition.
    # For N editions, M goes from 3 to 3 + (N-1) = N+2

    total_ways = 0
    
    # Calculate sum of M*(M-1)*(M-2) for M from 3 to N+2
    # This is a sum of cubic polynomials.
    # The sum of k(k-1)(k-2) for k from 3 to N+2.
    # Let k = i + 2, then i goes from 1 to N.
    # Sum of (i+2)(i+1)i for i from 1 to N.
    # This is sum of i^3 + 3i^2 + 2i.

    # Sum of k(k-1)(k-2) = sum of (k^3 - 3k^2 + 2k)
    # This is equivalent to 6 * C(k+1, 4)
    # So, the sum from k=3 to M_final is 6 * C(M_final + 1, 4)
    # where M_final = N + 2

    # The sum is (M_final+1) * M_final * (M_final-1) * (M_final-2) / 4
    # For N editions, the last M value is 3 + (N-1) = N+2.
    # So, M_final = N + 2.
    # Sum = (N+3) * (N+2) * (N+1) * N / 4

    # Using formula for sum of P(k,r)
    # Sum_{k=r to n} P(k,r) = (n+1)P(n+1, r+1) / (r+1)
    # Here, r=3, P(k,3) = k(k-1)(k-2)
    # Sum_{k=3 to N+2} k(k-1)(k-2) = ((N+2)+1)P((N+2)+1, 3+1) / (3+1)
    # = (N+3)P(N+3, 4) / 4
    # = (N+3) * (N+2) * (N+1) * N / 4

    # Modular inverse of 4 modulo 10^9 + 7
    # (10^9 + 7) is a prime number.
    # By Fermat's Little Theorem, a^(p-2) % p is the modular inverse of a % p
    # mod_inverse_4 = pow(4, MOD - 2, MOD)

    # However, N can be very large (10^18), so direct calculation of (N+3)...N is not feasible.
    # The formula (N+3) * (N+2) * (N+1) * N / 4 can be rewritten as
    # N^4 / 4 + (6N^3)/4 + (11N^2)/4 + (6N)/4
    # This is equivalent to a polynomial in N.
    # P(N) = (N^4 + 6N^3 + 11N^2 + 6N) / 4

    # Since N can be 10^18, we need modular arithmetic for each term.
    # Let's compute (N+3) * (N+2) * (N+1) * N % MOD
    # And then multiply by the modular inverse of 4.

    n_mod = N % MOD
    n_plus_1_mod = (N + 1) % MOD
    n_plus_2_mod = (N + 2) % MOD
    n_plus_3_mod = (N + 3) % MOD

    numerator_mod = (n_mod * n_plus_1_mod) % MOD
    numerator_mod = (numerator_mod * n_plus_2_mod) % MOD
    numerator_mod = (numerator_mod * n_plus_3_mod) % MOD

    # Calculate modular inverse of 4 modulo MOD (10^9 + 7)
    # MOD = 10^9 + 7
    # 4 * x = 1 (mod MOD)
    # x = 1 / 4 (mod MOD)
    # Use Fermat's Little Theorem: a^(p-2) % p
    inv_4 = pow(4, MOD - 2, MOD)

    total_ways = (numerator_mod * inv_4) % MOD
    print(total_ways)

solve_enxugando_gelo()