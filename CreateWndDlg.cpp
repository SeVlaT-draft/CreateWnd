// Taimanov Sergei, 02.06.2009
// CreateWndDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CreateWnd.h"
#include "CreateWndDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

LRESULT CALLBACK TestWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
const LPCTSTR c_szTestClass=_T("TestClass");

const int c_idTimer=100;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateWndDlg dialog

CCreateWndDlg::CCreateWndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateWndDlg::IDD, pParent),
    m_dwStyle(WS_VISIBLE | WS_POPUP),
    m_dwExStyle(0),
    m_hTestWnd(0),
    m_nCmdShow(SW_SHOW)
{
	//{{AFX_DATA_INIT(CCreateWndDlg)
	m_Parent = 0;
	m_sClass = _T("");
	m_sTitle = _T("");
	m_sWnd = _T("");
	m_bShowAfterCreation = FALSE;
	m_sErrorDescr = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreateWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

  if (pDX->m_bSaveAndValidate) {
  } else {
  }

	//{{AFX_DATA_MAP(CCreateWndDlg)
	DDX_Control(pDX, IDC_SWL, m_SwlBtn);
	DDX_Control(pDX, IDC_SWPARAM, m_CmdShowList);
	DDX_Control(pDX, IDC_WNDPLACE, m_WndPlace);
	DDX_Control(pDX, IDC_EXSTYLELIST, m_ExStyleList);
	DDX_Control(pDX, IDC_STYLELIST, m_StyleList);
	DDX_Radio(pDX, IDC_PARENT_THIS, m_Parent);
	DDX_Text(pDX, IDC_CLASS, m_sClass);
	DDX_Text(pDX, IDC_TITLE, m_sTitle);
	DDX_Text(pDX, IDC_HWINDOW, m_sWnd);
	DDX_Check(pDX, IDC_SHOWAFTERCREATION, m_bShowAfterCreation);
	DDX_Text(pDX, IDC_ERRORDESCR, m_sErrorDescr);
	//}}AFX_DATA_MAP

  if (pDX->m_bSaveAndValidate) {
    m_dwStyle=m_StyleList.GetData();
    m_dwExStyle=m_ExStyleList.GetData();
    m_nCmdShow=m_CmdShowList.GetData();
  } else {
    m_StyleList.SetData(m_dwStyle);
    m_ExStyleList.SetData(m_dwExStyle);
    m_CmdShowList.SetData(m_nCmdShow);
  }
}

BEGIN_MESSAGE_MAP(CCreateWndDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateWndDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CREATE, OnCreateWnd)
	ON_BN_CLICKED(IDC_TESTCLASS, OnTestClass)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CREATELATER, OnCreateLater)
	ON_BN_CLICKED(IDC_SWL, OnSwl)
	ON_BN_CLICKED(IDC_SETPARENT, OnSetParent)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateWndDlg message handlers

BOOL CCreateWndDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

  {
    WNDCLASS wc={0};
    wc.style         = 0;
    wc.lpfnWndProc   = TestWindowProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = AfxGetInstanceHandle();
    wc.hIcon         = 0;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = 0;
    wc.lpszClassName = c_szTestClass;

    RegisterClass(&wc);
  }

  m_StyleList.Init();
  m_ExStyleList.Init();
  m_CmdShowList.Init();

  FillStyleList();
  FillExStyleList();
  FillCmdShowList();

  UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCreateWndDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCreateWndDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCreateWndDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

CString GetLastErrorString()
{
  const dwError=GetLastError();
  SetLastError(S_OK);

  HLOCAL hlocal=0;

  if (FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, 
                    NULL, dwError, MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), 
                    (PTSTR) &hlocal, 0, NULL)>0 &&
      hlocal) {
    CString s=(LPCTSTR) LocalLock(hlocal);
    LocalFree(hlocal);
    s.TrimRight();
    return s;
  }

  CString s;
  s.Format(_T("!! Error 0x%08X. No comments"), dwError);
  return s;
}

void CCreateWndDlg::OnCreateWnd() 
{
  UpdateData(TRUE);

  CRect rectWnd;
  m_WndPlace.GetWindowRect(rectWnd);
  ScreenToClient(rectWnd);

  rectWnd.InflateRect(-15, -30);

/*
  rectWnd.right=rectWnd.left+100;
  rectWnd.bottom=rectWnd.top+100;
*/

  HWND hParentWnd=0;
  if (m_Parent==0) hParentWnd=m_hWnd;

  if (m_hTestWnd) ::DestroyWindow(m_hTestWnd);

  SetLastError(S_OK);
  m_hTestWnd=CreateWindowEx(m_dwExStyle,
                            m_sClass,
                            m_sTitle,
                            m_dwStyle,
                            rectWnd.left,
                            rectWnd.top,
                            rectWnd.Width(),
                            rectWnd.Height(),
                            hParentWnd,
                            0, //Menu
                            AfxGetInstanceHandle(),
                            0);
  m_sErrorDescr=_T("CreateWindow: ")+GetLastErrorString()+_T("\r\n");

  m_sWnd.Format(_T("0x%08X"), m_hTestWnd);

  if (m_hTestWnd && m_bShowAfterCreation) {
    ::ShowWindow(m_hTestWnd, m_nCmdShow);
    m_sErrorDescr+=_T("ShowWindow: ")+GetLastErrorString();
  }

	UpdateData(FALSE);
}

void CCreateWndDlg::OnTestClass() 
{
  UpdateData(TRUE);
	m_sClass=c_szTestClass;
	UpdateData(FALSE);
}

void CCreateWndDlg::OnTimer(UINT nIDEvent) 
{
  if (nIDEvent==c_idTimer) {
    KillTimer(nIDEvent);
    OnCreateWnd();
  };
	
	CDialog::OnTimer(nIDEvent);
}

void CCreateWndDlg::OnCreateLater() 
{
  if (m_hTestWnd) ::DestroyWindow(m_hTestWnd);
  m_hTestWnd=0;

  SetTimer(c_idTimer, 2000, 0);
}

void CCreateWndDlg::OnSwl() 
{
  UpdateData(TRUE);

  SetLastError(S_OK);
  if (m_hTestWnd && IsWindow(m_hTestWnd)) {
    ::SetWindowLong(m_hTestWnd, GWL_STYLE, m_dwStyle);
    m_sErrorDescr=_T("SetWindowLong(GWL_STYLE): ")+GetLastErrorString()+_T("\r\n");

    ::SetWindowPos(m_hTestWnd, 0, 0, 0, 0, 0,
                   SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
    m_sErrorDescr+=_T("SetWindowPos():  ")+GetLastErrorString()+_T("\r\n");

    ::SetWindowLong(m_hTestWnd, GWL_EXSTYLE, m_dwExStyle);
    m_sErrorDescr+=_T("SetWindowLong(GWL_EXSTYLE): ")+GetLastErrorString()+_T("\r\n");

    ::SetWindowPos(m_hTestWnd, 0, 0, 0, 0, 0,
                   SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
    m_sErrorDescr+=_T("SetWindowPos():  ")+GetLastErrorString()+_T("");

  } else {
    m_sErrorDescr=_T("Window was not created!");
  }

	UpdateData(FALSE);
}

void CCreateWndDlg::OnSetParent() 
{
  UpdateData(TRUE);
	
  if (m_hTestWnd && IsWindow(m_hTestWnd)) {
    HWND hParentWnd=0;
    if (m_Parent==0) hParentWnd=m_hWnd;

    ::SetParent(m_hTestWnd, hParentWnd);
    m_sErrorDescr=_T("SetParent():  ")+GetLastErrorString()+_T("");
  } else {
    m_sErrorDescr=_T("Window was not created!");
  }

	UpdateData(FALSE);
}
