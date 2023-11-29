#include "Calculator.h"
#include <string>
#include <math.h>
using namespace std;

 
int TCalculator::Priority(char elem) {
	switch (elem) {
	case '(': return 0; break;
	case ')': return 0; break;
	case '+': return 1; break;
	case '-': return 1; break;
	case '*': return 2; break;
	case '/': return 2; break;
	case '^': return 3; break;
	case 'c': return 3; break;
	case 't': return 3; break;
	case 's': return 3; break;
	}
	return -1;
}

string TCalculator::ToPostfix() {
	unsigned int i = 0;
	postfix = "";
	st.Clear();   
	string src = "(" + infix + ")";
	for (i = 0; i < src.size(); i++) {
		if ((src[i] >= '0') && (src[i] <= '9') || (src[i] == '.')) {
			postfix += src[i];
		}
		else if (src[i] == '(') {
			st.Push('(');
		}

		else if (src[i] == ')') {
			while (st.Top() != '(')
				postfix += st.Pop();
			st.Pop();
		}
		else if ((src[i] == '+') || (src[i] == '-') || (src[i] == '*') || (src[i] == '/') || (src[i] == '^') || (src[i] == 't') || (src[i] == 's') || (src[i] == 'c')) {
			postfix += ' ';
			if (Priority(st.Top()) < Priority(src[i]))
				st.Push(src[i]);
			else {
				while (Priority(st.Top()) >= Priority(src[i]))
					postfix += st.Pop();
				st.Push(src[i]);
			}
		}
	}
	return postfix;
	
}

bool TCalculator::Brackets(string str) {
	int Flag = 0;
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			Flag++;
		}
		if (str[i] == ')') {
			Flag--;
			if (Flag < 0) return false;
		}
	}
	if (Flag == 0)
		return true;
	else
		return false;
}

double TCalculator::Calculate() {
	st2.Clear();
	double a, b, res;
	if (!Brackets(postfix)) {
		throw "brackets are installed incorrectly";
	}
	for (size_t i = 0; i < postfix.size(); i++) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^' || postfix[i] == 'c' || postfix[i] == 't' || postfix[i] == 's') {
			if (postfix[i] == 't' || postfix[i] == 'c' || postfix[i] == 's') {
				if (st2.IsEmpty()) {
					throw "Stack is empty";
				}
				a = st2.Pop();
				if (postfix[i] == 't') {
					res = tan(a);
				}
				else if (postfix[i] == 'c') {
					res = cos(a);
				}
				else if (postfix[i] == 's') {
					res = sin(a);
				}
				st2.Push(res);
			}
			else {
				if (st2.IsEmpty()) {
					throw "Stack is empty";
				}
				b = st2.Pop();
				if (st2.IsEmpty()) {
					throw "Stack is empty";
				}
				a = st2.Pop();
				switch (postfix[i]) {
				case '+': res = a + b; break;
				case '-': res = a - b; break;
				case '*': res = a * b; break;
				case '/': res = a / b; break;
				case '^': res = pow(a, b); break;
				}
				st2.Push(res);
			}
		}
		else if ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '.') {
			char* tmp;
			res = strtod(&postfix[i], &tmp);
			st2.Push(res);
			size_t g = static_cast<size_t>(tmp - &postfix[i]);
			i += g - 1;
		}
	}
	if (st2.IsEmpty()) {
		throw "Stack is empty";
	}
	else {
		res = st2.Pop();
	}
	if (!st2.IsEmpty()) {
		throw "Stack is not empty";
	}
	
	return res;
}



string TCalculator::SetInfix(const string str) {
	infix = "";
	if (!Brackets(str)) {
		throw "brackets are installed incorrectly";
	}
	
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] != ' ') {
			infix += str[i];
		}
	}
	
	return infix;
}