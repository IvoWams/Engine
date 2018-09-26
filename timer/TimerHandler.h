// TimerHandler
// Handles timers :)

using namespace std;

#ifndef TIMERHANDLER_H
#define TIMERHANDLER_H

#include <vector>
#include <timer/TimerListener.h>
#include <timer/Timer.h>

// Could be static.. meh..

class TimerHandler {
	private:
		vector<Timer*>*			timers;
		vector<TimerListener*>*	listeners;

	public:
		TimerHandler();
		~TimerHandler();

		void			addListener(TimerListener*);
		void			delListener(TimerListener*);
		bool			hasListener(TimerListener*);

		void			addTimer(Timer*);
		void			delTimer(Timer*);

		// interface for mainengine
		void			tick(double);
};

#endif
