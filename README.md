# InsertionSortOnAsm

A small console experiment from December 2021: the same array is sorted once with an
MSVC inline-assembly (x86) loop and once with plain C++, and the program prints how many
processor cycles each version took, measured with the `rdtsc` instruction.

> **Note on the name.** Despite the repository and project names (*insertion sort*,
> `SortVstavkamiOnAssembly`), the code implements **selection sort** in both versions:
> on each pass it finds the minimum of the unsorted part and swaps it to the front.

## Stack

- C++ with MSVC `__asm { … }` inline assembly (32-bit x86 only)
- Visual Studio solution `SortVstavkamiOnAssembly.sln`, platform toolset v142 (Visual Studio 2019)

## Build and run

1. Open `SortVstavkamiOnAssembly.sln` in Visual Studio 2019 or newer with the
   *Desktop development with C++* workload.
2. Select the **x86 (Win32)** platform — MSVC does not support inline `__asm` on x64.
3. Build and run (Ctrl+F5).

Not verified here: these steps were not run, because the project needs Windows and MSVC.

## Usage

The program asks for 10 integers, clears the console (`system("cls")`) and prints both
sorted arrays side by side, then the cycle counts:

```
Enter mass[0]: 5
Enter mass[1]: 3
...
MassAsm[0]: 1		MassC[0]: 1
...
Number of processor cycles for asm: <cycles>
Number of processor cycles for C:   <cycles>
```

The cycle counts depend on the CPU and the run, so no sample numbers are given here.

## Context

A student exercise (2021) comparing hand-written assembly with compiler output.

## License

Public domain — see [LICENSE](LICENSE) (The Unlicense).
