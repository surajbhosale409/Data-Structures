// tts_final.h : main header file for the TTS_FINAL application
//

#if !defined(AFX_TTS_FINAL_H__BE6F39C5_B74F_48EF_885B_8F392DA386BB__INCLUDED_)
#define AFX_TTS_FINAL_H__BE6F39C5_B74F_48EF_885B_8F392DA386BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTts_finalApp:
// See tts_final.cpp for the implementation of this class
//

class CTts_finalApp : public CWinApp
{
public:
	CTts_finalApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTts_finalApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTts_finalApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TTS_FINAL_H__BE6F39C5_B74F_48EF_885B_8F392DA386BB__INCLUDED_)
