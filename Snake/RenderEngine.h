#pragma once

class CmdRender {
private:
	int sizeX, sizeY;
	char** grid;
	bool init;
	void setCursorPosition(int x, int y);
	void ShowConsoleCursor(bool showFlag);
	int clearScreen();
public:
	enum class PixelType {Hash, Dot, Line, Slash, Blank};
	int Init(int sizeX, int sizeY);
	int RenderScreen();
	int ChangePixel(int posX, int posY, PixelType pixelType);
	PixelType GetPixelType(int posX, int posY);
};