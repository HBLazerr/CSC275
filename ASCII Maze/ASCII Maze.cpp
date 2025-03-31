// ASCII Maze version 1.0
// Daniel Chavez

// Libraries
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>


using namespace std;

// Create maze variables
int MAZE_ROWS;
int MAZE_COLS;

// Define maze as 2D char vector
vector<vector<char>> maze;


// Function prints maze to console
void displayMaze() {
	for (int i = 0; i < MAZE_ROWS; i++) {

		for (int j = 0; j < MAZE_COLS; j++) {
			cout << maze[i][j] << " ";

		}

		cout << endl;
	}
}

// Function that checks if a cell is an unvisited neighbor
bool unvisitedNeighbor(int row, int col) {
	return row >= 0 && row < MAZE_ROWS && col >= 0 && col < MAZE_COLS && maze[row][col] == '#';
}

// Recursive function. Creates maze using backtracking
void createMaze(int row, int col) {
	//marks current cell as a path
	maze[row][col] = ' ';

	//defines an array of possible neighbors
	vector<pair<int, int>> neighbors = {{row - 2, col}, {row, col + 2}, {row + 2, col}, {row, col - 2}};

	//shuffles neighbors array
	random_shuffle(neighbors.begin(), neighbors.end());

	// Checks neighbors and calls function IF unvisited cell/neighbor
	for (int i = 0; i < 4; i++) {
		int neighborRow = neighbors[i].first;
		int neighborCol = neighbors[i].second;

		if (unvisitedNeighbor(neighborRow, neighborCol)) {
			int pathRow = (row + neighborRow) / 2;
			int pathCol = (col + neighborCol) / 2;

			//marks current cell as a path
			maze[pathRow][pathCol] = ' ';

			//calls function from new current cell
			createMaze(neighborRow, neighborCol);
		}
	}
}


int main() {
	// prints intro to user
	cout << "\n\n\t *** Welcome to the ASCII Recursion Maze! ***\n" << endl;

	cout << R"(
88888888888888888888888888888888888888888888888888888888888888888888888
88.._|      | `-.  | `.  -_-_ _-_  _-  _- -_ -  .'|   |.'|     |  _..88
88   `-.._  |    |`!  |`.  -_ -__ -_ _- _-_-  .'  |.;'   |   _.!-'|  88
88      | `-!._  |  `;!  ;. _______________ ,'| .-' |   _!.i'     |  88
88..__  |     |`-!._ | `.| |_______________||."'|  _!.;'   |     _|..88
88   |``"..__ |    |`";.| .|_|MMMMMMMMMMM|_|'| _!-|   |   _|..-|'    88
88   |      |``--..|_ | `;!|_|MMoMMMMoMMM|_|.'j   |_..!-'|     |     88
88   |      |    |   |`-,!_|_|MMMMP'YMMMM|_||.!-;'  |    |     |     88
88___|______|____!.,.!,.!,!|_|MMMo * loMM| |,!,.!.,.!..__|_____|_____88
88      |     |    |  |  | | |MMMMb,dMMMM|_|| |   |   |    |      |  88
88      |     |    |..!-;' |_|MPYMoMMMMoM|_| |`-..|   |    |      |  88
88      |    _!.-j'  | _!,"|_|M()MMMMoMMM|_||!._|  `i-!.._ |      |  88
88     _!.-'|    | _."|  !;| |MbdMMoMMMMM| |`.| `-._|    |``-.._  |  88
88..-i'     |  _.''|  !-| !|_|MMMoMMMMoMM|_|.|`-. | ``._ |     |``"..88
88   |      |.|    |.|  !| |_|MoMMMMoMMMM| ||`. |`!   | `".    |     88
88   |  _.-'  |  .'  |.' |/|_|MMMMoMMMMoM|_|! |`!  `,.|    |-._|     88
88  _!"'|     !.'|  .'| .'|[@]MMMMMMMMMMM[@] \|  `. | `._  |   `-._  88
88-'    |   .'   |.|  |/| /                 \|`.  |`!    |.|      |`-88
88      |_.'|   .' | .' |/                   \  \ |  `.  | `._    |  88
88     .'   | .'   |/|  /                     \ |`!   |`.|    `.  |  88
88  _.'     !'|   .' | /                       \|  `  |  `.    |`.|  88
8888888888888888888888888888888888888888888888888888888888-Lee(FL)88888
)" << endl;

	cout << "To enter the maze, ";
	system("pause");

	//ask user for row dimension
	cout << "Enter the number of rows for the maze: ";
	cin >> MAZE_ROWS;
	
	//evaluate user input
	if (MAZE_ROWS < 20 || MAZE_ROWS > 30) {
		cout << "Pick a number between 20-30.\n";

		return 0;
	}
	
	//ask user for column dimension
	cout << "Enter the number of columns for the maze: ";
	cin >> MAZE_COLS;

	//evaluate user input
	if (MAZE_COLS < 20 || MAZE_COLS > 30) {
		cout << "Pick a number between 20-30.\n";

		return 0;
	}
	cout << "\n\n";

	// Resizes maze to users dimensions
	maze.resize(MAZE_ROWS, vector<char>(MAZE_COLS, '#'));

	// Seeds random num generator
	srand(time(nullptr));

	// Randomizes start position
	int currentRow = rand() % MAZE_ROWS;
	int currentCol = rand() % MAZE_COLS;

	// Creates maze using recursive backtracking
	createMaze(currentRow, currentCol);

	// Prints ASCII maze
	displayMaze();

	cout << "\nTo exit the maze, ";
	system("pause");

	return 0;
}
