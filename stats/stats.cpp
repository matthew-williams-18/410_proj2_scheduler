/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *  Last edited: Sep 30, 2020
 *      Author: keith, Matt Williams
 */

//TODO fill in content

#include <iostream>

#include <vector>
#include "../includes/stats.h"
#include "../includes/constants.h"


Stats::Stats(std::vector<PCB> &finished_vector){
	vec = &finished_vector;
	calcStats();
}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo(){
	calcStats();

	std::vector<PCB> tmp = *vec;
	for(auto pcb : tmp){
		printf("Process %d Required CPU time:%d  arrived:%d started:%d finished:%d", pcb.process_number, pcb.required_cpu_time, pcb.arrival_time, pcb.start_time, pcb.finish_time);      //Process 1 Required CPU time:2  arrived:0 started:0 finished:2
	}
}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time(){
	return av_response_time;
}


//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time(){
	return av_turnaround_time;
}


//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time(){
	return av_wait_time;
}



void Stats::calcStats(){
	int sumOfResponseTimes = 0, sumOfTurnaroundTimes = 0, sumOfWaitTimes = 0;

	std::vector<PCB> tmp = *vec;
	for(auto pcb : tmp){
		sumOfResponseTimes += (pcb.start_time - pcb.arrival_time);
		sumOfTurnaroundTimes += (pcb.finish_time - pcb.arrival_time);
		sumOfWaitTimes += (pcb.finish_time - pcb.arrival_time - pcb.required_cpu_time);
	}

	float vecSize = (float)vec->size();

	av_response_time = sumOfResponseTimes / vecSize;
	av_turnaround_time = sumOfTurnaroundTimes / vecSize;
	av_wait_time = sumOfWaitTimes / vecSize;
}
