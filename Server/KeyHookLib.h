///////////////////////////////////////////
// KeyHookLib.h檔案

// 定義函數修飾宏，方便引用本DLL工程的匯出函數
#ifdef KEYHOOKLIB_EXPORTS
#define KEYHOOKLIB_API __declspec(dllexport)
#else
#define KEYHOOKLIB_API __declspec(dllimport)
#endif

// 自定義與主程式通信的消息
#define HM_KEY WM_USER + 101

// 聲明要匯出的函數
BOOL KEYHOOKLIB_API WINAPI SetKeyHook(BOOL bInstall, 
				      DWORD dwThreadId = 0, HWND hWndCaller = NULL);



