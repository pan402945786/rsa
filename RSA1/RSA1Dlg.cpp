
// RSA1Dlg.cpp : ʵ���ļ�
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



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CRSA1Dlg �Ի���



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


// CRSA1Dlg ��Ϣ�������

BOOL CRSA1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CComboBox* comboBox = (CComboBox*)GetDlgItem(IDC_COMBO_A);
	comboBox->AddString(_T("RSA-512"));
	comboBox->AddString(_T("RSA-768"));
	comboBox->AddString(_T("RSA-1024"));
	comboBox->AddString(_T("RSA-2048"));
	for (int i = 0; i < comboBox->GetCount(); i++)
	{
		comboBox->SetItemData(i, i);
	}


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRSA1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRSA1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRSA1Dlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString  strText;
	//int nIndex = RateSelect.GetCurSel();  //��ǰѡ�е���
	//RateSelect.GetLBText(nIndex, strText);



}


// ����α����
const long long MAX_ROW = 2000;
long long Pseudoprime(long long type)
{
	type = 10000;

	bool ifprime = false;
	long long a = 0;
	long long arr[MAX_ROW];   //����arrΪ{3��4��5��6...52}
	for (long long i = 0; i<MAX_ROW; ++i)
	{
		arr[i] = i + 3;
	}
	while (!ifprime)
	{
		ifprime = true;
		a = (rand() % type) * 2 + 3; //����һ����Χ��3��20003�������
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

long long  repeatMod(long long base, long long n, long long mod)//ģ�ظ�ƽ���㷨��(b^n)%m
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

//Miller-Rabin�������
bool rabinmiller(long long n, long long k)
{

	long long s = 0;
	long long temp = n - 1;
	while ((temp & 0x1) == 0 && temp)
	{
		temp = temp >> 1;
		s++;
	}   //��n-1��ʾΪ(2^s)*t
	long long t = temp;

	while (k--)  //�ж�k�����и��ʲ�����(1/4)^k
	{
		srand((long long)time(0));
		long long b = rand() % (n - 2) + 2; //����һ��b(2��a ��n-2)

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

	// ��ȡ���ܵȼ�
	//type = comboBox->GetCurSel();

	// ������������
	long long p,q;

	p = Pseudoprime(i);
	while (!rabinmiller(p, 10)) {
		p = Pseudoprime(i);
	}

	q = Pseudoprime(i);
	while (!rabinmiller(q,10)) {
		q = Pseudoprime(i);
	}

	// ����n
	long long n = p*q;
	N = n;

	// ����ŷ������
	long long phi_n = (p - 1)*(q - 1);
	
	// ѡȡ��Կ
	long long e = 65537;

	// ��չŷ����ü���˽Կ
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
	// ��ȡ����
	CEdit* pBoxThree;
	CEdit* pBoxFour;
	CString str;
	long long c;
	pBoxThree = (CEdit*)GetDlgItem(IDC_EDIT3);
	pBoxFour = (CEdit*)GetDlgItem(IDC_EDIT4);

	// ������ת��Ϊ����
	pBoxThree->GetWindowText(str);
	long long m = _wtoi(str);

	// ����
	c = Montgomery(m, pubKey, N);
	str.Format(_T("%d"), c);
	pBoxFour->SetWindowText(str);
}


void CRSA1Dlg::OnBnClickedButtonDecpt()
{
	// ��ȡ����
	CEdit* pBoxThree;
	CEdit* pBoxFour;
	CString str;
	CString str1;
	long long c,m;
	pBoxThree = (CEdit*)GetDlgItem(IDC_EDIT3);
	pBoxFour = (CEdit*)GetDlgItem(IDC_EDIT4);

	// ������ת��������
	pBoxFour->GetWindowText(str);
	c = _wtoi(str);

	// ����
	m = repeatMod(c, priKey, N);
	str1.Format(_T("%d"), m);
	pBoxThree->SetWindowText(str1);
}
