
// DiceMeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DiceMe.h"
#include "DiceMeDlg.h"
#include "afxdialogex.h"
#include "PRNG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDiceMeDlg dialog




CDiceMeDlg::CDiceMeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiceMeDlg::IDD, pParent)
	, die_Selected(4)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDiceMeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RESULTS, resultsList);
	//DDX_Control(pDX, IDC_D2, die_Selected);
	DDX_Radio(pDX, IDC_D2, die_Selected);
}

BEGIN_MESSAGE_MAP(CDiceMeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ROLLDIE, &CDiceMeDlg::OnBnClickedRolldie)
	ON_LBN_SELCHANGE(IDC_RESULTS, &CDiceMeDlg::OnLbnSelchangeResults)
	//ON_BN_CLICKED(IDC_D2, &CDiceMeDlg::OnBnClickedD2)
	ON_BN_CLICKED(IDC_D2, &CDiceMeDlg::OnBnClickedD2)
	ON_BN_CLICKED(IDC_D3, &CDiceMeDlg::OnBnClickedD3)
	ON_BN_CLICKED(IDC_D4, &CDiceMeDlg::OnBnClickedD4)
	ON_BN_CLICKED(IDC_D5, &CDiceMeDlg::OnBnClickedD5)
	ON_BN_CLICKED(IDC_D6, &CDiceMeDlg::OnBnClickedD6)
	ON_BN_CLICKED(IDC_CLEARRESULTS, &CDiceMeDlg::OnBnClickedClearresults)
END_MESSAGE_MAP()


// CDiceMeDlg message handlers

BOOL CDiceMeDlg::OnInitDialog()
{
	initQ();
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	die_Selected = 4;
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDiceMeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDiceMeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDiceMeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDiceMeDlg::OnBnClickedRolldie()
{
	// TODO: Add your control notification handler code here
	CString roll;
	unsigned int newRnd = MWC256();
	switch(die_Selected)
	{
		case 0: // d2
			newRnd %= 2;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 1: //d3
			newRnd %= 3;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 2: // d4
			newRnd %= 4;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 3: //d5
			newRnd %= 5;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 4: //d6
			newRnd %= 6;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
	}
}


void CDiceMeDlg::OnLbnSelchangeResults()
{
	// TODO: Add your control notification handler code here
}




void CDiceMeDlg::OnBnClickedD2()
{
	// TODO: Add your control notification handler code here
	die_Selected = 0;
}


void CDiceMeDlg::OnBnClickedD3()
{
	// TODO: Add your control notification handler code here
	die_Selected = 1;
}


void CDiceMeDlg::OnBnClickedD4()
{
	// TODO: Add your control notification handler code here
	die_Selected = 2;
}


void CDiceMeDlg::OnBnClickedD5()
{
	// TODO: Add your control notification handler code here
	die_Selected = 3;
}


void CDiceMeDlg::OnBnClickedD6()
{
	// TODO: Add your control notification handler code here
	die_Selected = 4;
}


void CDiceMeDlg::OnBnClickedClearresults()
{
	// TODO: Add your control notification handler code here
	resultsList.ResetContent();
}
