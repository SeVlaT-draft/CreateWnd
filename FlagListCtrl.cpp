// Taimanov Sergei, 02.06.2009
// FlagListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "CreateWnd.h"
#include "FlagListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlagListCtrl

CFlagListCtrl::CFlagListCtrl()
 : m_bInOnItemChanged(false),
   m_nSortSubItem(0)
{
}

CFlagListCtrl::~CFlagListCtrl()
{
}


BEGIN_MESSAGE_MAP(CFlagListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CFlagListCtrl)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnItemChanged)
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnClick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlagListCtrl message handlers

void CFlagListCtrl::OnItemChanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	*pResult = 0;
  if (!pNMListView) return;

  const NM_LISTVIEW &NMListView=*pNMListView;

  if (!m_bInOnItemChanged && NMListView.iItem>=0) {
    m_bInOnItemChanged=true;
    DWORD dwAll=GetData();
    const DWORD dwItem=GetItemData(NMListView.iItem);

    if (GetCheck(NMListView.iItem)) {
      dwAll |= dwItem;
    } else {
      dwAll &= ~dwItem;
    }

    SetData(dwAll);
    m_bInOnItemChanged=false;
  }
}

DWORD CFlagListCtrl::GetData() const
{
  int Count = GetItemCount();

  DWORD dw=0;
  for (int i=0; i<Count; i++) {
    if (GetCheck(i)) dw |= GetItemData(i);
  }

  return dw;
}

void CFlagListCtrl::SetData(DWORD dw)
{
  int Count = GetItemCount();
  for (int i=0; i<Count; i++) {
    const DWORD dwItem=GetItemData(i);
    SetCheck(i, dwItem==(dwItem & dw));
  }
}

void CFlagListCtrl::Init()
{
/*
  DWORD dwStyle=GetWindowLong(m_hWnd, GWL_STYLE);
  dwStyle &= ~LVS_TYPEMASK;
  dwStyle |= LVS_REPORT;
  SetWindowLong(m_hWnd, GWL_STYLE, dwStyle);
*/
  SetExtendedStyle(LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT);

  InsertColumn(0, _T("Value"), LVCFMT_LEFT, 100, 0);
  InsertColumn(1, _T("Name"),  LVCFMT_LEFT, 100, 1);
}

void CFlagListCtrl::AddFlags(const TFlagInfo fis[], int nCount)
{
  if (nCount<=0) return;
  if (!fis) return;

  for (int i=0; i<nCount; ++i) {
    const TFlagInfo fi=fis[i];

    LV_ITEM lvi={0};
    TCHAR szBuffer[256]="";

    lvi.mask = LVIF_TEXT | LVIF_PARAM;

    wsprintf(szBuffer, _T("0x%08x"), fi.dwFlag);
    lvi.pszText = szBuffer;
    lvi.lParam = fi.dwFlag;

    const int nItem=InsertItem(&lvi);

    if (fi.szName) SetItemText(nItem, 1, fi.szName);
  }

  SetColumnWidth(0, LVSCW_AUTOSIZE);
  SetColumnWidth(1, LVSCW_AUTOSIZE_USEHEADER);
}

int CFlagListCtrl::CompareItems(int nItem0, int nItem1) const
{
  return strcmp(GetItemText(nItem0, m_nSortSubItem),
                GetItemText(nItem1, m_nSortSubItem));
  
}

namespace {
int CALLBACK SortItemFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
  const CFlagListCtrl *plc=(CFlagListCtrl*)lParamSort;
  if (!plc) return 0;
  return plc->CompareItems(lParam1, lParam2);
}
}

#define LVM_SORTITEMSEX          (LVM_FIRST + 81)

void CFlagListCtrl::OnColumnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	*pResult = 0;

  if (!pNMListView) return;
  const NM_LISTVIEW &NMListView=*pNMListView;

  m_nSortSubItem=NMListView.iSubItem;

  SendMessage(LVM_SORTITEMSEX, (WPARAM)this, (LPARAM)&SortItemFunc); 
}

