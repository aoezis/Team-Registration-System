#include "Team.h"
#include <algorithm>
#include <iostream>
using namespace std;
Team::Team() {
	name = "";
	color = "";
	year = 0;
	head = NULL;
}
Team::Team(const string name, const string color, const int year) {
	this->name = name;
	this->color = color;
	this->year = year;
	head = NULL;
}
Team::Team(const Team &toCopy) {
	name = toCopy.name;
	color = toCopy.color;
	year = toCopy.year;
	playerCount = toCopy.playerCount;
	if (toCopy.head == NULL) {
		head = NULL;
	}
	else {
		head = new TeamNode;
		head->p = toCopy.head->p;
		TeamNode* ptr = head;
		for (TeamNode* cur = toCopy.head->next; cur != NULL; cur = cur->next) {
			ptr->next = new TeamNode;
			ptr = ptr->next;
			ptr->p = cur->p;
		}
		ptr->next = NULL;
	}
}
Team::~Team() {
	if (head != NULL) {
		TeamNode* cur = head;
		TeamNode* next;
		while (cur != NULL) {
			next = cur->next;
			delete cur;
			cur = next;
		}
	}
}
Team::TeamNode* Team::findPlayer(string pName) const {
	string toFind = pName;
	string curP = "";
	transform(toFind.begin(), toFind.end(), toFind.begin(), ::tolower);
	for (TeamNode* cur = head; cur != NULL; cur = cur->next) {
		curP = cur->p.getName();
		transform(curP.begin(), curP.end(), curP.begin(), ::tolower);
		if (curP == toFind) {
			return cur;
		}
	}
	return NULL;
}
bool Team::addPlayer(const string pName, const string pPosition) {
	if (findPlayer(pName) != NULL) {
		return false;
	}
	if (head == NULL) {
		head = new TeamNode;
		head->p.setName(pName);
		head->p.setPosition(pPosition);
		head->next = NULL;
		return true;
	}
	TeamNode* cur = head;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new TeamNode;
	cur = cur->next;
	cur->p.setName(pName);
	cur->p.setPosition(pPosition);
	cur->next = NULL;
	return true;
}
bool Team::removePlayer(const string pName) {
	TeamNode* toRemove = findPlayer(pName);
	if (toRemove == NULL)
		return false;
	TeamNode* prev = head;
	if (prev->next == NULL) {
		delete prev;
		head = NULL;
		playerCount--;
		return true;
	}
	for (TeamNode* cur = head->next; cur != NULL; cur = cur->next, prev = prev->next) {
		if (cur == toRemove) {
			prev->next = cur->next;
			delete cur;
			playerCount--;
			return true;
		}

	}
	return false;
}
void Team::operator=(const Team& st) {
	color = st.color;
	name = st.name;
	year = st.year;
	playerCount = st.playerCount;
	if (st.head == NULL) {
		head = NULL;
	}
	else {
		head = new TeamNode;
		head->p = st.head->p;
		TeamNode* toAdd = head;
		for (TeamNode* cur = st.head->next; cur != NULL; cur = cur->next) {
			toAdd->next = new TeamNode;
			toAdd = toAdd->next;
			toAdd->p = cur->p;
		}
		toAdd->next = NULL;
	}
}
void Team::display() {
	if (head == NULL) {
		cout << "--EMPTY--" << endl;
		return;
	}

	for (TeamNode* cur = head; cur != NULL; cur = cur->next)
		cout << cur->p.getName() << " " << cur->p.getPosition() << endl;
}
bool Team::displayPlayer(const string pName) const {
	TeamNode* pl = findPlayer(pName);
	if (pl!=NULL) {
		cout << pl->p.getPosition() << " " << name << " " << color << " " << year << endl;
		return true;
	}
	else {
		return false;
	}

}
Player& Team::operator[](const int index) {
	TeamNode* cur = head;
	int i = 0;
	while (cur != NULL && i < index) {
		if (i == index) {
			return cur->p;
		}
		cur = cur->next;
		i++;
	}
	cout << "Not in range" << endl;
}
string Team::getName() {
	return name;
}
string Team::getColor() {
	return color;
}
int Team::getYear() {
	return year;
}
void Team::setName(const string name) {
	this->name = name;
}
void Team::setColor(const string color) {
	this->color = color;
}
void Team::setYear(const int year) {
	this->year = year;
}