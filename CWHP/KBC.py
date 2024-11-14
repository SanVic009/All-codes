questions=["Sample question 1", "Sample question 2", "Sample question 3"]

options=["1: Option 1\n2: Option 2\n3: Option 3\n4: Option 4\n","1: Option 1\n2: Option 2\n3: Option 3\n4: Option 4\n","1: Option 1\n2: Option 2\n3: Option 3\n4: Option 4"]

answers=[2,3,1]

cashPrize=[100,10000,20000]

score=0
for i in range(0,3):
    print(questions[i])
    print(options[i])
    inputAnswer=int(input("Enter your answer here: "))
    if(inputAnswer==answers[i]):
        print("Good job, that was the correct answer!\n")
        score=cashPrize[i]
    else:
        print("Sorry that was not the correct answer.\nWell played.\n1")
        break
print(f"Your total cash prize is :{score}")