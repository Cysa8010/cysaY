#ifndef MAIN_H_
#define MAIN_H_

#include <Windows.h>
#include <assert.h> // エラー時の緊急停止
// 何故かlibがリンクできないから手動
#pragma comment(lib,"winmm.lib")
//#include "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include/d3d9.h"
#include <d3d9.h>
//#include <c:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include/d3d9.h>
//#pragma comment(lib,"C:\\Program Files (x86)\\Microsoft DirectX SDK (June 2010)\\Lib\\x86\\d3d9.lib")
//#pragma comment(lib,"C:\\Program Files (x86)\\Microsoft DirectX SDK (June 2010)\\Lib\\x86\\dxguid.lib")

#include <d3dx9.h>
#if defined(DEBUG) || defined(_DEBUG)
#pragma comment( lib, "d3dx9d.lib" )
#else
#pragma comment( lib, "d3dx9.lib" )
#endif

#define SCREEN_WIDTH (1024)
#define SCREEN_HEIGHT (576)

HWND GetHWnd();

#endif // !MAIN_H_
