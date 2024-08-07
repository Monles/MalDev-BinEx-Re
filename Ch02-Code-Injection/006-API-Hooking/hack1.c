/*
 * Malware Development for Ethical Hackers
 * hack1.c
 * illustration of basic hooking technique
 * author: @cocomelonc
*/
#include <windows.h>

typedef int (__cdecl *OriginalCatFunction)(LPCTSTR message);

// buffer to store the original bytes
char originalBytes[5];

FARPROC hookedFunctionAddress;

// we'll jump here after installing the hook
int __stdcall myModifiedCatFunction(LPCTSTR modifiedMessage) {
  HINSTANCE petDll;
  OriginalCatFunction originalCatFunc;

  // unhook the function: restore the original bytes
  WriteProcessMemory(GetCurrentProcess(), (LPVOID)hookedFunctionAddress, originalBytes, 5, NULL);

  // load the original function and modify the message
  petDll = LoadLibrary("pet.dll");
  originalCatFunc = (OriginalCatFunction)GetProcAddress(petDll, "Cat");

  return (originalCatFunc)("meow-squeak-tweet!!!");
}

// logic for installing the hook
void installMyHook() {
  HINSTANCE hLib;
  VOID *myModifiedFuncAddress;
  DWORD source;
  DWORD destination;
  DWORD relativeOffset;
  CHAR patch[5] = {0};

  // obtain the memory address of the original Cat function
  hLib = LoadLibraryA("pet.dll");
  hookedFunctionAddress = GetProcAddress(hLib, "Cat");

  // save the first 5 bytes into originalBytes buffer
  ReadProcessMemory(GetCurrentProcess(), (LPCVOID)hookedFunctionAddress, originalBytes, 5, NULL);

  // overwrite the first 5 bytes with a jump to myModifiedCatFunction
  myModifiedFuncAddress = &myModifiedCatFunction;

  // calculate the relative offset for the jump
  source = (DWORD)hookedFunctionAddress + 5;
  destination = (DWORD)myModifiedFuncAddress;
  relativeOffset = (DWORD)(destination - source);

  // \xE9 is the opcode for a jump instruction
  patch[0] = 0xE9;
  memcpy(patch + 1, &relativeOffset, 4);

  BOOL result = WriteProcessMemory(GetCurrentProcess(), (LPVOID)hookedFunctionAddress, patch, 5, NULL);
  if (!result) {
      printf("Error: %d\n", GetLastError());
  }
}

int main() {
  HINSTANCE petDll;
  OriginalCatFunction originalCatFunc;

  // load the original Cat function
  petDll = LoadLibrary("pet.dll");
  originalCatFunc = (OriginalCatFunction)GetProcAddress(petDll, "Cat");

  // call the original Cat function
  (originalCatFunc)("meow-meow");

  // install the hook
  installMyHook();

  // call the Cat function after installing the hook
  (originalCatFunc)("meow-meow");
}