# RS2 Client 377 Library

MSVC C++17 RuneScape 2 (revision 377) client library for use with [UnrealRS2](https://github.com/UnrealRS2/UnrealRS2).

## Overview

This library is a modernized build of the classic RuneScape 2 client core that  

- ✅ Provides UI framebuffer to UnrealRS
- ✅ Provides a scene graph to UnrealRS

---
Unlike traditional approaches that attempt to convert models or reimplement game logic, this library keeps the pipeline clean:
- ✅ No need to convert assets.
- ✅ No need for unreal to reimplement rendering logic.
- ✅ Resolution and graphical improvements are still possible on the Unreal side.

This gives the best of both worlds: original client logic preserved, but with the potential for modern rendering enhancements.

## Requirements

- **Visual Studio 2022** or **CLion** (MSVC toolchain, C++17).
- [Boost 1.89.0](https://www.boost.org/releases/latest/) (put in C:/libs/boost_1_89_0)
- [CMake](https://cmake.org/) for building.
- Windows x64 (tested).
