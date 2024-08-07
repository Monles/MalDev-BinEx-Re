# What's NtTestAlert?
This discussion aims to demonstrate the execution of shellcode within an officially undocumented Native API known as `NtTestAlert` (Zhussupov, 2024).

The `NtTestAlert` system call is an integral part of the Windows operating system's alerting mechanism. When invoked, this system function can trigger the execution of any pending `Asynchronous Procedure Calls` (APCs) associated with the thread. Before a thread begins execution at its Win32 start address, it calls `NtTestAlert` to handle any pending `APCs` (Zhussupov, 2024).

# API Hooking
`API hooking` is a technique used to manipulate and modify the functionality and sequence of `API calls`. This method is commonly employed by antivirus (AV) solutions to detect and analyze potentially malicious code. By intercepting `API calls`, AV software can monitor and control the behavior of applications, identifying suspicious or harmful activitie (Zhussupov, 2024).

# Steps
## 1.
```bash
x86_64-w64-mingw32-g++ -O2 cat.c -o cat.exe -mconsole -I/usr/share/mingw-w64/include/ -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc -fpermissive
```



---

# References
- cocomelonc (2024) [Malware-Development-for-Ethical-Hackers/chapter02/03-apc-injection
](https://github.com/PacktPublishing/Malware-Development-for-Ethical-Hackers/blob/main/chapter02/03-apc-injection/hack2.c). GitHub Repository.
- Zhassulan Zhussupov (2024) Chapter 2: Exploring Various Malware Injection Attacks. [Malware Development for Ethical Hackers: Learn how to develop various types of malware to strengthen cybersecurity](https://www.packtpub.com/en-gb/product/malware-development-for-ethical-hackers-9781801810173)