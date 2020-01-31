#include "constant.h"
#include "cursor.h"
#include "block.h"

#include <iostream>

using namespace std;

/*=========================
���
1. �ڽ� Ʋ �׸��� �Լ�
2. ������ ��Ĵ�� ����� �׸���/����� �Լ�
3. ����Ŭ�� �ѹ� ���� 2�� �����Ͽ� �ʵ� ����
=========================*/

int i, j;

void draw_box(int field[][WIDTH]) // Ʋ �׸���
{
	for (j = 0; j < HEIGHT; j++)
	{
		for (i = 0; i < WIDTH; i++)
		{
			if (i == 0 || i == WIDTH-1 || j == HEIGHT-1)
			{
				field[j][i] = 2;
				cout << "��";
				if (i == WIDTH-1)
					cout << endl;
			}
			else 
			{
				field[j][i] = 0;
				cout << "  ";
			}
		}
	}
}

void drawing_block(int caller, int phase, int x, int y, int what)
{ // ���������� ��ǥ�� ��� ����� ����Ʈ�ϴ� �Լ�
  // what �� 1�̸� �׸���, 2�� �����, 3�̸� �״´�.
	if (what == 1) { // draw command
		if (caller == 1) {
			if (phase == 1) {
				gotoxy(2 * x, y);
				cout << "��";
				gotoxy(2 * (x - 1), y);
				cout << "��";
				gotoxy(2 * (x + 1), y);
				cout << "��";
				gotoxy(2 * (x - 1), y + 1);
				cout << "��";
			}/* ��ڡ�
				��     */

			else if (phase == 2) {
				gotoxy(2 * x, y);
				cout << "��";
				gotoxy(2 * (x - 1), y);
				cout << "��";
				gotoxy(2 * x, y + 1);
				cout << "��";
				gotoxy(2 * x, y + 2);
				cout << "��";
			} /* ���
				   ��
				   �� */
			else if (phase == 3) {
				gotoxy(2 * x, y);
				cout << "��";
				gotoxy(2 * (x - 2), y + 1);
				cout << "����";
			} /*    ��
				����*/
			else if (phase == 4) {
				gotoxy(2 * x, y);
				cout << "��";
				gotoxy(2 * x, y + 1);
				cout << "��";
				gotoxy(2 * x, y + 2);
				cout << "���";
			} /* ��
				 ��
				 ��� */
			else
				cout << "\nillegal phase input.\n";
		}

		else if (caller == 2) {
			if (phase == 1) {
				gotoxy(2 * x, y);
				cout << "��";
				gotoxy(2 * x, y + 1);
				cout << "����";
			} /* ��
				 ���� */
			else if (phase == 2) {
				gotoxy(2 * x, y);
				cout << "���";
				gotoxy(2 * x, y + 1);
				cout << "��";
				gotoxy(2 * x, y + 2);
				cout << "��";
			} /* �ڡ�
				 ��
				 �� */
			else if (phase == 3) {
				gotoxy(2 * x, y);
				cout << "����";
				gotoxy(2 * (x + 2), y + 1);
				cout << "��";
			} /*�ڡ��
					��*/
			else if (phase == 4) {
				gotoxy(2 * x, y);
				cout << "��";
				gotoxy(2 * x, y + 1);
				cout << "��";
				gotoxy(2 * (x - 1), y + 2);
				cout << "���";
			} /* ��
				 ��
			   ��� */
			else
				cout << "\nillegal phase input.\n";
		}

		else if (caller == 3) {
			if (phase == 1) {
				gotoxy(2 * x, y);
				cout << "��";
				gotoxy(2 * (x - 1), y + 1);
				cout << "����";
			} /* ��
			   ����*/
			else if (phase == 2) {
				gotoxy(2 * x, y);
				cout << "��";
				gotoxy(2 * x, y + 1);
				cout << "���";
				gotoxy(2 * x, y + 2);
				cout << "��";
			} /*��
				���
				��*/
			else if (phase == 3) {
				gotoxy(2 * (x - 1), y);
				cout << "����";
				gotoxy(2 * x, y + 1);
				cout << "��";
			} /*��ڡ�
				  ��*/
			else if (phase == 4) {
				gotoxy(2 * x, y);
				cout << "��";
				gotoxy(2 * (x - 1), y + 1);
				cout << "���";
				gotoxy(2 * x, y + 2);
				cout << "��";
			} /* ��
			   ���
				 ��*/
			else
				cout << "\nillegal phase input.\n";
		}

		// ��ȸ�� ��� ****************************************************************
		else if (caller == 4) {
			gotoxy(2 * x, y);
			cout << "���";
			gotoxy(2 * x, y + 1);
			cout << "���";
		}
		/* �ڡ�
		   ��� */ // ȸ����ɾ���

		   // ������� 2ȸ�� ***************************************************************
		else if (caller == 5) {
			if (phase % 2 == 0) {
				gotoxy(2 * x, y);
				cout << "���";
				gotoxy(2 * (x - 1), y + 1);
				cout << "���";
			}
			/* �ڡ�
			 ���*/
			else {
				gotoxy(2 * x, y);
				cout << "��";
				gotoxy(2 * x, y + 1);
				cout << "���";
				gotoxy(2 * (x + 1), y + 2);
				cout << "��";
			} /* ��
				 ���
				   ��*/
		}

		else if (caller == 6) {
			if (phase % 2 == 0) {
				gotoxy(2 * (x - 1), y);
				cout << "���";
				gotoxy(2 * x, y + 1);
				cout << "���";
			}
			/* ���
				 ���*/
			else {
				gotoxy(2 * x, y);
				cout << "��";
				gotoxy(2 * (x - 1), y + 1);
				cout << "���";
				gotoxy(2 * (x - 1), y + 2);
				cout << "��";
			} /*   ��
				 ���
				 ��*/
		}

		else if (caller == 7) {
			if (phase % 2 == 0) {
				gotoxy(2 * (x - 1), y);
				cout << "�����";
			}
			// ��ڡ��
			else {
				gotoxy(2 * x, y);
				cout << "��";
				gotoxy(2 * x, y + 1);
				cout << "��";
				gotoxy(2 * x, y + 2);
				cout << "��";
				gotoxy(2 * x, y + 3);
				cout << "��";
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
	/*�ءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءء�*/
	else if (what == 2) { // erase command
		if (caller == 1) {
				if (phase == 1) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * (x - 1), y);
					cout << "  ";
					gotoxy(2 * (x + 1), y);
					cout << "  ";
					gotoxy(2 * (x - 1), y + 1);
					cout << "  ";
				}/* ��ڡ�
					��     */

				else if (phase == 2) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * (x - 1), y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "  ";
					gotoxy(2 * x, y + 2);
					cout << "  ";
				} /* ���
					   ��
					   �� */
				else if (phase == 3) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * (x - 2), y + 1);
					cout << "      ";
				} /*    ��
					����*/
				else if (phase == 4) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "  ";
					gotoxy(2 * x, y + 2);
					cout << "    ";
				} /* ��
					 ��
					 ��� */
				else
					cout << "\nillegal phase input.\n";
			}

		else if (caller == 2) {
				if (phase == 1) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "      ";
				} /* ��
					 ���� */
				else if (phase == 2) {
					gotoxy(2 * x, y);
					cout << "    ";
					gotoxy(2 * x, y + 1);
					cout << "  ";
					gotoxy(2 * x, y + 2);
					cout << "  ";
				} /* �ڡ�
					 ��
					 �� */
				else if (phase == 3) {
					gotoxy(2 * x, y);
					cout << "      ";
					gotoxy(2 * (x + 2), y + 1);
					cout << "  ";
				} /*�ڡ��
						��*/
				else if (phase == 4) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "  ";
					gotoxy(2 * (x - 1), y + 2);
					cout << "    ";
				} /* ��
					 ��
				   ��� */
				else
					cout << "\nillegal phase input.\n";
			}

		else if (caller == 3) {
				if (phase == 1) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * (x - 1), y + 1);
					cout << "      ";
				} /* ��
				   ����*/
				else if (phase == 2) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "    ";
					gotoxy(2 * x, y + 2);
					cout << "  ";
				} /*��
					���
					��*/
				else if (phase == 3) {
					gotoxy(2 * (x - 1), y);
					cout << "      ";
					gotoxy(2 * x, y + 1);
					cout << "  ";
				} /*��ڡ�
					  ��*/
				else if (phase == 4) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * (x - 1), y + 1);
					cout << "    ";
					gotoxy(2 * x, y + 2);
					cout << "  ";
				} /* ��
				   ���
					 ��*/
				else
					cout << "\nillegal phase input.\n";
			}

			// ��ȸ�� ��� ****************************************************************
		else if (caller == 4) {
				gotoxy(2 * x, y);
				cout << "    ";
				gotoxy(2 * x, y + 1);
				cout << "    ";
			}
			/* �ڡ�
			   ��� */ // ȸ����ɾ���

			   // ������� 2ȸ�� ***************************************************************
		else if (caller == 5) {
				if (phase % 2 == 0) {
					gotoxy(2 * x, y);
					cout << "    ";
					gotoxy(2 * (x - 1), y + 1);
					cout << "    ";
				}
				/* �ڡ�
				 ���*/
				else {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "    ";
					gotoxy(2 * (x + 1), y + 2);
					cout << "  ";
				} /* ��
					 ���
					   ��*/
			}

		else if (caller == 6) {
				if (phase % 2 == 0) {
					gotoxy(2 * (x - 1), y);
					cout << "    ";
					gotoxy(2 * x, y + 1);
					cout << "    ";
				}
				/* ���
					 ���*/
				else {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * (x - 1), y + 1);
					cout << "    ";
					gotoxy(2 * (x - 1), y + 2);
					cout << "  ";
				} /*   ��
					 ���
					 ��*/
			}

		else if (caller == 7) {
				if (phase % 2 == 0) {
					gotoxy(2 * (x - 1), y);
					cout << "        ";
				}
				// ��ڡ��
				else {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "  ";
					gotoxy(2 * x, y + 2);
					cout << "  ";
					gotoxy(2 * x, y + 3);
					cout << "  ";
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

	else if (what == 3) {
		if (caller == 1) {
			if (phase == 1) {
			gotoxy(2 * x, y);
			cout << "��";
			gotoxy(2 * (x - 1), y);
			cout << "��";
			gotoxy(2 * (x + 1), y);
			cout << "��";
			gotoxy(2 * (x - 1), y + 1);
			cout << "��";
		}/* ��ڡ�
			��     */

			else if (phase == 2) {
			gotoxy(2 * x, y);
			cout << "��";
			gotoxy(2 * (x - 1), y);
			cout << "��";
			gotoxy(2 * x, y + 1);
			cout << "��";
			gotoxy(2 * x, y + 2);
			cout << "��";
		} /* ���
			   ��
			   �� */
			else if (phase == 3) {
			gotoxy(2 * x, y);
			cout << "��";
			gotoxy(2 * (x - 2), y + 1);
			cout << "����";
		} /*    ��
			����*/
			else if (phase == 4) {
			gotoxy(2 * x, y);
			cout << "��";
			gotoxy(2 * x, y + 1);
			cout << "��";
			gotoxy(2 * x, y + 2);
			cout << "���";
		} /* ��
			 ��
			 ��� */
			else
				cout << "\nillegal phase input.\n";
	}

		else if (caller == 2) {
			if (phase == 1) {
			gotoxy(2 * x, y);
			cout << "��";
			gotoxy(2 * x, y + 1);
			cout << "����";
		} /* ��
			 ���� */
			else if (phase == 2) {
			gotoxy(2 * x, y);
			cout << "���";
			gotoxy(2 * x, y + 1);
			cout << "��";
			gotoxy(2 * x, y + 2);
			cout << "��";
		} /* �ڡ�
			 ��
			 �� */
			else if (phase == 3) {
			gotoxy(2 * x, y);
			cout << "����";
			gotoxy(2 * (x + 2), y + 1);
			cout << "��";
		} /*�ڡ��
				��*/
			else if (phase == 4) {
			gotoxy(2 * x, y);
			cout << "��";
			gotoxy(2 * x, y + 1);
			cout << "��";
			gotoxy(2 * (x - 1), y + 2);
			cout << "���";
		} /* ��
			 ��
		   ��� */
			else
			cout << "\nillegal phase input.\n";
	}

		else if (caller == 3) {
			if (phase == 1) {
			gotoxy(2 * x, y);
			cout << "��";
			gotoxy(2 * (x - 1), y + 1);
			cout << "����";
		} /* ��
		   ����*/
			else if (phase == 2) {
			gotoxy(2 * x, y);
			cout << "��";
			gotoxy(2 * x, y + 1);
			cout << "���";
			gotoxy(2 * x, y + 2);
			cout << "��";
		} /*��
			���
			��*/
			else if (phase == 3) {
			gotoxy(2 * (x - 1), y);
			cout << "����";
			gotoxy(2 * x, y + 1);
			cout << "��";
		} /*��ڡ�
			  ��*/
			else if (phase == 4) {
			gotoxy(2 * x, y);
			cout << "��";
			gotoxy(2 * (x - 1), y + 1);
			cout << "���";
			gotoxy(2 * x, y + 2);
			cout << "��";
		} /* ��
		   ���
			 ��*/
			else
				cout << "\nillegal phase input.\n";
	}

	// ��ȸ�� ��� ****************************************************************
		else if (caller == 4) {
		gotoxy(2 * x, y);
		cout << "���";
		gotoxy(2 * x, y + 1);
		cout << "���";
	}
	/* �ڡ�
	   ��� */ // ȸ����ɾ���

	   // ������� 2ȸ�� ***************************************************************
		else if (caller == 5) {
			if (phase % 2 == 0) {
			gotoxy(2 * x, y);
			cout << "���";
			gotoxy(2 * (x - 1), y + 1);
			cout << "���";
		}
		/* �ڡ�
		 ���*/
			else {
			gotoxy(2 * x, y);
			cout << "��";
			gotoxy(2 * x, y + 1);
			cout << "���";
			gotoxy(2 * (x + 1), y + 2);
			cout << "��";
		} /* ��
			 ���
			   ��*/
	}

		else if (caller == 6) {
			if (phase % 2 == 0) {
			gotoxy(2 * (x - 1), y);
			cout << "���";
			gotoxy(2 * x, y + 1);
			cout << "���";
		}
		/* ���
			 ���*/
			else {
			gotoxy(2 * x, y);
			cout << "��";
			gotoxy(2 * (x - 1), y + 1);
			cout << "���";
			gotoxy(2 * (x - 1), y + 2);
			cout << "��";
		} /*   ��
			 ���
			 ��*/
	}

		else if (caller == 7) {
			if (phase % 2 == 0) {
			gotoxy(2 * (x - 1), y);
			cout << "�����";
		}
		// ��ڡ��
			else {
			gotoxy(2 * x, y);
			cout << "��";
			gotoxy(2 * x, y + 1);
			cout << "��";
			gotoxy(2 * x, y + 2);
			cout << "��";
			gotoxy(2 * x, y + 3);
			cout << "��";
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
}