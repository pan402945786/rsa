
// RSA1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RSA1.h"
#include "RSA1Dlg.h"
#include "afxdialogex.h"

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
const int MAX_ROW = 50;
size_t Pseudoprime()
{
	bool ifprime = false;
	size_t a = 0;
	int arr[MAX_ROW];   //����arrΪ{3��4��5��6...52}
	for (int i = 0; i<MAX_ROW; ++i)
	{
		arr[i] = i + 3;
	}
	while (!ifprime)
	{
		srand((unsigned)time(0));
		ifprime = true;
		a = (rand() % 100) * 2 + 3; //����һ����Χ��3��2003�������
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

size_t  repeatMod(size_t base, size_t n, size_t mod)//ģ�ظ�ƽ���㷨��(b^n)%m
{
	size_t a = 1;
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
bool rabinmiller(size_t n, size_t k)
{

	int s = 0;
	int temp = n - 1;
	while ((temp & 0x1) == 0 && temp)
	{
		temp = temp >> 1;
		s++;
	}   //��n-1��ʾΪ(2^s)*t
	size_t t = temp;

	while (k--)  //�ж�k�����и��ʲ�����(1/4)^k
	{
		srand((unsigned)time(0));
		size_t b = rand() % (n - 2) + 2; //����һ��b(2��a ��n-2)

		size_t y = repeatMod(b, t, n);
		if (y == 1 || y == (n - 1))
			return true;
		for (int j = 1; j <= (s - 1) && y != (n - 1); ++j)
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


size_t gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b,a%b);
}

int xx;
void exgcd(int &x, int& y, int a, int b)
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


void CRSA1Dlg::OnClickedButton1()
{
	CEdit* pBoxOne;
	CEdit* pBoxTwo;
	CEdit* pBoxThree;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT1);
	pBoxTwo = (CEdit*)GetDlgItem(IDC_EDIT2);
	pBoxThree = (CEdit*)GetDlgItem(IDC_EDIT3);

	CComboBox* comboBox = (CComboBox*)GetDlgItem(IDC_COMBO_A);
	//��ֵ
	//pBoxOne-> SetWindowText( _T("FOO ") );
	//ȡֵ
	CString str;
	//pBoxOne->GetWindowText(str);
	int i;
	//i = euclidean_ext(1, 1, 1);
	i = comboBox->GetCurSel();

	str.Format(_T("%d"), i);

	//MessageBox(_T("�������н��"), MB_OK);
	//str.ReleaseBuffer();

	// ��ȡ���ܵȼ�
	i = comboBox->GetCurSel();



	// ������������
	size_t p = Pseudoprime();
	while (!rabinmiller(p,10)) {
		p = Pseudoprime();
	}
	size_t q = Pseudoprime();
	while (!rabinmiller(q,10)) {
		q = Pseudoprime();
	}

	// ����n
	size_t n = p*q;
	N = n;

	// ����ŷ������

	size_t phi_n = (p - 1)*(q - 1);

	// ѡȡ��Կ
	size_t e = 255;
	str.Format(_T("%d"), e);
	pBoxOne->SetWindowText(str);

	// ��չŷ����ü���˽Կ
	int x, y;
	exgcd(x, y, e, phi_n);
	size_t d = x;
	str.Format(_T("%d"), d);
	pBoxTwo->SetWindowText(str);
	str.Format(_T("%d"), phi_n);
	pBoxThree->SetWindowText(str);
}



void CRSA1Dlg::OnBnClickedButtonEncpt()
{
	// ��ȡ��Կ��n

	// ����

}


void CRSA1Dlg::OnBnClickedButtonDecpt()
{
	// ��ȡ˽Կ��n

	// ����

}
