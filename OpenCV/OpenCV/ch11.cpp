#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#if 1

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

#endif