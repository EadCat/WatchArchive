#include "constant.h"
#include "block.h"
#include "physics.h"
#include <iostream>
#include <conio.h>

using namespace std;

/*=========================
���
1. ����Ű �ް� x, y ��ǥ �̵� �Լ�
	(�浹 ���� �ʿ�)
2. �ʵ带 1�� �ǽð� ���� �Լ�
3. �ʵ带 0���� �ǽð� ���� �Լ�
4. ��Ȱ�� ���� �Լ�
=========================*/

void block_moving(int direction, screen* s, block* b)
{// �ݷ��� ������ �޾Ƽ� ���� Ž��

	if (direction == DOWN && funnel(b->caller, b->phase, s->x, s->y, direction, s->field)) {
		(s->y)++;
	} // �Ʒ� �̵�
	else if (direction == LEFT && funnel(b->caller, b->phase, s->x, s->y, direction, s->field)) {
		(s->x)--;
	} // ���� �̵�
	else if (direction == RIGHT && funnel(b->caller, b->phase, s->x, s->y, direction, s->field)) {
		(s->x)++;
	} // ������ �̵�
	else if (direction == SPACE) {
		while (funnel(b->caller, b->phase, s->x, s->y, direction, s->field)) {
			(s->y)++;
		}
	}
	// ����Ű �Է¿� ���� x, y ��ǥ ��ȭ�� ����.
}

// Axis (��)�� �������� ���� �ο���
void block_maker(int caller, int phase, int x, int y, int field[][WIDTH]) {
	block_porting(caller, phase, x, y, 1, field);
} // �׸��� ���Ͽ� �ʵ� ���� 1�� ����

void block_eraser(int caller, int phase, int x, int y, int field[][WIDTH]) {
	block_porting(caller, phase, x, y, 0, field);
} // ����� ���Ͽ� �ʵ� ���� 0���� ����

void block_store(int caller, int phase, int x, int y, int field[][WIDTH]) {
	block_porting(caller, phase, x, y, 2, field);
} // �����ϱ� ���Ͽ� �ʵ� ���� 2�� ����

void block_rotate(int direction, int* phase) {
	if (direction == TURN_LEFT_1 || direction == TURN_LEFT_2) {
		(*phase)--;
		if ((*phase) == 0)
			(*phase) = 4;
	} // a ���� ȸ��
	else if (direction == TURN_RIGHT_1 || direction == TURN_RIGHT_2) {
		(*phase)++;
		if ((*phase) == 5)
			(*phase) = 1;
	} // s ������ ȸ��
} // �� ȸ�� (����� �ʿ�)

void block_porting(int caller, int phase, int x, int y, int setup, int field[][WIDTH])
{ // setup ������ �ش� �ʵ带 �����ϴ� �Լ�
	if (caller == 1) {
		if (phase == 1) {
			field[y][x] = setup; // star
			field[y][x - 1] = setup;
			field[y][x + 1] = setup;
			field[y + 1][x - 1] = setup;
		} /* ��ڡ�
			 ��     */
		else if (phase == 2) {
			field[y][x] = setup; // star
			field[y][x - 1] = setup;
			field[y + 1][x] = setup;
			field[y + 2][x] = setup;
		} /* ���
			   ��
			   �� */
		else if (phase == 3) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 1][x - 1] = setup;
			field[y + 1][x - 2] = setup;
		} /*    ��
			����*/
		else if (phase == 4) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 2][x] = setup;
			field[y + 2][x + 1] = setup;
		} /* ��
			 ��
			 ��� */
		else
			cout << "\nillegal phase input.\n";
	}

	else if (caller == 2) {
		if (phase == 1) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 1][x + 1] = setup;
			field[y + 1][x + 2] = setup;
		} /* ��
			 ���� */
		else if (phase == 2) {
			field[y][x] = setup; // star
			field[y][x + 1] = setup;
			field[y + 1][x] = setup;
			field[y + 2][x] = setup;
		} /* �ڡ�
			 ��
			 �� */
		else if (phase == 3) {
			field[y][x] = setup; // star
			field[y][x + 1] = setup;
			field[y][x + 2] = setup;
			field[y + 1][x + 2] = setup;
		} /*�ڡ��
				��*/
		else if (phase == 4) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 2][x] = setup;
			field[y + 2][x - 1] = setup;
		} /* ��
			 ��
		   ��� */
		else
			cout << "\nillegal phase input.\n";
	}

	else if (caller == 3) {
		if (phase == 1) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 1][x - 1] = setup;
			field[y + 1][x + 1] = setup;
		} /* ��
		   ����*/
		else if (phase == 2) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 1][x + 1] = setup;
			field[y + 2][x] = setup;
		} /*��
			���
			��*/
		else if (phase == 3) {
			field[y][x] = setup; // star
			field[y][x - 1] = setup;
			field[y][x + 1] = setup;
			field[y + 1][x] = setup;
		} /*��ڡ�
			  ��*/
		else if (phase == 4) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 2][x] = setup;
			field[y + 1][x - 1] = setup;
		} /* ��
		   ���
			 ��*/
		else
			cout << "\nillegal phase input.\n";
	}

	// ��ȸ�� ��� ****************************************************************
	else if (caller == 4) {
		field[y][x] = setup;
		field[y][x + 1] = setup;
		field[y + 1][x] = setup;
		field[y + 1][x + 1] = setup;
	}
	/* �ڡ�
	   ��� */ // ȸ����ɾ���

	   // ������� 2ȸ�� ***************************************************************
	else if (caller == 5) {
		if (phase % 2 == 0) {
			field[y][x] = setup;
			field[y][x + 1] = setup;
			field[y + 1][x - 1] = setup;
			field[y + 1][x] = setup;
		}
		/* �ڡ�
		 ���*/
		else {
			field[y][x] = setup;
			field[y + 1][x] = setup;
			field[y + 1][x + 1] = setup;
			field[y + 2][x + 1] = setup;
		} /* ��
			 ���
			   ��*/
	}

	else if (caller == 6) {
		if (phase % 2 == 0) {
			field[y][x] = setup;
			field[y][x - 1] = setup;
			field[y + 1][x] = setup;
			field[y + 1][x + 1] = setup;
		} /* ���
		 	   ���*/
		else {
			field[y][x] = setup;
			field[y + 1][x - 1] = setup;
			field[y + 1][x] = setup;
			field[y + 2][x - 1] = setup;
		} /*   ��
			 ���
			 ��   */
	}
	
	else if (caller == 7) {
		if (phase % 2 == 0) {
			field[y][x] = setup;
			field[y][x - 1] = setup;
			field[y][x + 1] = setup;
			field[y][x + 2] = setup;
		}
		// ��ڡ��
		else {
			field[y][x] = setup;
			field[y + 1][x] = setup;
			field[y + 2][x] = setup;
			field[y + 3][x] = setup;
		}
		/* ��
		   ��
		   ��
		   �� */
	}

	else {
		cout << "\nillegal caller input value!\n";
		exit(1);
	}
}