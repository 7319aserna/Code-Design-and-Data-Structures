#pragma once
class GameState
{
private:
	GameState();
	GameState(GameState const&);  // prevents external use
	void operator=(GameState const&); // prevents external use
	int state;

public:
	///<summary>
	///doge
	///</summary>
	int getState();
	int setState(int newState);
	// Other parts of your code have to use this function to get an...
	// ... instance of GameState
	static GameState& GetInstance();
	~GameState();
};