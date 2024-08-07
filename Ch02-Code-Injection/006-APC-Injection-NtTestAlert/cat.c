/*
* Malware Development for Ethical Hackers
* cat.cpp
* API hooking example
* author: @cocomelonc
*/

#include <windows.h>
typedef int (__cdecl *CatFunction)(LPCTSTR message);
typedef int (__cdecl *BirdFunction)(LPCTSTR message);

int main(void) {
  HINSTANCE petDll;
  CatFunction catFunction;
  BirdFunction birdFunction;
  BOOL unloadResult;
  petDll = LoadLibrary("pet.dll");

  if (petDll != NULL) {
    catFunction = (CatFunction) GetProcAddress(petDll, "Cat");
    birdFunction = (BirdFunction) GetProcAddress(petDll, "Bird");
    if ((catFunction != NULL) && (birdFunction != NULL)) {
      (catFunction)("meow-meow");
      (catFunction)("mmmmeow");
      (birdFunction)("tweet-tweet");
    }
    unloadResult = FreeLibrary(petDll);
  }
  return 0;
}