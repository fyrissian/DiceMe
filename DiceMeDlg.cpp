
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
	ON_BN_CLICKED(IDC_D7, &CDiceMeDlg::OnBnClickedD7)
	ON_BN_CLICKED(IDC_D8, &CDiceMeDlg::OnBnClickedD8)
	ON_BN_CLICKED(IDC_D9, &CDiceMeDlg::OnBnClickedD9)
	ON_BN_CLICKED(IDC_D10, &CDiceMeDlg::OnBnClickedD10)
	ON_BN_CLICKED(IDC_D11, &CDiceMeDlg::OnBnClickedD11)
	ON_BN_CLICKED(IDC_D12, &CDiceMeDlg::OnBnClickedD12)
	ON_BN_CLICKED(IDC_D14, &CDiceMeDlg::OnBnClickedD14)
	ON_BN_CLICKED(IDC_D15, &CDiceMeDlg::OnBnClickedD15)
	ON_BN_CLICKED(IDC_D16, &CDiceMeDlg::OnBnClickedD16)
	ON_BN_CLICKED(IDC_D18, &CDiceMeDlg::OnBnClickedD18)
	ON_BN_CLICKED(IDC_D20, &CDiceMeDlg::OnBnClickedD20)
	ON_BN_CLICKED(IDC_D22, &CDiceMeDlg::OnBnClickedD22)
	ON_BN_CLICKED(IDC_D24, &CDiceMeDlg::OnBnClickedD24)
	ON_BN_CLICKED(IDC_D25, &CDiceMeDlg::OnBnClickedD25)
	ON_BN_CLICKED(IDC_D30, &CDiceMeDlg::OnBnClickedD30)
	ON_BN_CLICKED(IDC_D40, &CDiceMeDlg::OnBnClickedD40)
	ON_BN_CLICKED(IDC_D50, &CDiceMeDlg::OnBnClickedD50)
	ON_BN_CLICKED(IDC_D100, &CDiceMeDlg::OnBnClickedD100)
	ON_BN_CLICKED(IDC_D500, &CDiceMeDlg::OnBnClickedD500)
	ON_BN_CLICKED(IDC_D1000, &CDiceMeDlg::OnBnClickedD1000)
	ON_BN_CLICKED(IDC_D5000, &CDiceMeDlg::OnBnClickedD5000)
	ON_BN_CLICKED(IDC_D10000, &CDiceMeDlg::OnBnClickedD10000)
	ON_BN_CLICKED(IDC_CUSTOM, &CDiceMeDlg::OnBnClickedCustom)
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
		case 5: //d7
			newRnd %= 7;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 6: //d8
			newRnd %= 8;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 7: //d9
			newRnd %= 9;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 8: //d10
			newRnd %= 10;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 9: //d11
			newRnd %= 11;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 10: //d12
			newRnd %= 12;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 11: //d14
			newRnd %= 14;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 12: //d15
			newRnd %= 15;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 13: //d16
			newRnd %= 16;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 14: //d18
			newRnd %= 18;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 15: //d20
			newRnd %= 20;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 16: //d22
			newRnd %= 22;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 17: //d24
			newRnd %= 24;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 18: //d25
			newRnd %= 25;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 19: //d30
			newRnd %= 30;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 20: //d40
			newRnd %= 40;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 21: //d50
			newRnd %= 50;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 22: //d100
			newRnd %= 100;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 23: //d500
			newRnd %= 500;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 24: //d1000
			newRnd %= 1000;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 25: //d5000
			newRnd %= 5000;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 26: //d10000
			newRnd %= 10000;
			roll.Format(_T("%d"), newRnd+1);
			resultsList.AddString(roll); 
			break;
		case 27: //dCustom
			newRnd %= 777; // using test value of 777 until custom input field implemented
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


void CDiceMeDlg::OnBnClickedD7()
{
	// TODO: Add your control notification handler code here
	die_Selected = 5;
}


void CDiceMeDlg::OnBnClickedD8()
{
	// TODO: Add your control notification handler code here
	die_Selected = 6;
}


void CDiceMeDlg::OnBnClickedD9()
{
	// TODO: Add your control notification handler code here
	die_Selected = 7;
}


void CDiceMeDlg::OnBnClickedD10()
{
	// TODO: Add your control notification handler code here
	die_Selected = 8;
}


void CDiceMeDlg::OnBnClickedD11()
{
	// TODO: Add your control notification handler code here
	die_Selected = 9;
}


void CDiceMeDlg::OnBnClickedD12()
{
	// TODO: Add your control notification handler code here
	die_Selected = 10;
}


void CDiceMeDlg::OnBnClickedD14()
{
	// TODO: Add your control notification handler code here
	die_Selected = 11;
}


void CDiceMeDlg::OnBnClickedD15()
{
	// TODO: Add your control notification handler code here
	die_Selected = 12;
}


void CDiceMeDlg::OnBnClickedD16()
{
	// TODO: Add your control notification handler code here
	die_Selected = 13;
}


void CDiceMeDlg::OnBnClickedD18()
{
	// TODO: Add your control notification handler code here
	die_Selected = 14;
}


void CDiceMeDlg::OnBnClickedD20()
{
	// TODO: Add your control notification handler code here
	die_Selected = 15;
}


void CDiceMeDlg::OnBnClickedD22()
{
	// TODO: Add your control notification handler code here
	die_Selected = 16;
}


void CDiceMeDlg::OnBnClickedD24()
{
	// TODO: Add your control notification handler code here
	die_Selected = 17;
}


void CDiceMeDlg::OnBnClickedD25()
{
	// TODO: Add your control notification handler code here
	die_Selected = 18;
}


void CDiceMeDlg::OnBnClickedD30()
{
	// TODO: Add your control notification handler code here
	die_Selected = 19;
}


void CDiceMeDlg::OnBnClickedD40()
{
	// TODO: Add your control notification handler code here
	die_Selected = 20;
}


void CDiceMeDlg::OnBnClickedD50()
{
	// TODO: Add your control notification handler code here
	die_Selected = 21;
}


void CDiceMeDlg::OnBnClickedD100()
{
	// TODO: Add your control notification handler code here
	die_Selected = 22;
}


void CDiceMeDlg::OnBnClickedD500()
{
	// TODO: Add your control notification handler code here
	die_Selected = 23;
}


void CDiceMeDlg::OnBnClickedD1000()
{
	// TODO: Add your control notification handler code here
	die_Selected = 24;
}


void CDiceMeDlg::OnBnClickedD5000()
{
	// TODO: Add your control notification handler code here
	die_Selected = 25;
}


void CDiceMeDlg::OnBnClickedD10000()
{
	// TODO: Add your control notification handler code here
	die_Selected = 26;
}


void CDiceMeDlg::OnBnClickedCustom()
{
	// TODO: Add your control notification handler code here
	die_Selected = 27;
}
