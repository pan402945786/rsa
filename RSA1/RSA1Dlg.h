
// RSA1Dlg.h : ͷ�ļ�
//

#pragma once


// CRSA1Dlg �Ի���
class CRSA1Dlg : public CDialogEx
{
// ����
public:
	CRSA1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RSA1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButton1();
	CString edit_1;
	afx_msg void OnCbnSelchangeCombo1();
	CString RateSelect;
	afx_msg void OnBnClickedButtonEncpt();
	afx_msg void OnBnClickedButtonDecpt();
};
