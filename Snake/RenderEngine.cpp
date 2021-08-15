///////////////////////////
//   CMD RENDER ENGINE	 //
// DEVELOPED BY netbenix //
///////////////////////////

#include <iostream>
#include <windows.h>
#include <thread>

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
	CheckInit();
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
	grid = new char* [CmdRender::sizeX];
	for (int i = 0; i < CmdRender::sizeX; i++) {
		grid[i] = new char[CmdRender::sizeY];
	}
	init = true;
	clearScreen();
	ShowConsoleCursor(false);
	return 0;
}


void CmdRender::SetPixelColor(int posX, int posY, PixelColor pixelColor) {
	int colorCode;
	switch (pixelColor) {
	case (PixelColor::Blue): {colorCode = 1; break;}
	case (PixelColor::Green): {colorCode = 2; break;}
	case (PixelColor::Aqua): {colorCode = 3; break;}
	case (PixelColor::Red): {colorCode = 4; break;}
	case (PixelColor::Purple): {colorCode = 5; break;}
	case (PixelColor::Yellow): {colorCode = 6; break;}
	case (PixelColor::Clear): {colorCode = 7; break;}
	}

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorCode);
}

void CmdRender::CheckInit() {
	if (!init) {
		std::cout << "Renderer not initialized!";
		exit(2);
	}
}

void CmdRender::UpdatePixel(int posX, int posY) {
	setCursorPosition(posX, posY);
	std::cout << grid[posX][posY];
}


int CmdRender::ChangePixel(int posX, int posY, PixelType pixelType, PixelColor pixelColor) {
	CheckInit();

	if (posY > sizeY) {
		return 1;
	}

	char pixel;
	switch (pixelType) {
	case (PixelType::Hash): {pixel = '#';break;};
	case (PixelType::Dot): {pixel = '.'; break;};
	case (PixelType::Line): {pixel = '|'; break;};
	case (PixelType::Slash): {pixel = '/'; break;};
	case (PixelType::Blank): {pixel = ' '; break;};
	case (PixelType::X): {pixel = 'X'; break;}
	}
	SetPixelColor(posX, posY, pixelColor);
	if (pixel != NULL) {
		grid[posX][posY] = pixel;
	}

	UpdatePixel(posX, posY);
	return 0;
}

PixelType CmdRender::GetPixelType(int posX, int posY) {
	CheckInit();
	
	char pixel = grid[posX][posY];
	PixelType pixelType;
	switch (pixel) {
	case '#': { pixelType = PixelType::Hash; break;}
	case '.': { pixelType = PixelType::Dot; break;}
	case '|': { pixelType = PixelType::Line; break;}
	case '/': { pixelType = PixelType::Slash; break;}
	case ' ': {pixelType = PixelType::Blank; break;}
	}

	return pixelType;
}