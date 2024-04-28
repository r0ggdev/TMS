#pragma once
#ifndef STACKS_H
#define STACKS_H

template<typename value>
class Stacks
{
public:
	Stacks() { top = NULL; }
	~Stacks() {}

	struct Node
	{
		value element;
		Node* next;

		Node(value _element = nullptr, Node* _next = nullptr) : element(_element), next(_next) {}
	};

	bool isEmpty() { return (top == NULL); }

	void push(value _element) {
		top = isEmpty() ? new Node(_element) : new Node(_element, top);
	}

	value pop() {
		if (isEmpty()) { return NULL; }
		else {
			value _element = (top->element);
			top = top->next;
			return _element;
		}
	}

private:
	Node* top;
};

#endif // !STACKS_H