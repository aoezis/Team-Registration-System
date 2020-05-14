#ifndef __TEAM_H
#define __TEAM_H 
#include <string>
#include "Player.h"
using namespace std;
class Team {
public:
	Team();
	Team(const string name, const string color, const int year);
	~Team();
	Team(const Team &toCopy);
	void operator=(const Team&);
	string getName();
	string getColor();
	int getYear();
	void display();
	bool addPlayer(const string pName, const string pPosition);
	bool removePlayer(const string pName);
	void setName(const string name);
	void setColor(const string color);
	void setYear(const int year);
	bool displayPlayer(const string pName) const;
	Player& operator[](const int index);
	
private:
	struct TeamNode {
		Player p;
		TeamNode* next;
	};
	TeamNode* head;	
	string name;
	string color;
	int year;
	TeamNode* findPlayer(string pName) const;
	int playerCount;
};
#endif