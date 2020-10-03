/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *  Last updated: Oct 3, 2020
 *      Author: keith, Matt Williams
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

//TODO fill in content
#include "../includes/scheduler_RR.h"

//Scheduler_RR::Scheduler_RR(std::queue<PCB> &queue,int time_slice =UNINITIALIZED){}

bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p){
	return Scheduler::time_to_switch_processes(tick_count, p);
}

void Scheduler_RR::sort(){}
