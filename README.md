# Enigma-CLI is the commande line version of Enigma in C

# Enigma in C
- Projet de premier semestre de Génie Electrique et informatique industrielle.
- First semester's Project of electrical Engineer.
------

## How to run
- Download the [compilled zip archive](https://github.com/Ectalite/Enigma/releases).
- Unzip it. 
- Run `Enigma.exe`.

## How to compile
- [Windows](#windows)
- [MacOS](#macos)
- [Linux](#linux)
### <a name="windows"></a>Windows
---
#### 1.Prerequisite 
- [msys2](https://www.msys2.org)
- GCC Package:
```
pacman -Sy mingw-w64-x86_64-gcc
```
#### 2.Compilation
Go to the main.c path and execute:
```
x86_64-w64-mingw32-gcc.exe main.c
```
#### 3.Run
Run the `a.exe`.

### <a name="macos"></a>MacOS
---
#### 1.Prerequisite 
- Xcode
#### 2.Run
Xcode should start automaticaly the program.

### <a name="linux"></a>Linux
---
#### 1.Prerequisite 
- GCC
#### 2.Compilation
```
gcc main.c
```
#### 3.Run
Run the program a.out
