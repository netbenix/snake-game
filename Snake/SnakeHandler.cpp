#include <iostream>
#include "SnakeHandler.h"



int SnakeHandler::CheckCollision() {
	return 0;
}

int SnakeHandler::Init(CmdRender cmdRend, int sizeX, int sizeY) {
	SnakeHandler::sizeX = sizeX;
	SnakeHandler::sizeY = sizeY;
	SnakeHandler::length = 4;
	SnakeHandler::anchorCount = 0;

	snakeColor = PixelColor::Green;
	DrawBounds(cmdRend);
	SetHeadPosition((sizeX / 8) + 2, (sizeY / 2));
	cmdRend.ChangePixel((sizeX / 8) + 2, (sizeY / 2), PixelType::X, snakeColor);
	cmdRend.ChangePixel((sizeX / 8) + 1, (sizeY / 2), PixelType::X, snakeColor);
	cmdRend.ChangePixel((sizeX / 8), (sizeY / 2), PixelType::X, snakeColor);
	cmdRend.ChangePixel((sizeX / 8) - 1, (sizeY / 2), PixelType::X, snakeColor);
	init = true;
	return 1;
}

void SnakeHandler::CheckInit() {
	if (!init) {
		exit(3);
	}
}
void SnakeHandler::SetHeadPosition(int posX, int posY){
	CheckInit();
	SnakeHandler::headPosX = posX;
	SnakeHandler::headPosY = posY;
}

void SnakeHandler::SetTailPosition(int posX, int posY) {
	CheckInit();
	SnakeHandler::tailPosX = posX;
	SnakeHandler::tailPosY = posY;
}

void SnakeHandler::CreateAnchor(int posX, int posY) {
	CheckInit();
	anchorCount++;
	anchor[anchorCount - 1].anchorX = posX;
	anchor[anchorCount - 1].anchorY = posY;
}

void SnakeHandler::CheckAnchor(InputDirection input) {
	CheckInit();
	if (input != lastInput) {
		CreateAnchor(headPosX, headPosY);
	}
}

void SnakeHandler::RemoveTail() {
	//TODO
}

int SnakeHandler::MoveUp(CmdRender cmdRend) {
	CheckInit();
	if (!CheckBounds(headPosX, headPosY-1))
		return 1;
	CheckAnchor(InputDirection::Up);
	cmdRend.ChangePixel(headPosX, headPosY - 1, PixelType::X, snakeColor);
	SetHeadPosition(headPosX, headPosY - 1);
	lastInput = InputDirection::Up;
	return 0;
}

int SnakeHandler::MoveDown(CmdRender cmdRend) {
	CheckInit();
	if (!CheckBounds(headPosX, headPosY + 2))
		return 1;
	cmdRend.ChangePixel(headPosX, headPosY + 1, PixelType::X, snakeColor);
	SetHeadPosition(headPosX, headPosY + 1);
	lastInput = InputDirection::Down;
	return 0;
}

int SnakeHandler::MoveLeft(CmdRender cmdRend) {
	CheckInit();
	if (!CheckBounds(headPosX - 1, headPosY))
		return 1;
	cmdRend.ChangePixel(headPosX - 1, headPosY, PixelType::X, snakeColor);
	SetHeadPosition(headPosX - 1, headPosY);
	lastInput = InputDirection::Left;
	return 0;
}

int SnakeHandler::MoveRight(CmdRender cmdRend) {
	CheckInit();
	if (!CheckBounds(headPosX + 2, headPosY))
		return 1;
	cmdRend.ChangePixel(headPosX + 1, headPosY, PixelType::X, snakeColor);
	SetHeadPosition(headPosX + 1, headPosY);
	lastInput = InputDirection::Right;
	return 0;
}

bool SnakeHandler::CheckBounds(int posX, int posY) {
	if (posX > sizeX-1 || posX < 1) {
		return 0;
	} 

	if (posY > sizeY-1 || posY < 1) {
		return 0;
	}

	return 1;
}

void SnakeHandler::DrawBounds(CmdRender cmdRend) {
	for (int i = 0; i < sizeX; i++) { //TOP
		cmdRend.ChangePixel(i, 0, PixelType::Hash, PixelColor::Purple);
	}
	for (int i = 0; i < sizeX; i++) { //BOTTOM
		cmdRend.ChangePixel(i, sizeY-1, PixelType::Hash, PixelColor::Purple);
	}
	for (int i = 0; i < sizeY; i++) { //LEFT
		cmdRend.ChangePixel(0, i, PixelType::Hash, PixelColor::Purple);
	}
	for (int i = 0; i < sizeY; i++) { //RIGHT
		cmdRend.ChangePixel(sizeX-1, i, PixelType::Hash, PixelColor::Purple);
	}
}