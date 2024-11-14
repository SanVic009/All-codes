# Student Action: Use the revised 'prediction()' function to create the count based Mind Reader game algorithm.
# Import the random module
import random
# Create an empty list and store it in the 'player_inputs_list' variable.
player_inputs_list = []

# Create the 'player_score' and 'computer_score' variables. Set their initial values equal to 0.
player_score = 0
computer_score = 0
# Declare the 'prediction()' function here.
def prediction():
  count_zero = player_inputs_list.count(0)
  count_one = player_inputs_list.count(1)
  if count_zero > count_one:
    predict = 0
  elif count_zero < count_one:
    predict = 1
  else:
    predict = random.randint(0,1)
  return predict
# Declare the 'update_scores()' function here.
def update_scores(predicted,player_input):
  global computer_score , player_score
  if predicted == player_input:
    computer_score += 1
  else:
    player_score += 1
  print("You chose ")
  print("computer score : ", computer_score , "player score : ", player_score)
# Declare the 'gameplay()' function here. 
def gameplay():
  valid_entries = ["0" , "1"]
  while True:
    predicted = prediction()
    player_input = input("enter the number either 0 or 1 : ")
    while player_input not in valid_entries:
      print("invalid input")
      player_input = input("enter the valid number : ")
    player_input = int(player_input)
    player_inputs_list.append(player_input)
    update_scores(predicted,player_input)
    if player_score == 10:
      print("congrats you won")
      break
    elif computer_score == 10:
      print("you lost")
      break
# Call the 'gameplay()' function here.
gameplay()