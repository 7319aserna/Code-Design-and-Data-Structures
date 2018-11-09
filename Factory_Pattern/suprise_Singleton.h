#pragma once

class supriseSingleton {
private: 
	supriseSingleton();
	supriseSingleton(supriseSingleton const&);
	void operator=(supriseSingleton const&);

public:
	static supriseSingleton& getInstance();
	~supriseSingleton();
};