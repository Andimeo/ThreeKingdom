#include "General.h"
#include "Constants.h"
#include <cassert>

General::General(){
}

General::~General(){
}

int General::get_id() {
	return this->immutable_attributes.id;
}

General General::set_id(int id) {
	this->immutable_attributes.id = id;
	return *this;
}

string General::get_name() {
	return this->immutable_attributes.name;
}

General General::set_name(const string& name) {
	this->immutable_attributes.name = name;
	return *this;
}

bool General::get_sex() {
	return this->immutable_attributes.sex;
}

General General::set_sex(bool sex) {
	this->immutable_attributes.sex = sex;
	return *this;
}

GameTime General::get_debut_time() {
	return this->immutable_attributes.debut_time;
}

General General::set_debut_time(const GameTime& debut_time) {
	this->immutable_attributes.debut_time = debut_time;
	return *this;
}

General General::set_debut_time(int year, int month, int day, int hour) {
	this->immutable_attributes.debut_time.set_time(year, month, day, hour);
	return *this;
}

int General::get_debut_city() {
	return this->immutable_attributes.debut_city;
}

General General::set_debut_city(int city_id) {
	this->immutable_attributes.debut_city = city_id;
	return *this;
}

int General::get_vitality() {
	return this->vitality;
}

General General::set_vitality(int vitality) {
	this->vitality = vitality;
	return *this;
}

int General::get_force() {
	return this->force;
}

General General::set_force(int force) {
	this->force = force;
	return *this;
}

int General::get_intelligence() {
	return this->intelligence;
}

General General::set_intelligence(int intelligence){
	this->intelligence = intelligence;
	return *this;
}

int General::get_experience() {
	return this->experience;
}

General General::set_experience(int experience) {
	this->experience = experience;
	return *this;
}

int General::get_level() {
	for(int i = 0 ; i < Level_Num; i++ )
		if(this->experience < Level_Bound[i])
			return i + 1;
	return Level_Num;
}

int General::get_current_city() {
	return this->current_city;
}

General General::set_current_city(int city_id) {
	this->current_city = city_id;
	return *this;
}

int General::get_current_country() {
	return this->current_country;
}

General General::set_current_country(int country_id) {
	this->current_country = country_id;
	return *this;
}

int General::get_soldiers() {
	return this->soldiers;
}

General General::set_soldiers(int soldiers) {
	this->soldiers = soldiers;
	return *this;
}

int General::add_vitality(int delta) {
	if(this->vitality + delta < 0) {
		this->vitality = 0;
		return -this->vitality;
	}
	if(this->vitality + delta > this->vitality_bound) {
		int temp = this->vitality;
		this->vitality = this->vitality_bound;
		return this->vitality_bound - temp;
	}	
	this->vitality += delta;
	return delta;
}

int General::add_force(int delta) {
	assert(delta >= 0);
	this->force += delta;
	return delta;
}

int General::add_intelligence(int delta) {
	assert(delta >= 0);
	this->intelligence += delta;
	return delta;
}

int General::add_morality(int delta) {
	assert(delta >= 0);
	this->morality += delta;
	return delta;
}

int General::add_experience(int delta) {
	assert(delta >= 0);
	this->experience += delta;
	return delta;
}

int General::add_soldiers(int delta) {
	if(this->soldiers + delta < 0) {
		this->soldiers = 0;
		return -this->soldiers;
	}
	if(this->soldiers + delta > General_Soldier_Limit) {
		int temp = this->soldiers;
		this->soldiers = General_Soldier_Limit;
		return General_Soldier_Limit - temp;
	}
	this->soldiers += delta;
	return delta;
}

int General::add_vitality_bound(int delta) {
	assert(delta >= 0);
	this->vitality_bound += delta;
	return delta;
}