#include <iostream>
#include <vector>

using namespace std;

void ClockWise_rotate(int target_phase);
void CounterClockWise_rotate(int target_phase);
void ArraySwitcher(int M);

vector<int> command;

int cube[6][9];
int temp[9];

int main()
{
	/*
	면 'B’에 대한 회전 코드 수 : M
	회전 명령 코드 : C
	출력할 면의 번호 : P

	1 ≤ M ≤ 100
	1 ≤ C ≤ 12
	1 ≤ P ≤ 6
	각 출력 면은 1에서 6까지 순서대로 A, B, C, D, E 및 F를 의미한다.
	*/

	int backup[6][9] = { {1, 2, 3, 4, 5, 6, 7, 8, 9},
						 {10, 11, 12, 13, 14, 15, 16, 17, 18},
						 {19, 20, 21, 22, 23, 24, 25, 26, 27},
						 {28,29,30,31,32,33,34,35,36},
						 {37,38,39,40,41,42,43,44,45},
						 {46,47,48,49,50,51,52,53,54} };
	
	int T;
	int i, j, k; // wide use
	int M;
	int cnt = 0;
	int selection;
	int* ptr;

	int result[30][9]; 
	

	cin >> T; // Test Case

	for (cnt = 0; cnt < T; cnt++) {

		// initialize
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 9; j++) {
				cube[i][j] = backup[i][j];
			}
		}
		command.clear();

		cin >> M; // number of command
		for (i = 0; i < M; i++) {
			cin >> j;
			command.push_back(j);
		}

		cin >> selection; // print selection

		ArraySwitcher(M);

		ptr = &cube[selection - 1][0];
		for (i = 0; i < 9; i++) {
			result[cnt][i] = *ptr;
			ptr++;
		}
	}


	for (i = 0; i < T; i++) {
		printf("#%d ", i+1);
		for (j = 0; j < 9; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

void ClockWise_rotate(int target_phase) {
	int k = 0;

	temp[0] = cube[target_phase][0]; temp[1] = cube[target_phase][1]; temp[2] = cube[target_phase][2];
	temp[3] = cube[target_phase][3]; temp[4] = cube[target_phase][4]; temp[5] = cube[target_phase][5];
	temp[6] = cube[target_phase][6]; temp[7] = cube[target_phase][7]; temp[8] = cube[target_phase][8];

	for (int n = 0; n < 3; n++) {
		cube[target_phase][k] = temp[n + 6];
		cube[target_phase][k + 1] = temp[n + 3];
		cube[target_phase][k + 2] = temp[n];
		k += 3;
	}
}

void CounterClockWise_rotate(int target_phase) {
	int k = 0;

	temp[0] = cube[target_phase][0]; temp[1] = cube[target_phase][1]; temp[2] = cube[target_phase][2];
	temp[3] = cube[target_phase][3]; temp[4] = cube[target_phase][4]; temp[5] = cube[target_phase][5];
	temp[6] = cube[target_phase][6]; temp[7] = cube[target_phase][7]; temp[8] = cube[target_phase][8];

	for (int n = 2; n >= 0; n--) {
		cube[target_phase][k] = temp[n];
		cube[target_phase][k + 1] = temp[n + 3];
		cube[target_phase][k + 2] = temp[n + 6];
		k += 3;
	}
}

void ArraySwitcher(int M) {
	int i, k;

	for (i = 0; i < M; i++) {
		switch (command.at(i)) {
		case 1:
			for (k = 0; k < 9; k += 3) {
				temp[k] = cube[0][k];
				cube[0][k] = cube[1][k];
				cube[1][k] = cube[2][k];
				cube[2][k] = cube[3][k];
				cube[3][k] = temp[k];
			}
			CounterClockWise_rotate(4);
			break;
		case 2:
			for (k = 1; k < 9; k += 3) {
				temp[k] = cube[0][k];
				cube[0][k] = cube[1][k];
				cube[1][k] = cube[2][k];
				cube[2][k] = cube[3][k];
				cube[3][k] = temp[k];
			}
			break;
		case 3:
			for (k = 2; k < 9; k += 3) {
				temp[k] = cube[0][k];
				cube[0][k] = cube[1][k];
				cube[1][k] = cube[2][k];
				cube[2][k] = cube[3][k];
				cube[3][k] = temp[k];
			}
			ClockWise_rotate(5);
			break;
		case 4:
			for (k = 0; k < 9; k += 3) {
				temp[k] = cube[3][k];
				cube[3][k] = cube[2][k];
				cube[2][k] = cube[1][k];
				cube[1][k] = cube[0][k];
				cube[0][k] = temp[k];
			}
			ClockWise_rotate(4);
			break;
		case 5:
			for (k = 1; k < 9; k += 3) {
				temp[k] = cube[3][k];
				cube[3][k] = cube[2][k];
				cube[2][k] = cube[1][k];
				cube[1][k] = cube[0][k];
				cube[0][k] = temp[k];
			}
			break;
		case 6:
			for (k = 2; k < 9; k += 3) {
				temp[k] = cube[3][k];
				cube[3][k] = cube[2][k];
				cube[2][k] = cube[1][k];
				cube[1][k] = cube[0][k];
				cube[0][k] = temp[k];
			}
			CounterClockWise_rotate(5);
			break;
		case 7:
			for (k = 0; k < 3; k++) {
				temp[k] = cube[1][k];
				cube[1][k] = cube[5][k];
				cube[5][k] = cube[3][8 - k];
				cube[3][8 - k] = cube[4][k];
				cube[4][k] = temp[k];
			}
			ClockWise_rotate(0);
			break;
		case 8:
			for (k = 3; k < 6; k++) {
				temp[k] = cube[1][k];
				cube[1][k] = cube[5][k];
				cube[5][k] = cube[3][8 - k];
				cube[3][8 - k] = cube[4][k];
				cube[4][k] = temp[k];
			}
			break;
		case 9:
			for (k = 6; k < 9; k++) {
				temp[k] = cube[1][k];
				cube[1][k] = cube[5][k];
				cube[5][k] = cube[3][8 - k];
				cube[3][8 - k] = cube[4][k];
				cube[4][k] = temp[k];
			}
			CounterClockWise_rotate(2);
			break;
		case 10:
			for (k = 0; k < 3; k++) {
				temp[k] = cube[1][k];
				cube[1][k] = cube[4][k];
				cube[4][k] = cube[3][8 - k];
				cube[3][8 - k] = cube[5][k];
				cube[5][k] = temp[k];
			}
			CounterClockWise_rotate(0);
			break;
		case 11:
			for (k = 3; k < 6; k++) {
				temp[k] = cube[1][k];
				cube[1][k] = cube[4][k];
				cube[4][k] = cube[3][8 - k];
				cube[3][8 - k] = cube[5][k];
				cube[5][k] = temp[k];
			}
			break;
		case 12:
			for (k = 6; k < 9; k++) {
				temp[k] = cube[1][k];
				cube[1][k] = cube[4][k];
				cube[4][k] = cube[3][8 - k];
				cube[3][8 - k] = cube[5][k];
				cube[5][k] = temp[k];
			}
			ClockWise_rotate(2);
			break;
		}
	}
}