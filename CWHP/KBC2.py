display=[
  ["Q1 What is the capital of Canada?", "1: Heksinki\t2: Berlin\n3: Ottawa\t4: Jeddah\n", 3],
  ["Q2 Which is the smallest country in the world?", "1: Bhutan\t2: Vatican City\n3: New Zealand\t4: Maldives\n", 2],
  ["Q3 Which river runs through Baghdad?", "1: Nile\t2: Euphrates\n3: Karun\t4: Tigris\n", 4],
  ["Q4 What year did the Berln Wall fall?", "1: 1989\t2: 1991\n3: 1945\t4: 1999\n", 1],
  ["Q5 Which country gifted the Statue of Liberty?", "1: The UK\t2: France\n3: Russia 3\t4: China\n", 2],
  ["Q6 What is the national sport of Japan?", "1: Sumo\t2: Rugby\n3: Football\t4: Judo\n", 1],
  ["Q7 Who won the first FIFA World Cup?", "1: Urugway\t2: Argentina\n3: United States\t4: Spain\n", 1],
]
score=0
levelScore=0
cashPrize=[100,200,300,1000,2000,3000,10000]

for i in range(0, len(display)):
    print(f"The question for prize money {cashPrize[i]}, now on your screen is :\n")
    print(display[i][0])
    print(display[i][1])
    answer=int(input("Enter your answer (1-4), enter 0 to quit: "))
    print("\n")
    if(answer==0) :
        print(f"Well played! The answer was option number {display[i][-1]}")
        print(f"Your cash prize is {score}")
        break
    elif (answer==display[i][-1]):
        print(f"Good job!! That was the correct answer.")
        score=cashPrize[i]
        if(i==2):
            levelScore=cashPrize[i]
        elif(i==4):
            levelScore=cashPrize[i]
    else:
        print(f"Sorry, that was the wwrong answer!\nWell played")
        print(f"Your cash prize is {levelScore}")
        break