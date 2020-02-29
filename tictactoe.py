import sys
def check_winner(game):
	for i in range(3):
		flag = True
		for j in range(2):
			if game[i][j] != game[i][j+1]:
				flag = False

		if flag and str(game[i][0])!='0':
			print('Winner is',game[i][0])
			return

	for i in range(3):
		flag = True
		for j in range(2):
			if game[j][i] != game[j+1][i]:
				flag = False

		if flag and str(game[0][i])!='0':
			print('Winner is',game[0][i])
			return

	if game[0][0] == game[1][1] and game[1][1] == game[2][2] and str(game[0][0]) != '0':
		print('Winner is', game[0][0])
		return

	if game[2][0] == game[1][1] and game[1][1] == game[0][2] and str(game[2][0]) != '0':
		print('Winner is', game[2][0])
		return

	print('No Winner')


game = [sys.argv[1:4],sys.argv[4:7],sys.argv[7:]] #GET GAME
check_winner(game)
