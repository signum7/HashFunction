#include <windows.h>
#include <iostream>
 
 
unsigned char BufferByte[8 * 512];
 
 
int main(int argc, char** argv)
{
    std::cout << "Execute 512 click left button mouse." << "\n";
 
    unsigned long long LockButton;
    unsigned long long ClickMax = 12;
    unsigned long long ClickCount = 0;
 
 
    LockButton = 0;
    int Count = 0;
    while (1)
    {
 
        if (LockButton == 0)
        {
            if (GetAsyncKeyState(VK_LBUTTON) != 0)
            {
                LockButton = 1;
 
                
                LARGE_INTEGER TimerCount;
                QueryPerformanceCounter(&TimerCount);
 
                
                unsigned long long ValueCount;
                ValueCount = (unsigned long long)TimerCount.QuadPart;
 
 
                for (unsigned long long i = 0; i < 8; i = i + 1)
                {
                    BufferByte[ClickCount * 8 + (7 - i)] = ValueCount & 0xff;
                    ValueCount = ValueCount >> 8;
                }
 
 
                ClickCount = ClickCount + 1;
                if (ClickCount == ClickMax)
                {
                    break;
                }
 				 std::cout << "Click left button mouse: " << ++Count  << "\n";
            }
 
        }
 
 
        if (LockButton == 1)
        {
            if (GetAsyncKeyState(VK_LBUTTON) == 0)
            {
                LockButton = 0;
            }
        }
 
 
        Sleep(0);
    }
 
 
    std::cout << "Array BufferByte for create key over hash-function ready." << "\n";
 
    //Call Hash(ArrayHash, ArrayData = BufferByte, SizeArrayData = 8 * ClickMax);
 
    system("pause");
    return 0;
}
