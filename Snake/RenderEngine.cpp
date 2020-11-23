///////////////////////////
//   CMD RENDER ENGINE	 //
// DEVELOPED BY netbenix //
///////////////////////////

#include <iostream>
#include <windows.h>

#include "RenderEngine.h"

void CmdRender::setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void CmdRender::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int CmdRender::clearScreen() {
	if (!init) {
		std::cout << "Renderer not initialized!";
		return -1;
	}
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			grid[x][y] = ' ';
		}
	}
	return 0;
}

int CmdRender::Init(int sizeX, int sizeY) {
	CmdRender::sizeX = sizeX;
	CmdRender::sizeY = sizeY;
	grid = new char* [sizeX];
	for (int i = 0; i < sizeX; i++) {
		grid[i] = new char[sizeY];
	}
	init = true;
	clearScreen();
	ShowConsoleCursor(false);
	return 0;
}

int CmdRender::RenderScreen() {
	if (!init) {
		std::cout << "Renderer not initialized!";
		return -1;
	}
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			setCursorPosition(x, y);
			std::cout << grid[x][y];
		}
	}

	return 0;
}

int CmdRender::ChangePixel(int posX, int posY, PixelType pixelType) {
	if (!init) {
		std::cout << "Renderer not initialized!";
		return -1;
	}

	char pixel;
	switch (pixelType) {
	case (PixelType::Hash): {pixel = '#'; break;};
	case (PixelType::Dot): {pixel = '.'; break;};
	case (PixelType::Line): {pixel = '|'; break;};
	case (PixelType::Slash): {pixel = '/'; break;};
	case (PixelType::Blank): {pixel = ' '; break;};
	}

	if (pixel != NULL) {
		grid[posX][posY] = pixel;
	}
	return 0;
}

CmdRender::PixelType CmdRender::GetPixelType(int posX, int posY) {
	if (!init) {
		std::cout << "Renderer not initialized!";
		return;
	}
	
	char pixel = grid[posX][posY];
	CmdRender::PixelType pixelType;
	switch (pixel) {
	case '#': { pixelType = CmdRender::PixelType::Hash; break;}
	case '.': { pixelType = CmdRender::PixelType::Dot; break;}
	case '|': { pixelType = CmdRender::PixelType::Line; break;}
			//TODO remaining Types
	}

	return pixelType;
}