
// RSA1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RSA1.h"
#include "RSA1Dlg.h"
#include "afxdialogex.h"

#include <iostream>  
#include <ctime>
#include <cmath>
#include <algorithm>

#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRSA1Dlg 对话框



CRSA1Dlg::CRSA1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RSA1_DIALOG, pParent)
	, edit_1(_T(""))
	, RateSelect(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRSA1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, edit_1);

	DDX_CBString(pDX, IDC_COMBO_A, RateSelect);
	DDV_MaxChars(pDX, RateSelect, 99999);
}

BEGIN_MESSAGE_MAP(CRSA1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRSA1Dlg::OnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO_A, &CRSA1Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON_ENCPT, &CRSA1Dlg::OnBnClickedButtonEncpt)
	ON_BN_CLICKED(IDC_BUTTON_DECPT, &CRSA1Dlg::OnBnClickedButtonDecpt)
END_MESSAGE_MAP()


// CRSA1Dlg 消息处理程序

BOOL CRSA1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CComboBox* comboBox = (CComboBox*)GetDlgItem(IDC_COMBO_A);
	comboBox->AddString(_T("RSA-512"));
	comboBox->AddString(_T("RSA-768"));
	comboBox->AddString(_T("RSA-1024"));
	comboBox->AddString(_T("RSA-2048"));
	for (int i = 0; i < comboBox->GetCount(); i++)
	{
		comboBox->SetItemData(i, i);
	}


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRSA1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRSA1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRSA1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRSA1Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString  strText;
	//int nIndex = RateSelect.GetCurSel();  //当前选中的项
	//RateSelect.GetLBText(nIndex, strText);



}


// 生成伪素数
const long long MAX_ROW = 2000;
long long Pseudoprime(long long type)
{
	type = 10000;

	bool ifprime = false;
	long long a = 0;
	long long arr[MAX_ROW];   //数组arr为{3，4，5，6...52}
	for (long long i = 0; i<MAX_ROW; ++i)
	{
		arr[i] = i + 3;
	}
	while (!ifprime)
	{
		ifprime = true;
		a = (rand() % type) * 2 + 3; //生成一个范围在3到20003里的奇数
		for (int j = 0; j<MAX_ROW; ++j)
		{
			if (a%arr[j] == 0)
			{
				ifprime = false;
				break;
			}
		}
	}
	return a;
}

long long  repeatMod(long long base, long long n, long long mod)//模重复平方算法求(b^n)%m
{
	long long a = 1;
	while (n)
	{
		if (n & 1)
		{
			a = (a*base) % mod;
		}
		base = (base*base) % mod;
		n = n >> 1;
	}
	return a;
}

//Miller-Rabin素数检测
bool rabinmiller(long long n, long long k)
{

	long long s = 0;
	long long temp = n - 1;
	while ((temp & 0x1) == 0 && temp)
	{
		temp = temp >> 1;
		s++;
	}   //将n-1表示为(2^s)*t
	long long t = temp;

	while (k--)  //判断k轮误判概率不大于(1/4)^k
	{
		srand((long long)time(0));
		long long b = rand() % (n - 2) + 2; //生成一个b(2≤a ≤n-2)

		long long y = repeatMod(b, t, n);
		if (y == 1 || y == (n - 1))
			return true;
		for (long long j = 1; j <= (s - 1) && y != (n - 1); ++j)
		{
			y = repeatMod(y, 2, n);
			if (y == 1)
				return false;
		}
		if (y != (n - 1))
			return false;
	}
	return true;
}


long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b,a%b);
}

int xx;
void exgcd(long long &x, long long& y, long long a, long long b)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd(x, y, b, a%b);
	xx = x;
	x = y;
	y = xx - a / b*y;
}

long long Montgomery(long long base, long long exp, long long mod)
{
	long long res = 1;
	while (exp)
	{
		if (exp & 1)
			res = (res*base) % mod;
		exp >>= 1;
		base = (base*base) % mod;
	}
	return res;
}


void CRSA1Dlg::OnClickedButton1()
{
	CEdit* pBoxOne;
	CEdit* pBoxTwo;
	CEdit* pBoxThree;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT1);
	pBoxTwo = (CEdit*)GetDlgItem(IDC_EDIT2);
	pBoxThree = (CEdit*)GetDlgItem(IDC_EDIT3);

	CComboBox* comboBox = (CComboBox*)GetDlgItem(IDC_COMBO_A);
	CString str;
	long long i = 100000,type;

	// 获取加密等级
	//type = comboBox->GetCurSel();

	// 生成两个素数
	long long p,q;

	p = Pseudoprime(i);
	while (!rabinmiller(p, 10)) {
		p = Pseudoprime(i);
	}

	q = Pseudoprime(i);
	while (!rabinmiller(q,10)) {
		q = Pseudoprime(i);
	}

	// 计算n
	long long n = p*q;
	N = n;

	// 计算欧拉函数
	long long phi_n = (p - 1)*(q - 1);
	
	// 选取公钥
	long long e = 65537;

	// 扩展欧几里得计算私钥
	long long x, y;
	exgcd(x, y, e, phi_n);
	if (x < 0) x += phi_n;
	long long d = x;
	pubKey = e;
	priKey = d;
	str.Format(_T("%d"), e);
	pBoxOne->SetWindowText(str);
	str.Format(_T("%d"), d);
	pBoxTwo->SetWindowText(str);
}


void CRSA1Dlg::OnBnClickedButtonEncpt()
{
	// 获取明文
	CEdit* pBoxThree;
	CEdit* pBoxFour;
	CString str;
	long long c;
	pBoxThree = (CEdit*)GetDlgItem(IDC_EDIT3);
	pBoxFour = (CEdit*)GetDlgItem(IDC_EDIT4);

	// 把明文转换为数字
	pBoxThree->GetWindowText(str);
	long long m = _wtoi(str);

	// 加密
	c = Montgomery(m, pubKey, N);
	str.Format(_T("%d"), c);
	pBoxFour->SetWindowText(str);
}


void CRSA1Dlg::OnBnClickedButtonDecpt()
{
	// 获取密文
	CEdit* pBoxThree;
	CEdit* pBoxFour;
	CString str;
	CString str1;
	long long c,m;
	pBoxThree = (CEdit*)GetDlgItem(IDC_EDIT3);
	pBoxFour = (CEdit*)GetDlgItem(IDC_EDIT4);

	// 把密文转换成数字
	pBoxFour->GetWindowText(str);
	c = _wtoi(str);

	// 解密
	m = repeatMod(c, priKey, N);
	str1.Format(_T("%d"), m);
	pBoxThree->SetWindowText(str1);
}
