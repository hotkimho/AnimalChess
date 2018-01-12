
// AnimalChessDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "AnimalChess.h"
#include "AnimalChessDlg.h"
#include "afxdialogex.h"
#include "Kirin.h"
#include "Tiger.h"
#include "Elephant.h"
#include "Babychicken.h"
#include "Chicken.h"
#include "EnemyBabychicken.h"
#include "EnemyChicken.h"
//#ifdef _DEBUG
//#define new DEBUG_NEW
#define MY_TIGER 1
#define MY_ELEPHANT 2
#define MY_KIGIN 3
#define MY_BABYCHICKEN 4
#define MY_CHICKEN 5
#define ENEMY_TIGER 11
#define ENEMY_ELEPHANT 12
#define ENEMY_KIGIN 13
#define ENEMY_BABYCHICKEN 14
#define ENEMY_CHICKEN 15
#define UNIT_SIZE 4;
//#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

    // 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CAnimalChessDlg 대화 상자



CAnimalChessDlg::CAnimalChessDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(IDD_ANIMALCHESS_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnimalChessDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CAnimalChessDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_STN_CLICKED(IDC_BOARD, &CAnimalChessDlg::OnStnClickedBoard)
    ON_WM_ERASEBKGND()
    ON_WM_LBUTTONDOWN()
    ON_WM_CREATE()
    ON_BN_CLICKED(IDC_BUTTON1, &CAnimalChessDlg::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CAnimalChessDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CAnimalChessDlg 메시지 처리기

BOOL CAnimalChessDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    GetClientRect(&rect);
    setboard(); //보드 초기 설정값
    bitmap_Board.LoadBitmap(IDB_BOARD);
    bitmap_MyBabychicken.LoadBitmap(IDB_MYBABYCHICKEN);
    bitmap_MyChicken.LoadBitmap(IDB_MYCHICKEN);
    bitmap_MyKirin.LoadBitmap(IDB_MYKIRIN);
    bitmap_MyTiger.LoadBitmap(IDB_MYTIGER);
    bitmap_MyElephant.LoadBitmap(IDB_MYELEPHANT);
    bitmap_EnemyBabychicken.LoadBitmap(IDB_ENEMYBABYCHICKEN);
    bitmap_EnemyChicken.LoadBitmap(IDB_ENEMYCHICKEN);
    bitmap_EnemyKirin.LoadBitmap(IDB_ENEMYKIRIN);
    bitmap_EnemyTiger.LoadBitmap(IDB_ENEMYTIGER);
    bitmap_EnemyElephant.LoadBitmap(IDB_ENEMYELEPHANT);
    bitmap_HALF.LoadBitmap(IDB_HALF);
    Unit_board[0] = new Tiger(1);
    Unit_board[1] = new Elephant(2);
    Unit_board[2] = new Kirin(3);
    Unit_board[3] = new Babychicken(4);
    Unit_board[4] = new Chicken(5);
    E_Unit_board[0] = new Tiger(11);
    E_Unit_board[1] = new Elephant(12);
    E_Unit_board[2] = new Kirin(13);
    E_Unit_board[3] = new EnemyBabychicken(14);
    E_Unit_board[4] = new EnemyChicken(15);

    c = 0;
    size_x = 100; //기본 x 값
    size_y = 100; //기본 y 값
    space_x = 10; //공간
    space_y = 10; //공간


// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

    // 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
    //  프레임워크가 이 작업을 자동으로 수행합니다.
    SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
    SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

    // TODO: 여기에 추가 초기화 작업을 추가합니다.

    return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CAnimalChessDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CAnimalChessDlg::OnPaint()
{
    CPaintDC dc(this);

    if (IsIconic())
    {
        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // 아이콘을 그립니다.
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }

    CDC boardDC, memDC;
    memDC.CreateCompatibleDC(&dc);
    boardDC.CreateCompatibleDC(&dc);
    boardDC.SelectObject(&bitmap_Board);

    dc.BitBlt(100, 100, 300, 400, &boardDC, 0, 0, SRCCOPY);

    //실시간으로 말의 위치를 표시
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == MY_TIGER) {
                memDC.SelectObject(&bitmap_MyTiger);
                dc.BitBlt(size_x*(j + 1) + space_x, size_y*(i + 1) + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
            }
            else if (board[i][j] == MY_ELEPHANT) {
                memDC.SelectObject(&bitmap_MyElephant);
                dc.BitBlt(size_x*(j + 1) + space_x, size_y*(i + 1) + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
            }
            else if (board[i][j] == MY_KIGIN) {
                memDC.SelectObject(&bitmap_MyKirin);
                dc.BitBlt(size_x*(j + 1) + space_x, size_y*(i + 1) + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
            }
            else if (board[i][j] == MY_BABYCHICKEN) {
                memDC.SelectObject(&bitmap_MyBabychicken);
                dc.BitBlt(size_x*(j + 1) + space_x, size_y*(i + 1) + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
            }
            else if (board[i][j] == MY_CHICKEN) {
                memDC.SelectObject(&bitmap_MyChicken);
                dc.BitBlt(size_x*(j + 1) + space_x, size_y*(i + 1) + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
            }
            else if (board[i][j] == ENEMY_TIGER) {
                memDC.SelectObject(&bitmap_EnemyTiger);
                dc.BitBlt(size_x*(j + 1) + space_x, size_y*(i + 1) + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
            }

            else if (board[i][j] == ENEMY_ELEPHANT) {
                memDC.SelectObject(&bitmap_EnemyElephant);
                dc.BitBlt(size_x*(j + 1) + space_x, size_y*(i + 1) + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
            }

            else if (board[i][j] == ENEMY_KIGIN) {
                memDC.SelectObject(&bitmap_EnemyKirin);
                dc.BitBlt(size_x*(j + 1) + space_x, size_y*(i + 1) + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
            }

            else if (board[i][j] == ENEMY_BABYCHICKEN) {
                memDC.SelectObject(&bitmap_EnemyBabychicken);
                dc.BitBlt(size_x*(j + 1) + space_x, size_y*(i + 1) + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
            }
            else if (board[i][j] == ENEMY_CHICKEN) {
                memDC.SelectObject(&bitmap_EnemyChicken);
                dc.BitBlt(size_x*(j + 1) + space_x, size_y*(i + 1) + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
            }
        }
        CBrush brush1, brush2;
        brush1.CreateSolidBrush(RGB(0, 255, 0));
        brush2.CreateSolidBrush(RGB(255, 0, 0));

    }

    //먹은 말의 표시
    if (My_Eat_Babychicken) {
        memDC.SelectObject(&bitmap_MyBabychicken);
        dc.BitBlt(500, 300 + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
    }
    else {
        memDC.SelectObject(&bitmap_HALF);
        dc.BitBlt(500, 300 + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
    }

    if (My_Eat_Elephant) {
        memDC.SelectObject(&bitmap_MyElephant);
        dc.BitBlt(600, 300 + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
    }
    else {
        memDC.SelectObject(&bitmap_HALF);
        dc.BitBlt(600, 300 + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
    }

    if (My_Eat_Kigin) {
        memDC.SelectObject(&bitmap_MyKirin);
        dc.BitBlt(700, 300 + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
    }
    else {
        memDC.SelectObject(&bitmap_HALF);
        dc.BitBlt(700, 300 + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
    }


    if (Enemy_Eat_Babychicken) {
        memDC.SelectObject(&bitmap_MyBabychicken);
        dc.BitBlt(500, 100 + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
    }
    else {
        memDC.SelectObject(&bitmap_HALF);
        dc.BitBlt(500, 100 + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
    }

    if (Enemy_Eat_Elephant) {
        memDC.SelectObject(&bitmap_MyElephant);
        dc.BitBlt(600, 100 + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
    }
    else {
        memDC.SelectObject(&bitmap_HALF);
        dc.BitBlt(600, 100 + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
    }

    if (Enemy_Eat_Kigin) {
        memDC.SelectObject(&bitmap_MyKirin);
        dc.BitBlt(700, 100 + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
    }
    else {
        memDC.SelectObject(&bitmap_HALF);
        dc.BitBlt(700, 100 + space_y, 80, 80, &memDC, 0, 0, SRCCOPY);
    }

}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CAnimalChessDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}



void CAnimalChessDlg::OnStnClickedBoard()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL CAnimalChessDlg::OnEraseBkgnd(CDC* pDC)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    return false;
    return CDialogEx::OnEraseBkgnd(pDC);
}



void CAnimalChessDlg::setboard() { //보드 초기화
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;

    board[0][0] = ENEMY_KIGIN;
    board[0][1] = ENEMY_TIGER;
    board[0][2] = ENEMY_ELEPHANT;
    board[1][1] = ENEMY_BABYCHICKEN;
    board[2][1] = MY_BABYCHICKEN;
    board[3][0] = MY_ELEPHANT;
    board[3][1] = MY_TIGER;
    board[3][2] = MY_KIGIN;

    My_Eat_Elephant = false;
    My_Eat_Kigin = false;
    My_Eat_Babychicken = false;
    Enemy_Eat_Elephant = false;
    Enemy_Eat_Kigin = false;
    Enemy_Eat_Babychicken = false;

    first_x = 0;
    first_y = 0;
    last_x = 0;
    last_y = 0;
    choice_i = 0;
    move_Check = true;
    get_Check = false;
    myTurn = true;
    gameover = false;
    getId = 0;
    Invalidate();
}

void CAnimalChessDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    int x = (point.x / 100) - 1; //입력한 곳의 x좌표를 배열에 맞춤
    int y = (point.y / 100) - 1; //입력한 곳의 y좌표를 배열에 맞춤
    int choice_ID = board[y][x];
    CClientDC dc(this), memDC(this);

    CPen pen;
    pen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
    memDC.SelectObject(&pen);
    

    if (!gameover) {
        if (point.x < 100 || point.x>400 || point.y < 100 || point.y >500) // 밖을 눌렀을 때 경고
        {
            if (myTurn == true) {
                if ((point.x >= 500 && point.x <= 580 && point.y >= 300 && point.y <= 380) && My_Eat_Babychicken == true) {
                    get_Check = true;
                    move_Check = false;
                    getId = 4;
                    My_Eat_Babychicken = false;
                }
                else if ((point.x >= 600 && point.x <= 680 && point.y >= 300 && point.y <= 380) && My_Eat_Elephant == true) {
                    get_Check = true;
                    move_Check = false;
                    getId = 2;
                    My_Eat_Elephant = false;
                }
                else if ((point.x >= 700 && point.x <= 780 && point.y >= 300 && point.y <= 380) && My_Eat_Kigin == true) {
                    get_Check = true;
                    move_Check = false;
                    getId = 3;
                    My_Eat_Kigin = false;
                }
            }
            else if (myTurn == false) {
                if ((point.x >= 500 && point.x <= 580 && point.y >= 100 && point.y <= 180) && Enemy_Eat_Babychicken == true) {
                    get_Check = true;
                    move_Check = false;
                    getId = 14;
                    Enemy_Eat_Babychicken = false;
                }
                else if ((point.x >= 600 && point.x <= 680 && point.y >= 100 && point.y <= 180) && Enemy_Eat_Elephant == true) {
                    get_Check = true;
                    move_Check = false;
                    getId = 12;
                    Enemy_Eat_Elephant = false;
                }
                else if ((point.x >= 700 && point.x <= 780 && point.y >= 100 && point.y <= 180) && Enemy_Eat_Kigin == true) {
                    get_Check = true;
                    move_Check = false;
                    getId = 13;
                    Enemy_Eat_Kigin = false;
                }
            }
        }


        else if (myTurn) //내턴일때 실행
        {
            if (move_Check)
            {
                for (int i = 0; i < 5; i++)
                {
                    if (Unit_board[i]->getID() == choice_ID)
                    {
                        choice_i = i;
                        Unit_board[i]->setChoiceUp();
                        move_Check = false;
                        first_x = x;
                        first_y = y;
                        memDC.MoveTo(((x + 1) * 100) + space_x, ((y + 1) * 100) + space_y);
                        memDC.LineTo(((x + 2) * 100) - space_x, ((y + 1) * 100) + space_y);
                    }
                }
            }
            else if (get_Check) {
                last_x = x;
                last_y = y;
                if (board[last_y][last_x] == 0 && last_y != 0) {
                    board[last_y][last_x] = getId;
                    Invalidate();
                    move_Check = true;
                    get_Check = false;
                    myTurn = false;
                }
            }
            else if (move_Check == false && get_Check == false)
            {
                if (Unit_board[choice_i]->getChoice())
                {
                    last_x = x;
                    last_y = y;

                    if (!(board[y][x] == 1 || board[y][x] == 2 || board[y][x] == 3 || board[y][x] == 4))
                    {
                        if (Unit_board[choice_i]->move(first_x, first_y, last_x, last_y))
                        {
                            move_Check = true;
                            Unit_board[choice_i]->setChoiceDown();
                            int tmp = board[last_y][last_x]; //먹은 곳의 원래 있던 말 ID

                            board[last_y][last_x] = Unit_board[choice_i]->getID(); //입력한 곳에 누른 말을 이동
                            for (int i = 0; i < 3; i++) //병아리가 상대측의 진영에 가면 닭으로 변신
                                if (board[0][i] == MY_BABYCHICKEN)
                                    board[last_y][last_x] = MY_CHICKEN;

                            board[first_y][first_x] = 0; //이동하고 난 뒤 말이 있던곳은 공백으로


                            if (tmp == MY_TIGER || tmp == ENEMY_TIGER) //왕을 먹을시
                                finish();
                            if (tmp == ENEMY_CHICKEN) My_Eat_Babychicken = true; //닭을 먹으면 다시 병아리로 가져옴
                            if (tmp == ENEMY_BABYCHICKEN) My_Eat_Babychicken = true; // 다른말들을 먹을씨 쓸 수 있음
                            else if (tmp == ENEMY_ELEPHANT) My_Eat_Elephant = true;
                            else if (tmp == ENEMY_KIGIN) My_Eat_Kigin = true;
                            myTurn = false; //상대의 턴
                            Invalidate();
                        }
                    }

                }

            }
        }


        else if (!myTurn) //상대 턴일때 실행
        {
            if (move_Check)
            {
                for (int i = 0; i < 5; i++)
                {

                    if (E_Unit_board[i]->getID() == choice_ID)
                    {
                        choice_i = i;
                        E_Unit_board[i]->setChoiceUp();
                        move_Check = false;
                        first_x = x;
                        first_y = y;
                        memDC.MoveTo(((x + 1) * 100) + space_x, ((y + 1) * 100) + space_y);
                        memDC.LineTo(((x + 2) * 100) - space_x, ((y + 1) * 100) + space_y);
                    }
                }
            }
            else if (get_Check && myTurn == false) {
                last_x = x;
                last_y = y;
                if (board[last_y][last_x] == 0 && last_y != 3) {
                    board[last_y][last_x] = getId;
                    Invalidate();
                    move_Check = true;
                    get_Check = false;
                    myTurn = true;
                }
            }
            else if (move_Check == false && get_Check == false)
            {
                if (E_Unit_board[choice_i]->getChoice())
                {
                    last_x = x;
                    last_y = y;

                    if (!(board[y][x] == 11 || board[y][x] == 12 || board[y][x] == 13 || board[y][x] == 14))
                    {
                        if (E_Unit_board[choice_i]->move(first_x, first_y, last_x, last_y))
                        {
                            move_Check = true;
                            E_Unit_board[choice_i]->setChoiceDown();
                            int tmp = board[last_y][last_x]; //먹은 곳의 원래 있던 말 ID


                            board[last_y][last_x] = E_Unit_board[choice_i]->getID();
                            for (int i = 0; i < 3; i++)
                                if (board[3][i] == ENEMY_BABYCHICKEN)
                                    board[last_y][last_x] = ENEMY_CHICKEN;

                            board[first_y][first_x] = 0;


                            if (tmp == MY_TIGER || tmp == ENEMY_TIGER) //왕을 먹을시
                                finish();
                            if (tmp == MY_CHICKEN) Enemy_Eat_Babychicken = true; //닭을 먹으면 다시 병아리로 가져옴
                            if (tmp == MY_BABYCHICKEN) Enemy_Eat_Babychicken = true; // 다른말들을 먹을씨 쓸 수 있음
                            else if (tmp == MY_ELEPHANT) Enemy_Eat_Elephant = true;
                            else if (tmp == MY_KIGIN) Enemy_Eat_Kigin = true;
                            Invalidate();
                            myTurn = true;
                        }
                    }

                }

            }
        }
    }

    CDialogEx::OnLButtonDown(nFlags, point);
}


int CAnimalChessDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialogEx::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  여기에 특수화된 작성 코드를 추가합니다.

    return 0;
}

void CAnimalChessDlg::finish() {
    Invalidate();
    AfxMessageBox("게임 오버");
    gameover = true;
}
void CAnimalChessDlg::restart() {

    setboard();
}
void CAnimalChessDlg::OnBnClickedButton1()
{
    restart(); //게임 리스타트
    Invalidate();
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CAnimalChessDlg::OnBnClickedButton2()
{
    move_Check = true; //포커스 초기화
    Invalidate();
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
