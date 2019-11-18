/*
 * state.cpp
 *
 *  Created on: 2014/1/27
 *      Author: AdamChen
 */
#include <iostream>
#include "state.h"

using namespace std;

#define HERE "[" << __FUNCTION__ << "]: "


//class HashEntry
HashEntry::HashEntry(int state, STATE_FUNCP func)
{
	this->state = state;
	this->pStateFunc = func;
}

STATE_FUNCP HashEntry::getFunc()
{
	return this->pStateFunc;
}

int HashEntry::getState()
{
	return this->state;
}

//class HashMap
HashMap::HashMap()
{
	cout << HERE << endl;
	table = new HashEntry*[STATE_MAX];
	for(int i = 0; i < STATE_MAX; ++i) {
		table[i] =  NULL;
	}
}

HashMap::~HashMap()
{
	for(int i = 0; i < STATE_MAX; ++i) {
		if(table[i] != NULL) {
			delete table[i];
		}
	}

	delete[] table;
}

STATE_FUNCP HashMap::getFunc(int state)
{
	int hash = state % STATE_MAX;

	while(table[hash] != NULL && table[hash]->getState() != state)
		hash = (state + 1) % STATE_MAX;

	if(table[hash] == NULL)
		return NULL;
	else
		return table[hash]->getFunc();
}


void HashMap::put(int state, STATE_FUNCP funcp)
{
	int hash = state % STATE_MAX;

	while(table[hash] != NULL && table[hash]->getState() != state)
			hash = (state + 1) % STATE_MAX;

	if(table[hash] != NULL)
		delete table[hash];

	table[hash] = new HashEntry(state, funcp);
}






