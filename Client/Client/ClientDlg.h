// ClientDlg.h : ���Y��
//

#pragma once


// CClientDlg ��ܤ��
class CClientDlg : public CDialog
{
// �غc
public:
	CClientDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
	enum { IDD = IDD_CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedConnent();
};
