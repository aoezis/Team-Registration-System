#include "CompleteReg.h"
#include <iostream>
#include <algorithm>
using namespace std;
CompleteReg::CompleteReg() {
	teamCount = 0;
	head = NULL;
}
CompleteReg::~CompleteReg() {
	if (head != NULL) {
		Node* cur = head;
		Node* next;
		while (cur != NULL) {
			next = cur->next;
			delete cur;
			cur = next;
		}
	}
}
Team& CompleteReg::operator[](const int index) {
	Node* cur = head;
	int i = 0;
	while (cur != NULL && i <= index) {
		if (i == index) {
			return cur->t;
		}
		cur = cur->next;
		i++;
	}
	cout << "Not in range" << endl;
}
CompleteReg::CompleteReg(const CompleteReg &systemToCopy) {
	teamCount = systemToCopy.teamCount;
	if (systemToCopy.head == NULL) {
		head = NULL;
	}
	else {
		head = new Node;
		head->t = systemToCopy.head->t;
		Node* ptr = head;
		for (Node* cur = systemToCopy.head->next; cur != NULL; cur = cur -> next) {
			ptr->next = new Node;
			ptr = ptr->next;
			ptr->t = cur->t;
		}
		ptr->next = NULL;
	}

}
CompleteReg& CompleteReg::operator=(const CompleteReg &right) {
	
	teamCount =right.teamCount;
	if (right.head == NULL) {
		head = NULL;
	}
	else {
		head = new Node;
		head->t = right.head->t;
		Node* ptr = head;
		for (Node* cur = right.head->next; cur != NULL; cur = cur -> next) {
			ptr->next = new Node;
			ptr = ptr->next;
			ptr->t = cur->t;
		}
		ptr->next = NULL;
	}

	return *this;
}
void CompleteReg::addTeam(const string tName, const string tColor, const int tyear) {
	if (findTeam(tName) != NULL) {
		cout << "Cannot add " << tName << ". It aleady exists." << endl;
		return;
	}
	if (tyear < 1800 || tyear >2020) {
		cout << "Cannot add " << tName << " Invalýd year: " << tyear << endl;
	}
	if (head == NULL) {
		head = new Node;
		head->t.setName(tName);
		head->t.setColor(tColor);
		head->t.setYear(tyear);
		head->next = NULL;
		teamCount++;
		cout << "Team " << tName << " has been added"<<endl;
		return;
	}
	Node* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = new Node;
	cur = cur->next;
	cur->t.setName(tName);
	cur->t.setColor(tColor);
	cur->t.setYear(tyear);
	cur->next = NULL;
	teamCount++;
	cout << "Team " << tName << " has been added" << endl;
}
void CompleteReg::removeTeam(string teamName) {
	if (findTeam(teamName) == NULL) {
		cout << "Cannot find " << teamName << endl;
		return;
	}
	Node* toRemove = findTeam(teamName);
	Node* prev = head;
	if (prev->next == NULL) {
		delete prev;
		head = NULL;
		teamCount--;
		cout << "Team " << teamName << " has been removed." << endl;
		return;
	}
	for (Node* cur = head->next; cur != NULL; cur = cur->next, prev = prev->next) {
		if (cur == toRemove) {
			prev->next = cur->next;
			delete cur;
			teamCount--;
			cout << "Team " << teamName<< " has been removed."<<endl;
			return;
		}

	}
}
void CompleteReg::displayAllTeams() const {
	if (head == NULL) {
		cout << "--EMPTY--" << endl;
		return;
	}

	for (Node* cur = head; cur != NULL; cur = cur->next)
		cout << cur->t.getName() << " " << cur->t.getColor() << " " << cur->t.getYear() << endl;
}
CompleteReg::Node* CompleteReg::findTeam(string teamName) const {
	string toFind = teamName;
	string curTeam = "";
	transform(toFind.begin(), toFind.end(), toFind.begin(), ::tolower);
	for (Node* cur = head; cur != NULL; cur = cur->next) {
		curTeam = cur->t.getName();
		transform(curTeam.begin(), curTeam.end(), curTeam.begin(), ::tolower);
		if (curTeam == toFind) {
			return cur;
		}
	}
	return NULL;
}
void CompleteReg::addPlayer(const string tName, const string pName, const string pPosition) {
	Node* target = findTeam(tName);
	if (target == NULL) {
		cout << "Team " << tName << " does not exist" << endl;
		return;
	}
	if (target->t.addPlayer(pName, pPosition))
		cout << "Player " << pName << " has been added to the team " << tName << endl;
	else {
		cout << "Player " << pName << " already exists in team " << tName << endl;
	}
}
void CompleteReg::removePlayer(const string teamName, const string playerName) {
	Node* target = findTeam(teamName);
	if (target == NULL) {
		cout << "Team " << teamName << " does not exist" << endl;
		return;
	}
	if (target->t.removePlayer(playerName))
		cout << "Player " << playerName << " has been deleted from the team " << teamName << endl;
	else {
		cout << "Player " << playerName << " does not exist in team " << teamName << endl;
	}
}
void CompleteReg::displayTeam(const string teamName) const {
	Node* target = findTeam(teamName);
	if (target == NULL) {
		cout << "Team " << teamName << " does not exist" << endl;
	}
	else {
		cout << target->t.getName() << " " << target->t.getColor() << " " << target->t.getYear() << endl;
		target->t.display();
	}
}
void CompleteReg::displayPlayer(const  string playerName) const {
	cout << playerName << endl;
	bool exist = false;
	Node* cur = head;
	while (cur != NULL) {
		if (cur->t.displayPlayer(playerName)) exist = true;
		cur = cur->next;
	}
	if (!exist) {
		cout << "--EMPTY--" << endl;
	}
}