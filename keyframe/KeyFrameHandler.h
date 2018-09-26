using namespace std;

#ifndef KEYFRAMEHANDLER_H
#define KEYFRAMEHANDLER_H

#include <vector>
#include <keyframe/KeyFrameListener.h>
#include <keyframe/KeyFrameBar.h>
#include <keyframe/KeyFrameProperty.h>
#include <keyframe/KeyFrameVectorProperty.h>

#include <keyframe/KeyFramePositionProperty.h>
#include <keyframe/KeyFrameRotationProperty.h>
#include <keyframe/KeyFrameScaleProperty.h>
#include <keyframe/KeyFrameColorProperty.h>
#include <keyframe/KeyFrameAlphaProperty.h>

class KeyFrameHandler {
	private:
		vector<KeyFrameListener*>*	listeners;
		vector<KeyFrameBar*>*		keyframebars;
		double						last_time;

	public:
		KeyFrameHandler();
		~KeyFrameHandler();
		
		vector<KeyFrameBar*>*		getKeyFrameBars(){ return keyframebars; }

		void	addListener(KeyFrameListener*);
		void	delListener(KeyFrameListener*);
		bool	hasListener(KeyFrameListener*);

		bool	hasKeyFrames(RootObject*);
		void	delKeyFrameBarWith(RootObject*);
		
		void	setProperty(RootObject*, double, KeyFrameProperty*);
		
		
		// Clean handler of unused bars
		// void	clean();

// Easy use methods:
		void	setPosition(RootObject*, double, double, double, double);
		void	setRotation(RootObject*, double, double, double, double);
		void	setScale(RootObject*, double, double, double, double);
		void	setColor(RootObject*, double, double, double, double);
		void	setAlpha(RootObject*, double, double);

		void	tick(double);
};

#endif
