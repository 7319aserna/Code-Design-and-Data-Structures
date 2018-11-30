#pragma once

class currentState
{
private:
	currentState();
	currentState(currentState const&);  // prevents external use
	void operator=(currentState const&); // prevents external use
	int state;

public:
	int getState();
	int setState(int newState);
	static currentState& GetInstance();
	~currentState();
};