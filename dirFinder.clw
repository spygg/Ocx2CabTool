; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDirFinderDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "dirFinder.h"

ClassCount=4
Class1=CDirFinderApp
Class2=CDirFinderDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DIRFINDER_DIALOG

[CLS:CDirFinderApp]
Type=0
HeaderFile=dirFinder.h
ImplementationFile=dirFinder.cpp
Filter=N

[CLS:CDirFinderDlg]
Type=0
HeaderFile=dirFinderDlg.h
ImplementationFile=dirFinderDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=dirFinderDlg.h
ImplementationFile=dirFinderDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIRFINDER_DIALOG]
Type=1
Class=CDirFinderDlg
ControlCount=8
Control1=IDC_BUTTON_GEN,button,1342242816
Control2=IDC_BUTTON_QUIT,button,1342242816
Control3=IDC_BUTTON_BROWS,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_FILE,edit,1484849280
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_FILE_DEST,edit,1484849280
Control8=IDC_BUTTON_BROWS_DEST,button,1342242816

