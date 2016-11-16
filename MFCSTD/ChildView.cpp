
// ChildView.cpp : CChildView 클래스의 구현
//
#include "resource.h"
#include "stdafx.h"
#include "MFCSTD.h"
#include "ChildView.h"
#include <afxtempl.h>
#include <cmath>
#include "ChildView.h"
#include <ctime>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif
double force;

//플레이어 클래스====================================================================


// CChildView====================================================================================

CChildView::CChildView()
{
	pointx = 0;
	pointy = 0;
	xspeed = 0;
	yspeed = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), NULL);

	return TRUE;
}


//===========================================================================================객체 선언부분


Player player1 = Player(20, 20, 20, 100);
Player player2 = Player(20, 20, 1200, 100);

Ball ball = Ball();
Land q0(-20, 400, 40, 30);
Land q1(600, 640, 40, 30);
Land q2(600, 580, 40, 30);
Land q3(40, 400, 40, 30);
Land q4(120, 400, 40, 30);
Land q5(200, 400, 40, 30);
Land q6(280, 400, 40, 30);
Land q7(360, 400, 40, 30);
Land q8(1350, 400, 40, 30);
Land q9(1270, 400, 40, 30);
Land q10(1190, 400, 40, 30);
Land q11(1110, 400, 40, 30);
Land q12(1030, 400, 40, 30);
Land q13(950, 400, 40, 30);
Land q14(870, 400, 40, 30);

//바닥
Land q15(0, 700, 40, 30);
Land q16(80, 700, 40, 30);
Land q17(160, 700, 40, 30);
Land q18(240, 700, 40, 30);
Land q19(320, 700, 40, 30);
Land q20(400, 700, 40, 30);
Land q21(480, 700, 40, 30);
Land q22(560, 700, 40, 30);
Land q23(640, 700, 40, 30);
Land q24(720, 700, 40, 30);
Land q25(800, 700, 40, 30);
Land q26(880, 700, 40, 30);
Land q27(960, 700, 40, 30);
Land q28(1040, 700, 40, 30);
Land q29(1120, 700, 40, 30);
Land q30(1200, 700, 40, 30);
Land q31(1280, 700, 40, 30);
Land q32(1360, 700, 40, 30);


double yf = 0;
double yforce = 0.5;
double xforce;
double ga = 0; // 발사 게이지 표시용 변수
int thisturnplayer = -1; // 플레이어 구분용 변수 1: player1, -1: player2
int AirR = 0;

double pointerpoint = 0;
double K =1;
double Y;

//화면 출력 부분//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CChildView::OnPaint()
{
	CClientDC dc(this);

	//더블 버퍼링 부분. 해당 코드는 대략적인 것은 이해하고 있지만 세세한 부분은 이해못함
	CRect rect;
	GetClientRect(&rect);

	CDC MemDC;
	CBitmap * pOldBmp;
	CBitmap bmp;

	MemDC.CreateCompatibleDC(&dc);
	bmp.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	pOldBmp = (CBitmap*)MemDC.SelectObject(&bmp);
	MemDC.PatBlt(0, 0, rect.Width(), rect.Height(), WHITENESS);

	if (player1.die == false && player2.die == false)
	{

		player1.onland = false;
		player1.playermaxpoint();
		player1.playermove();


		player2.onland = false;
		player2.playermaxpoint();
		player2.playermove();

		

		CPen blackpen;
		blackpen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));


		CPen bruepen;
		bruepen.CreatePen(PS_SOLID, 3, RGB(0, 0, 255));

		CPen redpen;
		redpen.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));

		CPen purplepen;
		purplepen.CreatePen(PS_SOLID, 3, RGB(255, 0, 255));

		CPen limepen;
		limepen.CreatePen(PS_SOLID, 3, RGB(191, 255, 0));

		CPen Player1colorpen; //플레이어 1 색깔
		Player1colorpen.CreatePen(PS_SOLID, 3, RGB(0, 128, 255));

		CPen Player2colorpen;//플레이어 2 색
		Player2colorpen.CreatePen(PS_SOLID, 3, RGB(255, 51, 153));

		CBrush maincolorbrush;
		maincolorbrush.CreateSolidBrush(RGB(128, 128, 128));

		CBrush ballcolorbrush;
		ballcolorbrush.CreateSolidBrush(RGB(255, 0, 0));

		CBrush redbrush;
		redbrush.CreateSolidBrush(RGB(255, 51, 153));

		CBrush bruebrush;
		bruebrush.CreateSolidBrush(RGB(0, 128, 255));

		MemDC.SelectObject(&maincolorbrush);
		MemDC.SelectObject(&blackpen);


		//더블 버퍼링 화면 출력 내용 부분
		MemDC.Rectangle(q1.pointx - q1.sizex, q1.pointy - q1.sizey, q1.pointx + q1.sizex, q1.pointy + q1.sizey);
		MemDC.Rectangle(q2.pointx - q2.sizex, q2.pointy - q2.sizey, q2.pointx + q2.sizex, q2.pointy + q2.sizey);
		MemDC.Rectangle(q3.pointx - q3.sizex, q3.pointy - q3.sizey, q3.pointx + q3.sizex, q3.pointy + q3.sizey);
		MemDC.Rectangle(q4.pointx - q4.sizex, q4.pointy - q4.sizey, q4.pointx + q4.sizex, q4.pointy + q4.sizey);
		MemDC.Rectangle(q5.pointx - q5.sizex, q5.pointy - q5.sizey, q5.pointx + q5.sizex, q5.pointy + q5.sizey);
		MemDC.Rectangle(q6.pointx - q6.sizex, q6.pointy - q6.sizey, q6.pointx + q6.sizex, q6.pointy + q6.sizey);
		MemDC.Rectangle(q7.pointx - q7.sizex, q7.pointy - q7.sizey, q7.pointx + q7.sizex, q7.pointy + q7.sizey);
		MemDC.Rectangle(q8.pointx - q8.sizex, q8.pointy - q8.sizey, q8.pointx + q8.sizex, q8.pointy + q8.sizey);
		MemDC.Rectangle(q9.pointx - q9.sizex, q9.pointy - q9.sizey, q9.pointx + q9.sizex, q9.pointy + q9.sizey);
		MemDC.Rectangle(q10.pointx - q10.sizex, q10.pointy - q10.sizey, q10.pointx + q10.sizex, q10.pointy + q10.sizey);
		MemDC.Rectangle(q11.pointx - q11.sizex, q11.pointy - q11.sizey, q11.pointx + q11.sizex, q11.pointy + q11.sizey);
		MemDC.Rectangle(q12.pointx - q12.sizex, q12.pointy - q12.sizey, q12.pointx + q12.sizex, q12.pointy + q12.sizey);
		MemDC.Rectangle(q13.pointx - q13.sizex, q13.pointy - q13.sizey, q13.pointx + q13.sizex, q13.pointy + q13.sizey);
		MemDC.Rectangle(q14.pointx - q14.sizex, q14.pointy - q14.sizey, q14.pointx + q14.sizex, q14.pointy + q14.sizey);
		MemDC.Rectangle(q15.pointx - q15.sizex, q15.pointy - q15.sizey, q15.pointx + q15.sizex, q15.pointy + q15.sizey);
		MemDC.Rectangle(q16.pointx - q16.sizex, q16.pointy - q16.sizey, q16.pointx + q16.sizex, q16.pointy + q16.sizey);
		MemDC.Rectangle(q17.pointx - q17.sizex, q17.pointy - q17.sizey, q17.pointx + q17.sizex, q17.pointy + q17.sizey);
		MemDC.Rectangle(q18.pointx - q18.sizex, q18.pointy - q18.sizey, q18.pointx + q18.sizex, q18.pointy + q18.sizey);
		MemDC.Rectangle(q19.pointx - q19.sizex, q19.pointy - q19.sizey, q19.pointx + q19.sizex, q19.pointy + q19.sizey);
		MemDC.Rectangle(q20.pointx - q20.sizex, q20.pointy - q20.sizey, q20.pointx + q20.sizex, q20.pointy + q20.sizey);
		MemDC.Rectangle(q21.pointx - q21.sizex, q21.pointy - q21.sizey, q21.pointx + q21.sizex, q21.pointy + q21.sizey);
		MemDC.Rectangle(q22.pointx - q22.sizex, q22.pointy - q22.sizey, q22.pointx + q22.sizex, q22.pointy + q22.sizey);
		MemDC.Rectangle(q23.pointx - q23.sizex, q23.pointy - q23.sizey, q23.pointx + q23.sizex, q23.pointy + q23.sizey);
		MemDC.Rectangle(q24.pointx - q24.sizex, q24.pointy - q24.sizey, q24.pointx + q24.sizex, q24.pointy + q24.sizey);
		MemDC.Rectangle(q25.pointx - q25.sizex, q25.pointy - q25.sizey, q25.pointx + q25.sizex, q25.pointy + q25.sizey);
		MemDC.Rectangle(q26.pointx - q26.sizex, q26.pointy - q26.sizey, q26.pointx + q26.sizex, q26.pointy + q26.sizey);
		MemDC.Rectangle(q27.pointx - q27.sizex, q27.pointy - q27.sizey, q27.pointx + q27.sizex, q27.pointy + q27.sizey);
		MemDC.Rectangle(q28.pointx - q28.sizex, q28.pointy - q28.sizey, q28.pointx + q28.sizex, q28.pointy + q28.sizey);
		MemDC.Rectangle(q29.pointx - q29.sizex, q29.pointy - q29.sizey, q29.pointx + q29.sizex, q29.pointy + q29.sizey);
		MemDC.Rectangle(q30.pointx - q30.sizex, q30.pointy - q30.sizey, q30.pointx + q30.sizex, q30.pointy + q30.sizey);
		MemDC.Rectangle(q31.pointx - q31.sizex, q31.pointy - q31.sizey, q31.pointx + q31.sizex, q31.pointy + q31.sizey);
		MemDC.Rectangle(q32.pointx - q32.sizex, q32.pointy - q32.sizey, q32.pointx + q32.sizex, q32.pointy + q32.sizey);



		//지형_탄환 충돌 코드
		blcol(q1);
		blcol(q2);
		blcol(q3);
		blcol(q4);
		blcol(q5);
		blcol(q6);
		blcol(q7);
		blcol(q8);
		blcol(q9);
		blcol(q10);
		blcol(q11);
		blcol(q12);
		blcol(q13);
		blcol(q14);
		blcol(q15);
		blcol(q16);
		blcol(q17);
		blcol(q18);
		blcol(q19);
		blcol(q20);
		blcol(q21);
		blcol(q22);
		blcol(q23);
		blcol(q24);
		blcol(q25);
		blcol(q26);
		blcol(q27);
		blcol(q28);
		blcol(q29);
		blcol(q30);
		blcol(q31);
		blcol(q32);



		//플레이어 벽 충돌 코드
		q0.playerLanding(player1);
		q1.playerLanding(player1);
		q2.playerLanding(player1);
		q3.playerLanding(player1);
		q4.playerLanding(player1);
		q5.playerLanding(player1);
		q6.playerLanding(player1);
		q7.playerLanding(player1);
		q8.playerLanding(player1);
		q9.playerLanding(player1);
		q10.playerLanding(player1);
		q11.playerLanding(player1);
		q12.playerLanding(player1);
		q13.playerLanding(player1);
		q14.playerLanding(player1);
		q15.playerLanding(player1);
		q16.playerLanding(player1);
		q17.playerLanding(player1);
		q18.playerLanding(player1);
		q19.playerLanding(player1);
		q20.playerLanding(player1);
		q21.playerLanding(player1);
		q22.playerLanding(player1);
		q23.playerLanding(player1);
		q24.playerLanding(player1);
		q25.playerLanding(player1);
		q26.playerLanding(player1);
		q27.playerLanding(player1);
		q28.playerLanding(player1);
		q29.playerLanding(player1);
		q30.playerLanding(player1);
		q31.playerLanding(player1);
		q32.playerLanding(player1);

		q0.playerLanding(player2);
		q1.playerLanding(player2);
		q2.playerLanding(player2);
		q3.playerLanding(player2);
		q4.playerLanding(player2);
		q5.playerLanding(player2);
		q6.playerLanding(player2);
		q7.playerLanding(player2);
		q8.playerLanding(player2);
		q9.playerLanding(player2);
		q10.playerLanding(player2);
		q11.playerLanding(player2);
		q12.playerLanding(player2);
		q13.playerLanding(player2);
		q14.playerLanding(player2);
		q15.playerLanding(player2);
		q16.playerLanding(player2);
		q17.playerLanding(player2);
		q18.playerLanding(player2);
		q19.playerLanding(player2);
		q20.playerLanding(player2);
		q21.playerLanding(player2);
		q22.playerLanding(player2);
		q23.playerLanding(player2);
		q24.playerLanding(player2);
		q25.playerLanding(player2);
		q26.playerLanding(player2);
		q27.playerLanding(player2);
		q28.playerLanding(player2);
		q29.playerLanding(player2);
		q30.playerLanding(player2);
		q31.playerLanding(player2);
		q32.playerLanding(player2);



		firevector();//발사 방향 함수

		MemDC.SelectObject(&redpen);
		MemDC.SelectObject(&ballcolorbrush);

		if (player1.fire == true)
		{
			MemDC.Ellipse(ball.x - 10, ball.y - 10, ball.x + 10, ball.y + 10);
			ball.ballmove(AirR);
			ga = 0;
			player1.xspeed = 0;
		}

		if (player2.fire == true)
		{
			MemDC.Ellipse(ball.x - 10, ball.y - 10, ball.x + 10, ball.y + 10);
			ball.ballmove(AirR);
			ga = 0;
			player2.xspeed = 0;

		}


		MemDC.SelectObject(&maincolorbrush);
		if (ball.y > 900 || ball.x > 1400 || ball.x < 0)
		{
			ballmoveout();
		}

		//바람 게이지 코드
		if (AirR > 0)
		{

			MemDC.SelectObject(&blackpen);
			MemDC.SelectObject(&redbrush);
			MemDC.Rectangle(300, 10, 300 + AirR * 100, 30);
		}

		if (AirR < 0)
		{

			MemDC.SelectObject(&blackpen);
			MemDC.SelectObject(&bruebrush);
			MemDC.Rectangle(300, 10, 300 + AirR * 100, 30);
		}

		MemDC.SelectObject(&maincolorbrush);
		double cos;
		double sin;
		ball.sy -= force* yforce;
		sin = yforce / sqrt(yforce*yforce + (1 - yforce)*(1 - yforce));
		ga += force;

		if (thisturnplayer == 1)
		{
			if (player1.isRight == true)
			{
				ball.sx += force *(1.0 - yforce);
				cos = (1.0 - yforce) / sqrt(yforce*yforce + (1 - yforce)*(1 - yforce));
			}

			else
			{
				ball.sx += force *(yforce - 1.0);
				cos = (yforce - 1.0) / sqrt(yforce*yforce + (1 - yforce)*(1 - yforce));
			}

			//발사 각도 코드 1
			MemDC.SelectObject(&Player1colorpen);
			MemDC.MoveTo(player1.pointx, player1.pointy);
			MemDC.LineTo(100 * cos + player1.pointx, -100 * sin + player1.pointy);
			//발사강도 게이지 코드 1
			MemDC.Rectangle(player1.pointx - 30, player1.pointy - 60, player1.pointx - 30 + ga * 10, player1.pointy - 50);
			//스테미너 그리기 코드 1
			if (player1.sp > 0)
			{
				MemDC.Rectangle(player1.pointx - player1.sp / 4, player1.pointy + 30, player1.pointx + player1.sp / 4, player1.pointy + 40);
			}
			
			if (pointerpoint >= 30)
			{
				K = -0.5;
			}

			if (pointerpoint <= -30)
			{
				K= 0.5;
			}
			pointerpoint += K;
			
			MemDC.Rectangle(player1.pointx - 3, player1.pointy - 70 + pointerpoint, player1.pointx + 3, player1.pointy - 90 + pointerpoint);

		}

		if (thisturnplayer == -1)
		{
			if (player2.isRight == true)
			{
				ball.sx += force *(1.0 - yforce);
				cos = (1.0 - yforce) / sqrt(yforce*yforce + (1 - yforce)*(1 - yforce));
			}
			else
			{
				ball.sx += force *(yforce - 1.0);
				cos = (yforce - 1.0) / sqrt(yforce*yforce + (1 - yforce)*(1 - yforce));
			}

			//발사 각도 코드 2
			MemDC.SelectObject(&Player2colorpen);
			MemDC.MoveTo(player2.pointx, player2.pointy);
			MemDC.LineTo(100 * cos + player2.pointx, -100 * sin + player2.pointy);
			//발사강도 게이지 코드 2
			MemDC.Rectangle(player2.pointx - 30, player2.pointy - 60, player2.pointx - 30 + ga * 10, player2.pointy - 50);
			//스테미너 그리기 코드 2
			if (player2.sp > 0)
			{
				MemDC.Rectangle(player2.pointx - player2.sp / 4, player2.pointy + 30, player2.pointx + player2.sp / 4, player2.pointy + 40);
			}
			if (pointerpoint >= 30)
			{
				K = -0.5;
			}

			if (pointerpoint <= -30)
			{
				K = 0.5;
			}
			pointerpoint += K;

			MemDC.Rectangle(player2.pointx - 3, player2.pointy - 70 + pointerpoint, player2.pointx + 3, player2.pointy - 90 + pointerpoint);

		}

		//탄환이 위쪽 화면 밖으로 나갔을때 x좌표 보여주는 코드
		MemDC.SelectObject(&redpen);
		if (ball.y < 0)
		{
			MemDC.Rectangle(ball.x - 1, 0, ball.x + 1, 10);
		}
		else
		{
			MemDC.Rectangle(ball.x - 1, 0, ball.x + 1, -10);
		}

		//플레이어 1 그리기 코드

		MemDC.SelectObject(&Player1colorpen);
		MemDC.Rectangle(
			player1.pointx - player1.sizeX,
			player1.pointy - player1.sizeY,
			player1.pointx + player1.sizeX,
			player1.pointy + player1.sizeY
			);//player1 그리는 코드

		//플레이어 2 그리기 코드

		MemDC.SelectObject(&Player2colorpen);
		MemDC.Rectangle(
			player2.pointx - player2.sizeX,
			player2.pointy - player2.sizeY,
			player2.pointx + player2.sizeX,
			player2.pointy + player2.sizeY
			);//player2 그리는 코드

		
	}

	

	if (player1.die == true && player2.die == false)
	{
		
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_BITMAP2);
		CBrush brush(&bitmap);
		MemDC.SelectObject(&brush);
		MemDC.Rectangle(0, 0, 1400, 900);
	}

	if (player1.die == false && player2.die == true)
	{
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_BITMAP1);
		CBrush brush(&bitmap);
		MemDC.SelectObject(&brush);
		MemDC.Rectangle(0, 0, 1400, 900);
		
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &MemDC, 0, 0, SRCCOPY);

	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();

	bmp.DeleteObject();

	pOldBmp->DeleteObject();
	//Sleep(1);
}



void CChildView::blcol(Land &l)
{
	if ((l.pointx - l.sizex < ball.x && l.pointx + l.sizex>ball.x) && (l.pointy - l.sizey < ball.y && l.pointy + l.sizey > ball.y))
	{
		l.del();
		ballmoveout();
	}
}


void CChildView::ballmoveout()
{
	player1.fire = false;
	player2.fire = false;
	ball.x = 100;
	ball.y = 100;
	ball.sx = 0;
	ball.sy = 0;
	thisturnplayer *= -1;
	AirR = rand() % 7 - 3;
	player1.sp = 300;
	player2.sp = 300;
}

void CChildView::firevector()
{
	if (yforce < 0)
	{
		yforce = 0;
	}

	if (yforce > 1)
	{
		yforce = 1;
	}

	if (yforce <= 1 && yforce >= 0)
	{
		yforce += yf;
	}
}




//키보드 컨트롤러 방향에 따른 캐릭터 이동
bool addforce = false;
void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (player1.Twall==false || player2.Twall == false)
	{
		if (thisturnplayer == 1)
		{
			switch (nChar)
			{
			case VK_LEFT:
				if (player1.sp > 0)
				{

					if (addforce == false)
					{
						player1.xspeed = -1;
						player1.movesp = 1;
					}
					
				}


				player1.isRight = false;

				break;
			case VK_RIGHT:
				if (player1.sp > 0)
				{

					if (addforce == false)
					{
						player1.xspeed = 1;
						player1.movesp = 1;
					}
					
				}

				player1.isRight = true;

				break;
			case VK_UP:
				if (addforce == false)
				{
					yf = 0.001;
				}
				
				break;
			case VK_DOWN:
				if (addforce == false)
				{
					yf = -0.001;
				}
				break;
			case VK_SPACE:
				if (player1.fire == false)
				{
					ball.x = player1.pointx;
					ball.y = player1.pointy;
					ball.Ggravity = 0;
					ball.AirRig = 0;
					force = 0.02;
					addforce = true;
				}
				break;
			default:
				break;
			}
		}

		if (thisturnplayer == -1)
		{
			switch (nChar)
			{
			case VK_LEFT:
				if (player2.sp > 0)
				{
					if (addforce == false)
					{
						player2.xspeed = -1;
						player2.movesp = 1;
					}
				}

				player2.isRight = false;

				break;
			case VK_RIGHT:
				if (player2.sp > 0)
				{
					if (addforce == false)
					{
						player2.xspeed = 1;
						player2.movesp = 1;
					}
				}

				player2.isRight = true;

				break;

			case VK_UP:
				if (addforce == false)
				{
					yf = 0.001;
				}
				break;
			case VK_DOWN:
				if (addforce == false)
				{
					yf = -0.001;
				}
				break;

			case VK_SPACE:
				if (player2.fire == false)
				{
					ball.x = player2.pointx;
					ball.y = player2.pointy;
					ball.Ggravity = 0;
					ball.AirRig = 0;
					force = 0.02;
					addforce = true;
				}
				break;
			default:
				break;
			}
		}
	}


}


void CChildView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (thisturnplayer == 1)
	{
		switch (nChar)
		{
		case VK_LEFT:
			player1.xspeed = 0;
			player1.movesp = 0;
			break;
		case VK_RIGHT:
			player1.xspeed = 0;
			player1.movesp = 0;
			break;

		case VK_UP:
			yf = 0;
			break;
		case VK_DOWN:
			yf = 0;
			break;

		case VK_SPACE:
			if (player1.fire == false)
			{
				player1.fire = true;
				force = 0;
				addforce = false;
			}

			break;
		default:
			break;
		}
	}

	if (thisturnplayer == -1)
	{
		switch (nChar)
		{
		case VK_LEFT:
			player2.xspeed = 0;
			player2.movesp = 0;
			break;
		case VK_RIGHT:
			player2.xspeed = 0;
			player2.movesp = 0;
			break;
		case VK_UP:
			yf = 0;
			break;
		case VK_DOWN:
			yf = 0;
			break;

		case VK_SPACE:
			if (player2.fire == false)
			{
				player2.fire = true;
				force = 0;
				addforce = false;
			}
			break;

		default:
			break;
		}
	}
}