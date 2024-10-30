#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>

class Timer {

public:
	Timer();
	void start();
	void stop();
	int elapsed_time();

private:
	time_t startTime;
	time_t endTime;
};

#endif // !TIMER_HPP
