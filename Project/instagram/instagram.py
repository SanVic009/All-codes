from bs4 import BeautifulSoup

following = open('/home/sanvict/Sanchit/Github/All-codes/Project/instagram/following.html')
soup = BeautifulSoup(following, 'html.parser')
following.close()

following_list = [a.text.strip() for a in soup.find_all('a')]
dict = {}

for i in following_list:
    dict[i] = True 

followers = open('/home/sanvict/Sanchit/Github/All-codes/Project/instagram/followers_1.html')
flwrs = BeautifulSoup(followers, 'html.parser')
followers.close()

followers_list = [a.text.strip() for a in flwrs.find_all('a')]

for i in followers_list:
    dict[i] = False

for i in dict:
    if dict[i] == True:
        print(i)