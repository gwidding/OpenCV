#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// 영상의 산술 연산
#if 0
int main(void) {
	Mat src1 = imread("C:/work/img/lenna256.bmp", IMREAD_GRAYSCALE);
	Mat src2 = imread("C:/work/img/square.bmp", IMREAD_GRAYSCALE);

	if (src1.empty() || src2.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	imshow("src1", src1);
	imshow("src2", src2);

	Mat dst1, dst2, dst3, dst4;

	add(src1, src2, dst1);
	subtract(src1, src2, dst2);
	addWeighted(src1, 0.5, src2, 0.5, 0, dst3);
	absdiff(src1, src2, dst4);

	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("dst4", dst4);
	waitKey();

	return 0;

}

#elif 1
int main(void) {

}

#endif
