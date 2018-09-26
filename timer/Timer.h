// Timer
// Data for a time related trigger, handled by timerhandler

// todo
// replace with mmtimers

using namespace std;

#ifndef TIMER_H
#define TIMER_H

class Timer {
	private:
	protected:
		double	duration;
		double	cooldown;	
		bool	enabled;

	public:
		Timer(float);
		Timer(Timer*);
		~Timer();

		bool	isActive(){ return cooldown <= 0; }
		bool	isEnabled(){ return enabled; }

		double	getDuration(){ return duration; }
		double	getCooldown(){ return cooldown; }

		void	setDuration(double _duration){ duration = _duration; }
		void	setCooldown(double _cooldown){ cooldown = _cooldown; }
		
		void	tick(double _msec){ cooldown -= _msec; }
		void	reset(){ if(cooldown<=0)cooldown += duration; }
};

#endif
