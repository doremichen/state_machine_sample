/*
 * state.h
 *
 *  Created on: 2014/1/27
 *      Author: AdamChen
 */

#ifndef STATE_H_
#define STATE_H_

typedef enum {
	STATE_A = 0,
	STATE_B,
	STATE_C,
	STATE_D,
	STATE_MAX
} Current_State;

typedef void (*STATE_FUNCP) ();

class HashEntry {
public:
	HashEntry(int, STATE_FUNCP);
	STATE_FUNCP getFunc();
	int getState();

private:
	int state;
	STATE_FUNCP pStateFunc;
};

class HashMap {
public:
	HashMap();
	~HashMap();
	STATE_FUNCP getFunc(int);
	void put(int, STATE_FUNCP);
private:
	HashEntry** table;
};

#endif /* STATE_H_ */
