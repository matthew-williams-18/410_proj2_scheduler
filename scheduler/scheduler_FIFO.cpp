/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *  Last updated: Oct 3, 2020
 *      Author: keith, Matt Williams
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

//TODO fill in content
#include "../includes/scheduler_FIFO.h"


//Scheduler_FIFO::Scheduler_FIFO(std::queue<PCB> &queue){}

//call base class function
bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
	return Scheduler::time_to_switch_processes(tick_count, p);
}

void Scheduler_FIFO::sort(){
	//this is just here for fun. hehe
}
