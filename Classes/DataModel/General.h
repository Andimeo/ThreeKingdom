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

	int add_vitality(int delta); //���delta����Ϊ��
	int add_force(int delta);
	int add_intelligence(int delta);
	int add_morality(int delta);
	int add_experience(int delta);
	int add_soldiers(int delta); //���delta����Ϊ��
	int add_vitality_bound(int delta);

private:
	ImmutableGeneralAttributes immutable_attributes;
	int vitality; //����������ֵ
	int vitality_bound; //��������
	int force; //����ֵ
	int intelligence; //����ֵ
	int morality; //����ֵ
	int experience; //����ֵ
	int current_city; //��ǰ�ǳ�
	int current_country; //��ǰ����
	int soldiers; //������
};