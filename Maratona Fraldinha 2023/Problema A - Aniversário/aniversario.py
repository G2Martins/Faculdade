# Maratona Fraldinha 2023 - Problema A: Aniversário

def solve_aniversario():
    N = int(input())
    people = []
    for _ in range(N):
        name, age_str = input().split()
        people.append((name, int(age_str)))

    coincidences = []

    for i in range(N):
        for j in range(i + 1, N):
            name1, age1 = people[i]
            name2, age2 = people[j]

            # Consider ages up to 99
            for years_passed in range(100):  # A sufficiently large range to check ages up to 99
                current_age1 = age1 + years_passed
                current_age2 = age2 + years_passed

                if 10 <= current_age1 <= 99 and 10 <= current_age2 <= 99:
                    str_age1 = str(current_age1)
                    str_age2 = str(current_age2)

                    if len(str_age1) == 2 and len(str_age2) == 2:
                        reversed_age1_str = str_age1[1] + str_age1[0]
                        reversed_age2_str = str_age2[1] + str_age2[0]

                        if (str(current_age1) == reversed_age2_str and str(current_age2) == reversed_age1_str):
                            coincidences.append((years_passed, name1, current_age1, name2, current_age2))
                            
    
    coincidences.sort() 

    for d, p1, a1, p2, a2 in coincidences:
        print(f"Em {d} anos {p1} faz {a1} e {p2} {a2}")

solve_aniversario()