#include <assert.h>
#include <stdio.h>
#include "mylib.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int wmain(int argc, wchar_t** argv)
{
    myfunc();
    myfunc64();
    printf("main\n");
    HMODULE hModule = LoadLibraryW(L"libmylib.dll");
    assert(hModule);
    FARPROC myfuncptr = GetProcAddress(hModule, "myfunc");
    assert(myfuncptr);
    myfuncptr();
    FARPROC myfuncptr64 = GetProcAddress(hModule, "myfunc64");
    assert(myfuncptr64);
    myfuncptr64();
    return 0;
}
