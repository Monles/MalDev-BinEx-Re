# Intro
I will use `Kali Linux` to compile C code with `Clang` & `LLVM`. <br>

### What's Clang?
`Clang` is the front-end that compiles C source code to `LLVM Intermediate Representation` **(IR)**, and LLVM handles the rest, including optimization and code generation.

# 1. Installation of LLVM & Clang
### Linux
In Linux, use this command to install `Clang` & `LLVM`. <br>
```bash
sudo apt-get install clang llvm
```

### Windows
You can find the instructions to get started with the LLVM system. <br>
- Go to the official LLVM releases page.
- Download the pre-built binary for Windows. Look for the "Windows (64-bit)" section and download the installer (usually named something like LLVM-x.x.x-win64.exe).

```
https://llvm.org/docs/GettingStarted.html#checkout
```

Verify the installation. <br>
```bash
clang --version
```

# 2. Comparison

![Rust hello_world.exe](./screenshots/01.png)
