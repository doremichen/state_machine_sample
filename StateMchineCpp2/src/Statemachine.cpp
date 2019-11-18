/*
 * Statemachine.cpp
 *
 *  Created on: 2019/11/12
 *      Author: AdamChen
 */
#include "Statemachine.h"

StateMachine::StateMachine (const unsigned char maxState) :
    _maxState (maxState), _pEventData (NULL), _currentState (ST_MAX_STATES)
{
  // transition to idle
  EventData *pdata = new EventData ();
  pdata->setData (-1);
  transitionState (ST_IDLE, pdata);
}

void
StateMachine::start ()
{
  info << "enter" << end;
  info << "Current state: " << getState () << endl;
  // preCondition check
  if ((this->_currentState != ST_IDLE)) {
    info << "This state just only from idle state" << end;
    return;
  }

  // transition to start
  EventData *pdata = new EventData ();
  pdata->setData (0);
  transitionState (ST_START, pdata);
}

void
StateMachine::setData (EventData* pdata)
{
  info << "enter" << end;
  info << "Current state: " << getState () << endl;
  // preCondition check
  if ((this->_currentState != ST_CHANGE_DATA) && (this->_currentState != ST_START)) {
    info << "This state just only from start state or change data state" << end;
    return;
  }

  transitionState (ST_CHANGE_DATA, pdata);
}

void
StateMachine::navigateStop ()
{
  info << "enter" << end;
  info << "Current state: " << getState () << endl;
  // preCondition check
  if ((this->_currentState != ST_CHANGE_DATA) && (this->_currentState != ST_START)) {
    info << "This state just only from start state or change data state" << end;
    return;
  }

  transitionState (ST_STOP, NULL);
  // return idle state
  transitionState (ST_IDLE, NULL);
}

const string
StateMachine::getState ()
{
  const string ret = stateInfoMap[this->_currentState].msg;

  return ret;
}

// private methods
void
StateMachine::transitionState (E_States state, EventData* pdata)
{
  info << "enter" << end;
  // preCondiftion check
  if (state >= _maxState) {
    info << "No this state: " << state << end;
    return;
  }

  EventData *pTempData = pdata;

  // invoke state function
  const StateStruct* map = this->getStateMap ();
  (this->*map[state].pFunc) (pTempData);
  this->_currentState = state;

  // release event data
  if (pTempData != NULL) {
    delete (pTempData);
    pTempData = NULL;
  }

  info << "exit" << end;
}

void
StateMachine::ST_Idle (EventData* pData)
{
  info << "enter" << end;
}

void
StateMachine::ST_Stop (EventData* pData)
{
  info << "enter" << end;

}

void
StateMachine::ST_Start (EventData* pData)
{
  info << "enter" << end;

}

void
StateMachine::ST_Change_Data (EventData* pData)
{
  info << "enter" << end;
  info << "data: " << pData->getData () << end;
}
