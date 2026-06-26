# maze game
# X is boundary
# * is player
# $ is chest

maze = []
with open("maze.txt", "r") as file:
	for line in file:
		maze.append(list(line.strip()))
		
def print_maze():
	for row in maze:
		print("".join(row))

player_pos = (-1, -1)
chest_pos = (-1, -1)
for i in range(len(maze)):
    for j in range(len(maze[i])):
        if maze[i][j] == "*":
            player_pos = (i, j)
        if maze[i][j] == "$":
            chest_pos = (i, j)
if(chest_pos == (-1, -1)):
    print("Chest not found in the maze.")
    exit()
if(player_pos == (-1, -1)):
    print("Player not found in the maze.")
    exit()

dead = False
while(not dead):
    print_maze()
    if player_pos == chest_pos:
        print("You found the chest! You win!")
        break
    move = input("Enter your move (W/A/S/D), Q to quit: ").upper()
    if move == "Q":
        break
    elif move == "W":
        # Move up
        if player_pos[0] > 0 and maze[player_pos[0] - 1][player_pos[1]] != "X":
            maze[player_pos[0]][player_pos[1]] = " "
            player_pos = (player_pos[0] - 1, player_pos[1])
            maze[player_pos[0]][player_pos[1]] = "*"
        else:
             dead = True
    elif move == "A":
        # Move left
        if player_pos[1] > 0 and maze[player_pos[0]][player_pos[1] - 1] != "X":
            maze[player_pos[0]][player_pos[1]] = " "
            player_pos = (player_pos[0], player_pos[1] - 1)
            maze[player_pos[0]][player_pos[1]] = "*"
        else:
            dead = True
    elif move == "S":
        # Move down
        if player_pos[0] < len(maze) - 1 and maze[player_pos[0] + 1][player_pos[1]] != "X":
            maze[player_pos[0]][player_pos[1]] = " "
            player_pos = (player_pos[0] + 1, player_pos[1])
            maze[player_pos[0]][player_pos[1]] = "*"
        else:
            dead = True
    elif move == "D":
        # Move right
        if player_pos[1] < len(maze[0]) - 1 and maze[player_pos[0]][player_pos[1] + 1] != "X":
            maze[player_pos[0]][player_pos[1]] = " "
            player_pos = (player_pos[0], player_pos[1] + 1)
            maze[player_pos[0]][player_pos[1]] = "*"
        else:
            dead = True
    else:
        print("Invalid move. Please enter W, A, S, D, or Q.")
    
    if(dead):
        print("You hit a wall! Game over.")
        break
