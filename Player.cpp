#include "Player.h"
Player::Player() {
	name = "";
	position = "";
}
Player::Player(const string name, const string position){
	Player::name = name;
	Player::position = position;
}
string Player::getName() const{
	return name;
}
string Player::getPosition() const{
	return position;
}
void Player::setName(const string name) {
	this->name = name;
}
void Player::setPosition(const string position) {
	this->position = position;
}
