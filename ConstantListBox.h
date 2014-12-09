// Taimanov Sergei, 02.06.2009
#if !defined(AFX_CONSTANTLISTBOX_H__EEBFAA7C_F90D_455E_80C8_973A23E93866__INCLUDED_)
#define AFX_CONSTANTLISTBOX_H__EEBFAA7C_F90D_455E_80C8_973A23E93866__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConstantListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConstantListBox window

class CConstantListBox : public CListBox
{
// Construction
public:
	CConstantListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConstantListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
  struct TConstInfo {
    int     nValue;
    LPCTSTR szName;
  };

	void SetData(int n);
	int GetData() const;
	void AddConstants(const TConstInfo pci[], int nCount);
	void Init();
	virtual ~CConstantListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CConstantListBox)
	afx_msg void OnSelChange();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONSTANTLISTBOX_H__EEBFAA7C_F90D_455E_80C8_973A23E93866__INCLUDED_)
