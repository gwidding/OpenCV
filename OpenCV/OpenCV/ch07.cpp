#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#if 0
void filter_embossing() {
	Mat src = imread("C:/work/img/rose.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}
	float data[] = { -1, -1, 0, -1, 0, 1, 0, 1, 1 };
	Mat emboss(3, 3, CV_32FC1, data);

	Mat dst;
	filter2D(src, dst, -1, emboss, Point(-1, -1), 128);

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	//destroyAllWindows();
}

void blurring_mean() {
	Mat src = imread("C:/work/img/rose.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "image load failed!" << endl;
		return;
	}

	imshow("src", src);

	Mat dst;
	for (int ksize = 3; ksize <= 9; ksize += 2) {
		blur(src, dst, Size(ksize, ksize));

		String desc = format("Mean : %d x %d", ksize, ksize);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

		imshow("dst", dst);
		waitKey(0);
	}

	destroyAllWindows();
}


int main(void) {
	//filter_embossing();
	blurring_mean();
}


#elif 1
// 블러링
// 가우시안 필터
void blurring_gaussian() {
	Mat src = imread("C:/work/img/rose.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed1" << endl;
		return;
	}
	imshow("src", src);

	Mat dst;
	for (int sigma = 1; sigma <= 5; sigma++) {
		GaussianBlur(src, dst, Size(), (double)sigma);

		String text = format("sigma = %d", sigma); (dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
		putText(dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

		imshow("dst", dst);
		waitKey(0);
	}

	destroyAllWindows();
}

// 샤프닝
// 언샤프 마스크
void unsharp_mask() {
	Mat src = imread("C:/work/img/rose.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}
	imshow("src", src);

	for (int sigma = 1; sigma <= 5; sigma++) {
		Mat blurred;
		GaussianBlur(src, blurred, Size(), sigma);

		float alpha = 1.f;
		Mat dst = (1 + alpha) * src - alpha * blurred;

		String desc = format("sigma: %d", sigma);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

		imshow("dst", dst);
		waitKey();
	}

	destroyAllWindows();
}

//양방향 필터
void filter_bilateral() {
	Mat src = imread("C:/work/img/lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat noise(src.size(), CV_32SC1);
	randn(noise, 0, 5);
	add(src, noise, src, Mat(), CV_8U);

	Mat dst1;
	GaussianBlur(src, dst1, Size(), 5);

	Mat dst2;
	bilateralFilter(src, dst2, -1, 10, 5);

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();
}


int main() {
	//blurring_gaussian();
	//unsharp_mask();
	filter_bilateral();
}

#endif
