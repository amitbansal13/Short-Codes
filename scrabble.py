from random import *
#to use random function calls



#function to return random word
def choose_rand():
	#list of 10 random words
	random_words=['score','project','programming','love','shuffle','random','choice','function','jumbled','game']
	word=choice(random_words)#choosing a word at random
	return word

def shuffle_letters(word):
	#shuffle letters of chosen word
	word=sample(word,len(word))#sample at random
	word=''.join(word)#word is a list of alphabets in random distribution and join it to get a word
	return word #return word

def final_score(score1,score2):
	#printing score
	print('Player 1 score:',score1)
	print('Player 2 score:',score2)

def declare_winner(score1,score2):
	#declaring winner based on scores
	if score1>score2:
		print('Game Ends! Player 1 wins!')
	elif score2>score1:
		print('Game Ends! Player 2 wins!')
	else:
		print('Game Ends! Draw!')
	final_score(score1,score2)
	print('Thanks for playing!')

def play_game():
	username1=input('Enter name for user 1: ')
	username2=input('Enter name for user 2: ')
	turn=1#initially turn is odd for user 1 to play
	score1=0#score for player 1 is zero
	score2=0#score for player 2 is zero
	while True:
	#infinite loop till anyone of the users enters stop or exit
		word=choose_rand()
		shuffled=shuffle_letters(word)#get shuffled word
		print(shuffled)
		if turn%2==1:
			inp=input('Enter your answer '+username1+': ')
			if inp==word:#if word entered matches actual word
				score1+=1#increment score by 1
				print('Right answer! Your score is ',score1)
			else:
				print('You are wrong!')
		else:
			inp=input('Enter your answer '+username2+': ')
			if inp==word:
				score2+=1#increment score by 1
				print('Right answer! Your score is ',score2)
			else:
				print('You are wrong!')

		turn+=1

		if inp=='stop' or inp=='exit':
			break

	declare_winner(score1,score2)

	option=input('Do you want to play again?: Y/N ')
	if option=='Y' or option=='y':
		play_game()#call the function again



play_game()