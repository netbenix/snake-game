#pragma once

enum class PixelColor {
	Blue, Green, Aqua, Red, Purple,
	Yellow, Clear
};
enum class PixelType { Hash, Dot, Line, Slash, Blank, X };

class CmdRender {
private:
	int sizeX, sizeY;
	char** grid;
	bool init;

	void setCursorPosition(int x, int y);
	void ShowConsoleCursor(bool showFlag);
	void CheckInit();
	int clearScreen();
	void UpdatePixel(int posX, int posY);
	void SetPixelColor(int posX, int posY, PixelColor pixelColor);
public:
	int Init(int sizeX, int sizeY);
	int ChangePixel(int posX, int posY, PixelType pixelType, PixelColor pixelColor);
	PixelType GetPixelType(int posX, int posY);
};