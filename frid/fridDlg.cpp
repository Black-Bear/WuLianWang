// fridDlg.cpp : implementation file
//

#include "stdafx.h"
#include "frid.h"
#include "fridDlg.h"
#include "ZM124U.h"
#include "Resource.h"

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

	Ra = 0;
	Rb = 0;

}

void CFridDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFridDlg)
	DDX_Control(pDX, IDC_BUTN_KEY, m_a);
	DDX_Control(pDX, IDC_EDIT_CODE, d_code);
	DDX_Control(pDX, IDC_COMBO_BLOCK, d_block);
	DDX_Control(pDX, IDC_COMBO_PAGE, d_page);
	DDX_Control(pDX, IDC_BUTN_UID, m_uid);
	DDX_Control(pDX, IDC_BUTN_OPEN, m_open);
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
	ON_BN_CLICKED(IDC_BUTN_OPEN, OnButnOpen)
	ON_BN_CLICKED(IDC_BUTN_UID, OnButnUid)
	ON_BN_CLICKED(IDC_BUTN_KEY, OnButnKey)
	ON_BN_CLICKED(IDC_BUTN_READ_BLOCK, OnButnReadBlock)
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


BOOL CFridDlg::ErrMsg(const int resultCode)
{
	if (0 == resultCode)
		return TRUE;

	switch (resultCode)
	{
	case -1:
		{
			AfxMessageBox(_T("卡片类型不对"));
		}break;

	case -2:
		{
			AfxMessageBox(_T("无卡"));
		}break;
	case -3:
		{
			AfxMessageBox(_T("有卡未上电"));
		}break;

	case -4:
		{
			AfxMessageBox(_T("卡片无应答"));
		}break;

	case -5:
		{
			AfxMessageBox(_T("BCC校验错误"));
		}break;

	case -6:
		{
			AfxMessageBox(_T("接收超时"));
		}break;

	case -7:
		{
			AfxMessageBox(_T("执行失败"));
		}break;

	case -8:
		{
			AfxMessageBox(_T("卡片位置错误"));
		}break;

	case -9:
		{
			AfxMessageBox(_T("设置失败"));
		}break;

	case -10:
		{
			AfxMessageBox(_T("无卡"));
		}break;

	case -11:
		{
			AfxMessageBox(_T("读卡器连接错"));
		}break;

	case -12:
		{
			AfxMessageBox(_T("未建立连接(没有执行打开设备函数)"));
		}break;

	case -13:
		{
			AfxMessageBox(_T("(动态库)不支持该命令"));
		}break;

	case -14:
		{
			AfxMessageBox(_T("(发给动态库的)命令参数错"));
		}break;

	case -15:
		{
			AfxMessageBox(_T("信息校验和出错"));
		}break;

	case -16:
		{
			AfxMessageBox(_T("卡片上电失败"));
		}break;

	case -17:
		{
			AfxMessageBox(_T("卡片复位失败"));
		}break;

	case -18:
		{
			AfxMessageBox(_T("卡片下电失败"));
		}break;

	default:
		{
			AfxMessageBox(_T("未知错误！"));
		}break;

	}

	return FALSE;
}


BOOL CFridDlg::GetPswData(unsigned char& pswType,unsigned char* pswBuf,const int bufLen)
{
	int radioNum = GetCheckedRadioButton(IDC_RADIO_A,IDC_RADIO_B);

	if (IDC_RADIO_A == radioNum)
	{
		pswType = 0x0A;
	}
	else if (IDC_RADIO_B == radioNum)
	{
		pswType = 0x0B;
	}
	else
	{
		AfxMessageBox(_T("请选择密钥设置！"));
		return FALSE;
	}

	char c[256];
	d_code.GetWindowTextA(c,bufLen);

	memset(pswBuf,NULL,bufLen);
	for (int i = 0; i < d_code.GetWindowTextLength(); ++i)
	{
		memcpy(&pswBuf[i],&c[i],sizeof(char));
	}

	/*
	CString pswStr;
	d_code.GetWindowText(pswStr);

	CStringA pswStrA;
	if (pswStr.GetLength() > 0)
	{
		pswStrA = pswStr;
	}
	else
	{
		pswStrA = "0xFFFFFFFFFFFF";
	}

	memset(pswBuf,NULL,bufLen);
	char* c = pswStrA.GetBuffer();
	for (int i = 0; i < pswStrA.GetLength(); ++i)
	{
		memcpy(&pswBuf[i],&c[i],sizeof(char));
	}
	*/

	return TRUE;
}



// 电子钱包－钱包初始化
void CFridDlg::OnBnClickedButton1EmInit()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strPage;
	m_EMSectorCtrl.GetWindowText(strPage);

	CString strBlock;
	m_EMSectionCtrl.GetWindowText(strBlock);

	unsigned char pswType;
	const int len = 256;
	unsigned char pswBuf[len];
	if (!GetPswData(pswType,pswBuf,len))
		return;


	long lMoney = 0l;
	int rst =  write_account(atoi(strPage),atoi(strBlock),pswType,pswBuf,lMoney);

	if (ErrMsg(rst))
	{
		m_EMRechargeMoneyCtrl.SetWindowText(_T(""));
		m_EMPayMoneyCtrl.SetWindowText(_T(""));
		m_EMStatueCtrl.SetWindowText(_T(""));
		m_EMSectorCtrl.SetCurSel(-1);
		m_EMSectionCtrl.SetCurSel(-1);
		m_EMBalanceCtrl.SetWindowText(_T(""));
	}
}

// 电子钱包－查询余额
void CFridDlg::OnBnClickedButton2EmQueryBalance()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strPage;
	m_EMSectorCtrl.GetWindowText(strPage);

	CString strBlock;
	m_EMSectionCtrl.GetWindowText(strBlock);

	unsigned char pswType = NULL;
	const int len = 256;
	unsigned char pswBuf[len];
	if (!GetPswData(pswType,pswBuf,len))
		return;


	long lMoney = 0l;
	int rst = read_account(atoi(strPage),atoi(strBlock),pswType,pswBuf,&lMoney);

	if (ErrMsg(rst))
	{
		CString str;
		str.Format(_T("%l"),lMoney);
		m_EMBalanceCtrl.SetWindowText(str);
	}

}

// 电子钱包－充值
void CFridDlg::OnBnClickedButton3EmRecharge()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strPage;
	m_EMSectorCtrl.GetWindowText(strPage);

	CString strBlock;
	m_EMSectionCtrl.GetWindowText(strBlock);

	unsigned char pswType = NULL;
	const int len = 256;
	unsigned char pswBuf[len];
	if (!GetPswData(pswType,pswBuf,len))
		return;

	CString strAccount;
	m_EMRechargeMoneyCtrl.GetWindowText(strAccount);

	if (0 == strAccount.GetLength())
	{
		AfxMessageBox(_T("请输入充值金额"));
		return;
	}

	int rst = add_account(atoi(strPage),atoi(strBlock),pswType,pswBuf,atoi(strAccount));

	if (ErrMsg(rst))
	{
		m_EMStatueCtrl.SetWindowText(_T("充值成功"));
	}
}

// 电子钱包－扣款
void CFridDlg::OnBnClickedButton4EmPay()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strPage;
	m_EMSectorCtrl.GetWindowText(strPage);

	CString strBlock;
	m_EMSectionCtrl.GetWindowText(strBlock);

	unsigned char pswType = NULL;
	const int len = 256;
	unsigned char pswBuf[len];
	if (!GetPswData(pswType,pswBuf,len))
		return;


	CString strPay;
	m_EMPayMoneyCtrl.GetWindowText(strPay);

	if (0 == strPay.GetLength())
	{
		AfxMessageBox(_T("请输入扣款金额"));
		return;
	}


	int rst = sub_account(atoi(strPage),atoi(strBlock),pswType,pswBuf,atoi(strPay));

	if (ErrMsg(rst))
	{
		m_EMStatueCtrl.SetWindowText(_T("扣款成功"));
	}
}


void CFridDlg::OnRada() 
{
	Ra=1;
	Rb = 0;
}
void CFridDlg::OnRadb() 
{
	Ra = 0;
	Rb=1;
}


void CFridDlg::OnButnOpen() 
{
	// TODO: Add your control notification handler code here
		int j=IDD_PowerOn();
	if(j==0)
		m_open.SetWindowText("开启设备成功！");
	else
		m_open.SetWindowText("开启设备失败！");
}

void CFridDlg::OnButnUid() 
{
	// TODO: Add your control notification handler code here
	CString s,s1;
	unsigned char buff[1024];
	int buff_len;

	int j=find_14443(buff,&buff_len);
	if(0==j)
	{
	  s.Empty();
	  for(int i=0;i<buff_len;i++)
	  {
		  s1.Format("%02x",buff[i]);
		  s+=s1;
	  }
	  m_uid.SetWindowText(s);
	}
	else
	{
	   m_uid.SetWindowText("获取UID失败");
	}
}










void CFridDlg::OnButnKey() 
{
	// TODO: Add your control notification handler code here
	d_code.SetWindowText("FFFFFFFFFFFF");
//	GetDlgItem(IDC_EDIT_CODE)->SetWindowText("FFFFFFFFFFFF");
}


void CFridDlg::stringtohex(CString str, unsigned char *buff)
{
	CString s1;
	int len=str.GetLength();
	unsigned char buf[1024];
	int j;
	int i;
	char ch;
	
	str.MakeUpper();
	
	for (int i=0;i<len;i++)  //检测到A-F的情况
	{
		ch=str[i];
		
		if (ch>0x40)
		{
			buf[i]=(unsigned char)ch-0x37;
		} 
		else
		{
			buf[i]=(unsigned char)atoi(&ch); //将字符窜转换为整数   atoi(char *p)
		}
	}
	
	for (i=0;i<1024;i++)
	{
		buff[i]=0;
	}
	len+=1;
	
	for (j=0,i=0;j<len/2;)
	{
		buff[j]=(unsigned char)(buf[i++]<<4);
		buff[j++]|=buf[i++];
	}
}


void CFridDlg::OnButnReadBlock() 
{
	// TODO: Add your control notification handler code here
	int page;
	int block;
	unsigned char pswtype;
	unsigned char psw[1024];
	unsigned char buff[1024];
	int buff_len;
	CString s0,s1,getcode,code;

	page = d_page.GetCurSel();
	block = d_block.GetCurSel();
	UINT Key = GetCheckedRadioButton(IDC_RADIO_A,IDC_RADIO_B);
	switch (Key)
	{
	case IDC_RADIO_A : pswtype = 0x0A;  break;
	case IDC_RADIO_B : pswtype = 0x0B;  break;
	default : break;
	}


	
UpdateData(TRUE);
d_code.GetWindowText(getcode);
stringtohex(getcode,psw);	
code="FFFFFFFFFFFF";

if(getcode == code)
{
		int j = read_block(page,block,pswtype,psw,buff,&buff_len);
		if(j == 0)
		{
			s0.Empty();
			for (int k=0;k<buff_len;k++)
			{
				char ch = buff[k];
				s1.Format("%02x",buff[k]);
				s0+=s1;
			}

			switch(block)
			{
			case 0: GetDlgItem(IDC_EDIT_B0)->SetWindowText(s0); break;
			case 1: GetDlgItem(IDC_EDIT_B1)->SetWindowText(s0); break;
			case 2: GetDlgItem(IDC_EDIT_B2)->SetWindowText(s0); break;
			case 3: GetDlgItem(IDC_EDIT_B3)->SetWindowText(s0); break;
			default: break;
			}
		}
		else
		{
		switch (block)
			{
			case 0: GetDlgItem(IDC_EDIT_B0)->SetWindowText("读取块0信息失败！"); break;
			case 1: GetDlgItem(IDC_EDIT_B1)->SetWindowText("读取块1信息失败！"); break;
			case 2: GetDlgItem(IDC_EDIT_B2)->SetWindowText("读取块2信息失败！"); break;
			case 3: GetDlgItem(IDC_EDIT_B3)->SetWindowText("读取块3信息失败！"); break;
			default:break;
			}
		}
}
else 	MessageBox("输入密码错误！");
}


