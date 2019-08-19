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
