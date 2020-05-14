#ifndef __PLAYER_H
#define __PLAYER_H
#include <string>
using namespace std;

class Player {
public:
	Player();
	Player(const string name, const string position);
	string getPosition() const;
	void setPosition(const string position);
	string getName() const;
	void setName(const string name);
private:
	string name;
	string position;
};
#endif