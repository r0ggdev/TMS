#pragma once
#ifndef QUEUES_H
#define QUEUES_H

template<typename value>
class Queues
{
public:
	Queues() {
		this->initial = NULL;
		this->end = NULL;
	}
	~Queues() {}

	struct Node {
		value element;
		Node* next;

		Node(value _element, Node* _next = NULL) {
			element = _element;
			next = _next;
		}
	};

	void enqueue(value _element) {
		Node* node = new Node(_element);
		if (isEmpty()) {
			initial = node;
			end = initial;
		}
		else {
			end->next = node;
			end = node;
		}
		node = NULL;
	}

	value dequeue() {
		value element = initial->element;

		if (initial == end) {
			initial = NULL;
			end = NULL;
		}
		else { initial = initial->next; }

		return element;
	}

	bool isEmpty() { return (initial == NULL); }

private:
	Node* initial;
	Node* end;
};
#endif