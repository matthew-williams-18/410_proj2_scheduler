/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *  last updated: Oct 5, 2020
 *      Author: keith, Matt Williams
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include "../includes/scheduler_SRTF.h"


bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	this->sort();
	return Scheduler::time_to_switch_processes(tick_count, p);
}

void Scheduler_SRTF::sort(){
	//dump queue into a vector
	std::vector<PCB> sortVec;
	int ready_q_size = ready_q->size();
	for(int i = 0; i< ready_q_size; i++){
		sortVec.push_back(ready_q->front());
		ready_q->pop();
	}

	//sort vector
	std::sort(sortVec.begin(), sortVec.end(), [](PCB &left, PCB &right){
		return left.remaining_cpu_time < right.remaining_cpu_time;
	});

	//dump sorted vector into queue
	for(int i = 0; i < ready_q_size; i++){
		ready_q->push(sortVec.at(i));
	}


}
