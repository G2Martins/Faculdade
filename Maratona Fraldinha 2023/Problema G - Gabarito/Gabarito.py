# Maratona Fraldinha 2023 - Problema G: Gabarito

def solve_gabarito():
    n_questions = int(input())
    student_answers_str = input().replace(" ", "") 
    correct_answers_str = input().replace(" ", "") 

    correct_count = 0
    for i in range(n_questions):
        if student_answers_str[i] == correct_answers_str[i]:
            correct_count += 1
    
    score = (correct_count / n_questions) * 100
    print(f"{score:.10f}") 

solve_gabarito()