// Taimanov Sergei, 02.06.2009
// CreateWndDlg.h : header file
//

#if !defined(AFX_CREATEWNDDLG_H__4F8CF4D8_5163_4472_872B_0D52B327B7AA__INCLUDED_)
#define AFX_CREATEWNDDLG_H__4F8CF4D8_5163_4472_872B_0D52B327B7AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FlagListCtrl.h"
#include "ConstantListBox.h"


/////////////////////////////////////////////////////////////////////////////
// CCreateWndDlg dialog

class CCreateWndDlg : public CDialog
{
// Construction
public:
	CCreateWndDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateWndDlg)
	enum { IDD = IDD_CREATEWND_DIALOG };
	CButton	m_SwlBtn;
	CConstantListBox	m_CmdShowList;
	CButton	m_WndPlace;
	CFlagListCtrl	m_ExStyleList;
	CFlagListCtrl	m_StyleList;
	int		m_Parent;
	CString	m_sClass;
	CString	m_sTitle;
	CString	m_sWnd;
	BOOL	m_bShowAfterCreation;
	CString	m_sErrorDescr;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateWndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateWndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreateWnd();
	afx_msg void OnTestClass();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCreateLater();
	afx_msg void OnSwl();
	afx_msg void OnSetParent();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

 private:
  void FillStyleList();
  void FillExStyleList();
  void FillCmdShowList();


 private:
  DWORD m_dwStyle;
  DWORD m_dwExStyle;
  int m_nCmdShow;
  HWND m_hTestWnd;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEWNDDLG_H__4F8CF4D8_5163_4472_872B_0D52B327B7AA__INCLUDED_)
