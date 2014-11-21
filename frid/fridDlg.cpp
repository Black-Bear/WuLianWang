// fridDlg.cpp : implementation file
//

#include "stdafx.h"
#include "frid.h"
#include "fridDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

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
// CFridDlg dialog

CFridDlg::CFridDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFridDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFridDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFridDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFridDlg)

	// NOTE: the ClassWizard will add DDX and DDV calls here

	DDX_Control(pDX, IDC_EDIkey, m_Key);

	//}}AFX_DATA_MAP

	DDX_Control(pDX, IDC_EDIT2_EM, m_EMRechargeMoneyCtrl);
	DDX_Control(pDX, IDC_EDIT3_EM, m_EMPayMoneyCtrl);
	DDX_Control(pDX, IDC_EDIT4_EM, m_EMStatueCtrl);
	DDX_Control(pDX, IDC_COMBO2_EM, m_EMSectorCtrl);
	DDX_Control(pDX, IDC_COMBO1_EM, m_EMSectionCtrl);
	DDX_Control(pDX, IDC_EDIT1_EM, m_EMBalanceCtrl);
}

BEGIN_MESSAGE_MAP(CFridDlg, CDialog)
	//{{AFX_MSG_MAP(CFridDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADA, OnRada)
	ON_BN_CLICKED(IDC_RADB, OnRadb)
	ON_BN_CLICKED(IDC_BUTkey, OnBUTkey)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON2_EM, CFridDlg::OnBnClickedButton2EmQueryBalance)
	ON_BN_CLICKED(IDC_BUTTON1_EM, CFridDlg::OnBnClickedButton1EmInit)
	ON_BN_CLICKED(IDC_BUTTON3_EM, CFridDlg::OnBnClickedButton3EmRecharge)
	ON_BN_CLICKED(IDC_BUTTON4_EM, CFridDlg::OnBnClickedButton4EmPay)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFridDlg message handlers

BOOL CFridDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFridDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFridDlg::OnPaint() 
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
HCURSOR CFridDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}










// 电子钱包－钱包初始化
void CFridDlg::OnBnClickedButton1EmInit()
{
	// TODO: 在此添加控件通知处理程序代码
	m_EMRechargeMoneyCtrl.SetWindowText(_T(""));
	m_EMPayMoneyCtrl.SetWindowText(_T(""));
	m_EMStatueCtrl.SetWindowText(_T(""));
	m_EMSectorCtrl.SetCurSel(-1);
	m_EMSectionCtrl.SetCurSel(-1);
	m_EMBalanceCtrl.SetWindowText(_T(""));
}

// 电子钱包－查询余额
void CFridDlg::OnBnClickedButton2EmQueryBalance()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strPage;
	m_EMSectorCtrl.GetWindowText(strPage);

	CString strBlock;
	m_EMSectionCtrl.GetWindowText(strBlock);

	unsigned char pswtype = 0x0A;
	unsigned char psw[] = "0xFFFFFFFFFFFF";

	CString strMoney;
	m_EMRechargeMoneyCtrl.GetWindowText(strMoney);
	long lMoney = atol(strMoney);

	int rst = read_account(atoi(strPage),atoi(strBlock),pswtype,psw,&lMoney);

}

// 电子钱包－充值
void CFridDlg::OnBnClickedButton3EmRecharge()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strPage;
	m_EMSectorCtrl.GetWindowText(strPage);

	CString strBlock;
	m_EMSectionCtrl.GetWindowText(strBlock);

	unsigned char pswtype = 0x0A;
	unsigned char psw[] = "0xFFFFFFFFFFFF";

	CString strAccount;
	m_EMRechargeMoneyCtrl.GetWindowText(strAccount);

	int rst = add_account(atoi(strPage),atoi(strBlock),pswtype,psw,atoi(strAccount));
}

// 电子钱包－扣款
void CFridDlg::OnBnClickedButton4EmPay()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strPage;
	m_EMSectorCtrl.GetWindowText(strPage);

	CString strBlock;
	m_EMSectionCtrl.GetWindowText(strBlock);

	unsigned char pswtype = 0x0A;
	unsigned char psw[] = "0xFFFFFFFFFFFF";


	CString strPay;
	m_EMPayMoneyCtrl.GetWindowText(strPay);

	int rst = sub_account(atoi(strPage),atoi(strBlock),pswtype,psw,atoi(strPay));
}

bool Ra=0;
bool Rb=0;

void CFridDlg::OnRada() 
{
	Ra=1;
	
}
void CFridDlg::OnRadb() 
{
	Rb=1;
}




void CFridDlg::OnBUTkey() 
{
	m_Key.SetWindowText("0xFFFFFFFFFFFF");
}

/*void CFridDlg::OnUpdateEDIkey() 
{
	if(Ra&&OnBUTkey){
	m_Key="A密钥：0x0A";
	}
	else if(Rb&&OnBUTkey){
	m_Key="B密钥：0x0B";
	}
	else{m_Key="0";}
	
}*/

