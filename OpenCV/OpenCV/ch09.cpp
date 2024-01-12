#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#if 1
// �Һ� ����ũ ��� ���� ����
void sobel_edge() {
	Mat src = imread("C:/work/img/paper.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "�̹��� �ε� ���� " << endl;
		return;
	}

	Mat dx, dy;
	Sobel(src, dx, CV_32FC1, 1, 0);
	Sobel(src, dy, CV_32FC1, 0, 1);

	Mat fmag, mag;
	magnitude(dx, dy, fmag);
	fmag.convertTo(mag, CV_8UC1);

	Mat edge = mag > 150;

	imshow("src", src);
	imshow("mag", mag);
	imshow("edge", edge);
	
	waitKey();
	destroyAllWindows();
}

// ĳ�� ���� �����
void canny_edge() {
	Mat src = imread("C:/work/img/lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "�̹��� �ε� ����" << endl;
		return;
	}

	Mat dst1, dst2;
	Canny(src, dst1, 50, 100);
	Canny(src, dst2, 50, 150);

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();
}

// ���� ��ȯ ���� ����
void hough_lines() {
	Mat src = imread("C:/work/img/sudoku.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "�̹��� �ε� ����" << endl;
		return;
	}

	Mat edge;
	Canny(src, edge, 50, 150);

	vector<Vec2f> lines;
	HoughLines(edge, lines, 1, CV_PI / 180, 150);

	Mat dst;
	cvtColor(edge, dst, COLOR_GRAY2BGR);

	for (size_t i = 0; i < lines.size(); i++) {
		float r = lines[i][0], t = lines[i][1];
		double cos_t = cos(t), sin_t = sin(t);
		double x0 = r * cos_t, y0 = r * sin_t;
		double alpha = 700;

		Point pt1(cvRound(x0 + alpha * (-sin_t)), cvRound(y0 + alpha * cos_t));
		Point pt2(cvRound(x0 - alpha * (-sin_t)), cvRound(y0 - alpha * cos_t));
		line(dst, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);
	}

		imshow("src", src);
		imshow("dst", dst);

		waitKey(0);
		destroyAllWindows();
}

// Ȯ���� ���� ��ȯ ���� ����
void hough_line_segments() {
	Mat src = imread("C:/work/img/sudoku.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "�̹��� �ε� ����" << endl;
		return;
	}
	Mat adap;
	adaptiveThreshold(src, adap, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 115, 5);

	Mat edge;
	Canny(adap, edge, 50, 150);

	vector<Vec4i> lines;
	HoughLinesP(edge, lines, 1, CV_PI / 180, 160, 30, 5);

	Mat dst;
	cvtColor(edge, dst, COLOR_GRAY2BGR);

	for (Vec4i l : lines) {
		line(dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, LINE_AA);
	}

	imshow("src", src);
	imshow("adap", adap);
	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
}

int main() {
	//sobel_edge();
	//canny_edge();
	//hough_lines();
	hough_line_segments();
}


#endif