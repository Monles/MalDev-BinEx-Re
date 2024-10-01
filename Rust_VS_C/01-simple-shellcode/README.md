# C payload
This raw code can spawn a shell

```c
#include <unistd.h>
int main() {
char *args[2];
args[0] = "/bin/sh";
args[1] = NULL;
execve(args[0], args, NULL);
}
```







---
# References
- [Black Hat Rust](https://kerkour.com/black-hat-rust) by 
Sylvain Kerkour

