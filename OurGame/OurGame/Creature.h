#ifndef CREATURE_H
#define CREATURE_H
//#include <string>
#include "Controller.h"
#include "Tile.h"

class Creature
{
public:

	Creature(Controller *pController) {
		mp_Controller = pController;
		mp_Controller->AssignPlayer(this);
	}

	/*
	void SetHealth(int value) { m_Health = value; }
	void SetName(std::string value) { m_Name = value; }
	void SetStrength(int value) { m_Strength = value; }
	void SetLuck(int value) { m_Luck = value; }
	void SetAgility(int value) { m_Agility = value; }
	void SetPerception(int value) { m_Perception = value; }
	void SetSize(int value) { m_Size = value; }

	// getters
	bool IsDead() { return (m_Health <= 0) ? true : false; }

	int GetHealth() { return m_Health; }
	std::string GetName() { return m_Name; }
	int GetStrength() { return m_Strength; }
	int GetLuck() { return m_Luck; }
	int GetAgility() { return m_Agility; }
	int GetPerception() { return m_Perception; }
	int GetSize() { return m_Size; }
	*/

	void handleEvent(SDL_Event& e);

	void move(Tile *tiles[]) {
		mp_Controller->GetMove();
	}

	//Centers the camera over the dot
	void setCamera(SDL_Rect& camera);

	//Shows the dot on the screen
	void render(SDL_Rect& camera);




private:
	Controller * mp_Controller;
	

	SDL_Rect m_CollisionBox;
	// Velocity
	int m_VelX, m_VelY;

	/*
	std::string m_Name;
	int m_Health;

	int m_Strength;
	int m_Luck;
	int m_Agility;
	int m_Perception;
	int m_Size;

	int m_Level; // creatures level
	*/

};


#endif // !CREATURE_H


