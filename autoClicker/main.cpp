#include <iostream>
#include <windows.h>

// Function to perform a mouse click at the current cursor position
void mouseClick()
{
    INPUT input = {0};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main()
{
    std::cout << "Auto Clicker - Press 'Q' to start/stop the auto-clicking." << std::endl;
	
	users

    while (true)
    {
		mouseClick();
        if (GetAsyncKeyState('Q') & 0x8000) // Check if 'Q' key is pressed
        {
			      Sleep(10000); // Sleep for 10000 milliseconds (adjust as needed)
        }
    }

    return 0;
}
