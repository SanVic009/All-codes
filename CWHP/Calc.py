print("Welcome to the calculator!!")
t=1
while t==1:
    x=int(input("Enter the first number :"))
    y=int(input("ENter the second number :"))

    op=int(input("Enter the operation to perform : \n 1 Addition \n 2 Subtraction \n 3 multiplication \n 4 Division \n 5 Remainder \n"))
    if op==1:
        print(f"Addition of {x} and {y} is {x+y}")
    elif op==2:
        print(f"Subtraction of {x} and {y} is {x-y}")
    elif op==3:
        print(f"Multiplication of {x} and {y} is {x*y}")
    elif op==4:
        print(f"Division of {x} and {y} is {x/y}")
    elif op==5:
        print(f"Remainder we get when dividing {x} with {y} is {x%y}")
    else:
        print("Select a valid operation.")
    t=int(input("If you wish to continue, enter 1 else enter 0 :"))