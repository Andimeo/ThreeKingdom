#include "GeneralManager.h"
#include "General.h"

GeneralManager GeneralManager::instance;

GeneralManager GeneralManager::getInstance(){
	return instance;
}

General GeneralManager::get(int id) {
	//TODO
	return *(new General());
}

GeneralManager::GeneralManager(){
}