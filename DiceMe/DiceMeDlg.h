
// DiceMeDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CDiceMeDlg dialog
class CDiceMeDlg : public CDialogEx
{
// Construction
public:
	CDiceMeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DICEME_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRolldie();
	afx_msg void OnLbnSelchangeResults();
	// variable for the list box control
	CListBox resultsList;
	int die_Selected;
	afx_msg void OnBnClickedD2();
	afx_msg void OnBnClickedD3();
	afx_msg void OnBnClickedD4();
	afx_msg void OnBnClickedD5();
	afx_msg void OnBnClickedD6();
	afx_msg void OnBnClickedClearresults();
};
