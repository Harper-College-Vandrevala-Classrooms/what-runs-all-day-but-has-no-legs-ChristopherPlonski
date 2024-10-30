#include <iostream>
#include <cassert>
#include <vector>

#include "Timer.hpp"

using namespace std;

void wait_seconds(int seconds) {
	int startTime = time(nullptr);

	while (true) {
		int currentTime = time(nullptr);
		if (currentTime - startTime >= seconds) {
			return;
		}
	}
}

int main() {
	Timer timer = Timer();

	assert(timer.elapsed_time() == 0);

	timer.start();
	assert(timer.elapsed_time() == 0);
	wait_seconds(1);
	assert(timer.elapsed_time() == 1);

	wait_seconds(1);
	assert(timer.elapsed_time() == 2);

	timer.stop();
	assert(timer.elapsed_time() == 2);

	timer.stop(); // Stop timer again after already stopping
	assert(timer.elapsed_time() == 2);

	timer.start();
	assert(timer.elapsed_time() == 0);
	wait_seconds(2);
	assert(timer.elapsed_time() == 2);
	timer.start(); // Start timer without previously stopping should just reset it back to 0
	assert(timer.elapsed_time() == 0);
	wait_seconds(1);
	assert(timer.elapsed_time() == 1);
	timer.stop();
	assert(timer.elapsed_time() == 1);
}