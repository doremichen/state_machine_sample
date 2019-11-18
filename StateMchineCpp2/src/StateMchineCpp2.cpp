//============================================================================
// Name        : StateMchineCpp2.cpp
// Author      : AdamChen
// Version     :
// Copyright   : com.adam.app
// Description : Program state machine
//============================================================================

#include "Statemachine.h"

int
main ()
{

  StateMachine stateMachine(ST_MAX_STATES);

  stateMachine.start();

  EventData *data1 = new EventData();
  data1->setData(100);
  stateMachine.setData(data1);

  EventData *data2 = new EventData();
  data1->setData(100000);
  stateMachine.setData(data2);

  stateMachine.navigateStop();
  stateMachine.navigateStop();

  return 0;
}
