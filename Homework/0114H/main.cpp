// HomeWork220114.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>

//���� ���ϴ� �Լ�
int myLength(const char* _char)
{
	int count = 0;
	while (0 != _char[count]) count += 1;
	return count;
}

void ToUpper(const char* _Left, char* _Right)
{

	for (int i = 0; _Left[i] != 0; i++) {

		_Right[i] = _Left[i];

		if ('a' <= _Left[i] && _Left[i] <= 'z') {
			_Right[i] = _Left[i] - ('a' - 'A');
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

void CharChange(char* _Text, char _Prev, char _Next)
{
	for (int i = 0; _Text[i] != 0; i++) {

		if (_Text[i] == _Prev) _Text[i] = _Next;
	}


}

void Rervers(const char* _Sorce, char* _Result)
{
	int len = myLength(_Sorce)-1;

	for (int i = 0; i <= len ; i++) {
		char temp = _Sorce[i];			//�ӽ� ������ ���� ���� ù��° ���� �ְ�
		_Result[i] = _Sorce[len - i ];	//����ִ� ���� ������ ��Ҹ� �ִ´�
		_Result[len - i ] = temp;		//������ ��ҿ��� �ӽ� ������ ���ִ� ���� �־� �ٲ�ġ��
	}

}

void Cut(const char* _Sorce, int _Start, int _End, char* _Result)
{

	int resultNum = 0;

	for(int i = 0; _Sorce[i] != 0; i++){
	
		if (_Sorce[i] >= _Start + 48 &&
			_Sorce[i] <= _End + 48
			) {

			_Result[resultNum] = _Sorce[i];
			resultNum++;
		}
	}

}


int main()
{

	//{
	//	char Text[5];

	//	ToUpper("pP1231dcwsec", Text);
	////	"12ABCCEEE"
	//}

	{
		char Text[100] = " ";

		ToUpper("12abCcEee", Text);
		//	"12ABCCEEE"

		printf_s("%s\n", Text);

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

		printf_s("%s\n", Text);
	}

	{
		char Text[100] = { };
		Rervers("0123456789", Text);
		printf_s("%s\n",Text);

	}

	{
		char Text[100] = { };
		Cut("0123456789", 2, 7, Text);
		// "234567"
		printf_s(Text);

	}
}
