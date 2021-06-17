#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
using namespace std;

void usleep(__int64 usec) {
    HANDLE timer;
    LARGE_INTEGER ft;
    ft.QuadPart = -(10 * usec);
    timer = CreateWaitableTimer(NULL, TRUE, NULL);
    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
    WaitForSingleObject(timer, INFINITE);
    CloseHandle(timer);
}

POINT p;
string input1;
string input2;
int key;
int mode;
int for_length;

int main() {
    system("title Yeetclicker: Setup");
    cout << "Hex Keycode? (https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes)\n> ";
    cin >> input1;
    cout << "\nMode?\n1: Jitterclicking (~10cps)\n2: Butterfly (~14cps)\n3: Dragging (~12cps)\n4: Obvious Cheating (cps maximum to what your processor can handle.)\n> ";
    cin >> input2;
    try {
        mode = stoi(input2);
        transform(input1.begin(), input1.end(), input1.begin(), ::toupper);
        key = stoi(input1, 0, 16);
    } catch (const std::exception&) {
        cout << "Invalid input.\n";
        system("pause");
        return 0;
    }
    switch (mode) {
        case 1:
            cout << "Jitterclicking selected.\n";
            system("title Yeetclicker: Jitterclicking");
            while (true) {
                Sleep(100);
                if (GetAsyncKeyState(key)) {
                    while (GetAsyncKeyState(key)) {
                        if (GetCursorPos(&p)) {
                            usleep(static_cast<int>(rand() % 10 + 1) * 7000);
                            mouse_event(MOUSEEVENTF_LEFTDOWN, p.x, p.y, 0, 0);
                            usleep(static_cast<int>(rand() % 10 + 1) * 7000);
                            mouse_event(MOUSEEVENTF_LEFTUP, p.x, p.y, 0, 0);
                        }
                    }
                }
            }
            break;
    case 2:
        cout << "Butterfly selected.\n";
        system("title Yeetclicker: Butterfly");
        while (true) {
            Sleep(100);
            if (GetAsyncKeyState(key)) {
                while (GetAsyncKeyState(key)) {
                    if (GetCursorPos(&p)) {
                         mouse_event(MOUSEEVENTF_LEFTDOWN, p.x, p.y, 0, 0);
                         usleep(static_cast<int>(rand() % 10 + 1) * 1500);
                         mouse_event(MOUSEEVENTF_LEFTUP, p.x, p.y, 0, 0);
                    }
                    if (rand() % 10 + 1 < 8) {
                        if (GetCursorPos(&p)) {
                            usleep(static_cast<int>(rand() % 10 + 1) * 3000);
                            mouse_event(MOUSEEVENTF_LEFTDOWN, p.x, p.y, 0, 0);
                            usleep(static_cast<int>(rand() % 10 + 1) * 1500);
                            mouse_event(MOUSEEVENTF_LEFTUP, p.x, p.y, 0, 0);
                        }
                    }
                    usleep(static_cast<int>(rand() % 10 + 1) * 9000);

                }
            }
        }
        break;
    case 3:
        cout << "Dragging selected.\n";
        system("title Yeetclicker: Dragging");
        while (true) {
            Sleep(100);
            if (GetAsyncKeyState(key)) {
                while (GetAsyncKeyState(key)) {
                    for_length = rand() % 16 + 14;
                    for (size_t i = 0; i < for_length; i++) {
                        if (GetCursorPos(&p)) {
                            usleep(static_cast<int>(rand() % 10 + 1) * 8000);
                            mouse_event(MOUSEEVENTF_LEFTDOWN, p.x, p.y, 0, 0);
                            usleep(static_cast<int>(rand() % 10 + 1) * 1000);
                            mouse_event(MOUSEEVENTF_LEFTUP, p.x, p.y, 0, 0);
                        }
                    }
                    usleep(static_cast<int>(rand() % 10 + 20) * 10000);
                }
            }
        }
        break;
    case 4:
        cout << "Obvious Cheating selected.\n";
        system("title Yeetclicker: Obvious Cheating");
        while (true) {
            Sleep(100);
            if (GetAsyncKeyState(key)) {
                while (GetAsyncKeyState(key)) {
                    if (GetCursorPos(&p)) {
                        mouse_event(MOUSEEVENTF_LEFTDOWN, p.x, p.y, 0, 0);
                        mouse_event(MOUSEEVENTF_LEFTUP, p.x, p.y, 0, 0);
                    }
                }
            }
        }
        break;
    default:
        cout << "Invalid selection.\n";
        system("pause");
        break;
    }
}