import random


##Function to roll dice
def roll():
    min_value = 1
    max_value = 6
    roll_return = random.randint(min_value, max_value)

    return roll_return


##While loop to configure num of players to start game

print("The game is called 'Pig' (don't ask me I dont know why)\n Here is how it works: \n")
print("Each player will get a turn to roll the dice, you will choose whether to roll or pass to the next player\n")
print("Each roll of the dice adds to your score for that round. \n However, if you roll a 1 your turn will end and your score for that round will reset to 0 \n")
print("If you survive the round, your round score will be added to your total score\n")
print("The goal is to reach the target score first.\n If two players or more reach the target score in the same round, \n tie goes to the highest score")

max_score = 20

print("The target score configured for this round is ", max_score)


while True:
    ##Input num of players
    players = input("Enter the number of players (2-4): ")
    if players.isdigit():
        players = int(players)
        if 1 < players <= 4:
            print("Successful input")
            break
        else:
            print("must be between 2-4 players")
    else:
        print("Invalid input, try again")


player_scores = [0 for _ in range(players)]

round = 1

while max(player_scores) < max_score:
    ##Print current round
    print("START OF ROUND ", round)

    ##Loop through player scores and display to user
    print("Scoreboard:\n")
    for i in range(players):
        print("Player ", i+1,"- ", player_scores[i])

    for player_idx in range(players):
        print("\nPlayer ", player_idx + 1, "turn has just started\n")
        print("Your total score is:", player_scores[player_idx])

        ##Need to see what happens if we loop through all players once and the turn isnt over
        current_score = 0

        while True:
            should_roll = input("Are you ready to roll (y)? ")
            if should_roll.lower() != 'y':
                ##if should_roll isnt a y or n output error message
                break

            value = roll()

            if value == 1:
                print("Ouch! You rolled a 1, so your turn done")
                current_score = 0
                break
            else:
                current_score += value
                print("You rolled a ", value, "\n")

            ##Update print message to make this better, show potential total score too
            print("Your score for the current round is: ", current_score)

        player_scores[player_idx] += current_score
        print("Total score for player ", player_idx + 1, ": ", player_scores[player_idx])

##find the max score acheived to determine winner then display to user

max_score_acheived = max(player_scores)
winning_idx = player_scores.index(max_score_acheived)

print("Player ", winning_idx + 1, " wins with a score of ", max_score_acheived)
