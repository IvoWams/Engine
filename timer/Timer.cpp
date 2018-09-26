#include <timer/Timer.h>

Timer::Timer(float _duration){
	cooldown = _duration;
	duration = _duration;
	enabled  = true;
}

Timer::Timer(Timer* original){
	cooldown  = original->getCooldown();
	duration = original->getDuration();
	enabled  = original->isEnabled();
}

Timer::~Timer(){}
