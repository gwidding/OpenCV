#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/*
int main() {

	Mat src1 = imread("C:/work/img/lenna256.bmp", IMREAD_GRAYSCALE);
	Mat src2 = imread("C:/work/img/camera.bmp", IMREAD_GRAYSCALE);

	if (src1.empty() || src2.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	Mat dst;
	add(src1, src2, dst);
	imshow("dst", dst);

	Mat dst2;
	addWeighted(src1, 0.7, src2, 0.3, -100, dst2);
	imshow("dst2", dst2);

	waitKey();
	destroyAllWindows();

	return 0;
}
*/

//웹캠 차영상 예제
/*
void camera_in() {

	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	Mat frame, gray, model, result;

	while (true) {

		//int keycode = waitKey();

		cap >> frame;
		if (frame.empty())
			break;

		cvtColor(frame, gray, COLOR_BGR2GRAY);

		imshow("live", frame);
		
		if (waitKey(10) == 's') {
			cap >> model;
			cvtColor(model, model, COLOR_BGR2GRAY);
			imshow("model", model);
		}

		if (!(model.empty())) {
			absdiff(model, gray, result);
			threshold(result, result, 100, 255, THRESH_BINARY);
			imshow("result", result);
		}

		if (waitKey(10) == 27) // ESC key
			break;
	}
}

int main() {
	camera_in();

	return 0;
}
*/