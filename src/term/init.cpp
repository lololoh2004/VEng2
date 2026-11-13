#include "veng/term.hpp"

#ifdef _WIN32
    #include <windows.h>
#endif



void termInit(){
#ifdef _WIN32
    printf("[TERM] Enter terminal init..\n - Your term : ");
    if (getenv("WT_SESSION") != NULL) {
        printf("\033[1;32mWindows Terminal\033[0m\n");
        return;
    }

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!hOut) return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) return;

    printf("\033[1;32mWindows Legacy CMD\033[0m\n");
#endif
}
