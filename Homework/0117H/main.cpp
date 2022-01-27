// HomeWork220115.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


int StringLength(const char* _Str)
{
    int count = 0;

    while (0 != _Str[count])
    {
        count += 1;
    }

    return count;
}


bool StringCompare(const char* _Left, const char* _Right)
{

    int i = 0;
    for (; ((0 != _Left[i]) && (0 != _Right[i])); )
    {
        char Left = _Left[i];
        char Right = _Right[i];

        if (_Left[i] != _Right[i])
        {
            return false;
        }

        i += 1;
    }


    //int Count = 0;
    //while (0 == _Left[Count]
    //    || 0 == _Right[Count])
    //{
    //    if (_Left[Count] != _Right[Count])
    //    {
    //        return false;
    //    }
    //    ++Count;
    //}

    return true;
}

int CountFirst(const char* _Text, int _Start, const char* _FindStr)
{
    int FindStrLen = StringLength(_FindStr);
    int TextStrLen = StringLength(_Text);

    for (int i = _Start; i < TextStrLen; i += 1)
    {

        // "aaa eee ttt" 
        //     "eee"
        if (_Text[i] == _FindStr[0])
        {
            char TextChar = _Text[i];
            char findChar = _FindStr[0];

            if (true == StringCompare(&_Text[i], &_FindStr[0]))
            {
                return i;
            }


            //int count = 0;
            //int ComCount = FindStrLen;

            //for (int j = 0; j < ComCount; j += 1)
            //{
            //    char TextChar = _Text[i + j];
            //    char findChar = _FindStr[j];

            //    if (_Text[i + j] == _FindStr[j])
            //    {
            //        count += 1;
            //    }
            //    else {
            //        ComCount = 0;
            //    }
            //}

            //if (count == FindStrLen)
            //{
            //    return i;
            //}
        }

    }

    return -1;
}

int CountLast(const char* _Text, int _End, const char* _FindStr)
{
    return -1;
}


int main()
{
 /*   {
        char ArrLeft[100] = { 3,3,1,1,1,1,2,2,2,3,3,0 };
        char ArrRight[100] = { 1,1,1,0 };

        int Count = CountFirst(ArrLeft, 0, ArrRight);

        int a = 0;

    }*/

    // 실패
    {
        int Count = CountFirst("aaa eee ttt asdfasd eee", 15, "eee");
    }
    {
        int Count = CountLast("aaa eee asdfasd eee", 15, "eee");
    }



}
