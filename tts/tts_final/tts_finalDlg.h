// tts_finalDlg.h : header file
//

#if !defined(AFX_TTS_FINALDLG_H__AAB7F684_F962_40CC_9D48_CCC5E342B4E9__INCLUDED_)
#define AFX_TTS_FINALDLG_H__AAB7F684_F962_40CC_9D48_CCC5E342B4E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTts_finalDlg dialog

class CTts_finalDlg : public CDialog
{
// Construction
public:
	CTts_finalDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTts_finalDlg)
	enum { IDD = IDD_TTS_FINAL_DIALOG };
	CButton	m_browse;
	CSliderCtrl	m_rate;
	CSliderCtrl	m_volume;
	CButton	m_speak;
	CString	m_text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTts_finalDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTts_finalDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSpeak();
	virtual void OnCancel();
	afx_msg void OnPause();
	afx_msg void OnResume();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TTS_FINALDLG_H__AAB7F684_F962_40CC_9D48_CCC5E342B4E9__INCLUDED_)
