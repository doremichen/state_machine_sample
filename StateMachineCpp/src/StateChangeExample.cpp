//============================================================================
// Name        : StateChangeExample.cpp
// Author      : doremi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "state.h"

using namespace std;

#define HERE "[" << __FUNCTION__ << "]: "

//state function
void State_A()
{
	cout << "A" << endl;
}

void State_B()
{
	cout << "B" << endl;
}

void State_C()
{
	cout << "C" << endl;
}

void State_D()
{
	cout << "D" << endl;
}

//
HashMap map;

//initail table
void InitialTable()
{
	cout << HERE << endl;
	map.put(STATE_A, State_A);
	map.put(STATE_B, State_B);
	map.put(STATE_C, State_C);
	map.put(STATE_D, State_D);
}

//Change state function
void ChangeState(int status)
{

	if(status < STATE_MAX) {

		STATE_FUNCP pfunc = map.getFunc(status);
		pfunc();

	}
	else {
      cout << "NO fucntion" << endl;
	}
}


int main() {

	InitialTable();

	int input;

	while(true) {
		cout << "please input nuimber: " << endl;
		cin >> input;

		if(input == -1)
			break;

		ChangeState(input);
	}

	return 0;
}
