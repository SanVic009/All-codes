import random

rock_count=0
paper_count=0
scissor_count=0

score_player=0
score_comp=0

player_choice= int(input("Enter 0 for rock 1 for paper 2 for scissor"))

# def counter(pch):
#     if pch == 0:
#         rock_count+=1
#     elif pch == 1:
#         paper_count+=1
#     elif pch ==2:
#         scisso_count+=1


def comp_choice():
    if rock_count-paper_count>=2 and rock_count- scissor_count>=2:
        return 1
    elif paper_count- scissor_count>=2 and paper_count-rock_count>=2:
        return 2
    elif scissor_count-paper_count>=2 and scissor_count- rock_count>=2:
        return 0
    else: random.randint(0, 2)

# def score():
#     if comp_choice()==player_choice:
#         continue
#     1

'''
score counter
display
input name
make a list
all counters

'''