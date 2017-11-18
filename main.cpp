#include <windows.h>
#include <iostream>
#include<iomanip> // для setw()
//#include <iterator>
//#include <algorithm>
//#include <string> 

#define ERRTEXT SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY)
#define COMTEXT SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY)
#define DEFTEXT SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY)

using namespace std; 
HANDLE hConsole;
unsigned char BufferByte[8 * 12]; 

int main(int argc, char** argv)
{
	setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
	system("color 1E");
	system("title tst");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор устройства стандартного вывода

    cout << " Execute 512 click left button mouse." << "\n\n"; 
	DEFTEXT;
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
 
                for (unsigned long long i = 0; i < 8; i++)
                {
                    BufferByte[(ClickCount * 8) + (7 - i)] = ValueCount & 0xff;
                    ValueCount >>= 8;
                } 
 
                  ClickCount++;                
 				  cout << " Click left button mouse: " << ++Count  << "\n";
 				  if (ClickCount == ClickMax)
                 	{
                     			break;
                	}
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
 
   static int j = 1;
    cout << "\n ---------------------------------------------------------" << "\n\n";
    MessageBox(NULL, TEXT("Array BufferByte for create key over hash-function"), TEXT("Message"), MB_OK);
    cout << " Array BufferByte for create key over hash-function ready." << "\n\n";
    
	cout << " BufferByte: " <<"\n\n";
    for(int i=0; i < sizeof BufferByte/sizeof(unsigned char);) 
	{
			
			if(j > 8) {j = 1; cout << " ------------------- " <<"\n\n";}else{			}
	 		cout <<setw(5) << j++ << " ArrayData: " << (int)BufferByte[i++] <<"\n" ;
	
	}
    
    //Call Hash(ArrayHash, ArrayData = BufferByte, SizeArrayData = 8 * ClickMax);
     cout << "\n\n";
	 ERRTEXT;
    system("pause");
    return 0;
}
