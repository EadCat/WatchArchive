#include <iostream>

using namespace std;

class List {
private:
	class Node {
	public:
		int data;
		Node* link;
	};
	bool access_valid(int count);
	Node* head = NULL;
	int numbers;

public:
	int tracking(int data); // find index
	void add(int data); // add tail
	void add(int index, int data);
	void del(int index);
	void del_all(int data);
	void print();
	void clean();
	List reverse();
	List reverse(int index);
	List extract(int index);
	List concat(List after);
	bool isnull();
	int count();
};