///////////////////////////////////////////
// KeyHookLib.h�ɮ�

// �w�q��ƭ׹����A��K�ޥΥ�DLL�u�{���ץX���
#ifdef KEYHOOKLIB_EXPORTS
#define KEYHOOKLIB_API __declspec(dllexport)
#else
#define KEYHOOKLIB_API __declspec(dllimport)
#endif

// �۩w�q�P�D�{���q�H������
#define HM_KEY WM_USER + 101

// �n���n�ץX�����
BOOL KEYHOOKLIB_API WINAPI SetKeyHook(BOOL bInstall, 
				      DWORD dwThreadId = 0, HWND hWndCaller = NULL);



