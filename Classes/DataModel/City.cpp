#include "City.h"
#include "Constants.h"
#include "GeneralManager.h"
#include <cassert>

City::City(){
}

City::~City() {
}

Coordinate City::get_coordinate() {
	return this->immutable_attributes.coordinate;
}

City City::set_coordinate(const Coordinate& coordinate) {
	this->immutable_attributes.coordinate = coordinate;
	return *this;
}

City City::set_coordinate(double x, double y) {
	this->immutable_attributes.coordinate.first = x;
	this->immutable_attributes.coordinate.second = y;
	return *this;
}

string City::get_name() {
	return this->immutable_attributes.name;
}

City City::set_name(const string& name) {
	this->immutable_attributes.name = name;
	return *this;
}

double City::get_develop_factor() {
	return this->immutable_attributes.develop_factor;
}

City City::set_develop_factor(double factor) {
	this->immutable_attributes.develop_factor = factor;
	return *this;
}

int City::get_debut_country() {
	return this->immutable_attributes.debut_country;
}

City City::set_debut_country(int country) {
	this->immutable_attributes.debut_country = country;
	return *this;
}

int City::get_gold() {
	return this->gold;
}

City City::set_gold(int gold) {
	this->gold = gold;
	return *this;
}

int City::get_rice() {
	return this->rice;
}

City City::set_rice(int rice) {
	this->rice = rice;
	return *this;
}
	
int City::get_soil() {
	return this->soil;
}

City City::set_soil(int soil) {
	this->soil = soil;
	return *this;
}

int City::get_business() {
	return this->business;
}

City City::set_business(int business) {
	this->business = business;
	return *this;
}

int City::get_people() {
	return this->people;
}

City City::set_people(int people) {
	this->people = people;
	return *this;
}

int City::get_disaster_proof() {
	return this->disaster_proof;
}

City City::set_disaster_proof(int disaster_proof) {
	this->disaster_proof = disaster_proof;
	return *this;
}

int City::get_current_country() {
	return this->current_country;
}

City City::set_current_country(int current_country) {
	this->current_country = current_country;
	return *this;
}

int City::get_current_mayor() {
	return this->current_mayor;
}

City City::set_current_mayor(int current_mayor) {
	this->current_mayor = current_mayor;
	return *this;
}

CommonSet<int> City::get_generals() {
	return this->generals;
}

City City::set_generals(const CommonSet<int>& generals) {
	this->generals = generals;
	return *this;
}

int City::get_soldiers() {
	int result = this->unassigned_soldiers;
	GeneralManager manager = GeneralManager::getInstance();
	for(auto general : generals)
		result += manager.get(general).get_soldiers();
	return result;
}

int City::get_unassigned_soldiers() {
	return this->unassigned_soldiers;
}

City City::set_unassigned_soldiers(int unassigned_soldiers) {
	this->unassigned_soldiers = unassigned_soldiers;
	return *this;
}

int City::add_gold(int delta) {
	if(this->gold + delta < 0) {
		this->gold = 0;
		return -this->gold;
	}
	if(this->gold + delta > City_Gold_Bound) {
		int temp = this->gold;
		this->gold = City_Gold_Bound;
		return City_Gold_Bound - temp;
	}
	this->gold += delta;
	return delta;
}

int City::add_rice(int delta) {
	if(this->rice + delta < 0) {
		this->rice = 0;
		return -this->rice;
	}
	if(this->rice + delta > City_Rice_Bound) {
		int temp = this->rice;
		this->rice = City_Rice_Bound;
		return City_Rice_Bound - temp;
	}
	this->rice += delta;
	return delta;
}

int City::add_soil(int delta) {
	if(this->soil + delta < 0) {
		this->soil = 0;
		return -this->soil;
	}
	if(this->soil + delta > City_Soil_Bound) {
		int temp = this->soil;
		this->soil = City_Soil_Bound;
		return City_Soil_Bound - temp;
	}
	this->soil += delta;
	return delta;
}

int City::add_business(int delta) {
	if(this->business + delta < 0) {
		this->business = 0;
		return -this->business;
	}
	if(this->business + delta > City_Business_Bound) {
		int temp = this->business;
		this->business = City_Business_Bound;
		return City_Business_Bound - temp;
	}
	this->business += delta;
	return delta;
}

int City::add_people(int delta) {
	if(this->people + delta < 0) {
		this->people = 0;
		return -this->people;
	}
	if(this->people + delta > City_People_Bound) {
		int temp = this->people;
		this->people = City_People_Bound;
		return City_People_Bound - temp;
	}
	this->people += delta;
	return delta;
}

int City::add_disaster_proof(int delta) {
	if(this->disaster_proof+ delta < 0) {
		this->disaster_proof = 0;
		return -this->disaster_proof;
	}
	if(this->disaster_proof + delta > City_Disaster_Proof_Bound) {
		int temp = this->disaster_proof;
		this->disaster_proof = City_Disaster_Proof_Bound;
		return City_Disaster_Proof_Bound - temp;
	}
	this->disaster_proof += delta;
	return delta;
}
int City::add_general(int general) {
	assert(this->generals.size() + 1 <= City_Generals_Num);
	assert(!(this->generals.contains(general)));
	this->generals.add(general);
	return this->generals.size();
}

int City::add_generals(const CommonSet<int>& generals) {
	assert(this->generals.size() + generals.size() <= City_Generals_Num);
	for(auto general : generals) {
		assert(!(this->generals.contains(general)));
		this->generals.add(general);
	}
	return this->generals.size();
}

int City::remove_general(int general) {
	assert(this->generals.contains(general));
	this->generals.remove(general);
	return this->generals.size();
}

int City::remove_generals(const CommonSet<int>& generals) {
	for(auto general : generals) {
		this->remove_general(general);
	}
	return this->generals.size();
}

int City::add_unassigned_soldiers(int delta) {
	if(this->unassigned_soldiers + delta < 0) {
		this->unassigned_soldiers = 0;
		return -this->unassigned_soldiers;
	}
	if(this->unassigned_soldiers + delta > City_Unassigned_Soldiers_Bound) {
		int temp = this->unassigned_soldiers;
		this->unassigned_soldiers = City_Unassigned_Soldiers_Bound;
		return City_Unassigned_Soldiers_Bound - temp;
	}
	this->unassigned_soldiers += delta;
	return delta;
}