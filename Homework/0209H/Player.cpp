#include "Player.h"
#include <conio.h>

Player::Player(ConsoleScreen* _Screen, const char* _Text)
	: Screen_(_Screen)
	, Pos_(_Screen->GetSize().GetHalfVector())
	, Text_()
{
	if (nullptr == _Screen)
	{
		assert(false);
	}

	for (int i = 0; i < 3; i++)
	{
		Text_[i] = _Text[i];
	}

	// Pos_ = ;
}

Player::~Player() 
{
}


void Player::Update() 
{
	// Pos_.x_ += 1; // Pos_.y_ += 0;
	//   'a'
	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		Pos_.x_ -= 1;
		break;
	case 'd':
	case 'D':
		Pos_.x_ += 1;
		break;
	case 'w':
	case 'W':
		Pos_.y_ -= 1;
		break;
	case 's':
	case 'S':
		Pos_.y_ += 1;
		break;
	default:
		break;
	}
	
	
	if ((this->GetPos().x_ >= Screen_->GetSize().x_) ||
		(this->GetPos().x_ < 0))
	{
		assert(false);

	}

	if ((this->GetPos().y_ >= Screen_->GetSize().y_) ||
		(this->GetPos().y_ < 0))
	{
		assert(false);

	}


}

void Player::Render() 
{
	Screen_->SetPixel(Pos_, Text_);
}