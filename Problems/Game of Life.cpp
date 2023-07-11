#include<fstream>
#include <iostream>
#include <string>
using namespace std;
#define SIZE1 10
#define SIZE2 20
class GameOfLife {
private:
	bool grid[SIZE1 + 2][SIZE2 + 2]={{false}};
public:
	GameOfLife(string filename) {
		ifstream f(filename);
		for (int i = 1 ; i < SIZE1 + 1 ; i++) {
			for (int j = 1; j < SIZE2 + 1; j++) {
				f >> grid[i][j];
			}
		}
	}


	void display() {
		for (int i = 1; i < SIZE1 +1 ; i++) {
			for (int j = 1; j < SIZE2 +1 ; j++) {
				cout<< (grid[i][j]? '*' : '.' );
			}
			cout << "\n";
		}
	}


	int countNeighbours(int x, int y) {
		int res = -grid[x][y];
		for (int i = x-1; i <=x+1; i++) {
			for (int j = y-1; j <=y+1; j++) {
				res += grid[i][j];
			}
		}
		return res;
	}


	void nextGen() {
		bool new_grid[SIZE1 +2][SIZE2 + 2] = { {false} };
		for (int i = 1; i < SIZE1 + 1; i++) {
			for (int j = 1; j < SIZE2 + 1; j++) {
				int neighbours = countNeighbours(i, j);
				if (grid[i][j] == true) {
					if (neighbours == 2 || neighbours == 3) {
						new_grid[i][j] = true;
					}
					else {
						new_grid[i][j] = false;
					}
				}
				else {
					if (neighbours == 3) {
						new_grid[i][j] = true;
					}
				}
			}
		}
		for (int i = 1; i < SIZE1 + 1; i++) {
			for (int j = 1; j < SIZE2 + 1; j++) {
				grid[i][j] = new_grid[i][j];
			}
		}
	}


	void run(int n) {
		for (int i = 0; i < n; i++) {

			system("CLS");
			cout << "Generator: " << i << "/"<<n<<'\n';
			display();
			nextGen();
			cin.get();
		}
	}
};
int main() {
	GameOfLife game("game");
	game.run(20);
	return 0;
}
