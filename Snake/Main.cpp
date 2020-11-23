#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "RenderEngine.h"

int main() {

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	CmdRender cmdRend;
	cmdRend.Init(csbi.srWindow.Right - csbi.srWindow.Left, csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
	cmdRend.RenderScreen();	

	for (int i = 0; i < csbi.srWindow.Right - csbi.srWindow.Left; i++) {
		if (i == 0) {
			cmdRend.ChangePixel(7, i, CmdRender::PixelType::Hash);
			cmdRend.ChangePixel(7, i+1, CmdRender::PixelType::Hash);
			cmdRend.ChangePixel(7, i+2, CmdRender::PixelType::Hash);
		}
			

		if (i > 0) {
			cmdRend.ChangePixel(7, i-2, CmdRender::PixelType::Blank);
			cmdRend.ChangePixel(7, i + 2, CmdRender::PixelType::Hash);
		}
		cmdRend.RenderScreen();
		Sleep(16.66667);
	}
	return 0;
}