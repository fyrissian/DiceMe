
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
	afx_msg void OnBnClickedD7();
	afx_msg void OnBnClickedD8();
	afx_msg void OnBnClickedD9();
	afx_msg void OnBnClickedD10();
	afx_msg void OnBnClickedD11();
	afx_msg void OnBnClickedD12();
	afx_msg void OnBnClickedD14();
	afx_msg void OnBnClickedD15();
	afx_msg void OnBnClickedD16();
	afx_msg void OnBnClickedD18();
	afx_msg void OnBnClickedD20();
	afx_msg void OnBnClickedD22();
	afx_msg void OnBnClickedD24();
	afx_msg void OnBnClickedD25();
	afx_msg void OnBnClickedD30();
	afx_msg void OnBnClickedD40();
	afx_msg void OnBnClickedD50();
	afx_msg void OnBnClickedD100();
	afx_msg void OnBnClickedD500();
	afx_msg void OnBnClickedD1000();
	afx_msg void OnBnClickedD5000();
	afx_msg void OnBnClickedD10000();
	afx_msg void OnBnClickedCustom();
};
