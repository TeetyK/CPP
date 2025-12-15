#include<Windows.h>
//#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
//#include<istream>
#ifndef UNICODE
#define UNICODE
#endif
#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3
#define HELP_ABOUT 4
#define FILE_MENU_OPTION_GRAPHIC 5
#define CHANGE_TITLE 6
using namespace std;
LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
void AddMenu(HWND hWnd);
void Add_Control(HWND hWnd);
void Load_Image();
HBITMAP  hLogoImage; HWND hLogo;
HMENU hMenu;
HWND hEdit;
HWND POP_SHOW,dialog_WND_MAIN ;
void registerDialogClass(HINSTANCE hInst);
void displayDialog(HWND hWnd);

void display_file(char * path) {
	HANDLE hFile;
	hFile = CreateFile((LPCWSTR)path,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,NULL);
	if (hFile == INVALID_HANDLE_VALUE) { MessageBox(NULL,L"Failed to open file",L"Error", MB_OK); }
	constexpr size_t BUFSIZE = 256;
	char buffer[BUFSIZE];
	DWORD dwBytestoRead = BUFSIZE - 1;
	DWORD dwBytesRead = 0;
	BOOL bRlt = ReadFile(hFile,(void*)buffer,dwBytestoRead,&dwBytesRead,NULL);
	// have a bug is text korea in while to open file text
	// it really write is "Hello There!";
	if (dwBytesRead > 0) {}
		buffer[dwBytesRead] = '\0';
		SetWindowTextW(POP_SHOW,(LPCWSTR)buffer);
	////////////////////////////////////////////////
	CloseHandle(hFile);

}
void open_file(HWND hWnd) {
	OPENFILENAME ofn; 
	wchar_t file_name[MAX_PATH];
	file_name[0] = '\0';
	ZeroMemory(&ofn,sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = (LPWSTR)file_name;
	ofn.lpstrFile[0] = L'\0';
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFilter = L"All file\0*.*\0Source Files\0*.CPP\0*.Text Files\0*.TXT\0";
	ofn.nFilterIndex = 1;
	//ofn.lpstrDefExt =L"txt";
	GetOpenFileName(&ofn);
	MessageBox(NULL, ofn.lpstrFile, L"File Path", MB_OK);
	display_file((char*)file_name);
	
}
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR args , int cmdshow) {
	WNDCLASSW wc = { 0 };
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"Windows Project!";
	wc.lpfnWndProc = WindowProc;
	if (!RegisterClassW(&wc)) {
		return -1;
	}
	registerDialogClass(hInst);
	dialog_WND_MAIN =CreateWindow(L"Windows Project!", L"Windows Project!", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);
	MSG msg = { 0 };
	while (GetMessage(&msg,NULL,NULL,NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
LRESULT CALLBACK WindowProc(HWND hWnd,UINT msg , WPARAM wp , LPARAM lp) {
	int val;
	switch (msg) {
	case WM_COMMAND:
		switch (wp) {
		case FILE_MENU_EXIT: // exit program
			val = MessageBox(hWnd,L"Ara you sure?",L"Wait",MB_YESNO | MB_ICONEXCLAMATION);
			if (val == IDYES) {
			DestroyWindow(hWnd);
			}
			else if (val == IDNO) { /*NONE*/ }
			break;
		case FILE_MENU_NEW:
			MessageBeep(MB_ICONINFORMATION);
			break;
		case FILE_MENU_OPEN:
			open_file(hWnd);
			break;
		case HELP_ABOUT:
			MessageBox(hWnd,L"My Name is : Teety.",L"About me!", MB_OKCANCEL);
			break;
		case FILE_MENU_OPTION_GRAPHIC:
			MessageBox(hWnd,L"NONE",L"GRAPHIC",MB_OK | MB_ICONSTOP);
			break;
		case CHANGE_TITLE:
			wchar_t text[100];
			GetWindowText(hEdit, text,100);
			SetWindowText(hWnd, text);
			//SetWindowText(POP_SHOW,text); // GetWindowText(?? , varible, size) 
			// strcpy(HWND,varible) , strat(HWND,ต่อท้าย) เหมือน string [size] - > |S|T|W|
			//SetWindowText(HWND,varible string)
			break;
		}
		break;
	case WM_CREATE:
		displayDialog(hWnd);
		Load_Image();
		AddMenu(hWnd);
		Add_Control(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd,msg,wp,lp);
	}
}
void AddMenu(HWND hWnd) {
	hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	HMENU hSubMenu = CreateMenu();
	HMENU hOptionMenu = CreateMenu();

	AppendMenu(hOptionMenu, MF_STRING, NULL, L"Settings");
	AppendMenu(hOptionMenu, MF_STRING, NULL, L"Volume");
	AppendMenu(hOptionMenu, MF_STRING, FILE_MENU_OPTION_GRAPHIC, L"Graphic");
	AppendMenu(hSubMenu, MF_STRING, HELP_ABOUT, L"About me!");
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_NEW, L"New");
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_OPEN, L"Open");
	AppendMenu(hFileMenu, MF_STRING, CHANGE_TITLE,L"Change Title");
	AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFileMenu, MF_POPUP, (UINT_PTR)hOptionMenu, L"Option");
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, L"Exit");

	AppendMenu(hMenu, MF_POPUP,(UINT_PTR)hFileMenu,L"File");
	AppendMenu(hMenu, MF_POPUP,(UINT_PTR)hSubMenu, L"Help");
	
	SetMenu(hWnd, hMenu);

}
void Add_Control(HWND hWnd) {
	CreateWindow(L"static",L"TEXT :",WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER ,150,30,150,50,hWnd,NULL,NULL,NULL);
	hEdit = CreateWindow(L"Edit", L"..", WS_VISIBLE | WS_CHILD | SS_CENTER | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 150, 90, 150, 50,hWnd,NULL,NULL,NULL);
	POP_SHOW = CreateWindow(L"Edit",L"SHOW TEXT is writing now.", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER |ES_MULTILINE, 150, 180, 180,250, hWnd, NULL, NULL, NULL);
	CreateWindow(L"Button", L"[Change title]", WS_VISIBLE | WS_CHILD, 5, 250, 100, 50, hWnd,(HMENU)CHANGE_TITLE, NULL, NULL);
	hLogo = CreateWindow(L"static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,350,60,100,100,hWnd,NULL,NULL,NULL);
	SendMessage(hLogo,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hLogoImage);
	
}
void Load_Image() {
	hLogoImage = (HBITMAP)LoadImage(NULL,L"D:\\Code\\TS_WinGui\\windows_gui\\windows_gui\\IconTest.png",IMAGE_BITMAP,100,100,LR_LOADFROMFILE); // .bmp

}
LRESULT CALLBACK DialogProced(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg)
	{
	case WM_COMMAND:
		switch (wp) {
		case 1:
			EnableWindow(dialog_WND_MAIN, true);
			DestroyWindow(hWnd);
			break;
		}
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
}
void registerDialogClass(HINSTANCE hInst) {
	WNDCLASSW dialog_1 = { 0 };
	dialog_1.hbrBackground = (HBRUSH)COLOR_WINDOW;
	dialog_1.hCursor = LoadCursor(NULL, IDC_CROSS);
	dialog_1.hInstance = hInst;
	dialog_1.lpszClassName = L"my dialog class";
	dialog_1.lpfnWndProc = DialogProced;
	RegisterClass(&dialog_1);

}
void displayDialog(HWND hWnd) {
	HWND hDlg =  CreateWindow(L"my Dialog Class", L"Dialog", WS_VISIBLE | WS_OVERLAPPEDWINDOW, 400, 400, 200, 200, hWnd, NULL, NULL,NULL);
	CreateWindow(L"Button",L"Notting ?", WS_VISIBLE | WS_CHILD, 20, 20, 100, 40, hDlg, (HMENU)1, NULL, NULL);
	EnableWindow(hWnd, false);
}