#include <Windows.h>
#include <stdio.h>
#define PATH L"kr_dll.dll"
#define A 2
#define B 95
#define C 5
typedef int(_cdecl* Pr_chislo)(int a, int b);
typedef int(_cdecl* Pr_chislo_potok)(int a, int b, int c);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	HINSTANCE DLL;
	if ((DLL = LoadLibrary(PATH)) == NULL) return 1;
	Pr_chislo pr_chislo = (Pr_chislo)GetProcAddress(DLL, "pr_chislo");
	Pr_chislo_potok pr_chislo_potok = (Pr_chislo_potok)GetProcAddress(DLL, "pr_chislo_potok");
	pr_chislo(A, B);
	pr_chislo_potok(A, B, C);
	FreeLibrary(DLL);
	return 0;
}