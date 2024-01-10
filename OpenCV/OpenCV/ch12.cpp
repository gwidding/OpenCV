#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#if 0
// 레이블링의 이해

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

// 레이블링 응용
void labeling_stats() {
	Mat src = imread("C:/work/img/keyboard.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "이미지 로드 실패" << endl;
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

// 계층 구조 없는 외곽선 검출과 그리기

void contours_basic() {
	Mat src = imread("C:/work/img/contours.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "이미지 로드 실패" << endl;
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

// 계층 구조 사용하는 외곽선 검출과 그리기

void contours_hier() {
	Mat src = imread("C:/work/img/contours.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "이미지 로드 실패" << endl;
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
		cerr << "이미지 로드 실패" << endl;
		return;
	}

	vector<vector<Point>> contours;
	findContours(src, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);
	Point2f center;
	float r;
		
	// 최소 사각형
	rectangle(dst, boundingRect(contours[0]), Scalar(0, 0, 255), 2);
	// 최소 원
	minEnclosingCircle(contours[0], center, r);
	circle(dst, center, r, Scalar(255, 255, 0));
	// 회전된 최소 사각형

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

#elif 0

// 곡선의 길이, 면적 구하기

int main() {
	vector<Point> pts = { Point(0, 0), Point(10, 0), Point(0, 10) };

	cout << "len = " << arcLength(pts, true) << endl;
	cout << "area = " << contourArea(pts) << endl;
}

#elif 0

// 삼각형, 사각형, 원 판단하기

void setLabel(Mat& img, const vector<Point>& pts, const String& label) {
	Rect rc = boundingRect(pts);
	rectangle(img, rc, Scalar(0, 0, 255), 1);
	putText(img, label, rc.tl(), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
}

int main(int argc, char* argv[]) {
	Mat img = imread("C:/work/img/polygon.bmp", IMREAD_COLOR);
	if (img.empty()) {
		cerr << "이미지 로드 실패" << endl;
		return -1;
	}

	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);

	Mat bin;
	threshold(gray, bin, 200, 255, THRESH_BINARY_INV | THRESH_OTSU);

	vector<vector<Point>> contours;
	findContours(bin, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	for (vector<Point> pts : contours) {
		if (contourArea(pts) < 400)
			continue;

		vector<Point> approx;
		approxPolyDP(pts, approx, arcLength(pts, true) * 0.02, true);

		int vtc = (int)approx.size();

		if (vtc == 3) {
			setLabel(img, pts, "TRI");
		}
		else if (vtc == 4) {
			setLabel(img, pts, "RECT");
		}
		else if (vtc > 4) {
			double len = arcLength(pts, true);
			double area = contourArea(pts);
			double ratio = 4. * CV_PI * area / (len * len);

			if (ratio > 0.8) {
				setLabel(img, pts, "CIR");
			}
		}
	}

	imshow("img", img);

	waitKey(0);
	return 0;

}

#endif