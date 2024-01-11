/*
#include "opencv2/opencv.hpp"
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

Mat img(1500, 1500, CV_8UC3, Scalar(255, 255, 255));
Point ptOld;
void on_mouse(int event, int x, int y, int flags, void*);
vector<Point> pts;
bool eraseFlag = false;

//기능 구현 사항

// 두 점 c 원
// 두 점 r 직사각형
// 3~ 여러 점 p 다각형
// e 지우개
// r 전체 지우개

int main() {

	namedWindow("img");
	setMouseCallback("img", on_mouse);
	imshow("img", img);

	while (true) {

		int keycode = waitKey();
		int cnt = pts.size();

		if (cnt >= 2 && (keycode == 'c' || keycode == 'C')) {

			double x_d = pts[cnt - 2].x - pts[cnt - 1].x;
			double y_d = pts[cnt - 2].y - pts[cnt - 1].y;
			double r = sqrt(pow(x_d, 2) + pow(y_d, 2));

			circle(img, pts[cnt - 2], r, Scalar(255, 0, 0), 3, LINE_AA);
			pts.clear();
		}
		else if (cnt >= 2 && (keycode == 'r' || keycode == 'R')) {
			
			int width = abs(pts[cnt - 2].x - pts[cnt - 1].x);
			int height = abs(pts[cnt - 2].y - pts[cnt - 1].y);
			
			rectangle(img, Rect( pts[cnt-2].x , pts[cnt-2].y, width, height), Scalar(0, 255, 0), 2);
			pts.clear();
		}
		else if (cnt >= 3 && (keycode == 'p' || keycode == 'P')) {
			fillPoly(img, pts, Scalar(255, 204, 153));
			pts.clear();
		}
		else if (keycode == 'q' || keycode == 'Q') {
			img = Scalar(255, 255, 255);
			pts.clear();
		}

		imshow("img", img);

		if (keycode == 27) {
			destroyAllWindows();
			break;
		}
			
	}

	return 0;
}

void erase(Point pt) {
	
		double r = 10;
		circle(img, pt, r, Scalar(255, 255, 255), -1, LINE_AA);
}

void on_mouse(int event, int x, int y, int flags, void*) {

	switch (event) {

	case EVENT_LBUTTONDOWN :
		ptOld = Point(x, y);
		pts.push_back(ptOld);
		cout << "좌클릭 좌표 : " << x << ", " << y << endl;
		break;

	case EVENT_MOUSEMOVE:
		if (flags == EVENT_FLAG_CTRLKEY ) {
			erase(Point(x, y));
			imshow("img", img);
		}
		break;

	default:
		break;
	}

}
*/
