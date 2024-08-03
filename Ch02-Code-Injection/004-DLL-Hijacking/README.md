# 1. Find the Vulnerable `.dll` File
Use [procmon](https://learn.microsoft.com/en-us/sysinternals/downloads/procmon) to find the vulnerable `.dll` file.

### Filter Settings
Create the following 3 conditions
![procmon](./screenshots/02.png)

Then execute [Bginfo.exe](https://learn.microsoft.com/en-us/sysinternals/downloads/bginfo).

![Bginfo.exe](./screenshots/03.png)

I tried one or several `.dll` files in the folder of `C:\User\user\Desktop\BGinfo` at the same time, but none of them worked. Eventually, I found on `.dll` file `rps

![rpcss.exe](./screenshots/01.png)
