#ifndef CONTROLLER_H
#define CONTROLLER_H
class Creature;

class Controller
{
public:

	void AssignPlayer(Creature * pCreature) { mpCreature = pCreature; }
	virtual void GetMove() = 0;

private:
	Creature * mpCreature;

};

#endif //! CONTROLLER_H
