// tts_finalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "tts_final.h"
#include "tts_finalDlg.h"
#include <sapi.h>
#include <sphelper.h>
#include "slider.h"
#include "grammer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
	ISpVoice*  pVoice;
	CComPtr<ISpRecognizer> recognizer;
	CComPtr<ISpRecoContext> recocontext;
	CComPtr<ISpRecoGrammar> g_cpCmdGrammar;
	slider slide;
	HRESULT hr;
	IEnumSpObjectTokens* cpEnum;
	ULONG count=0;
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
// CTts_finalDlg dialog

CTts_finalDlg::CTts_finalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTts_finalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTts_finalDlg)
	m_text = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTts_finalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTts_finalDlg)
	DDX_Control(pDX, IDC_RATE, m_rate);
	DDX_Control(pDX, IDC_VOLUME, m_volume);
	DDX_Control(pDX, IDSPEAK, m_speak);
	DDX_Text(pDX, IDC_TEXT, m_text);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTts_finalDlg, CDialog)
	//{{AFX_MSG_MAP(CTts_finalDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDSPEAK, OnSpeak)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_RESUME, OnResume)
	ON_WM_HSCROLL()
	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTts_finalDlg message handlers

BOOL CTts_finalDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	 pVoice = NULL;
		
	 if (FAILED(::CoInitialize(NULL)))
        return FALSE;
	 hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	 m_volume.SetRange (0,100,TRUE);
	 m_rate.SetRange (-10,10,TRUE);
	 pVoice->SetVolume(50);
	 pVoice->SetRate(0);
     /*recognizer.CoCreateInstance(CLSID_SpSharedRecognizer);
	 hr = recognizer->CreateRecoContext(&recocontext);
	 hr =recocontext->CreateGrammar(0, &g_cpCmdGrammar);
	 hr = g_cpCmdGrammar->LoadCmdFromResource(
	 NULL,
	MAKEINTRESOURCEW(IDR_CMD_CFG),
	L"SRGRAMMAR",
	MAKELANGID( LANG_NEUTRAL, SUBLANG_NEUTRAL), SPLO_DYNAMIC);
	hr = g_cpCmdGrammar->SetRuleState( NULL, NULL,SPRS_ACTIVE);
	*/
       
//if ( FAILED( hr ) ) //Leave application
	return TRUE;  // return TRUE  unless you set the focus to a control

}

void CTts_finalDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTts_finalDlg::OnPaint() 
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
HCURSOR CTts_finalDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTts_finalDlg::OnSpeak() 
{
	// TODO: Add your control notification handler code here

		UpdateData(TRUE);
	if( SUCCEEDED( hr ) )
    {
	//	hr = SpEnumTokens(SPCAT_VOICES, NULL, NULL, &cpEnum);
	//	hr = cpEnum->GetCount(&ulCount);
		hr = pVoice->Speak(m_text.AllocSysString(), SPF_ASYNC, NULL );
		
    }

    ::CoUninitialize();
	
}

void CTts_finalDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
	pVoice->Release();
        pVoice = NULL;
}

void CTts_finalDlg::OnPause() 
{
	// TODO: Add your control notification handler code here
	pVoice->Pause();
			
}

void CTts_finalDlg::OnResume() 
{
	// TODO: Add your control notification handler code here
	pVoice->Resume();
}

void CTts_finalDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	int pos;
	int rate;
	pos=m_volume.GetPos ();
	rate=m_rate.GetPos ();

	pVoice->SetVolume(pos);//nMin*100/nMax);
	pVoice->SetRate(rate);
	//if(nPos>=60)
	//{
	//	MessageBox("hey"+nPos);
	//}

}

void CTts_finalDlg::OnBrowse() 
{
	// TODO: Add your control notification handler code here
	
}
