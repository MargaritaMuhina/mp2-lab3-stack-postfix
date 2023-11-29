#pragma once
#include "Stack.h"
#include <string>
using namespace std;

class TCalculator {
	string infix;
	string postfix;
	TStack<char> st;
	TStack<double> st2;
	int Priority(char elem);


public:
	TCalculator() : st(100), st2(100) {
		infix = "";
		postfix = "";
	}

	string GetExpression() {
		return infix;
	}
	string GetPostfix() {
		return postfix;
	}
	string ToPostfix();
	bool Brackets(string strc);
	double Calculate();
	string SetInfix(const string str);
};