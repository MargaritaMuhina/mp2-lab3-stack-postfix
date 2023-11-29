#pragma once
#include <iostream>
using namespace std;

template <class T>
class TStack {

protected:
	int size;
	int top;
	T* mas;
public:
	TStack(int n = 15) {
		if (n > 0) {
			size = n;
			top = 0;
			mas = new T[size];
		}
		else throw n;

	}
	TStack(TStack<T>& stack) {
		top = stack.top;
		size = stack.size;
		mas = new T[stack.top];
		for (int i = 0; i < size; i++) {
			mas[i] = stack.mas[i];
		}
	}
	~TStack() {
		delete[] mas;
		
	}

	void Push(T a) {
		if (IsFull())   throw "Stack is full";
		mas[top] = a;
		top++;
		
	}
	T Pop() {
		if (IsEmpty())  throw  "Stack is empty";
		top--;
		return mas[top];
	}
	T Top() {
		if (IsEmpty())  throw "Stack is empty";
		return mas[top - 1];
	}

	int GetSize() { return (top ); }


	bool IsFull() {
		if (top == size)
			return true;
		else
			return false;
	}
	bool IsEmpty() {
		if (top == 0)
			return true;
		else
			return false;
	}
	void Clear() {
		top = 0;
		
	}
};