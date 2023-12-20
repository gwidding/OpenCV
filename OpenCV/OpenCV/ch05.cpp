#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/*
void brightness1()
{
	Mat src = imread("C:/work/img/lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed! " << endl;
		return;
	}

	Mat dst = src + 100;

	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	//destroyAllWindows();

}

void brightness2()
{
	Mat src = imread("C:/work/img/lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed! " << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100;
		}
	}
	
	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	//destroyAllWindows();
}

void on_brightness(int por, void* userdata);

void brightness4() {
	Mat src = imread("C:/work/img/lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed! " << endl;
		return;
	}

	namedWindow("dst");
	createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
	on_brightness(0, (void*)&src);

	waitKey();
	destroyAllWindows;
}

void on_brightness(int pos, void* userdata) {
	Mat src = *(Mat*)userdata;
	Mat dst = src + pos;

	imshow("dst", dst);
}

int main() {
	//brightness1():
	//brightness2();
	brightness4();

	return 0;
}
*/