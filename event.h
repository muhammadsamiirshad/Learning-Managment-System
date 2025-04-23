#pragma once
#ifndef EVENT_H
#define EVENT_H
using namespace std;
#include <string>
class club; 

class event {
	int eventid;
	string title;
	string description;
	string date;
	string venue;
	friend class club;
	club* c;
public:
	static int numevents;
	void organizeevent(event & e);
	void displayallevents();
	void displayspecificclubevents();
};

#endif
