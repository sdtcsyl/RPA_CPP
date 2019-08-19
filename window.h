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

// the OPEN window Class

class WND_OPEN
{
    private:
        HWND wnd, wnd_child;
        int res_down, res_up;
        BOOL res;
    public:
        int click_cancel();
        int click_ok();
        BOOL set_text(const char* name);
}

int WND_OPEN::click_cancel()
{
    this->wnd = FindWindowA(NULL,"Open");
    this->wnd_child = GetWindow(this->wnd, GW_CHILD);
    this->wnd_child = FindWindowExA(this->wnd, this->wnd_child, NULL, "CANCEL");
    this->res_down = SendMessage(this->wnd_child, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
    this->res_up = SendMessage(this->wnd_child, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
    return this->res_down;
}

int WND_OPEN::click_ok()
{
    this->wnd = FindWindowA(NULL,"Open");
    this->wnd_child = GetWindow(this->wnd, GW_CHILD);
    this->wnd_child = FindWindowExA(this->wnd, this->wnd_child, NULL, "OK");
    this->res_down = SendMessage(this->this->wnd_child, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
    this->res_up = SendMessage(wnd_child, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
    return this->res_down;
}

BOOL WND_OPEN::set_text(const char* name)
{
    this->wnd = FindWindowA(NULL,"Open");
    this->wnd_child = GetWindow(this->wnd, GW_CHILD);
    this->wnd_child = FindWindowExA(this->wnd, this->wnd_child, NULL, "Files of &type:");
    this->wnd_child = GetWindow(this->wnd_child, GW_HWNDPREV);
    this->res = SendMessage(this->wnd_child, WM_SETTEXT, 0, (LPARAM) name);    
    return this->res;
}

// the SAVEAS window Class

class WND_SAVEAS
{
    private:
        HWND wnd, wnd_child;
        int res_down, res_up;
        BOOL res;
    public:
        int click_cancel();
        int click_save();
        BOOL set_text(const char* name);
}

int WND_SAVEAS::click_cancel()
{
    this->wnd = FindWindowA(NULL,"Save As");
    this->wnd_child = GetWindow(this->wnd, GW_CHILD);
    this->wnd_child = FindWindowExA(this->wnd, this->wnd_child, NULL, "CANCEL");
    this->res_down = SendMessage(this->wnd_child, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
    this->res_up = SendMessage(this->wnd_child, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
    return this->res_down;
}

int WND_SAVEAS::click_save()
{
    this->wnd = FindWindowA(NULL,"Save As");
    this->wnd_child = GetWindow(this->wnd, GW_CHILD);
    this->wnd_child = FindWindowExA(this->wnd, this->wnd_child, NULL, "&Save");
    this->res_down = SendMessage(this->wnd_child, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
    this->res_up = SendMessage(this->wnd_child, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
    return this->res_down;
}

BOOL WND_SAVEAS::set_text(const char* name)
{
    this->wnd = FindWindowA(NULL,"Save As");
    this->wnd_child = GetWindow(this->wnd, GW_CHILD);
    this->wnd_child = GetWindow(this->wnd_child, GW_CHILD);
    this->wnd_child = GetWindow(this->wnd_child, GW_CHILD);
    this->wnd_child = GetWindow(this->wnd_child, GW_CHILD);
    this->wnd_child = GetWindow(this->wnd_child, GW_CHILD);
    this->res = SendMessage(this->wnd_child, WM_SETTEXT, 0, (LPARAM) name);    
    return this->res;
}

