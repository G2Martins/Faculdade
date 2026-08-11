# Maratona Fraldinha 2023 - Problema I: Imã Hacker

def solve_ima_hacker():
    n = int(input())
    S = input()
    T = input()

    # The key insight for this problem is the parity of the number of '1's.
    # Operations 1 (00 -> 11) and 2 (11 -> 00) both change two bits.
    # This means the parity of the number of '1's in the string remains invariant.
    # If S has an odd number of '1's, and T has an even number of '1's, it's impossible.
    # If S has an even number of '1's, and T has an odd number of '1's, it's impossible.
    # In other words, the total number of 1s in S and T must have the same parity.

    # Let's count the number of '1's in S and T.
    count_ones_S = S.count('1')
    count_ones_T = T.count('1')

    if count_ones_S % 2 == count_ones_T % 2:
        print("YES")
    else:
        print("NO")

solve_ima_hacker()