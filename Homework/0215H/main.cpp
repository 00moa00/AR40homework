// GameArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <assert.h>
#include <crtdbg.h>

using DataType = int;

// 
class GameArray
{
private:
    int Size_;
    DataType* ArrData_;

public:
    int GetSize()
    {
        return Size_;
    }

    DataType& operator[](int _Index)
    {
        if (Size_ <= _Index)
        {
            assert(false);
        }

        return ArrData_[_Index];
    }

    inline void operator=(const GameArray& _Other)
    {
        ReSize(_Other.Size_);

        // 이걸 쉘로우 카피 
        // 혹은 얕은 복사라고 한다.
        //this->ArrData_ = _Other.ArrData_;
        //this->Size_ = _Other.Size_;

        // 이걸 딥 카피
        // 혹은 깊은 복사라고 한다.
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = _Other.ArrData_[i];
        }

        return;
    }

    inline void AllValueSetting(const DataType& Data)
    {
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = Data;
        }
    }


    inline void Release()
    {
        if (nullptr != ArrData_)
        {
            delete[] ArrData_;
            ArrData_ = nullptr;
        }
    }

    void ReSize(unsigned int _Size)
    {
        unsigned int beforeSize = Size_;
        DataType* CopyArry = new DataType[Size_];
        //GameArray CopyArry = GameArray(); 
        //CopyArry.ArrData = new DataType[Size_];

        for (int i = 0; i < Size_; i++)
        {
            CopyArry[i] = ArrData_[i];
        }

        Release();
        ArrData_ = new DataType[_Size];
        Size_ = _Size;

        AllValueSetting(0);

        if (Size_ > beforeSize)
        {
            for (size_t i = 0; i < beforeSize; i++)
            {
                ArrData_[i] = CopyArry[i];
            }
        }

        if (Size_ <= beforeSize)
        {
            for (size_t i = 0; i < Size_; i++)
            {
                ArrData_[i] = CopyArry[i];
            }
        }

        //CopyArry.release();
        if (CopyArry != nullptr) {
            delete[] CopyArry;
            CopyArry = nullptr;
        }
    }

public:

    GameArray()
        : ArrData_(nullptr)
        , Size_(0)
    {

    }

    GameArray(unsigned int _Size)
        : ArrData_(nullptr)
        , Size_(0)
    {
        ReSize(_Size);
    }

    ~GameArray()
    {
        Release();
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    GameArray NewArray = GameArray(10);
    GameArray NewArray2 = GameArray(20);

    int Size = sizeof(GameArray);

    //for (size_t i = 0; i < NewArray.GetSize(); i++)
    //{
    //    NewArray[i] = i;
    //}

    NewArray.AllValueSetting(1);
    NewArray2 = NewArray;

    NewArray2.ReSize(20);

    for (size_t i = 0; i < NewArray2.GetSize(); i++)
    {
        std::cout << NewArray2[i] << std::endl;
    }

    //int Arr[10];
    //int Arr2[10];

    //for (size_t i = 0; i < 10; i++)
    //{
    //    Arr[i] = Arr2[i];
    //}

    std::cout << "Hello World!\n";
}
