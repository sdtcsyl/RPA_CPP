////////////////////
//keyboard.h
//Simulate Keyword Common Activities
//https){//docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
////////////////////
#pragma once
#include<windows.h>
#include<string>
#include<map>
#include<regex>

using namespace std;

class KEYBOARD
    {
    private:
        BYTE keyState[256];
        BOOL Num, Caps, Scrl; 
        map<string,int> VK_CODE;   
    public:
        KEYBOARD();
        void  SetNumLock(BOOL bState);
        void  SetCapsLock(BOOL bState);
        void  SetScrlLock(BOOL bState);
        void  input(string kbstring);
        //void  fulfilmap();
        void  pagedwn();
        void  pageup();
        void  set_home();
        void  set_end();
    };

// KEYBOARD class constructor
KEYBOARD::KEYBOARD()
    {
      GetKeyboardState((LPBYTE)&this->keyState);
      if( (TRUE && !(keyState[VK_NUMLOCK] & 1)) ||
          (FALSE && (keyState[VK_NUMLOCK] & 1)) )
      {
          this->Num = TRUE; 
      }
      else
      {
          this->Num = FALSE; 
      }

      if( (TRUE && !(keyState[VK_CAPITAL] & 1)) ||
          (FALSE && (keyState[VK_CAPITAL] & 1)) )
      {
          this->Caps = TRUE; 
      }
      else
      {
          this->Caps = FALSE; 
      }
     
      if( (TRUE && !(keyState[VK_SCROLL] & 1)) ||
          (FALSE && (keyState[VK_SCROLL] & 1)) )
      {
          this->Scrl = TRUE; 
      }
      else
      {
          this->Scrl = FALSE; 
      }
    }

//Set NumLock (TRUE or FALSE)
void KEYBOARD::SetNumLock(BOOL bState)
   {
      if(this->Num == bState)
      {
         keybd_event( VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );
         keybd_event( VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
         this-> Num = ! this->Num;
      }
   }

//Set CapLock (TRUE or FALSE)
void KEYBOARD::SetCapsLock(BOOL bState)
   {
      if(this->Caps == bState)
      {
         keybd_event(VK_CAPITAL, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );
         keybd_event(VK_CAPITAL, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
         this-> Caps = ! this->Caps;
      }
   }

//Set ScrollLock (TRUE or FALSE)
void KEYBOARD::SetScrlLock(BOOL bState)
   {
      if(this->Scrl == bState)
      {
         keybd_event( VK_SCROLL, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );
         keybd_event( VK_SCROLL, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
         this-> Scrl = ! this->Scrl;
      }
   }


//input string(string)
void KEYBOARD::input(string kbstring)
    {
    this->SetCapsLock(FALSE);
    regex UpperChar ("[A-Z!@#$%^&*()_+|{}:<>?]");
    regex LowerChar ("[a-z0-9-=;',./]");

    for(int i = 0; i < kbstring.length(); i++)
    {
        if (regex_match (string(1, kbstring[i]) , UpperChar))
        {
            keybd_event(VK_LSHIFT, 0, KEYEVENTF_EXTENDEDKEY | 0, 0 );
            keybd_event(VkKeyScan(kbstring[i]), 0, KEYEVENTF_EXTENDEDKEY | 0, 0 );
            Sleep(1);
            keybd_event(VK_LSHIFT,0 ,KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
            keybd_event(VkKeyScan(kbstring[i]),0 ,KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
        }
        else
        {
            keybd_event(VkKeyScan(kbstring[i]), 0, KEYEVENTF_EXTENDEDKEY | 0, 0 );
            Sleep(1);
            keybd_event(VkKeyScan(kbstring[i]),0 ,KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
        }    
    }
    }

// //fill map()
// void KEYBOARD::fulfilmap():
//     {
//     this->VK_CODE["backspace"] = 0x08;
//     this->VK_CODE["tab"] = 0x09;
//     this->VK_CODE["clear"] = 0x0C;
//     this->VK_CODE["enter"] = 0x0D;
//     this->VK_CODE["shift"] = 0x10;
//     this->VK_CODE["ctrl"] = 0x11;
//     this->VK_CODE["alt"] = 0x12;
//     this->VK_CODE["pause"] = 0x13;
//     this->VK_CODE["caps_lock"] = 0x14;
//     this->VK_CODE["esc"] = 0x1B;
//     this->VK_CODE["spacebar"] = 0x20;
//     this->VK_CODE["page_up"] = 0x21;
//     this->VK_CODE["page_down"] = 0x22;
//     this->VK_CODE["end"] = 0x23;
//     this->VK_CODE["home"] = 0x24;
//     this->VK_CODE["left_arrow"] = 0x25;
//     this->VK_CODE["up_arrow"] = 0x26;
//     this->VK_CODE["right_arrow"] = 0x27;
//     this->VK_CODE["down_arrow"] = 0x28;
//     this->VK_CODE["select"] = 0x29;
//     this->VK_CODE["print"] = 0x2A;
//     this->VK_CODE["execute"] = 0x2B;
//     this->VK_CODE["print_screen"] = 0x2C;
//     this->VK_CODE["ins"] = 0x2D;
//     this->VK_CODE["del"] = 0x2E;
//     this->VK_CODE["help"] = 0x2F;
//     //number
//     this->VK_CODE["0"] = 0x30;
//     this->VK_CODE["1"] = 0x31;
//     this->VK_CODE["2"] = 0x32;
//     this->VK_CODE["3"] = 0x33;
//     this->VK_CODE["4"] = 0x34;
//     this->VK_CODE["5"] = 0x35;
//     this->VK_CODE["6"] = 0x36;
//     this->VK_CODE["7"] = 0x37;
//     this->VK_CODE["8"] = 0x38;
//     this->VK_CODE["9"] = 0x39;
//     //Alphabet
//     this->VK_CODE["a"] = 0x41;
//     this->VK_CODE["b"] = 0x42;
//     this->VK_CODE["c"] = 0x43;
//     this->VK_CODE["d"] = 0x44;
//     this->VK_CODE["e"] = 0x45;
//     this->VK_CODE["f"] = 0x46;
//     this->VK_CODE["g"] = 0x47;
//     this->VK_CODE["h"] = 0x48;
//     this->VK_CODE["i"] = 0x49;
//     this->VK_CODE["j"] = 0x4A;
//     this->VK_CODE["k"] = 0x4B;
//     this->VK_CODE["l"] = 0x4C;
//     this->VK_CODE["m"] = 0x4D;
//     this->VK_CODE["n"] = 0x4E;
//     this->VK_CODE["o"] = 0x4F;
//     this->VK_CODE["p"] = 0x50;
//     this->VK_CODE["q"] = 0x51;
//     this->VK_CODE["r"] = 0x52;
//     this->VK_CODE["s"] = 0x53;
//     this->VK_CODE["t"] = 0x54;
//     this->VK_CODE["u"] = 0x55;
//     this->VK_CODE["v"] = 0x56;
//     this->VK_CODE["w"] = 0x57;
//     this->VK_CODE["x"] = 0x58;
//     this->VK_CODE["y"] = 0x59;
//     this->VK_CODE["z"] = 0x5A;
//     //Numeric keypad with Num Lock
//     this->VK_CODE["numpad_0"] = 0x60;
//     this->VK_CODE["numpad_1"] = 0x61;
//     this->VK_CODE["numpad_2"] = 0x62;
//     this->VK_CODE["numpad_3"] = 0x63;
//     this->VK_CODE["numpad_4"] = 0x64;
//     this->VK_CODE["numpad_5"] = 0x65;
//     this->VK_CODE["numpad_6"] = 0x66;
//     this->VK_CODE["numpad_7"] = 0x67;
//     this->VK_CODE["numpad_8"] = 0x68;
//     this->VK_CODE["numpad_9"] = 0x69;

//     this->VK_CODE["*"] = 0x6A;
//     this->VK_CODE["+"] = 0x6B;
//     this->VK_CODE["separator"] = 0x6C; //(never generated by the keyboard)
//     this->VK_CODE["-"] = 0x6D;
//     this->VK_CODE["."] = 0x6E;
//     this->VK_CODE["/"] = 0x6F;
//     //F1-F24
//     this->VK_CODE["F1"] = 0x70;
//     this->VK_CODE["F2"] = 0x71;
//     this->VK_CODE["F3"] = 0x72;
//     this->VK_CODE["F4"] = 0x73;
//     this->VK_CODE["F5"] = 0x74;
//     this->VK_CODE["F6"] = 0x75;
//     this->VK_CODE["F7"] = 0x76;
//     this->VK_CODE["F8"] = 0x77;
//     this->VK_CODE["F9"] = 0x78;
//     this->VK_CODE["F10"] = 0x79;
//     this->VK_CODE["F11"] = 0x7A;
//     this->VK_CODE["F12"] = 0x7B;
//     this->VK_CODE["F13"] = 0x7C;
//     this->VK_CODE["F14"] = 0x7D;
//     this->VK_CODE["F15"] = 0x7E;
//     this->VK_CODE["F16"] = 0x7F;
//     this->VK_CODE["F17"] = 0x80;
//     this->VK_CODE["F18"] = 0x81;
//     this->VK_CODE["F19"] = 0x82;
//     this->VK_CODE["F20"] = 0x83;
//     this->VK_CODE["F21"] = 0x84;
//     this->VK_CODE["F22"] = 0x85;
//     this->VK_CODE["F23"] = 0x86;
//     this->VK_CODE["F24"] = 0x87;
//     //
//     this->VK_CODE["num_lock"] = 0x90;
//     this->VK_CODE["scroll_lock"] = 0x91;

//     this->VK_CODE["left_shift"] = 0xA0;
//     this->VK_CODE["right_shift "] = 0xA1;
//     this->VK_CODE["left_control"] = 0xA2;
//     this->VK_CODE["right_control"] = 0xA3;
//     this->VK_CODE["left_menu"] = 0xA4;
//     this->VK_CODE["right_menu"] = 0xA5;
//     this->VK_CODE["browser_back"] = 0xA6;
//     this->VK_CODE["browser_forward"] = 0xA7;
//     this->VK_CODE["browser_refresh"] = 0xA8;
//     this->VK_CODE["browser_stop"] = 0xA9;
//     this->VK_CODE["browser_search"] = 0xAA;
//     this->VK_CODE["browser_favorites"] = 0xAB;
//     this->VK_CODE["browser_start_and_home"] = 0xAC;
//     this->VK_CODE["volume_mute"] = 0xAD;
//     this->VK_CODE["volume_Down"] = 0xAE;
//     this->VK_CODE["volume_up"] = 0xAF;
//     this->VK_CODE["next_track"] = 0xB0;
//     this->VK_CODE["previous_track"] = 0xB1;
//     this->VK_CODE["stop_media"] = 0xB2;
//     this->VK_CODE["play/pause_media"] = 0xB3;
//     this->VK_CODE["start_mail"] = 0xB4;
//     this->VK_CODE["select_media"] = 0xB5;
//     this->VK_CODE["start_application_1"] = 0xB6;
//     this->VK_CODE["start_application_2"] = 0xB7;
//     //
//     this->VK_CODE["attn_key"] = 0xF6;
//     this->VK_CODE["crsel_key"] = 0xF7;
//     this->VK_CODE["exsel_key"] = 0xF8;
//     this->VK_CODE["play_key"] = 0xFA;
//     this->VK_CODE["zoom_key"] = 0xFB;
//     this->VK_CODE["clear_key"] = 0xFE;
//     this->VK_CODE["+"] = 0xBB;
//     this->VK_CODE[";"] = 0xBC;
//     this->VK_CODE["-"] = 0xBD;
//     this->VK_CODE["."] = 0xBE;
//     this->VK_CODE["/"] = 0xBF;
//     this->VK_CODE["`"] = 0xC0;
//     this->VK_CODE[";"] = 0xBA;
//     this->VK_CODE["["] = 0xDB;
//     this->VK_CODE["\\"] = 0xDC;
//     this->VK_CODE["]"] = 0xDD;
//     }

//pagedown function ()
void KEYBOARD::pagedwn()
    {
        keybd_event(VK_PRIOR, 0, KEYEVENTF_EXTENDEDKEY | 0, 0 );
        keybd_event(VK_PRIOR,0 ,KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    }

//pageup function ()
void KEYBOARD::pageup()
    {
        keybd_event(VK_NEXT, 0, KEYEVENTF_EXTENDEDKEY | 0, 0 );
        keybd_event(VK_NEXT,0 ,KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    }

//home function ()
void KEYBOARD::set_home()
    {
        keybd_event(VK_HOME, 0, KEYEVENTF_EXTENDEDKEY | 0, 0 );
        keybd_event(VK_HOME,0 ,KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    }

//home function ()
void KEYBOARD::set_end()
    {
        keybd_event(VK_END, 0, KEYEVENTF_EXTENDEDKEY | 0, 0 );
        keybd_event(VK_END,0 ,KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    }