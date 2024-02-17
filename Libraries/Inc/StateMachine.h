/*
 * StateMachine.h
 *
 *  Created on: Feb 11, 2024
 *      Author: erhangok
 *
 *  USAGE:
 *  Write your state functions and default state
 *  and run "void Sm_run(void)" inside your while loop
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "stm32f4xx.h"


typedef enum{
	STATE_A,
	STATE_B,
	STATE_C,
	NUM_STATES
}StateType;

typedef struct{
	StateType state;
	void (*function)(void); //function param can be changed
}StateMachineType;


StateType SmState;

void Sm_StateA(void);
void Sm_StateB(void);
void Sm_StateC(void);
void Sm_DefaultState(void);
void Sm_run(void);

static const StateMachineType StateMachine[] =
{
	{STATE_A, Sm_StateA},
	{STATE_B, Sm_StateB},
	{STATE_C, Sm_StateC}
};


#endif /* STATEMACHINE_H_ */
