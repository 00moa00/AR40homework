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


    //MyInt& operator+=(const MyInt& _i) {

    //Value += _i.Value;
    //return *this;
    //}

    MyInt operator+=(const MyInt& _i) {

        Value += _i.Value;
        std::cout << &(_i.Value) << std::endl;
        std::cout << &(Value) << std::endl;

        return Value;

    }                   

};

int main()
{

    MyInt MyResult = 0;

    
    //  MyResult =  MyResult + MyInt(2);
    //  (MyResult += MyInt(1)) += (MyInt(1));


    MyResult += MyInt(1);
  // (MyResult += MyInt(1)) += (MyInt(1));
   // MyResult.operator+=(MyInt(1));
    std::cout << &(MyResult.Value) << std::endl;

    std::cout << MyResult.Value << std::endl;
}


////++a
//MyInt& operator++() {
//
//    this->Value = this->Value + 10;
//    return *this;



//a++
//MyInt& operator++ (int) {

//    MyInt temp = this->Value;
//    this->Value =  this->Value + 10;

//    return temp;
//}