// Generic Trigger Listening Template

// MainEngine is the MainHandler :)

using namespace std;

#ifndef MAINLISTENER_H
#define MAINLISTENER_H

class MainListener{
	private:
	public:        
		MainListener();
		virtual	~MainListener();

		virtual void	onStart();
		virtual void	onFrame();
		virtual void	onStop();
};

#endif
