/*****************************************************************************
* Copyright (C) 2017-2020 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module       : 	ywfPlayerDlg.cpp
* Description       : 	ywfPlayerDlg Demo


* Created           : 	2017.09.21.
* Author            : 	Yu Weifeng
* Function List     :
* Last Modified     :
* History           :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/

#include "stdafx.h"
#include "ywfPlayer.h"
#include "ywfPlayerDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif





/*****************************************************************************
-Fuction        : CDialogEx
-Description    : 用于应用程序“关于”菜单项的 CAboutDlg 对话框
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};
/*****************************************************************************
-Fuction        : CDialogEx
-Description    : 用于应用程序“关于”菜单项的 CAboutDlg 对话框
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}
/*****************************************************************************
-Fuction        : DoDataExchange
-Description    : DoDataExchange
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CywfPlayerDlg 对话框


/*****************************************************************************
-Fuction        : CywfPlayerDlg
-Description    : CywfPlayerDlg
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
CywfPlayerDlg::CywfPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_YWFPLAYER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}
/*****************************************************************************
-Fuction        : DoDataExchange
-Description    : DoDataExchange
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CywfPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CywfPlayerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDOK, &CywfPlayerDlg::OnBnClickedOk)
ON_BN_CLICKED(IDC_PLAY, &CywfPlayerDlg::OnBnClickedPlay)
ON_BN_CLICKED(IDPAUSE, &CywfPlayerDlg::OnBnClickedPause)
ON_BN_CLICKED(IDSTOP, &CywfPlayerDlg::OnBnClickedStop)
ON_COMMAND(ID_OPENFILE, &CywfPlayerDlg::Openfile)
//ON_COMMAND(IDABORT, &CywfPlayerDlg::OnIdAbort)
ON_COMMAND(IDEXIT, &CywfPlayerDlg::OnIdExit)
ON_COMMAND(ID_ABOUT, &CywfPlayerDlg::OnAbout)
END_MESSAGE_MAP()



/*****************************************************************************
-Fuction        : OnInitDialog
-Description    : // CywfPlayerDlg 消息处理程序
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
BOOL CywfPlayerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
/*****************************************************************************
-Fuction        : OnSysCommand
-Description    : OnSysCommand
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CywfPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}


/*****************************************************************************
-Fuction        : OnPaint
-Description    : 
// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CywfPlayerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}


/*****************************************************************************
-Fuction        : OnQueryDragIcon
-Description    :
//当用户拖动最小化窗口时系统调用此函数取得光标
//显示
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
HCURSOR CywfPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




/*****************************************************************************
-Fuction        : OnBnClickedOk
-Description    :
// TODO: 在此添加控件通知处理程序代码
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CywfPlayerDlg::OnBnClickedPlay()
{
	//	CString strSet("123");
	//	AfxMessageBox(strSet);
	//	CDialog::OnOK();
	m_iThreadPauseFlag = 0;
}

/*****************************************************************************
-Fuction        : OnBnClickedPause
-Description    :
// TODO: 在此添加控件通知处理程序代码
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CywfPlayerDlg::OnBnClickedPause()
{
	m_iThreadPauseFlag = 1;
}

/*****************************************************************************
-Fuction        : OnBnClickedStop
-Description    :
// TODO: 在此添加控件通知处理程序代码
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CywfPlayerDlg::OnBnClickedStop()
{
	m_iThreadExitFlag = 1;
}

/*****************************************************************************
-Fuction        : Openfile
-Description    :
// TODO: 在此添加控件通知处理程序代码
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CywfPlayerDlg::Openfile()
{
	CFileDialog dlg(TRUE, NULL, NULL, NULL, NULL);///TRUE为OPEN对话框，FALSE为SAVE AS对话框 
	if (dlg.DoModal() == IDOK)
	{
		m_strURL = dlg.GetPathName();
		pThreadYwfPlayer = AfxBeginThread((AFX_THREADPROC)YwfPlayerThread, (LPVOID)this);//开启线程
	}
}

/*****************************************************************************
-Fuction        : OnIdExit
-Description    :
// TODO: 在此添加控件通知处理程序代码
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CywfPlayerDlg::OnIdExit()
{
	OnCancel();//mfc函数
}

/*****************************************************************************
-Fuction        : OnAbout
-Description    :
// TODO: 在此添加控件通知处理程序代码
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CywfPlayerDlg::OnAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}

/*****************************************************************************
-Fuction        : RefreshPlayThread
-Description    : 必须定义成静态的(c函数)才能作为线程函数
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int CywfPlayerDlg::RefreshPlayThread(void *args)
{
	if (NULL != args)
	{
		CywfPlayerDlg *pThis = (CywfPlayerDlg *)args;
		return pThis->RefreshPlayProc(NULL);//静态成员引用非静态成员必须要这样
	}
}	
/*****************************************************************************
-Fuction        : RefreshPlayThread
-Description    : RefreshPlayThread
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int CywfPlayerDlg::RefreshPlayProc(void *opaque)
{
	m_iThreadExitFlag = 0;
	m_iThreadPauseFlag = 0;
	SDL_Event tEvent = { 0 };
	//AfxMessageBox(m_strURL);
	while (!m_iThreadExitFlag)
	{
		if (0 == m_iThreadPauseFlag)
		{
			tEvent.type = PLAY_REFRESH_EVENT;
			SDL_PushEvent(&tEvent);//发送事件给其他线程
		}
		SDL_Delay(20);//延时函数 填40的时候，视频会有种卡的感觉
	}
	//Break
	m_iThreadExitFlag = 0;
	m_iThreadPauseFlag = 0;
	tEvent.type = PLAY_BREAK_EVENT;
	SDL_PushEvent(&tEvent);//发送事件给其他线程 发送一个事件

	return 0;
}


/*****************************************************************************
-Fuction        : RefreshPlayThread
-Description    : 必须定义成静态的(c函数)才能作为线程函数
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
UINT CywfPlayerDlg::YwfPlayerThread(LPVOID args)
{
	if (NULL != args)
	{
		CywfPlayerDlg *pThis = (CywfPlayerDlg *)args;
		return pThis->YwfPlayerProc(args);//静态成员引用非静态成员必须要这样
	}
}
/*****************************************************************************
-Fuction        : main
-Description    : main
-Input          :
-Output         :
-Return         :
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int CywfPlayerDlg::YwfPlayerProc(LPVOID args)
{
	CywfPlayerDlg *dlg = (CywfPlayerDlg *)args;
	/*------------FFmpeg----------------*/ 
	AVFormatContext	*ptFormatContext = NULL;//封装格式上下文，内部包含所有的视频信息
	int				i = 0;
	int             iVideoindex = 0;//纯视频信息在音视频流中的位置，也就是指向音视频流数组中的视频元素
	AVCodecContext	*ptCodecContext;//编码器相关信息上下文，内部包含编码器相关的信息，指向AVFormatContext中的streams成员中的codec成员
	AVCodec			*ptCodec;//编码器，使用函数avcodec_find_decoder或者，该函数需要的id参数，来自于ptCodecContext中的codec_id成员
	AVFrame	        *ptFrame = NULL;//存储一帧解码后像素（采样）数据
	AVFrame	        *ptFrameAfterScale = NULL;//存储(解码数据)转换后的像素（采样）数据
	unsigned char   *pucFrameAfterScaleBuf = NULL;//用于存储ptFrameAfterScale中的像素（采样）缓冲数据
	AVPacket        *ptPacket = NULL;//存储一帧压缩编码数据
	int             iRet = 0;
	int             iGotPicture = 0;//解码函数的返回参数，got_picture_ptr Zero if no frame could be decompressed, otherwise, it is nonzero

	/*------------SDL----------------*/
	int iScreenWidth = 0, iScreenHeight = 0;//视频的宽和高，指向ptCodecContext中的宽和高
	SDL_Window *ptSdlWindow = NULL;//用于sdl显示视频的窗口(用于显示的屏幕)
	SDL_Renderer* ptSdlRenderer = NULL;//sdl渲染器，把纹理数据画(渲染)到window上
	SDL_Texture* ptSdlTexture = NULL;//sdl纹理数据,用于存放像素（采样）数据，然后给渲染器
	SDL_Rect tSdlRect = { 0 };//正方形矩形结构，存了矩形的坐标，长宽，以便确定纹理数据画在哪个位置，确定位置用，比如画在左上角就用这个来确定。被渲染器调用
	SDL_Thread *ptVideoControlTID = NULL;//sdl线程id,线程的句柄
	SDL_Event tSdlEvent = { 0 };//sdl事件,代表一个事件

	/*------------像素数据处理----------------*/
	struct SwsContext *ptImgConvertInfo;//图像转换(上下文)信息，图像转换函数sws_scale需要的参数，由sws_getContext函数赋值


	/*------------FFmpeg----------------*/
	av_register_all();//注册FFmpeg所有组件
	avformat_network_init();//初始化网络组件
	//TRACE1("avcodec_configuration %s\r\n", avcodec_configuration());

	ptFormatContext = avformat_alloc_context();//分配空间给ptFormatContext

	//snprintf(strFilePath,sizeof(strFilePath),"%s", m_strURL);//不能使用如此字符，包括strncpy,memcpy都不行，因为在unicode下不行，同时拷贝传入的长度值从GetLength()来获取有问题
	int iLength = m_strURL.GetLength();
	int iBytes = WideCharToMultiByte(CP_ACP, 0, m_strURL, iLength, NULL, 0, NULL, NULL);
	char* strFilePath = new char[iBytes + 1];
	memset(strFilePath, 0, iLength + 1);
	WideCharToMultiByte(CP_OEMCP, 0, m_strURL, iLength, strFilePath, iBytes, NULL, NULL);
	strFilePath[iBytes] = 0;

	iRet = avformat_open_input(&ptFormatContext, strFilePath, NULL, NULL);
	if (iRet != 0)
	{//打开输入视频文件
		TRACE1 ("Couldn't open input stream:%s,%d\n", strFilePath, iRet);
		return -1;
	}
	if (avformat_find_stream_info(ptFormatContext, NULL)<0)
	{//获取视频文件信息
		OutputDebugString (L"Couldn't find stream information.\n");
		return -1;
	}
	//获取编码器相关信息上下文，并赋值给ptCodecContext
	iVideoindex = -1;
	for (i = 0; i<ptFormatContext->nb_streams; i++)
	{
		if (ptFormatContext->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
		{
			iVideoindex = i;
			break;
		}
	}
	if (iVideoindex == -1)
	{
		OutputDebugString (L"Didn't find a video stream.\n");
		return -1;
	}
	ptCodecContext = ptFormatContext->streams[iVideoindex]->codec;

	ptCodec = avcodec_find_decoder(ptCodecContext->codec_id);//查找解码器
	if (ptCodec == NULL)
	{
		OutputDebugString (L"Codec not found.\n");
		return -1;
	}
	if (avcodec_open2(ptCodecContext, ptCodec, NULL)<0)
	{//打开解码器
		OutputDebugString (L"Could not open codec.\n");
		return -1;
	}

	ptPacket = (AVPacket *)av_malloc(sizeof(AVPacket));//分配保存解码前数据的空间
	ptFrame = av_frame_alloc();//分配结构体空间，结构体内部的指针指向的数据暂未分配,用于保存图像转换前的像素数据

	/*------------像素数据处理----------------*/
	ptFrameAfterScale = av_frame_alloc();//分配结构体空间，结构体内部的指针指向的数据暂未分配,用于保存图像转换后的像素数据
	pucFrameAfterScaleBuf = (uint8_t *)av_malloc(avpicture_get_size(PIX_FMT_YUV420P, ptCodecContext->width, ptCodecContext->height));//分配保存数据的空间
	/*int avpicture_fill(AVPicture *picture, uint8_t *ptr,int pix_fmt, int width, int height);
	这个函数的使用本质上是为已经分配的空间的结构体(AVPicture *)ptFrame挂上一段用于保存数据的空间，
	这个结构体中有一个指针数组data[AV_NUM_DATA_POINTERS]，挂在这个数组里。一般我们这么使用：
	1） pFrameRGB=avcodec_alloc_frame();
	2） numBytes=avpicture_get_size(PIX_FMT_RGB24, pCodecCtx->width,pCodecCtx->height);
	buffer=(uint8_t *)av_malloc(numBytes*sizeof(uint8_t));
	3） avpicture_fill((AVPicture *)pFrameRGB, buffer, PIX_FMT_RGB24,pCodecCtx->width, pCodecCtx->height);
	以上就是为pFrameRGB挂上buffer。这个buffer是用于存缓冲数据的。
	ptFrame为什么不用fill空间。主要是下面这句：
	avcodec_decode_video(pCodecCtx, pFrame, &frameFinished,packet.data, packet.size);
	很可能是ptFrame已经挂上了packet.data，所以就不用fill了。*/
	avpicture_fill((AVPicture *)ptFrameAfterScale, pucFrameAfterScaleBuf, PIX_FMT_YUV420P, ptCodecContext->width, ptCodecContext->height);
	//sws开头的函数用于处理像素(采样)数据
	ptImgConvertInfo = sws_getContext(ptCodecContext->width, ptCodecContext->height, ptCodecContext->pix_fmt,
		ptCodecContext->width, ptCodecContext->height, PIX_FMT_YUV420P, SWS_BICUBIC, NULL, NULL, NULL);//获取图像转换(上下文)信息

	/*------------SDL----------------*/
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
	{//初始化SDL系统
		TRACE1("Could not initialize SDL - %s\n", SDL_GetError());
		return -1;
	}
	//SDL 2.0 Support for multiple windows
	iScreenWidth = ptCodecContext->width;
	iScreenHeight = ptCodecContext->height;
	//创建窗口SDL_Window
	//ptSdlWindow = SDL_CreateWindow("Simplest ffmpeg player's Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,iScreenWidth, iScreenHeight, SDL_WINDOW_OPENGL);
	//显示在MFC控件上
	ptSdlWindow = SDL_CreateWindowFrom(dlg->GetDlgItem(IDC_SCREEN)->GetSafeHwnd());
	if (!ptSdlWindow)
	{
		TRACE1("SDL: could not create window - exiting:%s\n", SDL_GetError());
		return -1;
	}
	ptSdlRenderer = SDL_CreateRenderer(ptSdlWindow, -1, 0);//创建渲染器SDL_Renderer
														   //IYUV: Y + U + V  (3 planes)
														   //YV12: Y + V + U  (3 planes)
														   //创建纹理SDL_Texture
	ptSdlTexture = SDL_CreateTexture(ptSdlRenderer, SDL_PIXELFORMAT_IYUV, SDL_TEXTUREACCESS_STREAMING, ptCodecContext->width, ptCodecContext->height);

	tSdlRect.x = 0;//x y值是左上角为圆点开始的坐标值，调整x y值以及w h值，就可以实现在窗口的指定位置显示，没有画面的地方为黑框
	tSdlRect.y = 0;//当x y等于0，w h等于窗口的宽高时即为全屏显示，此时调整宽高大小，只需调整窗口大小即可
	tSdlRect.w = iScreenWidth;
	tSdlRect.h = iScreenHeight;

	ptVideoControlTID = SDL_CreateThread(RefreshPlayThread, NULL, (LPVOID)this);//创建一个线程

	while (1)
	{//Event Loop		
		SDL_WaitEvent(&tSdlEvent);//Wait，等待其他线程过来的事件
		if (tSdlEvent.type == PLAY_REFRESH_EVENT) //自定义刷新图像(播放)事件
		{
			/*------------FFmpeg----------------*/
			if (av_read_frame(ptFormatContext, ptPacket) >= 0) //从输入文件读取一帧压缩数据
			{
				if (ptPacket->stream_index == iVideoindex)
				{
					iRet = avcodec_decode_video2(ptCodecContext, ptFrame, &iGotPicture, ptPacket);//解码一帧压缩数据
					if (iRet < 0)
					{
						OutputDebugString (L"Decode Error.\n");
						return -1;
					}
					if (iGotPicture)
					{
						//图像转换，sws_scale()函数需要用到的转换信息，即第一个参数，是由sws_getContext函数获得的
						sws_scale(ptImgConvertInfo, (const uint8_t* const*)ptFrame->data, ptFrame->linesize, 0, ptCodecContext->height, ptFrameAfterScale->data, ptFrameAfterScale->linesize);

						/*------------SDL----------------*/
						SDL_UpdateTexture(ptSdlTexture, NULL, ptFrameAfterScale->data[0], ptFrameAfterScale->linesize[0]);//设置(更新)纹理的数据
						SDL_RenderClear(ptSdlRenderer);//先清除渲染器里的数据
													   //SDL_RenderCopy( ptSdlRenderer, ptSdlTexture, &tSdlRect, &tSdlRect );  //将纹理的数据拷贝给渲染器
						SDL_RenderCopy(ptSdlRenderer, ptSdlTexture, NULL, NULL);//将纹理的数据拷贝给渲染器
						SDL_RenderPresent(ptSdlRenderer);//显示
					}
				}
				av_free_packet(ptPacket);//释放空间
			}
			else
			{
				m_iThreadExitFlag = 1;//Exit Thread
			}
		}
		else if (tSdlEvent.type == SDL_QUIT) //也是SDL自带的事件，当点击窗口的×时触发//SDL_WINDOWENVENT sdl系统自带的事件，当拉伸窗口的时候会触发
		{
			m_iThreadExitFlag = 1;
		}
		else if (tSdlEvent.type == PLAY_BREAK_EVENT) //自定义退出播放事件
		{
			break;
		}

	}

	/*------------像素数据处理----------------*/
	sws_freeContext(ptImgConvertInfo);//释放空间

	/*------------SDL----------------*/
	SDL_Quit();//退出SDL系统
	//SDL Hide Window When it finished
	dlg->GetDlgItem(IDC_SCREEN)->ShowWindow(SW_SHOWNORMAL);

	/*------------FFmpeg----------------*/
	av_frame_free(&ptFrameAfterScale);//释放空间
	av_frame_free(&ptFrame);//释放空间
	avcodec_close(ptCodecContext);//关闭解码器
	avformat_close_input(&ptFormatContext);//关闭输入视频文件

	return 0;
}
