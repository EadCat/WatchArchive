#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tx;
vector<int> comp;
vector<int> result; /* y_number , x_number , comp */
int x,y;

int arr[9][9];

void search_x(int* pointer);
void search_comp(int* pointer);
void search_y(int* pointer);

int main()
{
	int T; // test case
	int K[30]; // # of wrong number
	int i, j, k;
	int cnt;
	int* resultptr;

	cin >> T;
	
	for (i = 0; i < T; i++) 
	{
		cnt = 0;
		cin >> K[i];
		for (j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				cin >> arr[j][k];
			}
		} // ��� �Է�
		for (y = 0; y < 9; y++) 
		{
			if (cnt == K[i])
				break;
			search_x(&arr[y][0]); // ��� �࿡ ���� 9�� �˻�
			if (tx.empty() != true) 
			{ // ���� ����
				search_comp(&arr[y][0]); // �࿡ ���� ����� �˻� �� ����
				for (k = 0; k < comp.size() + 1; k++) {
					x = *(tx.begin() + k);
					search_y(&arr[0][x-1]); // ��� ���� �� ��� ����
					cnt++;
				}
			}
			tx.clear();
			comp.clear();
		}
	}
	resultptr = &result.at(0);
	for (j = 0; j < T; j++)
	{
		printf("#%d ", j + 1);
		for (int k = 0; k < K[i]; k++) {
			printf("%d %d %d ", *(resultptr), *(resultptr + 1), *(resultptr + 2));
			resultptr += 3;
		}
		cout << endl;
	}

	return 0;
}

void search_x(int* pointer) {
	int masking[9] = {0};
	for (int i = 0; i < 9; i++) {
		if (masking[(*pointer) - 1] == 0)
			masking[(*pointer) - 1] = i+1;
		else {
			tx.push_back(masking[(*pointer) - 1]); // tx ��ǥ ����
			tx.push_back(i+1);
		}
		pointer++;
	}
	if (tx.empty() != true) // �ߺ� üũ�Ͽ� ����
	{
		sort(tx.begin(), tx.end());
		for (int i = 0; i < tx.size() - 1; i++) {
			if (*(tx.begin() + i) == *(tx.begin() + i + 1))
				tx.erase(tx.begin() + i);
		}
	}
}

void search_comp(int* pointer) {
	int masking[9] = {0};
	for (int i = 0; i < 9; i++) { // Ÿ����
		if (masking[(*pointer) - 1] == 0)
			masking[(*pointer) - 1] = i+1;
	}
	for (int i = 0; i < 9; i++) { // 0 �˻� �� ����� ����
		if (masking[i] == 0)
			comp.push_back(i + 1);
	}
}

void search_y(int* pointer) { // ��� ������� ���Ͽ� �� ���� ���� ���� �˻�����
	int i, j;
	int* ptr = pointer;

	for (i = 0; i < comp.size(); i++) {
		for (j = 0; j < 9; j++) { // ���� ����
			if (*ptr == *(comp.begin() + i)) {
				break;
			}
			ptr += 8;
		}
		if (j == 9) {// ������� ����. �ش��ϴ� ������ ����.
			result.push_back(y + 1);
			result.push_back(x);
			result.push_back(*(comp.begin() + i));
			arr[y][x] = *(comp.begin() + i);
		}
	}
}