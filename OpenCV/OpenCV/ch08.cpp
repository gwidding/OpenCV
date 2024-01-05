
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

#if 0

// 어파인 변환
void affine_transform() {
	Mat src = imread("C:/work/img/tekapo.bmp");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Point2f srcPts[3], dstPts[3];
	srcPts[0] = Point2f(0, 0);
	srcPts[1] = Point2f(src.cols - 1, 0);
	srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
	dstPts[0] = Point2f(50, 50);
	dstPts[1] = Point2f(src.cols - 100, 100);
	dstPts[2] = Point2f(src.cols - 50, src.rows - 50);

	Mat M = getAffineTransform(srcPts, dstPts);

	Mat dst;
	warpAffine(src, dst, M, Size());

	imshow("src", src);
	imshow("dst", dst);

	//transform
	// 현재 사진 크기가 640, 480
	vector<Point2f> src_pt = { Point2f(0, 0), Point2f(0, 480), Point2f(640, 480), Point2f(640, 0) };
	vector<Point2f> dst_pt;

	transform(src_pt, dst_pt, M);

	cout << dst_pt << endl;

	waitKey();
	destroyAllWindows();
}

// 이동 변환
void affine_translation() {
	Mat src = imread("C:/work/img/tekapo.bmp");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat M = Mat_<double>({ 2, 3 }, { 1, 0, 150, 0, 1, 100 });

	Mat dst;
	warpAffine(src, dst, M, Size());

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

// 전단 변환
void affine_shear() {
	Mat src = imread("C:/work/img/tekapo.bmp");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}
	double mx = 0.3;
	//Mat M = Mat_<double>({ 2, 3 }, { 1, mx, 0, 0, 1, 0 });
	Mat M = Mat_<double>({ 2, 3 }, { 1, 0, 0, mx, 1, 0 });

	Mat dst;
	//warpAffine(src, dst, M, Size(cvRound(src.cols + src.rows * mx), src.rows));
	warpAffine(src, dst, M, Size(src.cols, (src.rows + src.cols * mx)));

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();

}

// 크기 변환
void affine_scale() {
	Mat src = imread("C:/work/img/rose.bmp");

	if (src.empty()) {
		cerr << "Image load failed! " << endl;
		return;
	}

	Mat dst1, dst2, dst3, dst4;
	resize(src, dst1, Size(), 4, 4, INTER_NEAREST);
	resize(src, dst2, Size(1920, 1280));
	resize(src, dst3, Size(1920, 1280), 0, 0, INTER_CUBIC);
	resize(src, dst4, Size(1920, 1280), 0, 0, INTER_LANCZOS4);

	imshow("src", src);
	imshow("dst1", dst1(Rect(400, 500, 400, 400)));
	imshow("dst2", dst2(Rect(400, 500, 400, 400)));
	imshow("dst3", dst3(Rect(400, 500, 400, 400)));
	imshow("dst4", dst4(Rect(400, 500, 400, 400)));

	waitKey();
	destroyAllWindows();
}

// 회전 변환
void affine_rotation() {
	Mat src = imread("C:/work/img/tekapo.bmp");

	if (src.empty()) {
		cerr << "이미지 로딩 실패" << endl;
		return;
	}

	// 회전 행렬
	Point2f cp(src.cols / 2.f, src.rows / 2.f);
	Mat M = getRotationMatrix2D(cp, 20, 1);

	// 원하는 결과 창 크기 
	vector<Point2f> src_pt = { Point2f(0, 0), Point2f(0, 480), Point2f(640, 480), Point2f(640, 0) };
	vector<Point2f> dst_pt;
	transform(src_pt, dst_pt, M);

	// 640 가로, 높이 480
	// 765 가로, 높이 670
	float width = dst_pt[2].x - dst_pt[0].x;
	float height = dst_pt[1].y - dst_pt[3].y;

	// 이동 + 창 크기
	Mat dst;
	Mat shiftM = Mat_<double>({ 2, 3 }, { 1, 0, (width - 640) / 2.f, 0, 1, (height - 480) / 2.f });;
	warpAffine(src, dst, shiftM, Size(width, height));

	// 이동한(쉬프트) 창의 중심점
	Point2f cp2(width / 2.f, height / 2.f);

	// 이동 + 창 회전
	Mat dst1;
	Mat M2 = getRotationMatrix2D(cp2, 20, 1);
	warpAffine(dst, dst1, M2, Size(width, height));

	imshow("src", src);
	imshow("dst", dst);
	imshow("dst1", dst1);

	waitKey();
	destroyAllWindows();
}

// 대칭 변환
void affine_flip() {
	Mat src = imread("C:/work/img/eastsea.bmp");

	if (src.empty()) {
		cerr << "이미지 로딩 실패" << endl;
		return;
	}

	imshow("src", src);

	Mat dst;
	int flipCode[] = { 1, 0, -1 };
	for (int i = 0; i < 3; i++) {
		flip(src, dst, flipCode[i]);

		String desc = format("flipCode: %d", flipCode[i]);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 1, LINE_AA);

		imshow("dst", dst);
		waitKey();
	}

	destroyAllWindows();
}


int main() {
	//affine_transform();
	//affine_translation();
	//affine_shear();
	//affine_scale();
	//affine_rotation();
	affine_flip();

	return 0;
}

#endif
