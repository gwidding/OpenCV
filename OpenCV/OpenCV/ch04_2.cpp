/*
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;


// 마우스 이벤트

Mat img;
Point ptOld;
void on_mouse(int event, int x, int y, int flags, void*);

int main(void) {
	img = imread("C:/work/img/lenna.bmp");

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("img");
	setMouseCallback("img", on_mouse);

	imshow("img", img);
	waitKey(0);

	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*) {
	switch (event) {
	case EVENT_LBUTTONDOWN:
		ptOld = Point(x, y);
		cout << "EVENT_LBUTTONDOWN: " << x << ", " << y << endl;
		break;

	case EVENT_LBUTTONUP:
		cout << "EVENT_LBUTTONUP: " << x << ", " << y << endl;
		break;

	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON) {
			if (flags == EVENT_FLAG_LBUTTON) {
				line(img, ptOld, Point(x, y), Scalar(0, 255, 255), 2);
			}
			else if (flags == (EVENT_FLAG_LBUTTON | EVENT_FLAG_SHIFTKEY)) {
				line(img, ptOld, Point(x, y), Scalar(0, 0, 255), 2);
			}			
		}
		else if (flags & EVENT_FLAG_RBUTTON) {
			line(img, ptOld, Point(x, y), Scalar(255, 0, 255), 2);
		}
		// 관심 영역으로 원본 이미지 가져와서 지우개 기능 (포인터 기준으로 가져오면 부하 많이 걸림)
		imshow("img", img);
		ptOld = Point(x, y);
		break;

	default:
		break;
	}
}
*/

/*
// 트랙바
void on_level_change(int pos, void* userdata);

int main(void) {
	Mat img = Mat::zeros(400, 800, CV_8UC3);

	namedWindow("image");
	createTrackbar("level_B", "image", 0, 16, on_level_change, (void*)&img);
	createTrackbar("level_G", "image", 0, 16, on_level_change, (void*)&img);
	createTrackbar("level_R", "image", 0, 16, on_level_change, (void*)&img);

	imshow("image", img);
	waitKey(0);

	return 0;
}

void on_level_change(int pos, void* userdata) {
	Mat img = *(Mat*)userdata;

	int blue = cv::getTrackbarPos("level_B", "image") * 16;
	int green = cv::getTrackbarPos("level_G", "image") * 16;
	int red = cv::getTrackbarPos("level_R", "image") * 16;

	img = Scalar(blue, green, red);
	//img.setTo(pos * 16);
	imshow("image", img);
}

*/

// 마스크 예제
/*
void mask_setTo() {
	Mat src = imread("C:/work/img/lenna.bmp", IMREAD_COLOR);

	Mat mask = imread("C:/work/img/mask_smile.bmp", IMREAD_GRAYSCALE);

	if (src.empty() || mask.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}
	src.setTo(Scalar(0, 255, 255), mask);

	imshow("src", src);
	imshow("mask", mask);

	waitKey(0);
	//destroyAllWindows();
}

void mask_copyTo() {
	Mat src = imread("C:/work/img/airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("C:/work/img/mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat dst = imread("C:/work/img/field.bmp", IMREAD_COLOR);

	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	src.copyTo(dst, mask);

	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
}

int main() {

	//mask_setTo();
	mask_copyTo();

	return 0;

}
*/