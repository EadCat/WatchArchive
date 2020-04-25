#include "ListNode.h"

int main() {
	List A, B;

	A.add(5);
	A.add(5);
	A.add(3);
	A.add(6);
	A.print();
	A.add(1, 1);
	A.print();
	A.del(1);
	A.print();
	A.add(1, 4);
	A.add(3, 4);
	A.print();
	A.del_all(5);
	A.print();
	B.add(5);
	B.add(6);
	B.add(7);
	B.print();
	B.del(0);
	B.print();
	B.add(0, 2);
	B.print();
	A.print();
	List C = A.reverse();
	C.print();
	List D = A.reverse(2);
	D.print();
	List E = A.extract(2);
	E.print();
	List F = A.concat(B);
	F.print();
	cout << "F count : " << F.count() << endl;

	A.clean();
	B.clean();
	C.clean();
	D.clean();
	E.clean();
	F.clean();

	
	return 0;
}