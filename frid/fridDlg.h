// fridDlg.h : header file
//

#include "afxwin.h"
#if !defined(AFX_FRIDDLG_H__8F746348_6D19_4E7D_BDD6_44A76D2745EB__INCLUDED_)
#define AFX_FRIDDLG_H__8F746348_6D19_4E7D_BDD6_44A76D2745EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFridDlg dialog

class CFridDlg : public CDialog
{
// Construction
public:
	CFridDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFridDlg)
	enum { IDD = IDD_FRID_DIALOG };
	CButton	m_uid;
	CButton	m_open;
	CEdit	m_Key;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFridDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFridDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRada();
	afx_msg void OnRadb();
	afx_msg void OnBUTkey();
	afx_msg void OnButnOpen();
	afx_msg void OnButnUid();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSta2();
	afx_msg void OnEnChangeEdit1();






	

	


	// ����Ǯ��������
	CComboBox m_EMSectorCtrl;
	// ����Ǯ�������
	CComboBox m_EMSectionCtrl;
	// ����Ǯ�������
	CEdit m_EMBalanceCtrl;
	// ��ֵ���
	CEdit m_EMRechargeMoneyCtrl;
	// �ۿ���
	CEdit m_EMPayMoneyCtrl;
	// ����Ǯ����״̬
	CEdit m_EMStatueCtrl;

	// ����Ǯ������ѯ���
	afx_msg void OnBnClickedButton2EmQueryBalance();
	// ����Ǯ����Ǯ����ʼ��
	afx_msg void OnBnClickedButton1EmInit();
	afx_msg void OnBnClickedButton3EmRecharge();
	afx_msg void OnBnClickedButton4EmPay();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRIDDLG_H__8F746348_6D19_4E7D_BDD6_44A76D2745EB__INCLUDED_)
