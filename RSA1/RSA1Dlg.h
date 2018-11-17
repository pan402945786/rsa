
// RSA1Dlg.h : 头文件
//

#pragma once


// CRSA1Dlg 对话框
class CRSA1Dlg : public CDialogEx
{
// 构造
public:
	CRSA1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RSA1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
