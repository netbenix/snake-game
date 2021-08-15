#pragma once
#include "RenderEngine.h"

enum class InputDirection {
	Up, Down, Left, Right
};


struct Anchor{
	int anchorX;
	int anchorY;
};

class SnakeHandler {
private:
	int headPosX, headPosY; //Head pos
	int tailPosX, tailPosY; //Tail pos
	int length;
	Anchor anchor[500];
	int anchorCount;
	int currentAnchor;
	int sizeX, sizeY;
	PixelColor snakeColor;
	bool init;
	InputDirection lastInput;


	int CheckCollision();
	void CheckInit();
	void SetHeadPosition(int posX, int posY);
	void SetTailPosition(int posX, int posY);
	bool CheckBounds(int posX, int posY);
	void CreateAnchor(int posX, int posY);
	void CheckAnchor(InputDirection input);
	void DrawBounds(CmdRender cmdRend);
	void RemoveTail();
public:
	int MoveUp(CmdRender cmdRend);
	int MoveDown(CmdRender cmdRend);
	int MoveLeft(CmdRender cmdRend);
	int MoveRight(CmdRender cmdRend);
	int Init(CmdRender cmdRend, int sizeX, int sizeY);
};