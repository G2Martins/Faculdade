# Maratona Fraldinha 2023 - Problema J: João e o Irrigador

import math

def solve_joao_irrigador():
    T = int(input())
    for _ in range(T):
        A, B, R = map(int, input().split())
        
        # We need to count integer points (x, y) such that (x-A)^2 + (y-B)^2 <= R^2
        # Since the problem states "nenhuma muda será plantada no ponto de fixação do irrigador",
        # we exclude the point (A, B) if it were an integer point.
        # However, A and B can be non-integers in general if problem does not constrain them.
        # But here, A and B are integers. So we must exclude (A,B).

        count = 0
        # Iterate over possible x coordinates for integer points
        # (x-A)^2 <= R^2 implies |x-A| <= R
        # So A-R <= x <= A+R
        
        # Example for R=1:
        # A=7, B=-2, R=1
        # (x-7)^2 + (y+2)^2 <= 1^2
        # Possible x values: 7-1 to 7+1 -> 6, 7, 8
        # Possible y values: -2-1 to -2+1 -> -3, -2, -1

        # For x = 6: (6-7)^2 + (y+2)^2 <= 1  => 1 + (y+2)^2 <= 1 => (y+2)^2 <= 0 => y+2=0 => y=-2. Point (6,-2)
        # For x = 7: (7-7)^2 + (y+2)^2 <= 1  => 0 + (y+2)^2 <= 1 => (y+2)^2 <= 1 => |y+2| <= 1 => -1 <= y+2 <= 1 => -3 <= y <= -1. Points (7,-3), (7,-2), (7,-1)
        # For x = 8: (8-7)^2 + (y+2)^2 <= 1  => 1 + (y+2)^2 <= 1 => (y+2)^2 <= 0 => y+2=0 => y=-2. Point (8,-2)
        # Total points: (6,-2), (7,-3), (7,-2), (7,-1), (8,-2) = 5 points.
        # Example output for 7 -2 1 is 4. This implies (A,B) itself (7,-2) is excluded.
        # So we count all points and subtract 1 if (A,B) is an integer point.
        # Since A and B are integers and plants are at integer coordinates, (A,B) is always an integer point.

        # The loop range for x should be from floor(A-R) to floor(A+R)
        # Since A is integer, it's A-R to A+R.
        
        for x in range(A - R, A + R + 1):
            dy_squared = R**2 - (x - A)**2
            if dy_squared < 0:
                continue
            
            # y_min_possible = B - sqrt(dy_squared)
            # y_max_possible = B + sqrt(dy_squared)
            # We need to count integers in [ceil(y_min_possible), floor(y_max_possible)]
            
            # Use floor and ceil more carefully to avoid floating point issues.
            # y_squared_diff_min = B - sqrt(dy_squared)
            # y_squared_diff_max = B + sqrt(dy_squared)

            # (y-B)^2 <= dy_squared
            # So, y-B must be between -sqrt(dy_squared) and +sqrt(dy_squared)
            # y must be between B - sqrt(dy_squared) and B + sqrt(dy_squared)

            # Calculate the integer bounds for y for a given x
            # Since dy_squared is an integer, sqrt(dy_squared) might be float.
            # int_sqrt_dy = int(math.sqrt(dy_squared))
            
            # This is safer:
            # We need to find y such that (y-B)^2 <= dy_squared
            # Let k = y-B. Then k^2 <= dy_squared
            # So, -sqrt(dy_squared) <= k <= sqrt(dy_squared)
            # k_min = -int(math.sqrt(dy_squared))
            # k_max = int(math.sqrt(dy_squared))

            # Need to be careful with floating point precision and floor/ceil.
            # (y - B)^2 <= R^2 - (x - A)^2
            # Let limit_y_sq = R^2 - (x - A)^2
            # The integer values of y-B that satisfy this are from -floor(sqrt(limit_y_sq)) to floor(sqrt(limit_y_sq)).
            # Or, more robustly, find max_abs_k such that max_abs_k^2 <= limit_y_sq
            
            max_abs_k = int(math.sqrt(dy_squared))
            
            # Check if (max_abs_k+1)^2 is also <= dy_squared to adjust max_abs_k
            # This handles cases where sqrt(dy_squared) is slightly less than an integer due to float precision
            if (max_abs_k + 1)**2 <= dy_squared:
                max_abs_k += 1
            
            # The y values satisfying the inequality are from B - max_abs_k to B + max_abs_k
            # The number of integer points for a given x is (B + max_abs_k) - (B - max_abs_k) + 1
            # = 2 * max_abs_k + 1
            count += (2 * max_abs_k + 1)
        
        # Exclude the center point (A, B) itself, as per problem statement "nenhuma muda será plantada no ponto de fixação do irrigador"
        # Since A and B are integers, (A,B) is always an integer grid point.
        print(count - 1)

solve_joao_irrigador()