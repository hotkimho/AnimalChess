
// AnimalChessDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "Unit.h"

// CAnimalChessDlg ��ȭ ����
class CAnimalChessDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CAnimalChessDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANIMALCHESS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

private :
    int board[4][3];
    int size_x;
    int size_y;
    int space_x;
    int space_y;
    int c;
    int first_x , first_y , last_x , last_y ;
    int choice_i;
    int getId;
    bool My_Eat_Elephant;
    bool My_Eat_Kigin;
    bool My_Eat_Babychicken;
    bool Enemy_Eat_Elephant;
    bool Enemy_Eat_Kigin;
    bool Enemy_Eat_Babychicken;
    bool move_Check;
    bool get_Check;
	bool myTurn;
    bool gameover;
    CRect rect;
    Unit * Unit_board[5];
    Unit * E_Unit_board[5];
    
// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public: //�߰��� ����
    afx_msg void OnStnClickedBoard();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    CBitmap bitmap_Board;
    CBitmap bitmap_MyBabychicken, bitmap_MyChicken;
    CBitmap bitmap_MyTiger, bitmap_MyKirin, bitmap_MyElephant;
    CBitmap bitmap_EnemyBabychicken, bitmap_EnemyChicken;
    CBitmap bitmap_EnemyTiger, bitmap_EnemyKirin, bitmap_EnemyElephant;
    CBitmap bitmap_HALF;

public : //�߰��� �Լ�
    void setboard();
    void finish();
    void restart();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnBnClickedButton1();
    afx_msg void OnBnClickedButton2();
};
