#ifndef MAIN_H_
#define MAIN_H_

#include <Windows.h>
// ‰½ŒÌ‚©lib‚ªƒŠƒ“ƒN‚Å‚«‚È‚¢‚©‚çŽè“®
#pragma comment(lib,"winmm.lib")
//#include "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include/d3d9.h"
#include <d3d9.h>
//#include <c:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include/d3d9.h>
//#pragma comment(lib,"C:\\Program Files (x86)\\Microsoft DirectX SDK (June 2010)\\Lib\\x86\\d3d9.lib")
//#pragma comment(lib,"C:\\Program Files (x86)\\Microsoft DirectX SDK (June 2010)\\Lib\\x86\\dxguid.lib")

#define SCREEN_WIDTH (1024)
#define SCREEN_HEIGHT (576)

HWND GetHWnd();

#endif // !MAIN_H_
