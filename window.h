////////////////////
//window.h
//模拟窗口的常见操作
//https://docs.microsoft.com/en-us/windows/win32/api/winuser/
////////////////////
#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<winuser.h>
using namespace std;

// click OPEN window's cancel button
// the OPEN window cannot display two window.
int wnd_open_cancel(){
    HWND wnd, wnd_child;
    int res_down, res_up;
    wnd = FindWindowA(NULL,"Open");
    cout << wnd << endl;
    wnd_child = GetWindow(wnd, GW_CHILD);
    cout << wnd_child << endl;
    wnd_child = FindWindowExA(wnd, wnd_child, NULL, "CANCEL");
    cout << wnd_child << endl;
    res_down = SendMessage(wnd_child, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
    res_up = SendMessage(wnd_child, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
    cout << res_down << endl << res_up << endl;
    return res_down;
}

int wnd_open_ok(){
    HWND wnd, wnd_child;
    int res_down, res_up;
    wnd = FindWindowA(NULL,"Open");
    cout << wnd << endl;
    wnd_child = GetWindow(wnd, GW_CHILD);
    cout << wnd_child << endl;
    wnd_child = FindWindowExA(wnd, wnd_child, NULL, "OK");
    cout << wnd_child << endl;
    res_down = SendMessage(wnd_child, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
    res_up = SendMessage(wnd_child, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
    cout << res_down << endl << res_up << endl;
    return res_down;
}

BOOL wnd_open_edit(const char* name){
    HWND wnd, wnd_child;
    BOOL res;

    wnd = FindWindowA(NULL,"Open");
    cout << wnd << endl;
    wnd_child = GetWindow(wnd, GW_CHILD);
    cout << wnd_child << endl;
    wnd_child = FindWindowExA(wnd, wnd_child, NULL, "Files of &type:");
    wnd_child = GetWindow(wnd_child, GW_HWNDPREV);
    cout << wnd_child << endl;
    res = SendMessage(wnd_child, WM_SETTEXT, 0, (LPARAM) name) ;
    
    cout << res << endl;
    return res;
}
