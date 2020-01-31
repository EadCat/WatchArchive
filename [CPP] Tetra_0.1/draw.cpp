#include "constant.h"
#include "cursor.h"
#include "block.h"

#include <iostream>

using namespace std;

/*=========================
목록
1. 박스 틀 그리는 함수
2. 정해진 양식대로 블록을 그리는/지우는 함수
3. 사이클이 한번 돌고 2를 감지하여 필드 세팅
=========================*/

int i, j;

void draw_box(int field[][WIDTH]) // 틀 그리기
{
	for (j = 0; j < HEIGHT; j++)
	{
		for (i = 0; i < WIDTH; i++)
		{
			if (i == 0 || i == WIDTH-1 || j == HEIGHT-1)
			{
				field[j][i] = 2;
				cout << "▩";
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
{ // 선택적으로 좌표를 찍어 블록을 프린트하는 함수
  // what 이 1이면 그리고, 2면 지우고, 3이면 쌓는다.
	if (what == 1) { // draw command
		if (caller == 1) {
			if (phase == 1) {
				gotoxy(2 * x, y);
				cout << "□";
				gotoxy(2 * (x - 1), y);
				cout << "□";
				gotoxy(2 * (x + 1), y);
				cout << "□";
				gotoxy(2 * (x - 1), y + 1);
				cout << "□";
			}/* ■★■
				■     */

			else if (phase == 2) {
				gotoxy(2 * x, y);
				cout << "□";
				gotoxy(2 * (x - 1), y);
				cout << "□";
				gotoxy(2 * x, y + 1);
				cout << "□";
				gotoxy(2 * x, y + 2);
				cout << "□";
			} /* ■★
				   ■
				   ■ */
			else if (phase == 3) {
				gotoxy(2 * x, y);
				cout << "□";
				gotoxy(2 * (x - 2), y + 1);
				cout << "□□□";
			} /*    ★
				■■■*/
			else if (phase == 4) {
				gotoxy(2 * x, y);
				cout << "□";
				gotoxy(2 * x, y + 1);
				cout << "□";
				gotoxy(2 * x, y + 2);
				cout << "□□";
			} /* ★
				 ■
				 ■■ */
			else
				cout << "\nillegal phase input.\n";
		}

		else if (caller == 2) {
			if (phase == 1) {
				gotoxy(2 * x, y);
				cout << "□";
				gotoxy(2 * x, y + 1);
				cout << "□□□";
			} /* ★
				 ■■■ */
			else if (phase == 2) {
				gotoxy(2 * x, y);
				cout << "□□";
				gotoxy(2 * x, y + 1);
				cout << "□";
				gotoxy(2 * x, y + 2);
				cout << "□";
			} /* ★■
				 ■
				 ■ */
			else if (phase == 3) {
				gotoxy(2 * x, y);
				cout << "□□□";
				gotoxy(2 * (x + 2), y + 1);
				cout << "□";
			} /*★■■
					■*/
			else if (phase == 4) {
				gotoxy(2 * x, y);
				cout << "□";
				gotoxy(2 * x, y + 1);
				cout << "□";
				gotoxy(2 * (x - 1), y + 2);
				cout << "□□";
			} /* ★
				 ■
			   ■■ */
			else
				cout << "\nillegal phase input.\n";
		}

		else if (caller == 3) {
			if (phase == 1) {
				gotoxy(2 * x, y);
				cout << "□";
				gotoxy(2 * (x - 1), y + 1);
				cout << "□□□";
			} /* ★
			   ■■■*/
			else if (phase == 2) {
				gotoxy(2 * x, y);
				cout << "□";
				gotoxy(2 * x, y + 1);
				cout << "□□";
				gotoxy(2 * x, y + 2);
				cout << "□";
			} /*★
				■■
				■*/
			else if (phase == 3) {
				gotoxy(2 * (x - 1), y);
				cout << "□□□";
				gotoxy(2 * x, y + 1);
				cout << "□";
			} /*■★■
				  ■*/
			else if (phase == 4) {
				gotoxy(2 * x, y);
				cout << "□";
				gotoxy(2 * (x - 1), y + 1);
				cout << "□□";
				gotoxy(2 * x, y + 2);
				cout << "□";
			} /* ★
			   ■■
				 ■*/
			else
				cout << "\nillegal phase input.\n";
		}

		// 무회전 블록 ****************************************************************
		else if (caller == 4) {
			gotoxy(2 * x, y);
			cout << "□□";
			gotoxy(2 * x, y + 1);
			cout << "□□";
		}
		/* ★■
		   ■■ */ // 회전기능없음

		   // 여기부터 2회전 ***************************************************************
		else if (caller == 5) {
			if (phase % 2 == 0) {
				gotoxy(2 * x, y);
				cout << "□□";
				gotoxy(2 * (x - 1), y + 1);
				cout << "□□";
			}
			/* ★■
			 ■■*/
			else {
				gotoxy(2 * x, y);
				cout << "□";
				gotoxy(2 * x, y + 1);
				cout << "□□";
				gotoxy(2 * (x + 1), y + 2);
				cout << "□";
			} /* ★
				 ■■
				   ■*/
		}

		else if (caller == 6) {
			if (phase % 2 == 0) {
				gotoxy(2 * (x - 1), y);
				cout << "□□";
				gotoxy(2 * x, y + 1);
				cout << "□□";
			}
			/* ■★
				 ■■*/
			else {
				gotoxy(2 * x, y);
				cout << "□";
				gotoxy(2 * (x - 1), y + 1);
				cout << "□□";
				gotoxy(2 * (x - 1), y + 2);
				cout << "□";
			} /*   ★
				 ■■
				 ■*/
		}

		else if (caller == 7) {
			if (phase % 2 == 0) {
				gotoxy(2 * (x - 1), y);
				cout << "□□□□";
			}
			// ■★■■
			else {
				gotoxy(2 * x, y);
				cout << "□";
				gotoxy(2 * x, y + 1);
				cout << "□";
				gotoxy(2 * x, y + 2);
				cout << "□";
				gotoxy(2 * x, y + 3);
				cout << "□";
			}
			/* ★
			   ■
			   ■
			   ■ */
		}

		else {
			cout << "\nillegal caller input value!\n";
			exit(1);
		}
	}
	/*※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※*/
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
				}/* ■★■
					■     */

				else if (phase == 2) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * (x - 1), y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "  ";
					gotoxy(2 * x, y + 2);
					cout << "  ";
				} /* ■★
					   ■
					   ■ */
				else if (phase == 3) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * (x - 2), y + 1);
					cout << "      ";
				} /*    ★
					■■■*/
				else if (phase == 4) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "  ";
					gotoxy(2 * x, y + 2);
					cout << "    ";
				} /* ★
					 ■
					 ■■ */
				else
					cout << "\nillegal phase input.\n";
			}

		else if (caller == 2) {
				if (phase == 1) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "      ";
				} /* ★
					 ■■■ */
				else if (phase == 2) {
					gotoxy(2 * x, y);
					cout << "    ";
					gotoxy(2 * x, y + 1);
					cout << "  ";
					gotoxy(2 * x, y + 2);
					cout << "  ";
				} /* ★■
					 ■
					 ■ */
				else if (phase == 3) {
					gotoxy(2 * x, y);
					cout << "      ";
					gotoxy(2 * (x + 2), y + 1);
					cout << "  ";
				} /*★■■
						■*/
				else if (phase == 4) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "  ";
					gotoxy(2 * (x - 1), y + 2);
					cout << "    ";
				} /* ★
					 ■
				   ■■ */
				else
					cout << "\nillegal phase input.\n";
			}

		else if (caller == 3) {
				if (phase == 1) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * (x - 1), y + 1);
					cout << "      ";
				} /* ★
				   ■■■*/
				else if (phase == 2) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "    ";
					gotoxy(2 * x, y + 2);
					cout << "  ";
				} /*★
					■■
					■*/
				else if (phase == 3) {
					gotoxy(2 * (x - 1), y);
					cout << "      ";
					gotoxy(2 * x, y + 1);
					cout << "  ";
				} /*■★■
					  ■*/
				else if (phase == 4) {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * (x - 1), y + 1);
					cout << "    ";
					gotoxy(2 * x, y + 2);
					cout << "  ";
				} /* ★
				   ■■
					 ■*/
				else
					cout << "\nillegal phase input.\n";
			}

			// 무회전 블록 ****************************************************************
		else if (caller == 4) {
				gotoxy(2 * x, y);
				cout << "    ";
				gotoxy(2 * x, y + 1);
				cout << "    ";
			}
			/* ★■
			   ■■ */ // 회전기능없음

			   // 여기부터 2회전 ***************************************************************
		else if (caller == 5) {
				if (phase % 2 == 0) {
					gotoxy(2 * x, y);
					cout << "    ";
					gotoxy(2 * (x - 1), y + 1);
					cout << "    ";
				}
				/* ★■
				 ■■*/
				else {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * x, y + 1);
					cout << "    ";
					gotoxy(2 * (x + 1), y + 2);
					cout << "  ";
				} /* ★
					 ■■
					   ■*/
			}

		else if (caller == 6) {
				if (phase % 2 == 0) {
					gotoxy(2 * (x - 1), y);
					cout << "    ";
					gotoxy(2 * x, y + 1);
					cout << "    ";
				}
				/* ■★
					 ■■*/
				else {
					gotoxy(2 * x, y);
					cout << "  ";
					gotoxy(2 * (x - 1), y + 1);
					cout << "    ";
					gotoxy(2 * (x - 1), y + 2);
					cout << "  ";
				} /*   ★
					 ■■
					 ■*/
			}

		else if (caller == 7) {
				if (phase % 2 == 0) {
					gotoxy(2 * (x - 1), y);
					cout << "        ";
				}
				// ■★■■
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
				/* ★
				   ■
				   ■
				   ■ */
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
			cout << "■";
			gotoxy(2 * (x - 1), y);
			cout << "■";
			gotoxy(2 * (x + 1), y);
			cout << "■";
			gotoxy(2 * (x - 1), y + 1);
			cout << "■";
		}/* ■★■
			■     */

			else if (phase == 2) {
			gotoxy(2 * x, y);
			cout << "■";
			gotoxy(2 * (x - 1), y);
			cout << "■";
			gotoxy(2 * x, y + 1);
			cout << "■";
			gotoxy(2 * x, y + 2);
			cout << "■";
		} /* ■★
			   ■
			   ■ */
			else if (phase == 3) {
			gotoxy(2 * x, y);
			cout << "■";
			gotoxy(2 * (x - 2), y + 1);
			cout << "■■■";
		} /*    ★
			■■■*/
			else if (phase == 4) {
			gotoxy(2 * x, y);
			cout << "■";
			gotoxy(2 * x, y + 1);
			cout << "■";
			gotoxy(2 * x, y + 2);
			cout << "■■";
		} /* ★
			 ■
			 ■■ */
			else
				cout << "\nillegal phase input.\n";
	}

		else if (caller == 2) {
			if (phase == 1) {
			gotoxy(2 * x, y);
			cout << "■";
			gotoxy(2 * x, y + 1);
			cout << "■■■";
		} /* ★
			 ■■■ */
			else if (phase == 2) {
			gotoxy(2 * x, y);
			cout << "■■";
			gotoxy(2 * x, y + 1);
			cout << "■";
			gotoxy(2 * x, y + 2);
			cout << "■";
		} /* ★■
			 ■
			 ■ */
			else if (phase == 3) {
			gotoxy(2 * x, y);
			cout << "■■■";
			gotoxy(2 * (x + 2), y + 1);
			cout << "■";
		} /*★■■
				■*/
			else if (phase == 4) {
			gotoxy(2 * x, y);
			cout << "■";
			gotoxy(2 * x, y + 1);
			cout << "■";
			gotoxy(2 * (x - 1), y + 2);
			cout << "■■";
		} /* ★
			 ■
		   ■■ */
			else
			cout << "\nillegal phase input.\n";
	}

		else if (caller == 3) {
			if (phase == 1) {
			gotoxy(2 * x, y);
			cout << "■";
			gotoxy(2 * (x - 1), y + 1);
			cout << "■■■";
		} /* ★
		   ■■■*/
			else if (phase == 2) {
			gotoxy(2 * x, y);
			cout << "■";
			gotoxy(2 * x, y + 1);
			cout << "■■";
			gotoxy(2 * x, y + 2);
			cout << "■";
		} /*★
			■■
			■*/
			else if (phase == 3) {
			gotoxy(2 * (x - 1), y);
			cout << "■■■";
			gotoxy(2 * x, y + 1);
			cout << "■";
		} /*■★■
			  ■*/
			else if (phase == 4) {
			gotoxy(2 * x, y);
			cout << "■";
			gotoxy(2 * (x - 1), y + 1);
			cout << "■■";
			gotoxy(2 * x, y + 2);
			cout << "■";
		} /* ★
		   ■■
			 ■*/
			else
				cout << "\nillegal phase input.\n";
	}

	// 무회전 블록 ****************************************************************
		else if (caller == 4) {
		gotoxy(2 * x, y);
		cout << "■■";
		gotoxy(2 * x, y + 1);
		cout << "■■";
	}
	/* ★■
	   ■■ */ // 회전기능없음

	   // 여기부터 2회전 ***************************************************************
		else if (caller == 5) {
			if (phase % 2 == 0) {
			gotoxy(2 * x, y);
			cout << "■■";
			gotoxy(2 * (x - 1), y + 1);
			cout << "■■";
		}
		/* ★■
		 ■■*/
			else {
			gotoxy(2 * x, y);
			cout << "■";
			gotoxy(2 * x, y + 1);
			cout << "■■";
			gotoxy(2 * (x + 1), y + 2);
			cout << "■";
		} /* ★
			 ■■
			   ■*/
	}

		else if (caller == 6) {
			if (phase % 2 == 0) {
			gotoxy(2 * (x - 1), y);
			cout << "■■";
			gotoxy(2 * x, y + 1);
			cout << "■■";
		}
		/* ■★
			 ■■*/
			else {
			gotoxy(2 * x, y);
			cout << "■";
			gotoxy(2 * (x - 1), y + 1);
			cout << "■■";
			gotoxy(2 * (x - 1), y + 2);
			cout << "■";
		} /*   ★
			 ■■
			 ■*/
	}

		else if (caller == 7) {
			if (phase % 2 == 0) {
			gotoxy(2 * (x - 1), y);
			cout << "■■■■";
		}
		// ■★■■
			else {
			gotoxy(2 * x, y);
			cout << "■";
			gotoxy(2 * x, y + 1);
			cout << "■";
			gotoxy(2 * x, y + 2);
			cout << "■";
			gotoxy(2 * x, y + 3);
			cout << "■";
		}
		/* ★
		   ■
		   ■
		   ■ */
	}

		else {
			cout << "\nillegal caller input value!\n";
			exit(1);
		}
	}
}