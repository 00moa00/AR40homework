// HomeWork220114.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//길이 구하는 함수
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
	bool type = 0; //부호 플러그

	//앞에 +가 붙어잇으면 무시한다.
	if (*_Left == '+') _Left++;

	//앞에 -가 있으면 type에 플러그 넣기
	else if (*_Left == '-') {
		type = true;
		_Left++;
	}

	while (*_Left != '/0') {
		//0~9이외의 문자열이라면 종료
		if (*_Left < 48 || *_Left > 57) break;

		num += *_Left - 48;
		num *= 10; //자릿수를 올려준다
		_Left++;
	}

	num /= 10; //루프에서 벗어나면 한자릿수 많기때문에 나눠주기

	//만약 -부호가 붙어있다면
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
		char temp = _Sorce[i];			//임시 변수를 만들어서 제일 첫번째 것을 넣고
		_Result[i] = _Sorce[len - i ];	//비어있는 곳에 마지막 요소를 넣는다
		_Result[len - i ] = temp;		//마지막 요소에는 임시 변수에 들어가있는 것을 넣어 바꿔치기
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
