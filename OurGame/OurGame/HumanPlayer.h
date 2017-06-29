#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Controller.h"

class HumanPlayer : public Controller
{
public:
	void GetMove(); // HandleEvents go in here.
private:

};

#endif // !HUMANPLAYER_H