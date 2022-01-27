// HomeWork220126.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class MyInt
{
public:
    int Value;

public:
    MyInt(int _Value)
        : Value(_Value)
    {
    }

    //a++
    MyInt& operator++() {

        this->Value = this->Value + 1;
        return *this ;
    }

    //++a
    MyInt& operator++ (int) {

        MyInt temp = this->Value;
        this->Value =  this->Value + 1;

        return temp;
    }
};

int main()
{

    MyInt MyValue = 10;
    MyInt MyResult = 0;

    MyResult = (MyValue++);
    //MyResult = (++MyValue);

}

