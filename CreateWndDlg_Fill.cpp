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

void CCreateWndDlg::FillStyleList()
{
  CFlagListCtrl::TFlagInfo fiWS[] = {
    {WS_OVERLAPPED,        "WS_OVERLAPPED"      },
    {WS_POPUP,             "WS_POPUP"           },
    {WS_CHILD,             "WS_CHILD"           },
    {WS_MINIMIZE,          "WS_MINIMIZE"        },
    {WS_VISIBLE,           "WS_VISIBLE"         },
    {WS_DISABLED,          "WS_DISABLED"        },
    {WS_CLIPSIBLINGS,      "WS_CLIPSIBLINGS"    },
    {WS_CLIPCHILDREN,      "WS_CLIPCHILDREN"    },
    {WS_MAXIMIZE,          "WS_MAXIMIZE"        },
    {WS_CAPTION,           "WS_CAPTION"         },
    {WS_BORDER,            "WS_BORDER"          },
    {WS_DLGFRAME,          "WS_DLGFRAME"        },
    {WS_VSCROLL,           "WS_VSCROLL"         },
    {WS_HSCROLL,           "WS_HSCROLL"         },
    {WS_SYSMENU,           "WS_SYSMENU"         },
    {WS_THICKFRAME,        "WS_THICKFRAME"      },
    {WS_GROUP,             "WS_GROUP"           },
    {WS_TABSTOP,           "WS_TABSTOP"         },
    {WS_MINIMIZEBOX,       "WS_MINIMIZEBOX"     },
    {WS_MAXIMIZEBOX,       "WS_MAXIMIZEBOX"     },
    {WS_TILED,             "WS_TILED"           },
    {WS_ICONIC,            "WS_ICONIC"          },
    {WS_SIZEBOX,           "WS_SIZEBOX"         },
    {WS_TILEDWINDOW,       "WS_TILEDWINDOW"     },
    {WS_OVERLAPPEDWINDOW,  "WS_OVERLAPPEDWINDOW"},
    {WS_POPUPWINDOW,       "WS_POPUPWINDOW"     },
    {WS_CHILDWINDOW,       "WS_CHILDWINDOW"     },
  };

  m_StyleList.AddFlags(fiWS, sizeof(fiWS)/sizeof(fiWS[0]));
}
	  
void CCreateWndDlg::FillExStyleList()
{
  CFlagListCtrl::TFlagInfo fiWSEx[] = {
    {WS_EX_DLGMODALFRAME,    "WS_EX_DLGMODALFRAME"    },
    {WS_EX_NOPARENTNOTIFY,   "WS_EX_NOPARENTNOTIFY"   },
    {WS_EX_TOPMOST,          "WS_EX_TOPMOST"          },
    {WS_EX_ACCEPTFILES,      "WS_EX_ACCEPTFILES"      },
    {WS_EX_TRANSPARENT,      "WS_EX_TRANSPARENT"      },
    {WS_EX_MDICHILD,         "WS_EX_MDICHILD"         },
    {WS_EX_TOOLWINDOW,       "WS_EX_TOOLWINDOW"       },
    {WS_EX_WINDOWEDGE,       "WS_EX_WINDOWEDGE"       },
    {WS_EX_CLIENTEDGE,       "WS_EX_CLIENTEDGE"       },
    {WS_EX_CONTEXTHELP,      "WS_EX_CONTEXTHELP"      },
    {WS_EX_RIGHT,            "WS_EX_RIGHT"            },
    {0x08000000,             "WS_EX_NOACTIVATE"       },
    {WS_EX_LEFT,             "WS_EX_LEFT"             },
    {WS_EX_RTLREADING,       "WS_EX_RTLREADING"       },
    {WS_EX_LTRREADING,       "WS_EX_LTRREADING"       },
    {WS_EX_LEFTSCROLLBAR,    "WS_EX_LEFTSCROLLBAR"    },
    {WS_EX_RIGHTSCROLLBAR,   "WS_EX_RIGHTSCROLLBAR"   },
    {WS_EX_CONTROLPARENT,    "WS_EX_CONTROLPARENT"    },
    {WS_EX_STATICEDGE,       "WS_EX_STATICEDGE"       },
    {WS_EX_APPWINDOW,        "WS_EX_APPWINDOW"        },
    {WS_EX_OVERLAPPEDWINDOW, "WS_EX_OVERLAPPEDWINDOW" },
    {WS_EX_PALETTEWINDOW,    "WS_EX_PALETTEWINDOW"    },
  };
	
  m_ExStyleList.AddFlags(fiWSEx, sizeof(fiWSEx)/sizeof(fiWSEx[0]));
}

void CCreateWndDlg::FillCmdShowList()
{
  CConstantListBox::TConstInfo ci[] = {
    {SW_HIDE,            "SW_HIDE"           },
    {SW_SHOWNORMAL,      "SW_SHOWNORMAL"     },
    {SW_NORMAL,          "SW_NORMAL"         },
    {SW_SHOWMINIMIZED,   "SW_SHOWMINIMIZED"  },
    {SW_SHOWMAXIMIZED,   "SW_SHOWMAXIMIZED"  },
    {SW_SHOWNOACTIVATE,  "SW_SHOWNOACTIVATE" },
    {SW_SHOW,            "SW_SHOW"           },
    {SW_MINIMIZE,        "SW_MINIMIZE"       },
    {SW_SHOWMINNOACTIVE, "SW_SHOWMINNOACTIVE"},
    {SW_SHOWNA,          "SW_SHOWNA"         },
    {SW_RESTORE,         "SW_RESTORE"        },
    {SW_SHOWDEFAULT,     "SW_SHOWDEFAULT"    },
    {SW_FORCEMINIMIZE,   "SW_FORCEMINIMIZE"  },
  };

  m_CmdShowList.AddConstants(ci, sizeof(ci)/sizeof(ci[0]));
}
