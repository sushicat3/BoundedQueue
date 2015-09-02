/*
It is likely this queue will annoy you.
*/

#include <iostream>

using namespace std;

const int SIZE = 10;

int length = 0;

struct node {
	unsigned int value;
	node * next;
};

node * head;

bool empty() { return length == 0 ? true : false; }
bool full() { return length == SIZE ? true : false; }

void insert(unsigned int x) {
	
	node * n = new node();
	n->value = x;
	n->next = NULL;

	if( empty() ) {
		head = n;
	}
	else {
		node * it = head;
		while (it->next != NULL) {
			it = it->next;
		}
		it->next = n;
	}

	length++;
}

int remove() {
	node * tmp = head;
	int ret = tmp->value;
	head = tmp->next;
	length--;
	delete tmp;
	return ret;
}

int main() {

	int keep_going = 1;
	int j, k;

	cout << "bounded buffer commence!\n" ;
	
	while(keep_going) {
		cout << "insert or delete? (1/0): " ;
		cin >> k;
		if (k==1 && full()) {
			cout << "looks like you're s.o.l.\n" ;
		}
		if (k==0 && empty()) {
			cout << "looks like you're s.o.l.\n" ;
		}
		if (k==1 && !full()) {
			cout << "insert a number: " ;
			cin >> j;
			insert(j);
		}
		if (k==0 && !empty()) {
			cout << "poof! " << remove() << endl;
		}

		cout << "keep going? (1/0): " ;
		cin >> keep_going;
	}

}