#include "constant.h"
#include "block.h"
#include <iostream>

// ������ ��� �̵� �����ϸ� 1�� ��ȯ
// �Ұ����ϸ� 0�� ��ȯ

using namespace std;

int seventh_physics(int direction, int phase, int x, int y, int field[][WIDTH])
{
	int k = 0;

	if (direction == LEFT)
		k = -1;
	else if (direction == RIGHT)
		k = 1;
	else if (direction == DOWN || direction == SPACE) {
		k = 1;
		goto UPDOWN;
	}
	// �ϰ���° ���� �¿� �Ǵ�
	if (phase % 2 == 0) {
		if (field[y][x - 1 + k] == 2)
			return 0;
		else if (field[y][x + 2 + k] == 2)
			return 0;
		else
			return 1;
	}
	// ��ڡ��
	else {
		if (field[y][x + k] == 2)
			return 0;
		else if (field[y + 1][x + k] == 2)
			return 0;
		else if (field[y + 2][x + k] == 2)
			return 0;
		else if (field[y + 3][x + k] == 2)
			return 0;
		else
			return 1;
	}
	/* ��
	   ��
	   ��
	   �� */

UPDOWN: // �Ʒ� �̵� �� ���� ����

	if (phase % 2 == 0) {
		if (field[y + k][x] == 2)
			return 0;
		else if (field[y + k][x + 1] == 2)
			return 0;
		else if (field[y + k][x - 1] == 2)
			return 0;
		else if (field[y + k][x + 2] == 2)
			return 0;
		else
			return 1;
	}
	// ��ڡ��
	else {
		if (field[y + 3 + k][x] == 2)
			return 0;
		else
			return 1;
	}/* ��
		��
		��
		�� */
}