1. Program Name:
Exercise 4 - "Cat the Circle" - OOP 2


2. Program Partners:
Meytal Abrahamian
Bar Oren


3. General Explanation: 
This game is from the genre of puzzle games, in which the player is presented with a board
with a "puzzle" that he has to solve according to the rules of the game.
The player is presented with a tile board with "blocked tiles" and "empty tiles".
In the game there is a frog, who can walk on the empty circles only. The phase begins 
with a number of circles that are already full, with the frog standing in a relatively
central and empty tile.

# The Purpose of the game:
  The player must surround the frog on all sides, using the "tile filler", so that he has nowhere to go.

# Game rules:
  It's a player's turn in front of a computer. The player in his turn selects one tile he wants to block
  (by clicking mouse on the desired circle). The computer in turn moves the frog to try to
  escape from obstacles, and to escape from the board. If the frog reached one side of the board, 
  the frog actually escaped from the board and won the game. If the player managed to surround the frog 
  on all sides, as mentioned, the player won. Note: In order to win and pass a stage, it is not enough to 
  block the frog in a certain space, because he can still "walk" within that space. 
  The frog should be blocked completely.


4. Explanation Of Program Design: 
In order to realize the game, we used the following objects:

# Controller - who is responsible for the management of the game, for the transition between the stages,
  holding the objects relevant to the game, etc.

# Graph - which is actually the game board we chose to keep in the form of a graph. It contains everything
  that is relevant to the game board. The tiles, which of them are painted and the frog.

# Frog - Object for the frog itself.

# Tile - object for each tile individually in which we keep relevant information about the tiles
  in the game and update accordingly

# Window - is responsible for the display of everything - the window is displayed.

# Resources - to save resources we use in the program

# Menu - for the program's manu

# Macros - for "global" variables that we use several times in the program in different objects

# Button - for the game buttons


5. Program Files:

include:
	- Button.h
	- CMakeLists.txt
	- Controller.h
	- Frog.h
	- Graph.h
	- Macros.h
	- Menu.h
	- Resources.h
	- Tile.h
	- Window.h

resources:
	- all the photos for the game

src:
	- Button.cpp
	- CMakeLists.txt
	- Controller.cpp
	- Frog.cpp
	- Graph.cpp
	- main.cpp
	- Menu.cpp
	- Resources.cpp
	- Tile.cpp
	- Window.cpp

README.txt


6. Main Data Bases 
# DB for the graph - vector<vector<Tile>> m_tiles 
  Used to hold all the tiles in a graph structure i.e., a matrix 
  of vertices where each vertex is a tile that holds within it a list of its neighbors

# DB for graph limits - vector<Tile*> m_limits 
  Holds pointers for tiles that are within the boundaries of the graph (frame). 
  Used to identify a target for the BFS algorithm

# DB for game history - std::list<std::pair<Tile *, std::pair<int,int>>> m_history
  Save the moves made during the game, so that we can go back to the previous situation.

# std::array <sf::Sprite, 9> m_sprite
  Holds the Sprite that is in the program.

# std::array <sf::Texture, 9> m_texture
  Holds the Texture that is in the program.

# DB for tile's neighbors - std::list<Tile*> m_neighbors
  Holds the list of neighbors in a graph of a particular tile. Used for the BFS algorithm.


7. Notable Algorithms 
# BFS - We use the BFS algorithm to identify the next tile to which the frog will go in 
  order to identify the shortest track.

# If we manage to block the frog (not completely) that is, there is no rail to one of the 
  boundaries at all, we just hold the first free neighbor we find left for the same tile.


8. Known Bugs 
none that we know of .

9. Other Comments 
# We made sure that the frog did not appear exactly in the middle but in the range 
  of the tiles that were relatively in the middle to add interest
# the randomization of the tiles are based on range to make it more dynamic.

# Hope you will enjoy to play :)
