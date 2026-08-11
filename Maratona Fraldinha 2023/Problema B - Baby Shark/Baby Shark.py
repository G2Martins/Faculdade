# Maratona Fraldinha 2023 - Problema B: Baby Shark

def solve_baby_shark():
    message = input()
    doo = "doo-doo"

    for _ in range(3):
        print(f"{message}, {doo}-{doo}-{doo}")
    
    print(f"{message}!")


solve_baby_shark()