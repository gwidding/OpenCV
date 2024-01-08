#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#if 0
// ���̺��� ����

void labeling_basic() {

	uchar data[] = {
		0, 0, 1, 1, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 0, 1, 0,
		1, 1, 1, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 1, 0,
		0, 0, 0, 1, 1, 1, 1, 0,
		0, 0, 0, 1, 0, 0, 1, 0,
		0, 0, 1, 1, 1, 1, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	Mat src = Mat(8, 8, CV_8UC1, data) * 255;

	Mat labels;
	int cnt = connectedComponents(src, labels);

	cout << "src:\n" << src << endl;
	cout << "label:\n" << labels << endl;
	cout << "number of labels: " << cnt << endl;
}

// ���̺� ����
void labeling_stats() {
	Mat src = imread("C:/work/img/keyboard.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "�̹��� �ε� ����" << endl;
		return;
	}

	Mat bin;
	threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

	Mat labels, stats, centroids;
	int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int i = 1; i < cnt; i++) {
		int* p = stats.ptr<int>(i);

		if (p[4] < 20) {
			rectangle(dst, Rect(p[0], p[1], p[2], p[3]), Scalar(0, 0, 255), 2);
			continue;

		}
		String text = format("%2d", i);
		putText(dst, text, Point(p[0], p[1]), FONT_HERSHEY_COMPLEX, 0.5, Scalar(150, 200, 150), 1);

		rectangle(dst, Rect(p[0], p[1], p[2], p[3]), Scalar(0, 255, 255), 2);		
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

int main() {
	//labeling_basic();
	labeling_stats();

	return 0;
}

#elif 0

// ���� ���� ���� �ܰ��� ����� �׸���

void contours_basic() {
	Mat src = imread("C:/work/img/contours.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "�̹��� �ε� ����" << endl;
		return;
	}

	vector<vector<Point>> contours;
	findContours(src, contours, RETR_LIST, CHAIN_APPROX_NONE);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int i = 0; i < contours.size(); i++) {
		Scalar c(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst, contours, i, c, 2);

		String text = format("%2d", i);
		putText(dst, text, Point(contours[i][0].x, contours[i][0].y), FONT_HERSHEY_COMPLEX, 0.5, Scalar(150, 200, 150), 1);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

// ���� ���� ����ϴ� �ܰ��� ����� �׸���

void contours_hier() {
	Mat src = imread("C:/work/img/contours.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "�̹��� �ε� ����" << endl;
		return;
	}

	vector<vector<Point>> contours;
	vector<Vec4i>hierarchy;
	findContours(src, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int idx = 0; idx >= 0; idx = hierarchy[idx][0]) {
		Scalar c(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst, contours, idx, c, -1, LINE_8, hierarchy);

		cout << idx << ": " << hierarchy[idx] << endl;

		String text = format("%2d", idx);
		putText(dst, text, Point(contours[idx][0].x, contours[idx][0].y), FONT_HERSHEY_COMPLEX, 0.5, Scalar(150, 200, 150), 1);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
}

int main() {
	//contours_basic();
	contours_hier();

	return 0;
}

#elif 0

void enclose_beta() {
	Mat src = imread("C:/work/img/beta2.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "�̹��� �ε� ����" << endl;
		return;
	}

	vector<vector<Point>> contours;
	findContours(src, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);
	Point2f center;
	float r;
		
	// �ּ� �簢��
	rectangle(dst, boundingRect(contours[0]), Scalar(0, 0, 255), 2);
	// �ּ� ��
	minEnclosingCircle(contours[0], center, r);
	circle(dst, center, r, Scalar(255, 255, 0));
	// ȸ���� �ּ� �簢��

	RotatedRect rotatedRect = minAreaRect(contours[0]);
	Point2f pp[4];
	rotatedRect.points(pp);

	line(dst, pp[0], pp[1], Scalar(255, 0, 255), 1);
	line(dst, pp[1], pp[2], Scalar(255, 0, 255), 1);
	line(dst, pp[2], pp[3], Scalar(255, 0, 255), 1);
	line(dst, pp[3], pp[0], Scalar(255, 0, 255), 1);


	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
}

int main() {

	enclose_beta();
	return 0;
}

#endif