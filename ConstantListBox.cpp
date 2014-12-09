// Taimanov Sergei, 02.06.2009
// ConstantListBox.cpp : implementation file
//

#include "stdafx.h"
#include "createwnd.h"
#include "ConstantListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConstantListBox

CConstantListBox::CConstantListBox()
{
}

CConstantListBox::~CConstantListBox()
{
}


BEGIN_MESSAGE_MAP(CConstantListBox, CListBox)
	//{{AFX_MSG_MAP(CConstantListBox)
	ON_CONTROL_REFLECT(LBN_SELCHANGE, OnSelChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConstantListBox message handlers

void CConstantListBox::OnSelChange() 
{

}

void CConstantListBox::Init()
{

}

void CConstantListBox::AddConstants(const TConstInfo cis[], int nCount)
{
  if (nCount<=0) return;
  if (!cis) return;

  for (int i=0; i<nCount; ++i) {
    const TConstInfo ci=cis[i];
    const int nItem=AddString(ci.szName);
    SetItemData(nItem, ci.nValue);
  }
}

int CConstantListBox::GetData() const
{
  int nItem=GetCurSel();

  if (nItem<0) return -1;

  return GetItemData(nItem);
}

void CConstantListBox::SetData(int n)
{
  const int nCount=GetCount();

  for (int i=0; i<nCount; ++i) {
    const int nData=GetItemData(i);
    if (n==nData) {
      SetCurSel(i);
      return;
    }
  }

  SetCurSel(-1);
}
