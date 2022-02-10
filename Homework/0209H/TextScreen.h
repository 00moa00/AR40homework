#pragma once
#include "ConsoleMath.h"
#include <assert.h>
#include <conio.h>

class ConsoleScreen
{
public:

	ConsoleScreen(int _Width, int _Height, const char* _DefaultValue);
	~ConsoleScreen();

	ConsoleScreen(const ConsoleScreen& _Other) = delete;
	ConsoleScreen(ConsoleScreen&& _Other) noexcept = delete;
	ConsoleScreen& operator=(const ConsoleScreen& _Other) = delete;
	ConsoleScreen& operator=(ConsoleScreen&& _Other) noexcept = delete;


	ConsoleVector GetSize() 
	{
		return Size_;
	}

	void CreateScreen(int _Width, int _Height, const char* _DefaultValue);

	void SettingScreen();

	void PrintScreen();

	void SetPixel(ConsoleVector _Pos, const char* _DefaultValue);
	void SetPixel(int _X, int _Y, const char* _DefaultValue);

	

protected:

private:
	ConsoleVector Size_;
	char** PixelData_;
	char DefaultPixel_[3];

};

