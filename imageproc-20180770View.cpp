
// imageproc-20180770View.cpp: Cimageproc20180770View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "imageproc-20180770.h"
#endif

#include "imageproc-20180770Doc.h"
#include "imageproc-20180770View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cimageproc20180770View

IMPLEMENT_DYNCREATE(Cimageproc20180770View, CScrollView)

BEGIN_MESSAGE_MAP(Cimageproc20180770View, CScrollView)
//	ON_COMMAND(ID_MENUTEST, &Cimageproc20180770View::OnMenutest)
ON_COMMAND(ID_Pixel_ADD, &Cimageproc20180770View::OnPixelAdd)
ON_COMMAND(ID_PIXEL_TWO_IMAGE_ADD, &Cimageproc20180770View::OnPixelTwoImageAdd)
ON_COMMAND(ID_32812, &Cimageproc20180770View::OnPixelHistoEqu)
ON_COMMAND(ID_Pixel_Mul, &Cimageproc20180770View::OnPixelMul)
ON_COMMAND(ID_32796, &Cimageproc20180770View::OnRegionMeaning)
ON_COMMAND(ID_32797, &Cimageproc20180770View::OnRegionSharpening)
ON_COMMAND(ID_32798, &Cimageproc20180770View::OnRegionEmbossing)
ON_COMMAND(ID_32792, &Cimageproc20180770View::OnRegionPrewitt)
ON_COMMAND(ID_32799, &Cimageproc20180770View::OnRegionRoberts)
ON_COMMAND(ID_32800, &Cimageproc20180770View::OnRegionSobel)
ON_COMMAND(ID_32801, &Cimageproc20180770View::OnRegionAverageFiltering)
ON_COMMAND(ID_32802, &Cimageproc20180770View::OnRegionMedianFiltering)
ON_COMMAND(ID_32803, &Cimageproc20180770View::OnMopologyColorToGray)
ON_COMMAND(ID_32804, &Cimageproc20180770View::OnMopologyBinarization)
ON_COMMAND(ID_32805, &Cimageproc20180770View::OnMopologyErosion)
ON_COMMAND(ID_32793, &Cimageproc20180770View::OnMopologyDilation)
ON_COMMAND(ID_32806, &Cimageproc20180770View::OnMopologyOpening)
ON_COMMAND(ID_32807, &Cimageproc20180770View::OnMopologyClosing)
ON_COMMAND(ID_32794, &Cimageproc20180770View::OnGeometryZoominPixelCopy)
ON_COMMAND(ID_32795, &Cimageproc20180770View::OnGeometryZoomimBilinearInterpolation)
ON_COMMAND(ID_32808, &Cimageproc20180770View::OnGeometryZoomoutSubsampling)
ON_COMMAND(ID_32809, &Cimageproc20180770View::OnGeometryZoomoutMeanSub)
ON_COMMAND(ID_32810, &Cimageproc20180770View::OnGeometryAvgSampling)
ON_COMMAND(ID_32811, &Cimageproc20180770View::OnGeometryRotation)
END_MESSAGE_MAP()

// Cimageproc20180770View 생성/소멸

Cimageproc20180770View::Cimageproc20180770View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cimageproc20180770View::~Cimageproc20180770View()
{
}

BOOL Cimageproc20180770View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// Cimageproc20180770View 그리기

void Cimageproc20180770View::OnDraw(CDC* pDC)
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int x, y;

	if (pDoc->inputImg != NULL)
	{
		if (pDoc->depth == 1)
		{
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(x, y, RGB(pDoc->inputImg[y][x], pDoc->inputImg[y][x], pDoc->inputImg[y][x]));
		}
		else
		{
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(x, y, RGB(pDoc->inputImg[y][3 * x + 0], pDoc->inputImg[y][3 * x + 1], pDoc->inputImg[y][3 * x + 2]));
		}
	}

	if (pDoc->resultImg != NULL)
	{
		if (pDoc->depth == 1)
		{
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(pDoc->imageWidth + 20 + x, y, RGB(pDoc->resultImg[y][x], pDoc->resultImg[y][x], pDoc->resultImg[y][x]));
		}
		else
		{
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(pDoc->imageWidth + 20 + x, y, RGB(pDoc->resultImg[y][3 * x + 0], pDoc->resultImg[y][3 * x + 1], pDoc->resultImg[y][3 * x + 2]));

		}
	}

	if (pDoc->inputImg2 != NULL)
	{
		if (pDoc->depth == 1)
		{
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel((pDoc->imageWidth + 20) * 2 + x, y, RGB(pDoc->inputImg2[y][x], pDoc->inputImg2[y][x], pDoc->inputImg2[y][x]));
		}
		else
		{
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel((pDoc->imageWidth + 20) * 2 + x, y, RGB(pDoc->inputImg2[y][3 * x + 0], pDoc->inputImg2[y][3 * x + 1], pDoc->inputImg2[y][3 * x + 2]));
		}
	}

	if (pDoc->gResultImg != NULL)
	{
		if (pDoc->depth == 1)
		{
			for (y = 0; y < pDoc->gImageHeight; y++)
				for (x = 0; x < pDoc->gImageWidth; x++)
					pDC->SetPixel(x, pDoc->imageHeight + 20 + y, RGB(pDoc->gResultImg[y][x], pDoc->gResultImg[y][x], pDoc->gResultImg[y][x]));
		}
		else
		{
			for (y = 0; y < pDoc->gImageHeight; y++)
				for (x = 0; x < pDoc->gImageWidth; x++)
					pDC->SetPixel(x, pDoc->imageHeight + 20 + y, RGB(pDoc->gResultImg[y][3 * x + 0], pDoc->gResultImg[y][3 * x + 1], pDoc->gResultImg[y][3 * x + 2]));

		}
	}
}


void Cimageproc20180770View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = 2048; sizeTotal.cy = 1024;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Cimageproc20180770View 진단

#ifdef _DEBUG
void Cimageproc20180770View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Cimageproc20180770View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Cimageproc20180770Doc* Cimageproc20180770View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cimageproc20180770Doc)));
	return (Cimageproc20180770Doc*)m_pDocument;
}
#endif //_DEBUG


// Cimageproc20180770View 메시지 처리기


//void Cimageproc20180770View::OnMenutest()
//{
//	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//	AfxMessageBox("안녕하세요 매뉴출력입니다");
//
//}


void Cimageproc20180770View::OnPixelAdd()
{
	Cimageproc20180770Doc* pDoc = GetDocument();

	if (pDoc->inputImg == NULL)	return;

	int x, y;
	int value;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			if (pDoc->depth == 1)
			{
				value = pDoc->inputImg[y][x] + 100;
				if (value > 255)	value = 255;
				else if (value < 0)	value = 0;
				pDoc->resultImg[y][x] = value;
			}
			else
			{
				value = pDoc->inputImg[y][3 * x + 0] + 100;
				if (value > 255)	value = 255;
				else if (value < 0)	value = 0;
				pDoc->resultImg[y][3 * x + 0] = value;

				value = pDoc->inputImg[y][3 * x + 1] + 100;
				if (value > 255)	value = 255;
				else if (value < 0)	value = 0;
				pDoc->resultImg[y][3 * x + 1] = value;

				value = pDoc->inputImg[y][3 * x + 2] + 100;
				if (value > 255)	value = 255;
				else if (value < 0)	value = 0;
				pDoc->resultImg[y][3 * x + 2] = value;
			}

		}

	Invalidate();
}


void Cimageproc20180770View::OnPixelTwoImageAdd()
{
	Cimageproc20180770Doc* pDoc = GetDocument();

	CFileDialog dlg(true);
	CFile file;

	if (dlg.DoModal() == IDOK)
	{
		file.Open(dlg.GetPathName(), CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		pDoc->LoadSecondImageFile(ar);
		file.Close();

		int x, y;

		for (y = 0; y < pDoc->imageHeight; y++)
			for (x = 0; x < pDoc->imageWidth; x++)
			{
				if (pDoc->depth == 1)
				{
					pDoc->resultImg[y][x] = 0.5 * pDoc->inputImg[y][x] + 0.5 * pDoc->inputImg2[y][x];
				}
				else
				{
					pDoc->resultImg[y][3 * x + 0] = 0.5 * pDoc->inputImg[y][3 * x + 0] + 0.5 * pDoc->inputImg2[y][3 * x + 0];
					pDoc->resultImg[y][3 * x + 1] = 0.5 * pDoc->inputImg[y][3 * x + 1] + 0.5 * pDoc->inputImg2[y][3 * x + 1];
					pDoc->resultImg[y][3 * x + 2] = 0.5 * pDoc->inputImg[y][3 * x + 2] + 0.5 * pDoc->inputImg2[y][3 * x + 2];
				}
			}

		Invalidate();
	}

}



void Cimageproc20180770View::OnPixelHistoEqu()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y, k;
	int hist[256], sum[256];
	int acc_hist = 0;
	int N = 256 * 256;

	for (k = 0; k < 256; k++)	hist[k] = 0;

	for (y = 0; y < 256; y++)
		for (x = 0; x < 256; x++)
			hist[pDoc->inputImg[y][x]]++;

	for (k = 0; k < 256; k++)
	{
		acc_hist += hist[k];
		sum[k] = acc_hist;
	}

	for (y = 0; y < 256; y++)
		for (x = 0; x < 256; x++)
		{
			k = pDoc->inputImg[y][x];
			pDoc->resultImg[y][x] = (float)sum[k] / N * 255;
		}

	Invalidate();
}


void Cimageproc20180770View::OnPixelMul()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y;
	int value;

	for (y = 0; y < 256; y++)
		for (x = 0; x < 256; x++)
		{
			value = pDoc->inputImg[y][x] * 1.5;
			if (value > 255)	value = 255;
			else if (value < 0)	value = 0;
			pDoc->resultImg[y][x] = value;
		}

	Invalidate();
}


void Cimageproc20180770View::OnRegionMeaning()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	float kernel[3][3] = { {1.0 / 9.0,1.0 / 9.0,1.0 / 9.0},
							{1.0 / 9.0,1.0 / 9.0,1.0 / 9.0},
							{1.0 / 9.0,1.0 / 9.0,1.0 / 9.0} };

	convolve(pDoc->inputImg, pDoc->resultImg, pDoc->imageWidth, pDoc->imageHeight, kernel, 0, pDoc->depth);

	Invalidate();
}
void Cimageproc20180770View::convolve(unsigned char** inimg, unsigned char** outimg, int cols, int rows, float mask[][3], int bias, int depth)
{
	int x, y;
	int i, j;
	int sum, rsum, gsum, bsum;

	for (y = 1; y < rows - 1; y++)
		for (x = 1; x < cols - 1; x++)
		{
			if (depth == 1)
			{
				sum = 0;
				for (j = 0; j < 3; j++)
					for (i = 0; i < 3; i++)
					{
						sum += (inimg[y + j - 1][x + i - 1] * mask[j][i]);
					}
				sum += bias;
				if (sum > 255)	sum = 255;
				else if (sum < 0)	sum = 0;
				outimg[y][x] = sum;
			}
			else
			{
				rsum = 0; gsum = 0; bsum = 0;
				for (j = 0; j < 3; j++)
					for (i = 0; i < 3; i++)
					{
						rsum += (inimg[y + j - 1][3 * (x + i - 1) + 0] * mask[j][i]);
						gsum += (inimg[y + j - 1][3 * (x + i - 1) + 1] * mask[j][i]);
						bsum += (inimg[y + j - 1][3 * (x + i - 1) + 2] * mask[j][i]);
					}
				rsum += bias;	gsum += bias;	bsum += bias;
				if (rsum > 255)	rsum = 255;
				else if (rsum < 0)	rsum = 0;
				if (gsum > 255)	gsum = 255;
				else if (gsum < 0)	gsum = 0;
				if (bsum > 255)	bsum = 255;
				else if (bsum < 0)	bsum = 0;

				outimg[y][3 * x + 0] = rsum;
				outimg[y][3 * x + 1] = gsum;
				outimg[y][3 * x + 2] = bsum;
			}
		}
}


void Cimageproc20180770View::OnRegionSharpening()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	float kernel[3][3] = { { 0, -1,  0},
							{-1,  5, -1},
							{ 0, -1,  0} };

	convolve(pDoc->inputImg, pDoc->resultImg, pDoc->imageWidth, pDoc->imageHeight, kernel, 0, pDoc->depth);

	Invalidate();
}


void Cimageproc20180770View::OnRegionEmbossing()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	float kernel[3][3] = { { -1,  0,  0},
							{ 0,  0, 0},
							{ 0, 0,  1} };

	convolve(pDoc->inputImg, pDoc->resultImg, pDoc->imageWidth, pDoc->imageHeight, kernel, 128, pDoc->depth);

	Invalidate();
}


void Cimageproc20180770View::OnRegionPrewitt()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	float kernel_h[3][3] = { { -1, -1,  -1},
									{  0,  0,   0},
									{  1,   1,   1} };
	float kernel_v[3][3] = { { -1,  0,  1},
										{ -1,  0,  1},
										{ -1,  0,  1} };

	int x, y, i;
	int value, rvalue, gvalue, bvalue;

	unsigned char** Er, ** Ec;
	// 메모리 할당
	Er = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->imageHeight; i++)
	{
		Er[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
	}

	convolve(pDoc->inputImg, Er, pDoc->imageWidth, pDoc->imageHeight, kernel_h, 128, pDoc->depth);
	convolve(pDoc->inputImg, Ec, pDoc->imageWidth, pDoc->imageHeight, kernel_v, 128, pDoc->depth);

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			if (pDoc->depth == 1)
			{
				value = sqrt((Er[y][x] - 128) * (Er[y][x] - 128) + (Ec[y][x] - 128) * (Ec[y][x] - 128));
				if (value > 255)		value = 255;
				else if (value < 0)	value = 0;
				pDoc->resultImg[y][x] = value;
			}
			else
			{
				rvalue = sqrt((Er[y][3 * x + 0] - 128) * (Er[y][3 * x + 0] - 128) + (Ec[y][3 * x + 0] - 128) * (Ec[y][3 * x + 0] - 128));
				gvalue = sqrt((Er[y][3 * x + 1] - 128) * (Er[y][3 * x + 1] - 128) + (Ec[y][3 * x + 1] - 128) * (Ec[y][3 * x + 1] - 128));
				bvalue = sqrt((Er[y][3 * x + 2] - 128) * (Er[y][3 * x + 2] - 128) + (Ec[y][3 * x + 2] - 128) * (Ec[y][3 * x + 2] - 128));

				value = sqrt(rvalue * rvalue + gvalue * gvalue + bvalue * bvalue);
				if (value > 255)		value = 255;
				else if (value < 0)	value = 0;
				pDoc->resultImg[y][3 * x + 0] = value;
				pDoc->resultImg[y][3 * x + 1] = value;
				pDoc->resultImg[y][3 * x + 2] = value;
			}
		}

	//메모리 삭제
	for (i = 0; i < pDoc->imageHeight; i++)
	{
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void Cimageproc20180770View::OnRegionRoberts()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void Cimageproc20180770View::OnRegionSobel()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	float kernel_h[3][3] = { { -1, -2,  -1},
									{  0,  0,   0},
									{  1,   2,   1} };
	float kernel_v[3][3] = { { -1,  0,  1},
										{ -2,  0,  2},
										{ -1,  0,  1} };

	int x, y, i;
	int value, rvalue, gvalue, bvalue;

	unsigned char** Er, ** Ec;
	// 메모리 할당
	Er = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->imageHeight; i++)
	{
		Er[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
	}

	convolve(pDoc->inputImg, Er, pDoc->imageWidth, pDoc->imageHeight, kernel_h, 128, pDoc->depth);
	convolve(pDoc->inputImg, Ec, pDoc->imageWidth, pDoc->imageHeight, kernel_v, 128, pDoc->depth);

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			if (pDoc->depth == 1)
			{
				value = sqrt((Er[y][x] - 128) * (Er[y][x] - 128) + (Ec[y][x] - 128) * (Ec[y][x] - 128));
				if (value > 255)		value = 255;
				else if (value < 0)	value = 0;
				pDoc->resultImg[y][x] = value;
			}
			else
			{
				rvalue = sqrt((Er[y][3 * x + 0] - 128) * (Er[y][3 * x + 0] - 128) + (Ec[y][3 * x + 0] - 128) * (Ec[y][3 * x + 0] - 128));
				gvalue = sqrt((Er[y][3 * x + 1] - 128) * (Er[y][3 * x + 1] - 128) + (Ec[y][3 * x + 1] - 128) * (Ec[y][3 * x + 1] - 128));
				bvalue = sqrt((Er[y][3 * x + 2] - 128) * (Er[y][3 * x + 2] - 128) + (Ec[y][3 * x + 2] - 128) * (Ec[y][3 * x + 2] - 128));

				value = sqrt(rvalue * rvalue + gvalue * gvalue + bvalue * bvalue);
				if (value > 255)		value = 255;
				else if (value < 0)	value = 0;
				pDoc->resultImg[y][3 * x + 0] = value;
				pDoc->resultImg[y][3 * x + 1] = value;
				pDoc->resultImg[y][3 * x + 2] = value;
			}
		}

	//메모리 삭제
	for (i = 0; i < pDoc->imageHeight; i++)
	{
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void Cimageproc20180770View::OnRegionAverageFiltering()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y, i, j;
	int xpos, ypos;
	int sum, rsum, gsum, bsum;
	int pixelcount;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			sum = 0;		pixelcount = 0;		rsum = gsum = bsum = 0;
			for (j = -2; j <= 2; j++)
				for (i = -2; i <= 2; i++)
				{
					xpos = x + i;
					ypos = y + j;
					if (xpos >= 0 && xpos <= pDoc->imageWidth - 1 && ypos >= 0 && ypos <= pDoc->imageHeight - 1)
					{
						if (pDoc->depth == 1)
							sum += pDoc->inputImg[y + j][x + i];
						else
						{
							rsum += pDoc->inputImg[y + j][3 * (x + i) + 0];
							gsum += pDoc->inputImg[y + j][3 * (x + i) + 1];
							bsum += pDoc->inputImg[y + j][3 * (x + i) + 2];
						}
						pixelcount++;
					}
				}

			if (pDoc->depth == 1)
				pDoc->resultImg[y][x] = sum / pixelcount;
			else
			{
				pDoc->resultImg[y][3 * x + 0] = rsum / pixelcount;
				pDoc->resultImg[y][3 * x + 1] = gsum / pixelcount;
				pDoc->resultImg[y][3 * x + 2] = bsum / pixelcount;
			}
		}

	Invalidate();
}


void Cimageproc20180770View::OnRegionMedianFiltering()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y, i, j;
	int n[9], temp;

	for (y = 1; y < pDoc->imageHeight - 1; y++)
		for (x = 1; x < pDoc->imageWidth - 1; x++)
		{
			n[0] = pDoc->inputImg[y - 1][x - 1];
			n[1] = pDoc->inputImg[y - 1][x - 0];
			n[2] = pDoc->inputImg[y - 1][x + 1];
			n[3] = pDoc->inputImg[y - 0][x - 1];
			n[4] = pDoc->inputImg[y - 0][x - 0];
			n[5] = pDoc->inputImg[y - 0][x + 1];
			n[6] = pDoc->inputImg[y + 1][x - 1];
			n[7] = pDoc->inputImg[y + 1][x - 0];
			n[8] = pDoc->inputImg[y + 1][x + 1];

			// 버블소팅(오름차순)
			for (i = 8; i > 0; i--)
				for (j = 0; j < i; j++)
				{
					if (n[j] > n[j + 1])
					{
						temp = n[j + 1];
						n[j + 1] = n[j];
						n[j] = temp;
					}
				}

			pDoc->resultImg[y][x] = n[4];
		}
	Invalidate();
}


void Cimageproc20180770View::OnMopologyColorToGray()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	if (pDoc->depth == 1)		return;

	int x, y;
	int gray;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			gray = (pDoc->inputImg[y][3 * x + 0] + pDoc->inputImg[y][3 * x + 1] + pDoc->inputImg[y][3 * x + 2]) / 3;
			pDoc->inputImg[y][3 * x + 0] = gray;
			pDoc->inputImg[y][3 * x + 1] = gray;
			pDoc->inputImg[y][3 * x + 2] = gray;
		}

	Invalidate();
}


void Cimageproc20180770View::OnMopologyBinarization()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y;
	int gray, threshold = 100;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			if (pDoc->depth == 1)
			{
				if (pDoc->inputImg[y][x] > threshold)	pDoc->inputImg[y][x] = 255;
				else														pDoc->inputImg[y][x] = 0;
			}
			else
			{
				if ((pDoc->inputImg[y][3 * x + 0] + pDoc->inputImg[y][3 * x + 1] + pDoc->inputImg[y][3 * x + 2]) / 3 > threshold)
				{
					pDoc->inputImg[y][3 * x + 0] = 255;
					pDoc->inputImg[y][3 * x + 1] = 255;
					pDoc->inputImg[y][3 * x + 2] = 255;
				}
				else
				{
					pDoc->inputImg[y][3 * x + 0] = 0;
					pDoc->inputImg[y][3 * x + 1] = 0;
					pDoc->inputImg[y][3 * x + 2] = 0;
				}
			}
		}
	Invalidate();
}


void Cimageproc20180770View::OnMopologyErosion()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y, i, j;
	int min = 255, rmin, gmin, bmin;

	for (y = 1; y < pDoc->imageHeight - 1; y++)
		for (x = 1; x < pDoc->imageWidth - 1; x++)
		{
			min = 255;	rmin = 255;	gmin = 255;	bmin = 255;
			for (j = -1; j <= 1; j++)
				for (i = -1; i <= 1; i++)
				{
					if (pDoc->depth == 1)
					{
						if (pDoc->inputImg[y + j][x + i] < min)
							min = pDoc->inputImg[y + j][x + i];
					}
					else
					{
						if (pDoc->inputImg[y + j][3 * (x + i) + 0] < rmin)		rmin = pDoc->inputImg[y + j][3 * (x + i) + 0];
						if (pDoc->inputImg[y + j][3 * (x + i) + 1] < gmin)		gmin = pDoc->inputImg[y + j][3 * (x + i) + 1];
						if (pDoc->inputImg[y + j][3 * (x + i) + 2] < bmin)		bmin = pDoc->inputImg[y + j][3 * (x + i) + 2];
					}
				}
			if (pDoc->depth == 1)
				pDoc->resultImg[y][x] = min;
			else
			{
				pDoc->resultImg[y][3 * x + 0] = rmin;
				pDoc->resultImg[y][3 * x + 1] = gmin;
				pDoc->resultImg[y][3 * x + 2] = bmin;
			}
		}
	Invalidate();
}


void Cimageproc20180770View::OnMopologyDilation()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y, i, j;
	int max, rmax, gmax, bmax;

	for (y = 1; y < pDoc->imageHeight - 1; y++)
		for (x = 1; x < pDoc->imageWidth - 1; x++)
		{
			max = 0;	rmax = 0;	gmax = 0;	bmax = 0;
			for (j = -1; j <= 1; j++)
				for (i = -1; i <= 1; i++)
				{
					if (pDoc->depth == 1)
					{
						if (pDoc->inputImg[y + j][x + i] > max)
							max = pDoc->inputImg[y + j][x + i];
					}
					else
					{
						if (pDoc->inputImg[y + j][3 * (x + i) + 0] > rmax)		rmax = pDoc->inputImg[y + j][3 * (x + i) + 0];
						if (pDoc->inputImg[y + j][3 * (x + i) + 1] > gmax)		gmax = pDoc->inputImg[y + j][3 * (x + i) + 1];
						if (pDoc->inputImg[y + j][3 * (x + i) + 2] > bmax)		bmax = pDoc->inputImg[y + j][3 * (x + i) + 2];
					}
				}
			if (pDoc->depth == 1)
				pDoc->resultImg[y][x] = max;
			else
			{
				pDoc->resultImg[y][3 * x + 0] = rmax;
				pDoc->resultImg[y][3 * x + 1] = gmax;
				pDoc->resultImg[y][3 * x + 2] = bmax;
			}
		}
	Invalidate();
}


void Cimageproc20180770View::OnMopologyOpening()
{
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();

	CopyResultToInput();
	OnMopologyDilation();
	CopyResultToInput();
	OnMopologyDilation();
	CopyResultToInput();
	OnMopologyDilation();
}

void Cimageproc20180770View::CopyResultToInput()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth * pDoc->depth; x++)
		{
			pDoc->inputImg[y][x] = pDoc->resultImg[y][x];
		}
}


void Cimageproc20180770View::OnMopologyClosing()
{
	OnMopologyDilation();
	CopyResultToInput();
	OnMopologyDilation();
	CopyResultToInput();
	OnMopologyDilation();

	CopyResultToInput();
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();
}


void Cimageproc20180770View::OnGeometryZoominPixelCopy()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y, i;

	int xscale = 3;
	int yscale = 2;

	if (pDoc->gResultImg != NULL)
	{
		for (i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = pDoc->imageWidth * xscale;
	pDoc->gImageHeight = pDoc->imageHeight * yscale;
	// 메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}
	/*
		// 전방향 사상
		for (y = 0; y < pDoc->imageHeight; y++)
			for (x = 0; x < pDoc->imageWidth; x++)
			{
				pDoc->gResultImg[y* yscale][x* xscale] = pDoc->inputImg[y][x];
			}
	*/

	// 역방향 사상
	for (y = 0; y < pDoc->gImageHeight; y++)
		for (x = 0; x < pDoc->gImageWidth; x++)
		{
			if (pDoc->depth == 1)
				pDoc->gResultImg[y][x] = pDoc->inputImg[y / yscale][x / xscale];
			else
			{
				pDoc->gResultImg[y][3 * x + 0] = pDoc->inputImg[y / yscale][3 * (x / xscale) + 0];
				pDoc->gResultImg[y][3 * x + 1] = pDoc->inputImg[y / yscale][3 * (x / xscale) + 1];
				pDoc->gResultImg[y][3 * x + 2] = pDoc->inputImg[y / yscale][3 * (x / xscale) + 2];
			}
		}

	Invalidate();
}


void Cimageproc20180770View::OnGeometryZoomimBilinearInterpolation()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y, i;

	float xscale = 2.1;
	float yscale = 1.5;
	float src_x, src_y;
	float alpha, beta;
	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	int E, F;

	if (pDoc->gResultImg != NULL)
	{
		for (i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = (pDoc->imageWidth) * xscale;
	pDoc->gImageHeight = (pDoc->imageHeight) * yscale;
	// 메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	// 역방향 사상
	for (y = 0; y < pDoc->gImageHeight; y++)
		for (x = 0; x < pDoc->gImageWidth; x++)
		{
			src_x = x / xscale;
			src_y = y / yscale;
			alpha = src_x - (int)src_x;
			beta = src_y - (int)src_y;

			Ax = (int)src_x;
			Ay = (int)src_y;
			Bx = Ax + 1;
			By = Ay;
			Cx = Ax;
			Cy = Ay + 1;
			Dx = Ax + 1;
			Dy = Ay + 1;

			if (Bx > pDoc->imageWidth - 1)		Bx = pDoc->imageWidth - 1;
			if (Cy > pDoc->imageHeight - 1)		Cy = pDoc->imageHeight - 1;
			if (Dx > pDoc->imageWidth - 1)		Dx = pDoc->imageWidth - 1;
			if (Dy > pDoc->imageHeight - 1)		Dy = pDoc->imageHeight - 1;

			if (pDoc->depth == 1)
			{
				E = (1 - alpha) * pDoc->inputImg[Ay][Ax] + alpha * pDoc->inputImg[By][Bx];
				F = (1 - alpha) * pDoc->inputImg[Cy][Cx] + alpha * pDoc->inputImg[Dy][Dx];

				pDoc->gResultImg[y][x] = (1 - beta) * E + beta * F;
			}
			else
			{
				E = (1 - alpha) * pDoc->inputImg[Ay][3 * Ax + 0] + alpha * pDoc->inputImg[By][3 * Bx + 0];
				F = (1 - alpha) * pDoc->inputImg[Cy][3 * Cx + 0] + alpha * pDoc->inputImg[Dy][3 * Dx + 0];
				pDoc->gResultImg[y][3 * x + 0] = (1 - beta) * E + beta * F;

				E = (1 - alpha) * pDoc->inputImg[Ay][3 * Ax + 1] + alpha * pDoc->inputImg[By][3 * Bx + 1];
				F = (1 - alpha) * pDoc->inputImg[Cy][3 * Cx + 1] + alpha * pDoc->inputImg[Dy][3 * Dx + 1];
				pDoc->gResultImg[y][3 * x + 1] = (1 - beta) * E + beta * F;

				E = (1 - alpha) * pDoc->inputImg[Ay][3 * Ax + 2] + alpha * pDoc->inputImg[By][3 * Bx + 2];
				F = (1 - alpha) * pDoc->inputImg[Cy][3 * Cx + 2] + alpha * pDoc->inputImg[Dy][3 * Dx + 2];
				pDoc->gResultImg[y][3 * x + 2] = (1 - beta) * E + beta * F;
			}
		}

	Invalidate();
}



void Cimageproc20180770View::OnGeometryZoomoutSubsampling()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y, i;

	int xscale = 3;		//1/3
	int yscale = 2;		//1/2

	if (pDoc->gResultImg != NULL)
	{
		for (i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = (pDoc->imageWidth) / xscale;
	pDoc->gImageHeight = (pDoc->imageHeight) / yscale;
	// 메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	// 역방향 사상
	for (y = 0; y < pDoc->gImageHeight; y++)
		for (x = 0; x < pDoc->gImageWidth; x++)
		{
			if (pDoc->depth == 1)
				pDoc->gResultImg[y][x] = pDoc->inputImg[y * yscale][x * xscale];
			else
			{
				pDoc->gResultImg[y][3 * x + 0] = pDoc->inputImg[y * yscale][3 * (x * xscale) + 0];
				pDoc->gResultImg[y][3 * x + 1] = pDoc->inputImg[y * yscale][3 * (x * xscale) + 1];
				pDoc->gResultImg[y][3 * x + 2] = pDoc->inputImg[y * yscale][3 * (x * xscale) + 2];
			}
		}
	Invalidate();
}



void Cimageproc20180770View::OnGeometryZoomoutMeanSub()
{
	OnRegionMeaning();
	CopyResultToInput();
	OnGeometryZoomoutSubsampling();
}


void Cimageproc20180770View::OnGeometryAvgSampling()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y, i, j;

	int xscale = 3;		//1/3
	int yscale = 2;		//1/2
	int src_x, src_y;
	int sum, rsum, gsum, bsum;

	if (pDoc->gResultImg != NULL)
	{
		for (i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = (pDoc->imageWidth) / xscale;
	pDoc->gImageHeight = (pDoc->imageHeight) / yscale;
	// 메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	// 전방향 사상
	for (y = 0; y < pDoc->imageHeight; y += yscale)
		for (x = 0; x < pDoc->imageWidth; x += xscale)
		{
			sum = 0;	rsum = 0; gsum = 0; bsum = 0;
			for (j = 0; j < yscale; j++)
				for (i = 0; i < xscale; i++)
				{
					src_x = x + i;
					src_y = y + j;
					if (src_x > pDoc->imageWidth - 1)		src_x = pDoc->imageWidth - 1;
					if (src_y > pDoc->imageHeight - 1)		src_y = pDoc->imageHeight - 1;

					if (pDoc->depth == 1)
						sum += pDoc->inputImg[src_y][src_x];
					else
					{
						rsum += pDoc->inputImg[src_y][3 * src_x + 0];
						gsum += pDoc->inputImg[src_y][3 * src_x + 1];
						bsum += pDoc->inputImg[src_y][3 * src_x + 2];
					}
				}
			if (pDoc->depth == 1)
				pDoc->gResultImg[y / yscale][x / xscale] = sum / (xscale * yscale);
			else
			{
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 0] = rsum / (xscale * yscale);
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 1] = gsum / (xscale * yscale);
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 2] = bsum / (xscale * yscale);
			}
		}
	Invalidate();
}

#define PI 3.1415926521

void Cimageproc20180770View::OnGeometryRotation()
{
	Cimageproc20180770Doc* pDoc = GetDocument();
	int x, y, i, j;
	int angle = 120;		//degree
	float radian;
	int Cx, Cy, Oy;
	int x_source, y_source, xdiff, ydiff;

	if (pDoc->gResultImg != NULL)
	{
		for (i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	radian = 2 * PI / 360 * angle;
	pDoc->gImageWidth = pDoc->imageHeight * fabs(cos(PI / 2 - radian)) + pDoc->imageWidth * fabs(cos(radian));
	pDoc->gImageHeight = pDoc->imageHeight * fabs(cos(radian)) + pDoc->imageWidth * fabs(cos(PI / 2 - radian));
	// 메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	// 중심점
	Cx = pDoc->imageWidth / 2;	Cy = pDoc->imageHeight / 2;
	//y의 마지막 좌표
	Oy = pDoc->imageHeight - 1;
	xdiff = (pDoc->gImageWidth - pDoc->imageWidth) / 2;
	ydiff = (pDoc->gImageHeight - pDoc->imageHeight) / 2;

	for (y = -ydiff; y < pDoc->gImageHeight - ydiff; y++)
		for (x = -xdiff; x < pDoc->gImageWidth - xdiff; x++)
		{
			x_source = (Oy - y - Cy) * sin(radian) + (x - Cx) * cos(radian) + Cx;
			y_source = Oy - ((Oy - y - Cy) * cos(radian) - (x - Cx) * sin(radian) + Cy);

			if (pDoc->depth == 1)
			{
				if (x_source<0 || x_source>pDoc->imageWidth - 1 ||
					y_source<0 || y_source>pDoc->imageHeight - 1)
					pDoc->gResultImg[y + ydiff][x + xdiff] = 255;
				else
					pDoc->gResultImg[y + ydiff][x + xdiff] = pDoc->inputImg[y_source][x_source];
			}
			else
			{
				if (x_source<0 || x_source>pDoc->imageWidth - 1 ||
					y_source<0 || y_source>pDoc->imageHeight - 1)
				{
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 0] = 255;
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 1] = 255;
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 2] = 255;
				}
				else
				{
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 0] = pDoc->inputImg[y_source][3 * x_source + 0];
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 1] = pDoc->inputImg[y_source][3 * x_source + 1];
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 2] = pDoc->inputImg[y_source][3 * x_source + 2];
				}
			}

		}
	Invalidate();
}
