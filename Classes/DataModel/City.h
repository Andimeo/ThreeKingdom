#pragma once
#include <string>
#include "../Utility/CommonSet.h"

using namespace std;

typedef pair<double, double> Coordinate;

struct ImmutableCityAttributes {
	Coordinate coordinate;
	string name;
	double develop_factor;
	int debut_country;
};

class City {
public:
	City();
	~City();

	Coordinate get_coordinate();
	City set_coordinate(const Coordinate& coordinate);
	City set_coordinate(double x, double y);

	string get_name();
	City set_name(const string& name);

	double get_develop_factor();
	City set_develop_factor(double factor);

	int get_debut_country();
	City set_debut_country(int country_id);

	int get_gold();
	City set_gold(int gold);

	int get_rice();
	City set_rice(int rice);
	
	int get_soil();
	City set_soil(int soil);
	
	int get_business();
	City set_business(int business);
	
	int get_people();
	City set_people(int people);
	
	int get_disaster_proof();
	City set_disaster_proof(int disaster_proof);
	
	int get_current_country();
	City set_current_country(int current_country);
	
	int get_current_mayor();
	City set_current_mayor(int current_mayor);

	CommonSet<int> get_generals();
	City set_generals(const CommonSet<int>& generals);

	int get_soldiers();

	int get_unassigned_soldiers();
	City set_unassigned_soldiers(int unassigned_soldiers);

	int add_gold(int delta);
	int add_rice(int delta);
	int add_soil(int delta);
	int add_business(int delta);
	int add_people(int delta);
	int add_disaster_proof(int delta);
	int add_general(int general);
	int add_generals(const CommonSet<int>& generals);
	int remove_general(int general);
	int remove_generals(const CommonSet<int>& generals);

	int add_unassigned_soldiers(int delta);
private:
	ImmutableCityAttributes immutable_attributes;
	int gold;
	int rice;
	int soil; //对应土地值，与10月份发rice相关
	int business; //对应产业值，实际为商业值，与4月份发gold相关
	int people;
	int disaster_proof;
	CommonSet<int> generals;
	
	int current_country;
	int current_mayor;

	int unassigned_soldiers;
};