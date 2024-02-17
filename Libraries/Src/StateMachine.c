/*
 * StateMachine.c
 *
 *  Created on: Feb 11, 2024
 *      Author: erhangok
 *
 *  USAGE:
 *  Write your state functions and default state
 *  and run "void Sm_run(void)" inside your while loop
 */

#include "StateMachine.h"
#include "uart.h"

StateType SmState = STATE_A;

void Sm_StateA(void)
{
	SmState = STATE_B;
	println("Switching to State A");
}

void Sm_StateB(void)
{
	SmState = STATE_C;
	println("Switching to State B");
}

void Sm_StateC(void)
{
	SmState = STATE_A;
	println("Switching to State C");
}

//Restart the State Machine or do what you want in this state
void Sm_DefaultState(void)
{
	SmState = STATE_A;
	println("Switching to State A");
}

void Sm_run(void)
{
	if(SmState < NUM_STATES)
	{
		(*StateMachine[SmState].function)();
	}
	else
	{
		println("Invalid state! Switching to default state...");
		Sm_DefaultState();
	}
}
