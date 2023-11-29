// mp2-lab3-stack-postfix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Stack.h"
#include "Calculator.h"
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	TStack<int> s;
	
	cout << "Simple test of stack" << endl;
	cout << "Push elements and pop one element" << endl;
	s.Push(3);
	s.Pop();
	cout << "Everything works correctly" << endl;


	cout << endl << "Simple test of calculator" << endl;

	TCalculator STR;
	try {
		cout<<STR.SetInfix("(3-7+11*2*(8/4-1+7))*2")<<endl;
		cout << STR.ToPostfix()<< endl;
		cout << STR.Calculate() << endl;
	}
	catch (const char* e) {
		cout << e << endl;
	}
	return 1;
}


