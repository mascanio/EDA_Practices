#include <iostream>
using namespace std;

void mover(int i, int x, int y, int& nx, int& ny);
void caballo(int tablero[8][8], bool marca[8][8], int k, int x, int y, int acu, int& max);

void caballo(int tablero[8][8], bool marca[8][8], int k, int x, int y, int acu, int& max) {
	//hago los 8 movimientos posibles

	int nx, ny;
	for (int j = 0; j < 8; j++)
	{
		mover(j, x, y, nx, ny);
		if ((nx < 8 && nx >= 0) && (ny < 8 && ny >= 0) && !marca[nx][ny]) { //Sol parcial válida
			acu += tablero[nx][ny];

			if  (0 == k) { //Sol final
				if (acu > max) //sol mejor
					max = acu;
			}
			else
			{
				marca[nx][ny] = true;
				caballo(tablero, marca, k-1, nx, ny, acu, max);
				marca[nx][ny] = false;
			}

			acu -= tablero[nx][ny];
		}
	}

}

void mover(int i, int x, int y, int& nx, int& ny) {
	int dx[8] = {2,2,1,-1,-2,-2,-1,1};
	int dy[8] = {1,-1,-2,-2,-1,1,2,2};

	nx = x + dx[i];
	ny = y + dy[i];
}

int main() {

	bool marca[8][8] = {{false}};
	marca[3][3] = true;

	int tablero[8][8] = {
		{0,2,0,0,0,0,3,0},
		{0,0,0,1,0,0,0,0},
		{0,2,0,0,0,0,3,0},
		{0,0,0,0,4,0,0,0},
		{1,0,0,0,0,1,3,0},
		{0,0,0,3,0,2,0,0},
		{0,6,0,0,0,1,0,0},
		{0,2,0,1,0,0,0,0}
	};

	int k = 10;
	int max = 0;

	for (int i = 0; i < k; i++)
	{
		max = 0;
		caballo(tablero, marca, i, 3, 3, 0, max);
		cout << max << endl ;
	}

	return 0;
}
