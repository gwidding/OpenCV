#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#if 0

// 영상의 이진화 - 임계값 : 트랙바
void on_threshold(int pos, void* userdata);

int main(int argc, char* argv[]) {
	Mat src;

	if (argc < 2)
		src = imread("C:/work/img/neutrophils.png", IMREAD_GRAYSCALE);
	else
		src = imread(argv[1], IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "이미지 로드 실패" << endl;
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

// 적응형 이진화 - 트랙바 : 블록 크기
void on_trackbar(int pos, void* userdata);

int main() {
	Mat src = imread("C:/work/img/sudoku.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "이미지 로드 실패!" << endl;
		return -1;
	}

	imshow("src", src);

	namedWindow("dst");
	createTrackbar("블럭 크기", "dst", 0, 200, on_trackbar, (void*)&src);
	setTrackbarPos("블럭 크기", "dst", 11);

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

// 모폴로지 연산
#elif 0

// 침식 연산, 팽창 연산
void erode_dilate() {
	Mat src = imread("C:/work/img/milkdrop.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "이미지 로드 실패" << endl;
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

// 이진 영상의 열기와 닫기
void open_close() {
	Mat src = imread("C:/work/img/milkdrop.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "이미지 로드 실패" << endl;
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