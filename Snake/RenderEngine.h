#pragma once

enum class PixelColor {
	Blue, Green, Aqua, Red, Purple,
	Yellow, Clear
};
enum class PixelType { Hash, Dot, Line, Slash, Blank };

class CmdRender {
private:
	int sizeX, sizeY;
	char** grid;
	PixelColor** colorGrid;
	bool init;
	void setCursorPosition(int x, int y);
	void ShowConsoleCursor(bool showFlag);
	int clearScreen();
	void SetPixelColor(int posX, int posY, PixelColor pixelColor);
public:
	int Init(int sizeX, int sizeY);
	int RenderScreen();
	int ChangePixel(int posX, int posY, PixelType pixelType, PixelColor pixelColor);
	PixelType GetPixelType(int posX, int posY);
};