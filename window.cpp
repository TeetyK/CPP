// #ifndef UNICODE
// #define UNICODE
// #endif
// #ifndef _UNICODE
// #define _UNICODE
// #endif
// #define WIN32_LEAN_AND_MEAN
#define _WIN32_IE 0x0300
// #define STRSAFE_LIB
#include <windows.h>
#include <windowsx.h>
#include <iostream>
#include <commctrl.h>
#include <winuser.h>
#include <wchar.h>
#include <cwchar>
#include <Lmcons.h>
#include <initguid.h>
#include <shlobj.h>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE MAX_PATH
#define ID_CENTER_WINDOW 1
#define HELLO 1
#define CHANGE_NAME 2
#define TEST 3
#define MEMORY_CHECK 4
#define DISK_SPACE 5
#define CPU_SPEED 6
#define WINDOW_TEST 7
#define FLASH_W 8
#define IDM_VIEW_STB 9
//define mode tabs
#define MODE_Q 10
#define MODE_W 11
#define MODE_E 12
//
#define DIALOG_NEW 13
#define FILE_NEW 14
#define NOTHING 0
//#################
using namespace std;
class set_win{
    public:
        int width;
        int height;
        
        set_win();
};
set_win::set_win(){

}
HWND text_f;HWND HEdit;HINSTANCE hInst;HWND hTab;
HWND hwndstatic1,hwndstatic2;
HWND ghSb;HMENU ghMenu;
HMENU hRatio;
// wostringstream wss;

void check_version_window();
void Add_Menu(HWND hwnd);
void Main_page(HWND hwnd);
void Tab_menu(HWND hwnd);
void set_center(HWND hwwnd);
void RegisterRedPanelClass();
void RegisterBluePanelClass();
void Set_panel_class(HWND hwnd);
void CreateLabels(HWND hwnd);
void Pos_screen(HWND hwnd);
void PopMenu(HWND hwnd,LPARAM lParam);
void Flash_window(HWND hwnd);
LRESULT CALLBACK PanelProc(HWND hwnd,UINT msg ,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK DialogProc(HWND hwnd,UINT msg , WPARAM wParam , LPARAM lParam);
void CreateDialogBox(HWND);
void RegisterDialogClass(HWND);
LRESULT CALLBACK ColorProc(HWND,UINT,WPARAM,LPARAM);
void  RegisterColor(void);
COLORREF ShowColorDialog(HWND);
COLORREF gColor = RGB(255,255,255); // WHITE 
void OpenDialog(HWND);
void LoadFile(LPSTR);
HBITMAP hBitmap;
const char g_szClassName[] = "myWindowClass";
// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            {
                if(MessageBox(hwnd,TEXT("Really quit ?"),TEXT("[Quit]"),MB_OKCANCEL) == IDOK){
                    cout << "Window exit is OK." << endl;
                    DestroyWindow(hwnd);
                }else{
                    cout << "Window exit is cancel." << endl;
                }
            }
        break;
        case WM_DESTROY:
            {
                UnregisterHotKey(hwnd,ID_CENTER_WINDOW);
                PostQuitMessage(0);

            }
        break;
        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hwnd, &ps);
                HBRUSH Color_auqa_low = CreateSolidBrush(RGB(204,255,255));
                FillRect(hdc,&ps.rcPaint,Color_auqa_low);
                EndPaint(hwnd, &ps);
            }
        break;
        case WM_SIZE:
            {
                int width = LOWORD(lParam);
                int height = HIWORD(lParam);
                cout << "width :" << width << endl;
                cout << "height :" << height << endl;
            }
        break;
        case WM_CREATE:
            {
                RegisterHotKey(hwnd,ID_CENTER_WINDOW,MOD_CONTROL,0x43);  // CONTROL + C
                Set_panel_class(hwnd);
                Tab_menu(hwnd);
                Add_Menu(hwnd);
                Main_page(hwnd);
                CreateLabels(hwnd);
                Flash_window(hwnd);
            }
        break;
        case WM_COMMAND:
            {
                switch (wParam)
                {
                    case HELLO:
                    {
                        MessageBox(NULL,TEXT("Hello"),TEXT("Greething"),MB_OK);
                        // cout << "Hello" << endl;
                    }
                    break;
                    case CHANGE_NAME:
                    {
                        char *text =(char*) malloc(sizeof(char) * 100);
                        GetWindowText(HEdit, text, 100);
                        SetWindowText(text_f, text);
                        cout << text << endl;
                    }
                    break;
                    case TEST:
                    {
                        int x = GetSystemMetrics(SM_CXSCREEN);
                        int y = GetSystemMetrics(SM_CYSCREEN);
                        cout << "Screen size : " << x << "x" << y << endl;
                        // int r = LockWorkStation(); // lock screen to workstation
                        // if(r == 0)
                        // {
                        //     cout << "Failed" << GetLastError() << endl;
                        // } 
                        wchar_t computerName[MAX_COMPUTERNAME_LENGTH + 1];
                        DWORD size = sizeof(computerName) / sizeof(computerName[0]);
                        int r = GetComputerNameW(computerName,&size);
                        wcout << "Computer Name : " << computerName << endl;
                        wchar_t username[UNLEN+1];
                        DWORD len = sizeof(username) / sizeof(wchar_t);
                        int get_user = GetUserNameW(username,&len);
                        wcout << "UserName : " << username << endl;

                        wchar_t buf[BUFSIZE];
                        DWORD dir_here = SetCurrentDirectoryW(NULL);
                        dir_here = GetCurrentDirectoryW(BUFSIZE,buf);
                        wcout << "Current directroy is : " << buf << endl;
                        check_version_window();
                        // wchar_t LogicalDrives[MAX_PATH] = {0};
                        // DWORD get_Drive = GetLogicalDriveStringsW(MAX_PATH,LogicalDrives);
                        // if(get_Drive > 0 && get_Drive <= MAX_PATH){
                        //     wchar_t *SingleDrive = LogicalDrives;
                        //     while(*SingleDrive){
                        //         wcout << SingleDrive << endl;
                        //         SingleDrive += wcslen(SingleDrive) + 1;
                        //     }
                        // }




                    }
                    break;
                    case MEMORY_CHECK:
                        {
                            MEMORYSTATUSEX mem = {0};
                            mem.dwLength = sizeof(mem);
                            int mem_check = GlobalMemoryStatusEx(&mem);
                            if(mem_check == 0){cout << "Failed to memory status." << endl; return 1;}
                            wcout << "Memory in use : " << mem.dwMemoryLoad << " percent." << endl;
                            wcout << "Total physical memory : " << mem.ullTotalPhys << endl;
                            wcout << "Free physical memory : " << mem.ullAvailPhys << endl;
                            wcout << "Total virtual memory : " << mem.ullTotalVirtual << endl;
                            wcout << "Free virtual memory : " << mem.ullAvailVirtual << endl;
                            
                        }
                    break;
                    case DISK_SPACE:
                        {
                            unsigned __int64 freecall,total,free;
                            int get_disk = GetDiskFreeSpaceExW(L"C:\\",(PULARGE_INTEGER) &freecall,(PULARGE_INTEGER) &total,(PULARGE_INTEGER) &free);
                            wcout << "Available space to caller : " << freecall / (1024*1024) << endl;
                            wcout << "Total space : " << total / (1024*1024) << endl;
                            wcout << "Free space on drive : " << free / (1024*1024) << endl;
                        }
                    break;
                    case CPU_SPEED:
                        {
                            DWORD BufSize_CPU = MAX_PATH;
                            DWORD mhz = MAX_PATH;
                            HKEY key;
                            long Check_cpu = RegOpenKeyExW(HKEY_LOCAL_MACHINE,L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",0,KEY_READ,&key);
                            if( Check_cpu != ERROR_SUCCESS ){ cout << "Failed to RegOpenKeyExW()" << endl;}
                            Check_cpu = RegQueryValueExW(key,L"~MHz",NULL,NULL,(LPBYTE) &mhz,&BufSize_CPU);
                            wcout << "CPU speed : " << mhz << " MHZ" << endl;
                            Check_cpu = RegCloseKey(key);
                            if( Check_cpu != ERROR_SUCCESS){ wcout << "Failed to close registry handle" << endl; return 1;}
                        }
                    break;
                    case WINDOW_TEST:
                        {
                            RegisterColor();
                            HWND hwndcolor;
                            hwndcolor = CreateWindow(TEXT("COLOR"),NULL,WS_CHILD | WS_VISIBLE, 20,30,80,80,hwnd,(HMENU) 1,NULL,NULL);
                            gColor = ShowColorDialog(hwnd);
                            InvalidateRect(hwndcolor,NULL,TRUE);
                        }
                    break;
                    case FLASH_W:
                        {   
                            FLASHWINFO fwi;
                            fwi.cbSize = sizeof(fwi);
                            fwi.dwFlags = FLASHW_ALL;
                            fwi.dwTimeout = 0;
                            fwi.hwnd = hwnd;
                            fwi.uCount = 4;
                            FlashWindowEx(&fwi);
                        }
                    break;
                    case IDM_VIEW_STB:
                        {
                            UINT state;
                            state = GetMenuState(ghMenu,IDM_VIEW_STB,MF_BYCOMMAND);
                            if(state == MF_CHECKED) {
                                ShowWindow(ghSb,SW_HIDE);
                                CheckMenuItem(ghMenu,IDM_VIEW_STB,MF_UNCHECKED);
                            }else{
                                ShowWindow(ghSb,SW_SHOWNA);
                                CheckMenuItem(ghMenu,IDM_VIEW_STB,MF_CHECKED);
                            }
                        }
                    break;
                    case MODE_Q:
                        {
                            CheckMenuRadioItem(hRatio,MODE_Q,MODE_E,MODE_Q,MF_BYCOMMAND);
                            MessageBeep(MB_ICONERROR);
                        }
                    break;
                    case MODE_W:
                        {
                            CheckMenuRadioItem(hRatio,MODE_Q,MODE_E,MODE_W,MF_BYCOMMAND);
                            MessageBeep(0xFFFFFFFF);
                        }
                    break;
                    case MODE_E:
                        {
                            CheckMenuRadioItem(hRatio,MODE_Q,MODE_E,MODE_E,MF_BYCOMMAND);
                            MessageBeep(MB_ICONWARNING);
                        }
                    break;
                    case DIALOG_NEW:
                        {
                            RegisterDialogClass(hwnd);
                            CreateDialogBox(hwnd);
                        }
                    break;
                    case FILE_NEW:
                        {
                            OpenDialog(hwnd);
                        }
                    break;
                    default:
                    break;
                }   
            }
        break;
        case WM_MOUSEWHEEL:
            {
                POINT pt;
                pt.x = GET_X_LPARAM(lParam);
                pt.y = GET_Y_LPARAM(lParam);
                ScreenToClient(hwnd,&pt);
                cout << "x = " << pt.x << " , y =" << pt.y << endl;
            }
        break;
        case WM_NOTIFY:
            {
                switch (lParam)
                {
                    case TCN_SELCHANGE:
                        {

                        }
                    break;
                    default:
                    break;
                }
            }
        break;
        case WM_HOTKEY:
            {
                if((wParam) == ID_CENTER_WINDOW){
                    set_center(hwnd);
                }
            }
        break;
        case WM_KEYDOWN:
            {
                if(wParam == VK_ESCAPE)
                {
                    int ret = MessageBoxW(hwnd,L"Are you sure to quit?",L"Message",MB_OKCANCEL);
                    if(ret == IDOK){
                        SendMessage(hwnd,WM_CLOSE,0,0);
                    }
                }
            }
        break;
        case WM_MOVE:
            {
                Pos_screen(hwnd);
            }
        break;
        case WM_RBUTTONUP:
            {
                PopMenu(hwnd,lParam);
            }
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    set_win Set_window;
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    
    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        TEXT("Windows title"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,500,600,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Step 3: The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}
void Add_Menu(HWND hwnd){
    HMENU hMenu = CreateMenu();
    HMENU hMenuSub = CreateMenu();
     
    hRatio = CreateMenu();

    AppendMenu(hMenuSub,MF_POPUP,HELLO,TEXT("Hello"));
    AppendMenu(hMenuSub,MF_POPUP,TEST,TEXT("Test Command"));
    AppendMenu(hMenuSub,MF_POPUP,MEMORY_CHECK,TEXT("Check MEMORY"));
    AppendMenu(hMenuSub,MF_POPUP,DISK_SPACE,TEXT("Disk_SPACE"));
    AppendMenu(hMenuSub,MF_POPUP,CPU_SPEED,TEXT("CPU_SPEED"));
    AppendMenu(hMenuSub,MF_POPUP,WINDOW_TEST,TEXT("COLOR"));
    
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hMenuSub,TEXT("List_Command"));

    ghMenu =CreateMenu();

    AppendMenu(ghMenu,MF_STRING,IDM_VIEW_STB,TEXT("StatusBar"));
    CheckMenuItem(ghMenu,IDM_VIEW_STB,MF_CHECKED);

    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)ghMenu,TEXT("View"));
    InitCommonControls();
    ghSb = CreateWindowExW(0,STATUSCLASSNAMEW,NULL,
                        WS_CHILD|WS_VISIBLE,0,0,0,0,hwnd,(HMENU)1,GetModuleHandle(NULL),NULL);


    AppendMenu(hRatio,MF_STRING,MODE_Q,TEXT("MODE Q"));
    AppendMenu(hRatio,MF_STRING,MODE_W,TEXT("MODE W"));
    AppendMenu(hRatio,MF_STRING,MODE_E,TEXT("MODE E"));
    CheckMenuRadioItem(hRatio,MODE_Q,MODE_E,MODE_Q,MF_BYCOMMAND);

    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hRatio,TEXT("Ratio"));

    AppendMenu(hMenu,MF_STRING,DIALOG_NEW,TEXT("Dialog"));
    AppendMenu(hMenu,MF_STRING,FILE_NEW,TEXT("File New"));

    SetMenu(hwnd, hMenu);
}
void Main_page(HWND hwnd){
    text_f = CreateWindow(TEXT("static"),TEXT("YOUR NAME"),WS_VISIBLE | WS_CHILD,150,50,150,40,hwnd,NULL,NULL,NULL);
    HEdit = CreateWindow(TEXT("Edit"),TEXT(".."),WS_VISIBLE | WS_CHILD | SS_CENTER | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 150, 90, 150, 50,hwnd,NULL,NULL,NULL);
    CreateWindow(TEXT("Button"),TEXT("ENTER"),WS_VISIBLE | WS_CHILD ,150,150,100,50,hwnd,(HMENU) CHANGE_NAME ,NULL,NULL);

}
void Tab_menu(HWND hwnd){
    RECT rcClient;
    // HWND hTab;
    TCITEM t_item;
    INITCOMMONCONTROLSEX icex;
    int i;
    TCHAR achtemp[256];
    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC = ICC_TAB_CLASSES;
    InitCommonControlsEx(&icex);

    GetClientRect(hwnd,&rcClient);
    hTab = CreateWindow(
        WC_TABCONTROL,TEXT(""),WS_CHILD | WS_VISIBLE,
        0,0,500,30,hwnd,NULL,hInst,NULL
    );
    if(hTab == NULL)
    {
        return;
    }
    t_item.mask = TCIF_TEXT | TCIF_IMAGE;
    t_item.iImage = -1;
    t_item.pszText = (char*)TEXT("First");    
    TabCtrl_InsertItem(hTab,0,&t_item);
    t_item.pszText = (char*)TEXT("Second");    
    TabCtrl_InsertItem(hTab,1,&t_item);
    t_item.pszText = (char*)TEXT("Third");    
    TabCtrl_InsertItem(hTab,2,&t_item);

    
}
void check_version_window(){
    // OSVERSIONINFOEX windowVs;
    // ZeroMemory(&windowVs,sizeof(OSVERSIONINFOEX));
    // windowVs.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    // GetVersionEx( (LPOSVERSIONINFO) &windowVs );
    // cout << "Windows version : " << windowVs.dwMajorVersion << "." << windowVs.dwMinorVersion << endl; 
    DWORD dwVersion = 0;
    DWORD dwMajorVersion = 0;
    DWORD dwMinorVersion = 0;
    DWORD dwBuild = 0;
    
    dwVersion = GetVersion();
    dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));
    if(dwVersion < 0x80000000){ dwBuild = (DWORD)(HIWORD(dwVersion)); }
    cout << "WindowsOS version : " << dwMajorVersion << "." << dwMinorVersion << ":" << dwBuild << endl; 
}
void set_center(HWND hwnd){
    RECT set_ps ={0};
    GetWindowRect(hwnd,&set_ps);
    int win_w = set_ps.right- set_ps.left;
    int win_h = set_ps.bottom- set_ps.top;

    int screen_w = GetSystemMetrics(SM_CXSCREEN);
    int screen_h = GetSystemMetrics(SM_CYSCREEN);

    SetWindowPos(hwnd,HWND_TOP,(screen_w - win_w) / 2 , (screen_h - win_h) / 2,0,0,SWP_NOSIZE);


}
LRESULT CALLBACK PanelProc(HWND hwnd,UINT msg,WPARAM wParam, LPARAM lParam){
    switch(msg)
    {
        case WM_LBUTTONUP:
            {
                MessageBeep(MB_OK);
            }
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);

    }
    return 0;
}
void RegisterRedPanelClass(){
    HBRUSH hbrush = CreateSolidBrush(RGB(255,0,0));
    WNDCLASSW rwc = {0};
    rwc.lpszClassName =L"RedPanelClass";
    rwc.hbrBackground = hbrush;
    rwc.lpfnWndProc = PanelProc;
    rwc.hCursor = LoadCursor(0,IDC_ARROW);
    RegisterClassW(&rwc);
}
void RegisterBluePanelClass(){
    HBRUSH hbrush = CreateSolidBrush(RGB(0,0,255));
    WNDCLASSW rwc = {0};
    rwc.lpszClassName =L"BluePanelClass";
    rwc.hbrBackground = hbrush;
    rwc.lpfnWndProc = PanelProc;
    rwc.hCursor = LoadCursor(0,IDC_ARROW);
    RegisterClassW(&rwc);
}
void Set_panel_class(HWND hwnd){
    RegisterRedPanelClass();
    CreateWindowW(L"RedPanelClass",NULL,WS_CHILD |  WS_VISIBLE ,20,600,80,80,hwnd,(HMENU)1,NULL,NULL);
    RegisterBluePanelClass();
    CreateWindowW(L"BluePanelClass",NULL,WS_CHILD |  WS_VISIBLE ,120,600,80,80,hwnd,(HMENU)2,NULL,NULL);
}
void CreateLabels(HWND hwnd){
    CreateWindow(TEXT("static"),TEXT("x: "),WS_CHILD | WS_VISIBLE,100,270,25,25,hwnd,(HMENU) 1 ,NULL,NULL);
    hwndstatic1 = CreateWindowW(L"static",L"0",WS_CHILD | WS_VISIBLE,120,270,25,25,hwnd,(HMENU) 2 ,NULL,NULL);
    CreateWindow(TEXT("static"),TEXT("y: "),WS_CHILD | WS_VISIBLE,100,300,25,25,hwnd,(HMENU) 3 ,NULL,NULL);
    hwndstatic2 = CreateWindowW(L"static",L"0",WS_CHILD | WS_VISIBLE,120,300,25,25,hwnd,(HMENU) 4 ,NULL,NULL);
}
void Pos_screen(HWND hwnd){
    char buf_text[100];RECT rect_1;
    GetWindowRect(hwnd,&rect_1);
    // Problem convert int to string assign to buf_text #clear :D
    long long int value = rect_1.left;
    sprintf(buf_text,"%ld",value);
    SetWindowText(hwndstatic1,buf_text);
    value = rect_1.top;
    sprintf(buf_text,"%d",value);
    SetWindowText(hwndstatic2,buf_text);
}
void Flash_window(HWND hwnd){
    CreateWindow(TEXT("Button"),TEXT("Flash"),WS_CHILD | WS_VISIBLE,300,150,100,50,hwnd,(HMENU)FLASH_W,NULL,NULL);
    hBitmap = (HBITMAP)LoadImage(NULL,TEXT("D:\\Code\\I\\cpp\\123.png"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    
    HWND hsti;
    hsti = CreateWindow(TEXT("static"),TEXT(""),WS_CHILD | WS_VISIBLE | SS_BITMAP,
    100,250,200,200,hwnd,(HMENU) 1, NULL,NULL);
    SendMessage(hsti,STM_SETIMAGE,(WPARAM) IMAGE_BITMAP,(LPARAM) hBitmap);

    CreateWindow(TEXT("button"),TEXT("BoxCheck"),WS_VISIBLE | WS_CHILD | BS_CHECKBOX,20,50,100,60,hwnd,NOTHING, NULL,NULL);

}
void PopMenu(HWND hwnd,LPARAM lParam){
    HMENU hMenuR;
    POINT point_R;
    point_R.x = LOWORD(lParam);
    point_R.y = HIWORD(lParam);
    hMenuR = CreatePopupMenu();
    ClientToScreen(hwnd,&point_R);
    
    AppendMenu(hMenuR,MF_STRING,0,TEXT("Refresh"));

    TrackPopupMenu(hMenuR,TPM_RIGHTBUTTON,point_R.x,point_R.y,0,hwnd,NULL);

    DestroyMenu(hMenuR);


}
LRESULT CALLBACK DialogProc(HWND hwnd,UINT msg , WPARAM wParam , LPARAM lParam){
    switch(msg){
        case WM_CREATE:
            {
                CreateWindow(TEXT("Button"),TEXT("OK"),WS_VISIBLE | WS_CHILD ,
                50,50,80,25,hwnd,(HMENU) 1,NULL,NULL);
            }
        break;
        case WM_COMMAND:
            {
                switch(wParam){

                    case 1:
                        {
                            DestroyWindow(hwnd);
                        }
                    break;
                    default:
                        return 0;
                }
            }
        break;
        case WM_CLOSE:
            {
                DestroyWindow(hwnd);
            }
        break;
        default:
            return DefWindowProc(hwnd,msg,wParam,lParam);
    }
    return 0;
}
void CreateDialogBox(HWND hwnd){
    CreateWindowEx(WS_EX_DLGMODALFRAME | WS_EX_TOPMOST,TEXT("DialogClass"),TEXT("Dialog Box"),WS_VISIBLE | WS_SYSMENU | WS_CAPTION,
    200,200,200,150,NULL,NULL,hInst,NULL);
}
void RegisterDialogClass(HWND hwnd){
    WNDCLASSEX dialog{0};
    dialog.cbSize = sizeof(WNDCLASSEX);
    dialog.lpfnWndProc = &DialogProc;
    dialog.hInstance = hInst;
    dialog.hbrBackground = (HBRUSH)COLOR_WINDOW;
    // dialog.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    dialog.lpszClassName = TEXT("DialogClass");
    dialog.hCursor = LoadCursor(NULL, IDC_CROSS);
    dialog.cbClsExtra = 0;
    dialog.cbWndExtra = 0;
    RegisterClassEx(&dialog);
    
}
void RegisterColor(void){
    WNDCLASS colorS{0};
    colorS.lpszClassName = TEXT("Color");
    colorS.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    colorS.lpfnWndProc = ColorProc;
    RegisterClass(&colorS);
}
LRESULT CALLBACK ColorProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam){
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;
    switch(msg){
        case WM_PAINT:
            {
                GetClientRect(hwnd,&rect);
                hdc = BeginPaint(hwnd,&ps);
                SetBkColor(hdc,gColor);
            }
        break;
        default:
            return DefWindowProc(hwnd,msg,wParam,lParam);
    }
}
COLORREF ShowColorDialog(HWND hwnd){
    CHOOSECOLOR cc;
    static COLORREF crCustClr[16];
    ZeroMemory(&cc,sizeof(cc));
    cc.lStructSize = sizeof(cc);
    cc.hwndOwner = hwnd;
    cc.lpCustColors = (LPDWORD) crCustClr;
    cc.rgbResult = RGB(0,255,0);
    cc.Flags = CC_FULLOPEN | CC_RGBINIT;
    ChooseColor(&cc);
    return cc.rgbResult;
}
void OpenDialog(HWND hwnd){
    OPENFILENAME ofn;
    TCHAR szFile[MAX_PATH];
    ZeroMemory(&ofn,sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = '\0';
    ofn.hwndOwner = hwnd;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = TEXT("All files(*.*)\0*.*\0");
    ofn.nFilterIndex = 1;
    ofn.lpstrInitialDir =NULL;
    ofn.lpstrFileTitle = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    if(GetOpenFileName(&ofn)){ LoadFile(ofn.lpstrFile);}
}
void LoadFile(LPSTR file){
    HANDLE hFile;
    DWORD dwSize;
    DWORD dw;
    LPBYTE lpBuffer = NULL;
    hFile = CreateFile(file,GENERIC_READ,0,NULL,OPEN_EXISTING,0,NULL);
    dwSize = GetFileSize(hFile,NULL);
    lpBuffer = (LPBYTE) HeapAlloc(GetProcessHeap(),HEAP_GENERATE_EXCEPTIONS,dwSize + 1);
    ReadFile(hFile,(LPWSTR)lpBuffer,dwSize,&dw,NULL);
    CloseHandle(hFile);
    lpBuffer[dwSize] = 0;
    SetWindowText(text_f,(LPSTR)lpBuffer);
    HeapFree(GetProcessHeap(),0,lpBuffer);
}