/*
* Malware Development for Ethical Hackers
* pet.cpp
* API hooking example
* author: @cocomelonc
*/
#include <windows.h>

// Entry point of the DLL
BOOL APIENTRY DllMain(HMODULE hModule,  DWORD  dwReasonForCall, LPVOID lpReserved) {
  switch (dwReasonForCall) {
    case DLL_PROCESS_ATTACH:
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

// Exported function to display a cat message box
extern "C" {
  __declspec(dllexport) int _cdecl Cat(LPCTSTR message) {
    MessageBox(NULL, message, "=^..^=", MB_OK);
    return 1;
  }
}

// Exported function to display a mouse message box
extern "C" {
  __declspec(dllexport) int _cdecl Mouse(LPCTSTR message) {
    MessageBox(NULL, message, "<:3()~~", MB_OK);
    return 1;
  }
}

// Exported function to display a frog message box
extern "C" {
  __declspec(dllexport) int _cdecl Frog(LPCTSTR message) {
    MessageBox(NULL, message, "8)~", MB_OK);
    return 1;
  }
}

// Exported function to display a bird message box
extern "C" {
  __declspec(dllexport) int _cdecl Bird(LPCTSTR message) {
    MessageBox(NULL, message, "<(-)", MB_OK);
    return 1;
  }
}