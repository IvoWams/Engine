// Generic Trigger Listening Template

using namespace std;

#ifndef TIMERLISTENER_H
#define TIMERLISTENER_H

#include <timer/Timer.h>

class TimerListener {
	private:
	public:        
		TimerListener();
		virtual	~TimerListener();

		// Event methods implementedable by the listener
		virtual void	onTime(Timer*);
};

#endif
