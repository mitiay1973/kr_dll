#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
int dd=0;
__declspec(dllimport) int pr_chislo(int a, int b);
int pr_chislo(int a, int b)
{
    int chet = 0;
		int ch = -1;
		for (int i = a; i < b; i++)
		{
			if (i == 1)
				ch = 0;
			for (int d = 2; d * d <= i; d++)
				if (i % d == 0)
				{
					ch = 0;
					break;
				}
			if (ch < 0) ch = 1;
			if (ch)
				chet++;
			ch = -1;
		}
	char* d=calloc(100, sizeof(char));
	sprintf(d, " %d", chet);
	MessageBoxA(NULL, d, "Ответ", NULL);
}
struct Par
{
	int *x;
	int *y;
};
int pr_chislo1(struct Par pr)
{
	int a = pr.x;
	int b = pr.y;
	int chet = 0;
	int ch = -1;
	for (int i = a; i < b; i++)
	{
		if (i == 1)
			ch = 0;
		for (int d = 2; d * d <= i; d++)
			if (i % d == 0)
			{
				ch = 0;
				break;
			}
		if (ch < 0) ch = 1;
		if (ch)
			chet++;
		ch = -1;
	}
	char* d = calloc(100, sizeof(char));
	sprintf(d, " %d", chet);
	dd += chet;
}
__declspec(dllimport) int pr_chislo_potok(int a, int b, int c);
int pr_chislo_potok(int a, int b, int c)
{
	HANDLE hTread[163];
	CRITICAL_SECTION s = { 0 };
	int aa[] = { 0,0,0,0,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 };
	int bb[] = { 0,0,0,0,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 };
	aa[0] = a;
	bb[0] = b/c;
	for (size_t i = 1; i < c; i++)
	{
		aa[i] = bb[i-1] + 1;
		bb[i]= bb[i - 1]+ bb[0];
	}
	struct Par par[163];
	for (size_t i = 0; i < c; i++)
	{
		par[i].x = aa[i];
		par[i].y = bb[i];
	}
	InitializeCriticalSection(&s);
	for (size_t i = 0; i < c; i++)
	{
		EnterCriticalSection(&s);
		hTread[i] = CreateThread(NULL, 0, pr_chislo1,&par[i], NULL, NULL);
		WaitForMultipleObjects(c, hTread, TRUE, INFINITE);
		LeaveCriticalSection(&s);
	}
	DeleteCriticalSection(&s);
	char* ds = calloc(100, sizeof(char));
	sprintf(ds, " %d", dd);
	MessageBoxA(NULL, ds, "Ответ", NULL);
}