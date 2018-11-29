#pragma once
class GameState
{
private:
	GameState();
	GameState(GameState const&);  // prevents external use
	void operator=(GameState const&); // prevents external use
	
	int state;

public:
	int getState();
	int setState(int newState);

	static GameState& GetInstance();

	~GameState();
};