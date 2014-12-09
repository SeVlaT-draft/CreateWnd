// Taimanov Sergei, 02.06.2009
// CreateWnd.h : main header file for the CREATEWND application
//

#if !defined(AFX_CREATEWND_H__620094B5_585E_4A4E_8530_781227E7BAA5__INCLUDED_)
#define AFX_CREATEWND_H__620094B5_585E_4A4E_8530_781227E7BAA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateWndApp:
// See CreateWnd.cpp for the implementation of this class
//

class CCreateWndApp : public CWinApp
{
public:
	CCreateWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateWndApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEWND_H__620094B5_585E_4A4E_8530_781227E7BAA5__INCLUDED_)
