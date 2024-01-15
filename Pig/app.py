import random


##Function to roll dice
def roll():
    min_value = 1
    max_value = 6
    roll_return = random.randint(min_value, max_value)

    return roll_return

##While loop to configure num of players to start game

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

max_score = 20
player_scores = [0 for _ in range(players)]

round = 1

while max(player_scores) < max_score:
    ##Print current round
    print("ROUND ", round)

    ##Loop through player scores and display to user
    print("Current Scores will be added here in next update")

    for player_idx in range(players):
        print("\nPlayer ", player_idx + 1, "turn has just started\n")
        print("Your total score is:", player_scores[player_idx])

        ##Need to see what happens if we loop through all players once and the turn isnt over
        current_score = 0

        while True:
            should_roll = input("Are you ready to roll (y)? ")
            if should_roll.lower() != 'y':
                break

            value = roll()

            if value == 1:
                print("You rolled a one, turn ends")
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