#include <iostream>

#include "Timer.hpp"

Timer::Timer()
{
	this->startTime = 0;
	this->endTime = 0;
}

void Timer::start()
{
	//std::cout << "Started timer. \n";
	startTime = time(nullptr);
	endTime = 0;
}

void Timer::stop()
{
	//std::cout << "Stopped timer. \n";
	endTime = time(nullptr);
}

int Timer::elapsed_time()
{
	if (startTime == 0) {
		//std::cout << "Returning 0 \n";
		return 0;
	}

	if (endTime == 0) {
		//std::cout << "Returning startTime - current \n";
		return time(nullptr) - startTime;
	}

	//std::cout << "Returning endTime - startTime \n";
	return endTime - startTime;
}
