// dirFinderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dirFinder.h"
#include "dirFinderDlg.h"
#include <IO.H>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
#define  BUFFER_SIZE 1024 * 1024 * 4
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
// CDirFinderDlg dialog

CDirFinderDlg::CDirFinderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDirFinderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDirFinderDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDirFinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDirFinderDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDirFinderDlg, CDialog)
	//{{AFX_MSG_MAP(CDirFinderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_GEN, OnButtonGen)
	ON_BN_CLICKED(IDC_BUTTON_QUIT, OnButtonQuit)
	ON_BN_CLICKED(IDC_BUTTON_BROWS, OnButtonBrows)
	ON_BN_CLICKED(IDC_BUTTON_BROWS_DEST, OnButtonBrowsDest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDirFinderDlg message handlers

BOOL CDirFinderDlg::OnInitDialog()
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
	

	m_szDestDirList = new char[BUFFER_SIZE];
	
	memset(m_szDestDirList, 0, BUFFER_SIZE);

	SetDlgItemText(IDC_EDIT_FILE_DEST, "c:\\webocx\\");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDirFinderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDirFinderDlg::OnPaint() 
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
HCURSOR CDirFinderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDirFinderDlg::UpdateDestDirs(CString szCurrentDir)
{


	CString strSrcDir = szCurrentDir.Right(szCurrentDir.GetLength() - m_szSrcDir.GetLength());

	memset(m_szDestDirList, 0, strlen(m_szDestDirList) + 1);
	LoadIniFile("DefaultInstall", "CopyFiles", m_szDestDirList);
	if(strcmp(m_szDestDirList, "") == 0)
	{
		strcat(m_szDestDirList,  "FileList,");
		strcat(m_szDestDirList,  "FileList\\");
		strcat(m_szDestDirList,  strSrcDir);
	}
	else
	{
		strcat(m_szDestDirList, ",");
		strcat(m_szDestDirList,  "FileList\\");
		strcat(m_szDestDirList, strSrcDir);
	}
	SaveIniFile("DefaultInstall", "CopyFiles", m_szDestDirList);

	CString key;
	CString value;

	value.Format("%s", m_szDestDir.Left(m_szDestDir.GetLength() - 1));
	value.Replace("C:", "30,");
	value.Replace("c:", "30,");

	SaveIniFile("DestinationDirs", "FileList", value);

	key = "FileList\\" + strSrcDir;

	SaveIniFile("DestinationDirs", key, value);

}

void CDirFinderDlg::UpdateDestFiles(CString szFilePath, CString szFileName)
{
	TRACE("%s\n", szFilePath);

	TRACE("%s\n", szFileName);

	CString session;
	CString key;
	CString destvalue;
	CString srcValue;

	CString temp = szFilePath.Mid(m_szSrcDir.GetLength() - 1, szFilePath.GetLength() - szFileName.GetLength() - m_szSrcDir.GetLength());
	session = "FileList" + temp;
	
	key = szFileName;
	destvalue = temp + "\\" + szFileName;
	SaveIniFile(session, key, destvalue);


	if(szFileName.Right(4).CompareNoCase(".inf") == 0)
	{
		int iRet = MessageBox("监测到Inf文件" + szFileName + "可能会冲突,删除?", "删除?", MB_YESNO);

		if(IDYES == iRet)
		{
		
		}
		else
		{
			CFile file;
			file.Rename(szFilePath, szFilePath.Left(szFilePath.GetLength() - 3) + "bak");
		}
	}

	if(szFileName.Right(4).CompareNoCase(".ocx") == 0)
	{
		CString ocxRegeist = m_szDestDir + szFileName;
		SaveIniFile("RegisterDLL", szFileName, ocxRegeist);
	}
}

void CDirFinderDlg::RecurseDir(LPCTSTR pstrSrc, LPCTSTR pstrDest, int len)
{
	CFileFind finder;
	CString strWildcard(pstrSrc);

	strWildcard += _T("\\*.*");
	
	int iIndex = -1;
	BOOL bWorking = finder.FindFile(strWildcard);
	bool bFlag = false;


	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		
		if (finder.IsDots())
		{
			continue;
		}
		
		if (finder.IsDirectory())//如果是文件夹
		{

			UpdateDestDirs(finder.GetFilePath());
			RecurseDir(finder.GetFilePath(), pstrDest, len);
		}
		else//数据文件
		{
			UpdateDestFiles(finder.GetFilePath(), finder.GetFileName());
		}
	}
	
	finder.Close();
}




void CDirFinderDlg::OnButtonGen() 
{
	m_szSrcDir.Empty();
	m_szDestDir.Empty();

	GetDlgItemText(IDC_EDIT_FILE, m_szSrcDir);
	GetDlgItemText(IDC_EDIT_FILE_DEST, m_szDestDir);


	if(m_szSrcDir.IsEmpty() || m_szDestDir.IsEmpty())
	{
		MessageBox("请选择文件夹!", "错误提示", MB_OK);
		return;
	}


	InitSetting();

	RecurseDir(m_szSrcDir, m_szDestDir, m_szSrcDir.GetLength());

	char szFilePath[255] = {0};
	char szFileName[255] = {0};
	
	GetModulePath(szFilePath);	
	sprintf(szFileName, "%s%s", szFilePath, "sample_xxxxxx_sample.ini");

	
	
	CopyFile(szFileName, m_szSrcDir + "myCab.inf", FALSE);
	
	sprintf(szFileName, "%s%s", szFilePath, "CABARC.EXE");
	CopyFile(szFileName, m_szSrcDir + "CABARC.EXE", FALSE);
	
	char szBat[255] = {0};
	sprintf(szBat, "%srealse.bat", m_szSrcDir);
	FILE *fp = fopen(szBat, "w");

	if(fp)
	{
		fprintf(fp, "cd %s\n", m_szSrcDir);
		fprintf(fp, "%s\n", "del *.inf");
		fprintf(fp, "%s\n", "del *.cab");
		fprintf(fp, "%s\n", "CABARC -r  -p N myOcx.cab *");
		fclose(fp);
	}
	
	::ShellExecute(NULL, NULL, szBat, NULL, NULL, SW_SHOW);
	::ShellExecute(NULL, "open", m_szSrcDir, NULL, NULL, SW_SHOW);

}

void CDirFinderDlg::InitSetting()
{
	SaveIniFile(NULL, NULL, NULL);

	//生成公用信息
	//签名
	SaveIniFile("Version", "signature", "$CHICAGO$");
	
	//版本
	SaveIniFile("Version", "AdvancedINF", "2.0");
	
	//注册入口
	SaveIniFile("DefaultInstall", "RegisterOCXs", "RegisterDLL");
	
// 	//目的盘符入口
// 	SaveIniFile("SourceDisksNames", "1", ",,0");

	//清空目的文件夹入口
	SaveIniFile("DefaultInstall", "CopyFiles", "");
}


void CDirFinderDlg::OnButtonQuit() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CDirFinderDlg::OnButtonBrows() 
{
	// TODO: Add your control notification handler code here
	char szDisplayName[MAX_PATH] = {0};
	BROWSEINFO browse_info;
	browse_info.hwndOwner = m_hWnd;
	browse_info.iImage = 0;
	browse_info.lParam = (long)this;
	browse_info.lpfn = NULL;
	browse_info.lpszTitle = "文件保存路径";
	browse_info.pidlRoot = NULL;
	browse_info.pszDisplayName = szDisplayName;
	browse_info.ulFlags = BIF_RETURNONLYFSDIRS ;
	
	ITEMIDLIST *pItemIdList = SHBrowseForFolder(&browse_info);
	if (pItemIdList != NULL)
	{
		TCHAR szPathName[MAX_PATH] = {0};
		if (SHGetPathFromIDList(pItemIdList, szPathName))
		{
			if(_taccess(szPathName, 0) == -1)
			{
				MessageBox("路径不可用!", "错误", MB_OK);
				return;
			}
			
			if(szPathName[strlen(szPathName) - 1] != '\\')
				strcat(szPathName, "\\");
			
			SetDlgItemText(IDC_EDIT_FILE, szPathName);
		}
	}

}

void CDirFinderDlg::OnButtonBrowsDest() 
{
	// TODO: Add your control notification handler code here
	char szDisplayName[MAX_PATH] = {0};
	BROWSEINFO browse_info;
	browse_info.hwndOwner = m_hWnd;
	browse_info.iImage = 0;
	browse_info.lParam = (long)this;
	browse_info.lpfn = NULL;
	browse_info.lpszTitle = "文件保存路径";
	browse_info.pidlRoot = NULL;
	browse_info.pszDisplayName = szDisplayName;
	browse_info.ulFlags = BIF_RETURNONLYFSDIRS ;
	
	ITEMIDLIST *pItemIdList = SHBrowseForFolder(&browse_info);
	if (pItemIdList != NULL)
	{
		TCHAR szPathName[MAX_PATH] = {0};
		if (SHGetPathFromIDList(pItemIdList, szPathName))
		{
			if(_taccess(szPathName, 0) == -1)
			{
				MessageBox("路径不可用!", "错误", MB_OK);
				return;
			}

			if(szPathName[0] != 'c' && szPathName[0] != 'C')
			{
				MessageBox("还是选C盘吧", "错误", MB_OK);
				return;
			}
			
			if(szPathName[strlen(szPathName) - 1] != '\\')
				strcat(szPathName, "\\");
			
			SetDlgItemText(IDC_EDIT_FILE_DEST, szPathName);
		}
	}
}

CDirFinderDlg::~CDirFinderDlg()
{
	if(m_szDestDirList)
	{
		delete [] m_szDestDirList;
		m_szDestDirList = NULL;
	}
}
