#include "suprise_Singleton.h"

supriseSingleton::supriseSingleton() {}
supriseSingleton::~supriseSingleton() {}

void supriseSingleton::operator=(supriseSingleton const&){}

supriseSingleton & supriseSingleton::getInstance() {
	static supriseSingleton instance;
	return instance;
}