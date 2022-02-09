#include "TextScreen.h"
#include <iostream>

ConsoleScreen::ConsoleScreen(int _Width, int _Height, const char* _DefaultValue)
	: PixelData_(nullptr)
	, Size_(0, 0)
	, DefaultPixel_() 
{
	CreateScreen(_Width, _Height, _DefaultValue);
}

ConsoleScreen::~ConsoleScreen()
{
	for (int i = 0; i < Size_.y_; i++)
	{
		if (nullptr != PixelData_)
		{
			delete[] PixelData_[i];
			PixelData_[i] = nullptr;
		}
	}

	if (nullptr != PixelData_)
	{
		delete[] PixelData_;
		PixelData_ = nullptr;
	}
}

void ConsoleScreen::CreateScreen(int _Width, int _Height, const char* _DefaultValue)
{
	Size_.x_ = _Width;
	Size_.y_ = _Height;

	for (int i = 0; i < 3; i++)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}

	int RealWidth = Size_.x_ * 2;
	RealWidth += 2;

	PixelData_ = new char*[Size_.y_];

	for (int i = 0; i < Size_.y_; i++)
	{
		PixelData_[i] = new char[RealWidth];
	}
}

void ConsoleScreen::SettingScreen()
{
	int RealWidth = Size_.x_ * 2;
	RealWidth += 1;

	for (int y = 0; y < Size_.y_; y++)
	{
		for (int x = 0; x < Size_.x_; x++)
		{
			for (int i = 0; i < 2; i++)
			{
				PixelData_[y][(x * 2) + i] = DefaultPixel_[i];
			}
		}
		PixelData_[y][(Size_.x_ * 2)] = '\n';
		PixelData_[y][(Size_.x_ * 2) + 1] = 0;
	}

}

void ConsoleScreen::PrintScreen()
{
	system("cls");

	for (int y = 0; y < Size_.y_; y++)
	{
		printf_s(PixelData_[y]);
	}
}


void ConsoleScreen::SetPixel(ConsoleVector _Pos, const char* _DefaultValue)
{
	SetPixel(_Pos.x_, _Pos.y_, _DefaultValue);
}

void ConsoleScreen::SetPixel(int _X, int _Y, const char* _DefaultValue)
{

	for (int i = 0; i < 2; i++)
	{
		PixelData_[_Y][(_X * 2) + i] = _DefaultValue[i];
	}
}