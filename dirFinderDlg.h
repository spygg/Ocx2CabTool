// dirFinderDlg.h : header file
//

#if !defined(AFX_DIRFINDERDLG_H__FAE7ED50_F30D_4711_AA99_0A53255FB311__INCLUDED_)
#define AFX_DIRFINDERDLG_H__FAE7ED50_F30D_4711_AA99_0A53255FB311__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDirFinderDlg dialog

class CDirFinderDlg : public CDialog
{
// Construction
public:
	CDirFinderDlg(CWnd* pParent = NULL);	// standard constructor
	~CDirFinderDlg();	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDirFinderDlg)
	enum { IDD = IDD_DIRFINDER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDirFinderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDirFinderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonGen();
	afx_msg void OnButtonQuit();
	afx_msg void OnButtonBrows();
	afx_msg void OnButtonBrowsDest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


private:
	void RecurseDir(LPCTSTR pstrSrc, LPCTSTR pstrDest, int len);
	void InitSetting();
	void UpdateDestDirs(CString szCurrentDir);
	void UpdateDestFiles(CString szFilePath, CString szFileName);
private:
	char *m_szDestDirList;
	CString m_szDestDir;
	CString m_szSrcDir;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIRFINDERDLG_H__FAE7ED50_F30D_4711_AA99_0A53255FB311__INCLUDED_)
