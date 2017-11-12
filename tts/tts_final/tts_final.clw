; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=slider
LastTemplate=CSliderCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "tts_final.h"

ClassCount=4
Class1=CTts_finalApp
Class2=CTts_finalDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=slider
Resource3=IDD_TTS_FINAL_DIALOG

[CLS:CTts_finalApp]
Type=0
HeaderFile=tts_final.h
ImplementationFile=tts_final.cpp
Filter=N
LastObject=CTts_finalApp

[CLS:CTts_finalDlg]
Type=0
HeaderFile=tts_finalDlg.h
ImplementationFile=tts_finalDlg.cpp
Filter=D
LastObject=IDC_VOICE
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=tts_finalDlg.h
ImplementationFile=tts_finalDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TTS_FINAL_DIALOG]
Type=1
Class=CTts_finalDlg
ControlCount=14
Control1=IDSPEAK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TEXT,edit,1350631552
Control5=IDC_PAUSE,button,1342242816
Control6=IDC_RESUME,button,1342242816
Control7=IDC_VOLUME,msctls_trackbar32,1342242832
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_RATE,msctls_trackbar32,1342242832
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352

[CLS:slider]
Type=0
HeaderFile=slider.h
ImplementationFile=slider.cpp
BaseClass=CSliderCtrl
Filter=W
LastObject=slider
VirtualFilter=KWC

