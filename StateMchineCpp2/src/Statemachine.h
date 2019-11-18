/*
 * Staemachine.h
 *
 *  Created on: 2019/11/12
 *      Author: AdamChen
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


#define info cout << __FUNCTION__ << " "
#define end endl

/**
 * event data
 */
class EventData
{
public:
  virtual ~EventData() {}
  void setData(int data)
  {
     this->_data = data;
  }
  int getData() {
    return this->_data;
  }
private:
  int _data;
};

/**
 * State tag
 */
enum E_States
{
  ST_IDLE = 0,
  ST_STOP,
  ST_START,
  ST_CHANGE_DATA,
  ST_MAX_STATES
};

/**
 * state info
 */
static struct _StateInfo {
  E_States state;
  const string msg;
} stateInfoMap[] = {
    {ST_IDLE, "Idle state"},
    {ST_STOP, "Stop state"},
    {ST_START, "Start state"},
    {ST_CHANGE_DATA, "Set data state"},
    {ST_MAX_STATES, "Unknown state"},
};


class StateMachine;
// state function pointer type
typedef void (StateMachine::*StateFunc)(EventData*);
typedef struct _StateStruct {
  StateFunc pFunc;
} StateStruct;


/**
 * This is state engine
 */
class StateMachine
{
public:
  StateMachine(const unsigned char maxState);
  virtual ~StateMachine() {}
  void start();
  void setData(EventData*);
  void navigateStop();
  const string getState();
  const StateStruct * getStateMap()
  {
    // state machine map
      static const StateStruct stateMap[] = {
          ST_Idle,
          ST_Stop,
          ST_Start,
          ST_Change_Data,
      };

      return &stateMap[0];
  }
private:
  // STATE MACHINE STATE FUNCTION
  void ST_Idle(EventData*);
  void ST_Stop(EventData*);
  void ST_Start(EventData*);
  void ST_Change_Data(EventData*);


  const unsigned char _maxState;
  EventData* _pEventData;
  E_States _currentState;
  void transitionState(E_States, EventData*);


};


#endif /* STATEMACHINE_H_ */
