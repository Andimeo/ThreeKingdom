#pragma once
#include "General.h";

class GeneralManager {
public:
	static GeneralManager getInstance();
	General get(int id);
private:
	GeneralManager();
	void init();
	static GeneralManager instance;
};