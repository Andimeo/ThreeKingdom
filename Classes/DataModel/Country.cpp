#include "Country.h"
#include <cassert>

Country::Country(){
}

Country::~Country(){
}

int Country::get_id() {
	return this->id;
}

Country Country::set_id(int id) {
	this->id = id;
	return *this;
}

int Country::get_emperor() {
	return this->emperor;
}

Country Country::set_emperor(int emperor) {
	this->emperor = emperor;
	return *this;
}

string Country::get_name() {
	return this->name;
}

Country Country::set_name(const string& name) {
	this->name = name;
	return *this;
}

CommonSet<int> Country::get_citys() {
	return this->citys;
}

Country Country::set_citys(const CommonSet<int>& citys) {
	this->citys = citys;
	return *this;
}

int Country::add_city(int city) {
	assert(!(this->citys.contains(city)));
	this->citys.add(city);
	return this->citys.size();
}

int Country::add_citys(const CommonSet<int>& citys) {
	for(auto iter = citys.begin(); iter != citys.end(); iter++ ) {
		assert(!(this->citys.add(*iter)));
		this->citys.add(*iter);
	}
	return this->citys.size();
}

int Country::remove_city(int city) {
	assert(this->citys.contains(city));
	this->citys.remove(city);
	return this->citys.size();
}

int Country::remove_citys(const CommonSet<int>& citys) {
	for(auto iter = citys.begin(); iter != citys.end(); iter++ ) {
		assert(this->citys.contains(*iter));
		this->citys.add(*iter);
	}
	return this->citys.size();
}