// HomeWork220114.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>


//int Len(const char* _char)
//{
//	int count = 0;
//	while (0 != _char[count]) count += 1;
//	return count;
//}

void ToUpper(const char* _Left, char* _Right)
{


	for (int num = 0; _Left[num] != 0; num++) {


		_Right[num] = _Left[num];

		if ('a' <= _Left[num] && _Left[num] <= 'z') {
			_Right[num] = _Left[num] - ('a' - 'A');
		}

	}

}


int ToInt(const char* _Left)
{
	int num = 0;
	bool type = 0; //��ȣ �÷���

	//�տ� +�� �پ������� �����Ѵ�.
	if (*_Left == '+') _Left++;

	//�տ� -�� ������ type�� �÷��� �ֱ�
	else if (*_Left == '-') {
		type = true;
		_Left++;
	}

	while (*_Left != '/0') {
		//0~9�̿��� ���ڿ��̶�� ����
		if (*_Left < 48 || *_Left > 57) break;

		num += *_Left - 48;
		num *= 10; //�ڸ����� �÷��ش�
		_Left++;
	}

	num /= 10; //�������� ����� ���ڸ��� ���⶧���� �����ֱ�

	//���� -��ȣ�� �پ��ִٸ�
	if (type) num = 0 - num;


	return num;

}

// �� �����Ŵ�.
void CharChange(char* _Text, char _Prev, char _Next)
{
	for (int num = 0; _Text[num] != 0; num++) {


		if (_Text[num] == _Prev) _Text[num] = _Next;

	}


}



int main()
{

	{
		char Text[5];

		ToUpper("pP1231dcwsec", Text);
	//	"12ABCCEEE"
	}

	{
		char Text[100];

		ToUpper("12abCcEee", Text);
	//	"12ABCCEEE"

			printf_s(Text);

	}

	{
		char Text = '1';
		int Count = '2';

		//int Value = ToInt("15815");

		printf("%d\n", ToInt("123"));
	}

	{
		char Text[100] = "aa, bb, cc, dd";

		CharChange(Text, ',', '|');
		// aa| bb| cc| dd

		printf_s(Text);
	}


}
