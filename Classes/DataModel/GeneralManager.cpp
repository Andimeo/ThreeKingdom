#include "GeneralManager.h"
#include "General.h"

GeneralManager GeneralManager::instance;
GeneralManager GeneralManager::getInstance(){
	return instance;
}

General GeneralManager::get(int id) {
	return *(new General());
}

GeneralManager::GeneralManager(){
}