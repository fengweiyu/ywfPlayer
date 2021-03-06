
// ywfPlayerDlg.h: 头文件
//
/*
__STDC_LIMIT_MACROS and __STDC_CONSTANT_MACROS are a workaround to allow C++ programs to use stdint.h
macros specified in the C99 standard that aren't in the C++ standard. The macros, such as UINT8_MAX, INT64_MIN,
and INT32_C() may be defined already in C++ applications in other ways. To allow the user to decide
if they want the macros defined as C99 does, many implementations require that __STDC_LIMIT_MACROS
and __STDC_CONSTANT_MACROS be defined before stdint.h is included.

This isn't part of the C++ standard, but it has been adopted by more than one implementation.
*/
#define __STDC_CONSTANT_MACROS

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "SDL2/SDL.h"
};
#include "Windows.h"

#define TRACE1(fmt,var) {TCHAR sOut[2560];_stprintf_s(sOut,_T(fmt),var);OutputDebugString(sOut);}    
#define TRACE2(fmt,var1,var2) {TCHAR sOut[2560];_stprintf_s(sOut,_T(fmt),var1,var2);OutputDebugString(sOut);}    
#define TRACE3(fmt,var1,var2,var3) {TCHAR sOut[2560];_stprintf_s(sOut,_T(fmt),var1,var2,var3);OutputDebugString(sOut);} 

//Refresh Event 自定义事件
#define PLAY_REFRESH_EVENT       (SDL_USEREVENT + 1)//自定义刷新图像(播放)事件
#define PLAY_BREAK_EVENT         (SDL_USEREVENT + 2) //自定义退出播放事件

#pragma once


// CywfPlayerDlg 对话框
class CywfPlayerDlg : public CDialog
{
// 构造
public:
	CywfPlayerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YWFPLAYER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedPlay();
	afx_msg void OnBnClickedPause();
	afx_msg void OnBnClickedStop();
	afx_msg void Openfile();
//	afx_msg void OnIdAbort();
	afx_msg void OnIdExit();
	afx_msg void OnAbout();

	CWinThread *pThreadYwfPlayer;
	static int RefreshPlayThread(void *args);
	int RefreshPlayProc(void *opaque);
	static UINT YwfPlayerThread(LPVOID args);
	int YwfPlayerProc(LPVOID args);
private:
	CString m_strURL;
	int m_iThreadExitFlag;
	int m_iThreadPauseFlag;
};
