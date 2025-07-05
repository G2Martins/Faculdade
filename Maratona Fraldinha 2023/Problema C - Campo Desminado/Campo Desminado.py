# Maratona Fraldinha 2023 - Problema C: Campo Desminado

def solve_campo_desminado():
    N, M, K = map(int, input().split())
    grid = []
    for _ in range(N):
        grid.append(list(input()))

    mines_detonated = 0
    for r in range(N):
        for c in range(M):
            if mines_detonated < K and grid[r][c] == '*':
                grid[r][c] = '.'  
                mines_detonated += 1

    result_grid = [[0 for _ in range(M)] for _ in range(N)]

    for r in range(N):
        for c in range(M):
            if grid[r][c] == '*':
                result_grid[r][c] = -1
            else:
                mine_count = 0
                
                for dr in [-1, 0, 1]:
                    for dc in [-1, 0, 1]:
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < N and 0 <= nc < M and grid[nr][nc] == '*':
                            mine_count += 1
                result_grid[r][c] = mine_count

    for row in result_grid:
        print(*row) 

solve_campo_desminado()