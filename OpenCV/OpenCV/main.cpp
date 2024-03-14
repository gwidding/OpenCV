#include "opencv2/opencv.hpp"
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

// ���콺 �̺�Ʈ �޾ƾ� �ϴ� ��������
Mat src, sample;

Point2f srcQuad[4], dstQuad[4];

void on_mouse(int event, int x, int y, int flags, void* userdata);

int cnt = 0;

int main() {
	src = imread("C:/work/img/card.bmp");
	sample = src.clone();

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("src");
	setMouseCallback("src", on_mouse);

	imshow("src", src);

	while (true) {
		int keycode = waitKey();

		// �� �Է� �ٽ� �ޱ�
		if (keycode == 'r') {
			cout << "Ȯ��" << endl;
			// srcQuad�� dstQuad �迭�� �⺻������ Ŭ����
			Point2f srcQuad[4] = { Point2f(), Point2f(), Point2f(), Point2f() };
			Point2f dstQuad[4] = { Point2f(), Point2f(), Point2f(), Point2f() };
			sample = src.clone();
			imshow("src", sample);
			cnt = 0;
		}

		// ����
		if (keycode == 27) {
			destroyAllWindows();
			break;
		}
	}

	return 0;
}

// ���� ���� ������ ���� �Ÿ� ����
float distancePoints(Point2f p1, Point2f p2) {
	float distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
	return distance;
}

void on_mouse(int event, int x, int y, int flags, void*) {

	if (event == EVENT_LBUTTONDOWN) {
		if (cnt < 4) {
			srcQuad[cnt++] = Point2f(x, y);

			circle(sample, Point(x, y), 5, Scalar(0, 0, 255), -1);
			imshow("src", sample);

			// �� �� ��� ����
			if (cnt == 4) {
				int w = 200, h = 300;

				dstQuad[0] = Point2f(0, 0);
				dstQuad[1] = Point2f(w - 1, 0);
				dstQuad[2] = Point2f(w - 1, h - 1);
				dstQuad[3] = Point2f(0, h - 1);

				// y ���� ����
				for (int i = 0; i < 4; i++) {

					int tmp = i;
					for (int j = i + 1; j < 4; j++) {
						if (srcQuad[tmp].y >= srcQuad[j].y) {
							tmp = j;
						}
						swap(srcQuad[i], srcQuad[tmp]);
					}

				}

				swap(srcQuad[2], srcQuad[3]);

				// ���η� ���� ��
				if (distancePoints(srcQuad[0], srcQuad[1]) > distancePoints(srcQuad[1], srcQuad[2])) {
					swap(srcQuad[1], srcQuad[3]);
				}

				// �������� ���� �� (�밢������ ���� ����)
				if (srcQuad[0].x > srcQuad[1].x) {
					swap(srcQuad[0], srcQuad[1]);
					swap(srcQuad[2], srcQuad[3]);
				}

				// ���� ��ȯ
				Mat pers = getPerspectiveTransform(srcQuad, dstQuad);

				Mat dst;
				warpPerspective(src, dst, pers, Size(w, h));

				imshow("dst", dst);
			}
		}
	}
}