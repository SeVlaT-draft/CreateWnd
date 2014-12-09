// Taimanov Sergei, 02.06.2009
#if !defined(AFX_FLAGLISTCTRL_H__86F76E2F_59C8_4165_9C6D_5936BDBD4522__INCLUDED_)
#define AFX_FLAGLISTCTRL_H__86F76E2F_59C8_4165_9C6D_5936BDBD4522__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlagListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFlagListCtrl window

class CFlagListCtrl : public CListCtrl
{
// Construction
public:
	CFlagListCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlagListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
  struct TFlagInfo {
    DWORD   dwFlag;
    LPCTSTR szName;
  };

  void Init();
  void AddFlags(const TFlagInfo fis[], int nCount);
	void SetData(DWORD dw);
	DWORD GetData() const;
	virtual ~CFlagListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFlagListCtrl)
	afx_msg void OnItemChanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnClick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
 private:
  bool m_bInOnItemChanged;
  int m_nSortSubItem;

 public:
  int CompareItems(int nItem0, int nItem1) const;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLAGLISTCTRL_H__86F76E2F_59C8_4165_9C6D_5936BDBD4522__INCLUDED_)
