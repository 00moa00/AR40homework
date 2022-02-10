#include "ConsoleObject.h"

ConsoleObject::ConsoleObject(
	TextScreen* _Screen,
	const char* _Text,
	const ConsoleVector& _Pos
	)
	: Screen_(_Screen)
	, Pos_(_Pos)
{
	//if (nullptr == _Screen)
	//{
	//	assert(false);
	//}

	if (nullptr == _Text)
	{
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		Text_[i] = _Text[i];
	}
}

ConsoleObject::~ConsoleObject() 
{
}

void ConsoleObject::AreaOut()
{
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

void ConsoleObject::Render()
{
	if (nullptr == Screen_)
	{
		assert(false);
	}

	Screen_->SetPixel(Pos_, Text_);
}
