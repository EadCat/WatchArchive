#include "Listnode.h"

bool List::access_valid(int count) {
	if (count > numbers) {
		printf("유효하지 않은 index입니다.\n");
		return false;
	}
	else
		return true;
		
}

int List::tracking(int data) {
	int i = 0;
	if (head == NULL) {
		cout << "There is no data" << endl;
		return -1;
	}
	else {
		Node* p = head;
		while (p->link != NULL) {
			if (p->data == data) return i;
			else i++;
			p = p->link;
		}
		cout << "There is no data you want." << endl;
		return -1;
	}
}

void List::add(int data) {
	Node* new_node = new Node;
	Node* searcher;
	new_node->data = data;
	new_node->link = NULL;
	if (head == NULL) {
		head = new_node;
		cout << "생성!" << endl;
	}
	else {
		searcher = head;
		while (searcher->link != NULL) {
			searcher = searcher->link;
		}
		searcher->link = new_node;
	}
	numbers++;
}

void List::add(int index, int data) {
	if (List::access_valid(index)) {
		if (index == 0) {
			Node* new_node = new Node;
			new_node->data = data;
			new_node->link = head;
			head = new_node;
			numbers++;
		}
		else {
			int i = 0;
			Node* new_node = new Node;
			Node* searcher = head;
			new_node->data = data;
			while (i != index - 1) {
				searcher = searcher->link;
				i++;
			}
			new_node->link = searcher->link;
			searcher->link = new_node;
			numbers++;
		}
	}
	else
		;
}

void List::del(int index) {
	if (List::access_valid(index)) {
		if (index == 0) {
			Node* searcher = head;
			Node* memory = searcher->link;
			head = memory;
			delete searcher;
			numbers--;
		}
		else {
			int i = 0;
			Node* memory_prev = NULL;
			Node* memory_next = NULL;
			Node* searcher = head;
			while (i < index - 1) {
				searcher = searcher->link;
				i++;
			}
			memory_prev = searcher; // i - 1
			searcher = searcher->link; // jump to i
			memory_next = searcher->link; // i + 1

			memory_prev->link = memory_next; // link i-1 with i+1

			delete(searcher); // delete i
			numbers--;
		}
	}
	else
		;
}

void List::del_all(int data) {
	if (head == NULL) {
		cout << "NULL List." << endl;
	}
	else {
		Node* searcher;
		Node* memory_prev = NULL;
		Node* memory_next = NULL;
		while (1) {
			searcher = head;
			if (searcher->data == data) {
				memory_next = searcher->link;
				head = memory_next;
				delete searcher;
				numbers--;
			}
			else
				break;
		}

		memory_prev = searcher; // i-1
		searcher = searcher->link; // i
		memory_next = searcher->link; // i+1

		while (searcher->link != NULL) {
			if (searcher->data == data) {
				memory_prev->link = memory_next;
				delete searcher;
				searcher = memory_next;
				memory_next = memory_next->link;
				numbers--;
			}
			else {
				memory_prev = searcher;
				searcher = memory_next;
				memory_next = memory_next->link;
			}
		}
	}
}

void List::print() {
	if (head == NULL) {
		cout << "NULL List." << endl;
	}
	else if (numbers == 1) {
		Node* searcher = head;
		cout << searcher->data << endl;
	}
	else {
		int i = 0;
		Node* searcher = head;
		while (i < numbers - 1) {
			cout << searcher->data << " >> ";
			i++;
			searcher = searcher->link;
		}
		cout << searcher->data << endl;
	}
}

void List::clean() {
	if (head == NULL) {
		cout << "already NULL List." << endl;
	}
	else {
		int count = 0;
		Node* searcher = head;
		Node* memory = searcher;
		while (count < numbers) {
			memory = memory->link;
			delete searcher;
			searcher = memory;
			count++;
		}
		numbers = 0;
	}
}

List List::reverse() {
	List rev;
	int* element = new int[numbers];
	Node* searcher = head;
	for (int i = 0; i < numbers; i++) {
		element[i] = searcher->data;
		searcher = searcher->link;
	}
	for (int i = numbers-1; i > -1; i--) {
		rev.add(element[i]);
	}
	return rev;
}

List List::reverse(int index) {
	List rev;
	int* element = new int[numbers - index];
	Node* searcher = head;
	for (int i = 0; i < index; i++)
		searcher = searcher->link; // travel code
	for (int i = 0; i < numbers - index; i++) {
		element[i] = searcher->data; // copy
		searcher = searcher->link; // step
	}
	for (int i = numbers - index - 1; i > -1; i--)
		rev.add(element[i]);
	return rev;
}

List List::extract(int index) {
	List ext;
	int* element = new int[numbers - index];
	Node* searcher = head;
	for (int i = 0; i < index; i++)
		searcher = searcher->link; // travel code
	for (int i = 0; i < numbers - index; i++) {
		element[i] = searcher->data; // copy
		searcher = searcher->link; // step
	}
	for (int i = 0; i < numbers - index; i++)
		ext.add(element[i]);
	return ext;
}

List List::concat(List after) {
	List conc;
	Node* searcher = head; // targeting head
	for (int i = 0; i < numbers; i++) {
		conc.add(searcher->data); // copy
		searcher = searcher->link; // step
	}
	searcher = after.head; // targeting head
	for (int j = 0; j < after.numbers; j++) {
		conc.add(searcher->data); // copy
		searcher = searcher->link; // step
	}

	return conc;
}

bool List::isnull() {
	if (head == NULL)
		return true;
	else
		return false;
}

int List::count() {
	return numbers;
}