#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <thread>

#include "RenderEngine.h"
#include "SnakeHandler.h"



/*
Error Codes:

2 CmdRender not initialized
3 SnakeHandler not initialized

*/

int main() {
	CmdRender cmdRend;
	SnakeHandler snake;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	
	cmdRend.Init(csbi.srWindow.Right - csbi.srWindow.Left, csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
	snake.Init(cmdRend, csbi.srWindow.Right - csbi.srWindow.Left, csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
	while (true) {
		if (GetKeyState(VK_UP) & 0x8000) {
			snake.MoveUp(cmdRend);
		}
		if (GetKeyState(VK_DOWN) & 0x8000) {
			snake.MoveDown(cmdRend);
		}
		if (GetKeyState(VK_LEFT) & 0x8000) {
			snake.MoveLeft(cmdRend);
		}
		if (GetKeyState(VK_RIGHT) & 0x8000) {
			snake.MoveRight(cmdRend);
		}

		Sleep(16.66667);
	}
	return 0;
}

