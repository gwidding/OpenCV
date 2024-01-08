#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#if 0

// ������ ����ȭ - �Ӱ谪 : Ʈ����
void on_threshold(int pos, void* userdata);

int main(int argc, char* argv[]) {
	Mat src;

	if (argc < 2)
		src = imread("C:/work/img/neutrophils.png", IMREAD_GRAYSCALE);
	else
		src = imread(argv[1], IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "�̹��� �ε� ����" << endl;
		return - 1;
	}

	imshow("src", src);

	namedWindow("dst");
	createTrackbar("Threshold", "dst", 0, 255, on_threshold, (void*)&src);
	setTrackbarPos("Threshold", "dst", 128);

	waitKey(0);
	return 0;
}

void on_threshold(int pos, void* userdata) {

	Mat src = *(Mat*)userdata;

	Mat dst;
	threshold(src, dst, pos, 255, THRESH_BINARY);

	imshow("dst", dst);
}

#elif 0

// ������ ����ȭ - Ʈ���� : ��� ũ��
void on_trackbar(int pos, void* userdata);

int main() {
	Mat src = imread("C:/work/img/sudoku.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "�̹��� �ε� ����!" << endl;
		return -1;
	}

	imshow("src", src);

	namedWindow("dst");
	createTrackbar("�� ũ��", "dst", 0, 200, on_trackbar, (void*)&src);
	setTrackbarPos("�� ũ��", "dst", 11);

	waitKey(0);
	return 0;
}

void on_trackbar(int pos, void* userdata) {
	Mat src = *(Mat*)userdata;

	int bsize = pos;
	if (bsize % 2 == 0) bsize--;
	if (bsize < 3) bsize = 3;

	Mat dst;
	adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, bsize, 5);

	imshow("dst", dst);
}

// �������� ����
#elif 0

// ħ�� ����, ��â ����
void erode_dilate() {
	Mat src = imread("C:/work/img/milkdrop.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "�̹��� �ε� ����" << endl;
		return;
	}

	Mat bin;
	
	threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

	Mat dst1, dst2;
	erode(bin, dst1, Mat());
	dilate(bin, dst2, Mat());

	imshow("src", src);
	imshow("bin", bin);
	imshow("erode", dst1);
	imshow("dilate", dst2);

	waitKey();
	destroyAllWindows();
}

// ���� ������ ����� �ݱ�
void open_close() {
	Mat src = imread("C:/work/img/milkdrop.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "�̹��� �ε� ����" << endl;
		return;
	}

	Mat bin;
	threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

	Mat dst1, dst2;
	morphologyEx(bin, dst1, MORPH_OPEN, Mat());
	morphologyEx(bin, dst2, MORPH_CLOSE, Mat());

	imshow("src", src);
	imshow("bin", bin);
	imshow("open", dst1);
	imshow("close", dst2);

	waitKey();
	destroyAllWindows();
}

int main() {
	//erode_dilate();
	open_close();

	return 0;
}
#endif