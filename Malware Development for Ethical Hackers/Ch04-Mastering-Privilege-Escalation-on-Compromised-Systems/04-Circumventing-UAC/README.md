# Compile the code
```bash
x86_64-w64-mingw32-g++ -O2 hack.c -o hack.exe -I/usr/share/mingw-w64/include/ -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc -fpermissive
```
![](./screenshots/01.png) <br>

```
reg query "HKCU\Software\Classes\ms-settings\Shell\open\command"
```

```
whoami /priv
```
![](./screenshots/02.png) <br>
![](./screenshots/03.png) <br>

Execute `hack.exe`. <br>

![](./screenshots/04.png) <br>
![](./screenshots/05.png) <br>

Now, if we check the process hacker, we can see the poped `cmd.exe` is elevated. <br>
![](./screenshots/06.png) <br>
![](./screenshots/07.png) <br>

---
# References
- Book - [Malware Development for Ethical Hackers: Learn how to develop various types of malware to strengthen cybersecurity](https://www.packtpub.com/en-us/product/malware-development-for-ethical-hackers-9781801810173) By
Zhassulan Zhussupov, 2024
- [Source code - hack.c](https://github.com/PacktPublishing/Malware-Development-for-Ethical-Hackers/blob/main/chapter04/04-uac-bypass/hack.c)

- [MITRE ATT&CK - Privilege Escalation](https://attack.mitre.org/tactics/TA0004/)
