#pragma once
#include <string>
#include "BaseModel.h"

using namespace std;

struct ImmutableGeneralAttributes {
	int id;
	string name;
	bool sex;
	GameTime debut_time;
	int debut_city;
};

class General {
public:
	General();
	~General();
	
	int get_id();
	General set_id(int id);

	string get_name();
	General set_name(const string& name);

	bool get_sex();
	General set_sex(bool sex);

	GameTime get_debut_time();
	General set_debut_time(const GameTime& time);
	General set_debut_time(int year, int month, int day, int hour);

	int get_debut_city();
	General set_debut_city(int city_id);

	int get_vitality();
	General set_vitality(int vitality);

	int get_force();
	General set_force(int force);

	int get_intelligence();
	General set_intelligence(int intelligence);

	int get_experience();
	General set_experience(int experience);

	int get_level();

	int get_current_city();
	General set_current_city(int city_id);

	int get_current_country();
	General set_current_country(int country_id);

	int get_soldiers();
	General set_soldiers(int soldiers);

	int add_vitality(int delta); //这个delta可以为负
	int add_force(int delta);
	int add_intelligence(int delta);
	int add_morality(int delta);
	int add_experience(int delta);
	int add_soldiers(int delta); //这个delta可以为负
	int add_vitality_bound(int delta);

private:
	ImmutableGeneralAttributes immutable_attributes;
	int vitality; //体力，生命值
	int vitality_bound; //体力上限
	int force; //武力值
	int intelligence; //智力值
	int morality; //道德值
	int experience; //经验值
	int current_city; //当前城池
	int current_country; //当前势力
	int soldiers; //带兵数
};