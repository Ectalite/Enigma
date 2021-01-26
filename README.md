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
- GCC, GTK and pkg-config Packages:
```
pacman -Sy pkg-config mingw-w64-x86_64-gcc mingw-w64-x86_64-gtk3
```
#### 2.Compilation
Go to the main.c path and execute:
```
x86_64-w64-mingw32-gcc.exe main.c `pkg-config.exe --cflags --libs gtk+-3.0`
```
#### 3.Run
Run the `a.exe`.

======
### <a name="macos"></a>MacOS
---
#### 1.Prerequisite 
- Xcode
- [Homebrew](https://brew.sh)
- GTK package for MacOS (inside MacOS terminal)
```
brew install gtk+3
```
#### 2.Compilation (for other projects using GTK)
 - Set up compiler flags: 
 ```
 pkg-config --cflags gtk+-3.0
 ```
 - Add the result to Other C Flags of Xcode target's Build Settings.
 - Set up linker flags:
 ```
 pkg-config --libs gtk+-3.0
 ```
 - Add the result to Other Linker Flags.
#### 3.Run
Xcode should start automaticaly the program.

======
### <a name="linux"></a>Linux
---
#### 1.Prerequisite 
- [GTK](https://www.gtk.org) 
- GCC
- pkg-config
#### 2.Compilation
```
gcc main.c `pkg-config.exe --cflags --libs gtk+-3.0`
```
#### 3.Run
Run the program a.out
