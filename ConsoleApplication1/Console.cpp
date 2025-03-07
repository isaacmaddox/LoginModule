/**
 * Adapted from https://www.geeksforgeeks.org/taking-password-as-input-in-cpp/
 * and https://stackoverflow.com/questions/1413445/reading-a-password-from-stdcin
 */

#include <windows.h>

static void SetStdinEcho(bool enabled = true)
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);

	if (!enabled)
	{
		mode &= ~ENABLE_ECHO_INPUT;
	}
	else
	{
		mode |= ENABLE_ECHO_INPUT;
	}

	SetConsoleMode(hStdin, mode);
}