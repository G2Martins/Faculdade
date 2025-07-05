# Maratona Fraldinha 2023 - Problema D: Descubra o Segredo

def solve_descubra_o_segredo():
    n_test_cases = int(input())
    for _ in range(n_test_cases):
        S1 = input()
        S2 = input()
        length = len(S1)

        left_rotations = 0
        temp_S2 = S2
        while temp_S2 != S1:
            temp_S2 = temp_S2[1:] + temp_S2[0]
            left_rotations += 1
            if left_rotations > length:
                break
        
        right_rotations = 0
        temp_S2 = S2
        while temp_S2 != S1:
            temp_S2 = temp_S2[-1] + temp_S2[:-1]
            right_rotations += 1
            if right_rotations > length: 
                break

        print(min(left_rotations, right_rotations))

solve_descubra_o_segredo()