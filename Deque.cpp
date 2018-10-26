#include <iostream>
#include<stdio.h>
#include<string>
using namespace std;

typedef struct node {
	int data;
	node * next;
	node * prev;
}Node;

typedef struct deque {
	Node * head;
	Node * tail;
	int size;
}Deque;

void init(Deque *dq) {
	dq->size = 0;
	dq->head = NULL;
	dq->tail = NULL;

}
void push_front(Deque *dq,int X) {
	Node * newNode = new Node();
	
	if (newNode) { //성공적으로 할당 되면
		newNode->data = X;
		newNode->prev = NULL;
		newNode->next = NULL;
		if (dq->head == NULL) { //첫 노드
			dq->head = newNode;
			dq->tail = newNode;
		}
		else {
			newNode->next = dq->head; 
			dq->head->prev = newNode;
			dq->head = newNode;
		}
		dq->size++;
	}
}

void push_back(Deque *dq, int X) {
	Node * newNode = new Node();

	if (newNode) { //성공적으로 할당 되면
		newNode->data = X;
		newNode->prev = NULL;
		newNode->next = NULL;

		if (dq->tail == NULL) { //첫 노드
			dq->head = newNode;
			dq->tail = newNode;
		}
		else {
			dq->tail->next = newNode;
			newNode->prev = dq->tail;
			dq->tail = newNode;
		}
		dq->size++;
	}
}

bool empty(Deque *dq) {
	if (dq->size == 0)
		return true;
	else
		return false;
}

int pop_front(Deque *dq) {
	if (empty(dq))
		return -1;
	Node * delNode = dq->head;
	int deldata = delNode->data;

	/*
	dq->head = dq->head->next;
	if (dq->head) {
	dq->head->prev = NULL;
		}
	*/
	if (dq->head == dq->tail) {
		dq->head = NULL;
		dq->tail = NULL;
	}
	else {
		dq->head = dq->head->next;
		if (dq->head) 
		dq->head->prev = NULL;
	}
	delete delNode;
	dq->size--;
	return deldata;
}

int pop_back(Deque *dq) {
	if (empty(dq)) 
		return -1;
	Node * delNode = dq->tail;
	int deldata = delNode->data;
	/*
	dq->tail = dq->tail->prev;
	if(dq->tail)
		dq->tail->next = NULL;
		*/

	if (dq->head == dq->tail) {
		dq->head = NULL;
		dq->tail = NULL;
	}
	else {
		dq->tail = dq->tail->prev;
		if (dq->tail)
		dq->tail->next = NULL;

	}
	delete delNode;
	dq->size--;
	return deldata;
}

int size(Deque * dq) {
	return dq->size;
}


int front(Deque *dq) {
	if (empty(dq))
		return -1;
	else
		return dq->head->data;
}
int back(Deque *dq) {
	if (empty(dq))
		return -1;
	else
		return dq->tail->data;
}

int main() {
	Deque dq;
	init(&dq);
	string input;
	int t,n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> input;

		if (!input.compare("push_back")) {
			cin >> n;
			push_back(&dq, n);
		}
		else if (!input.compare("push_front")) {
			cin >> n;
			push_front(&dq, n);
		}
		else if (!input.compare("pop_front"))
			cout << pop_front(&dq) << '\n';
		else if (!input.compare("pop_back"))
			cout << pop_back(&dq) << '\n';
		else if (!input.compare("size"))
			cout << size(&dq) << '\n';
		else if (!input.compare("empty"))
			cout << empty(&dq) << '\n';
		else if (!input.compare("front"))
			cout << front(&dq) << '\n';
		else if (!input.compare("back"))
			cout << back(&dq) << '\n';
	}
}