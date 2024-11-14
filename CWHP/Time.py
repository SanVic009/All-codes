import time

x=int(time.strftime('%H'))

if(x>=4 and x<12):
    print("Good Morning!")
elif(x>=12 and x<18):
    print("Good Afternoon!")
else:
    print("Good Night!")