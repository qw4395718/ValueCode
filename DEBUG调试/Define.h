#ifndef __WK_PUBLIC_DEFINE_H_
#define __WK_PUBLIC_DEFINE_H_

#include <stdio.h>
#include <io.h>
#include <string>
//#include "LibDbgLog.h"



#ifndef WK_OK
typedef char   WK_INT8;
typedef short  WK_INT16;
typedef int    WK_INT32;
typedef long WK_LONG;

typedef unsigned char   WK_UINT8;
typedef unsigned short  WK_UINT16;
typedef unsigned int    WK_UINT32;
typedef unsigned long WK_ULONG;

typedef double	WK_FLOAT;

typedef __int64 WK_INT64;
typedef unsigned __int64   WK_UINT64;

#ifdef _WIN64
	typedef unsigned long long WK_POINT;
#else
	typedef unsigned long WK_POINT;
#endif

typedef void WK_VOID;

typedef int  WK_BOOL;


#define WK_SECCESS 1
#define WK_FAILED  0

#define WK_OK    0
#define WK_ERR  -1

#define WK_EOF   1

#define WK_TRUE  1
#define WK_FALSE 0

#define WK_IN_USE 		1
#define WK_NO_USE 		0

#define WK_NULL		0

#define WK_OUT
#define WK_IN
#define WK_IN_OUT
#endif

// 对于 __DEBUG  的定义
#ifndef __DEBUG
#if 0
#define __DEBUG(fmt, ...) { char* ppp = NULL; int lBlll = 0; fnLibDbgLogGetBuffer(__FILE__, __LINE__, &ppp, &lBlll); if(NULL != ppp) {int llll = sprintf_s(ppp, lBlll, fmt, ##__VA_ARGS__ ); fnLibDbgLogSend(llll);}}

#else
#define __DEBUG(fmt, ...) {	\
		char *p = NULL, *pH = (char*)__FILE__, *pBegin = (char*)malloc(1024+1024);SYSTEMTIME stTime;\
		if(pBegin){p=pH;\
				while(*pH!=0){if('\\'==*pH)p=pH+1;pH++;};\
		pH = p; p = pBegin;GetLocalTime(&stTime);\
		p += sprintf_s(p, 1024 + 512, "[%02d:%02d:%02d.%03d][%ld]%s[%d]>>"fmt, stTime.wHour, stTime.wMinute, stTime.wSecond, stTime.wMilliseconds, GetCurrentThreadId(), pH, __LINE__, ##__VA_ARGS__ );\
				while (p > pBegin && isspace(p[-1])) *--p = '\0';	\
		*p++ = '\r';*p++ = '\n';*p = '\0'; \
		OutputDebugStringA(pBegin);free(pBegin);}}
#endif

#endif


#ifdef LIBCFGCAMX1_EXPORTS
#define LIBCFGCAMX1_API __declspec(dllexport)
#else
#define LIBCFGCAMX1_API __declspec(dllimport)
#pragma comment(lib,"LibCfgCamX1")
#endif


typedef struct{
	WK_INT32 x;
	WK_INT32 y;
}TLiPntXY;

typedef struct 
{
	WK_FLOAT m_fPosX;//当前X轴坐标
	WK_FLOAT m_fPosY;//当前Y轴坐标
}TLfPosXY;

#endif /* ifndef __WK_PUBLIC_DEFINE_H_ */

