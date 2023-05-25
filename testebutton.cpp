#include <Windows.h>

int main(int argc, int CHAR, int argv[])
{
    MSG msg;
    //if you add WS_CHILD flag,CreateWindow will fail because there is no parent window.
    HWND hWnd = CreateWindow(TEXT("button"), TEXT("Easy"), WS_VISIBLE | WS_POPUP,
        100, 500, 800, 25, NULL, NULL, NULL,  NULL);

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    while (GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    
}
