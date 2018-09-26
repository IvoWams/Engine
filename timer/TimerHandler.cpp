#include <timer/TimerHandler.h>

TimerHandler::TimerHandler(){
	timers = new vector<Timer*>;
	listeners = new vector<TimerListener*>;
}

TimerHandler::~TimerHandler(){
	delete(timers);
	delete(listeners);
}

void	TimerHandler::addListener(TimerListener* _timerlistener){
	listeners->push_back(_timerlistener);
}

void	TimerHandler::delListener(TimerListener* _timerlistener){
	for(int i=0;i<listeners->size();++i)
		if((*listeners)[i]==_timerlistener)
			listeners->erase(listeners->begin()+i);
}

bool	TimerHandler::hasListener(TimerListener* listener){
	for(int i=0;i<listeners->size();++i)
		if((*listeners)[i]==listener)
			return true;
	return false;
}

void	TimerHandler::addTimer(Timer* _timer){
	timers->push_back(_timer);
}

void	TimerHandler::delTimer(Timer* timer){
	for(int i=0;i<timers->size();++i)
		if((*timers)[i]==timer)
			timers->erase(timers->begin()+i);
}

void			TimerHandler::tick(double t){
	for(int i=0;i<timers->size();++i)
		if((*timers)[i]->isEnabled()){
			(*timers)[i]->tick(t);
//			while((*timers)[i]->isActive()){
				// we have a trigger here!
				if((*timers)[i]->isActive()){
					for(int j=0;j<listeners->size();++j)
						(*listeners)[j]->onTime((*timers)[i]);
					(*timers)[i]->reset();
				}
//			}
		}
}
