// HomeWork220126.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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

