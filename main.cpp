#include <windows.h>
#include<iostream>
#include<string>
#include <regex>
#include<map>

#include "mouse.h"
#include "keyboard.h"
//#include "window.h" 


using namespace std;

int main(){
    MOUSE me;
    KEYBOARD kb;

    kb.SetCapsLock(TRUE);
    HWND W;

    ShellExecute(NULL, "open","notepad.exe",NULL,NULL,SW_SHOWNORMAL);

    W = GetForegroundWindow();
    ShowWindow(W,SW_SHOWNORMAL);
    // Sleep(500);
    // string kbstring;
    // kbstring = "ASDF!@#*?+asd.asf{}+_()";
    // kb.input(kbstring);

    // Sleep(10000);

    SendMessage(HWND_BROADCAST, WM_LBUTTONDOWN, 0, 0);
    SendMessage(HWND_BROADCAST, WM_LBUTTONUP, 0, 0);


}