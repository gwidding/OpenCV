/*
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void MatOp1()
{
	Mat img1;

	Mat img2(480, 640, CV_8UC1);
	Mat img3(480, 640, CV_8UC3);
	Mat img4(Size(640, 480), CV_8UC3);
	
	Mat img5(480, 640, CV_8UC1, Scalar(128));
	Mat img6(480, 640, CV_8UC3, Scalar(0, 0, 255));

	Mat mat1 = Mat::zeros(3, 3, CV_32SC1);
	Mat mat2 = Mat::ones(3, 3, CV_32FC1);
	Mat mat3 = Mat::eye(3, 3, CV_32FC1);

	float data[] = { 1, 2, 3, 4, 5, 6 };
	Mat mat4(2, 3, CV_32FC1, data);

	Mat mat5 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	Mat mat6 = Mat_<uchar>({ 2, 3 }, { 1, 2, 3, 4, 5, 6 });

	mat4.create(256, 256, CV_8UC3);
	mat5.create(4, 4, CV_32FC1);

	mat4 = Scalar(255, 0, 0);
	mat5.setTo(1.f);

}


void MatOp2()
{
	Mat img1 = imread("C:/work/img/dog.bmp");

	Mat img2 = img1;
	Mat img3;
	img3 = img1;
	// 1,2,3 동일

	Mat img4 = img1.clone();
	Mat img5;
	img1.copyTo(img5);
	// 4,5는 깊은 복사

	img1.setTo(Scalar(0, 255, 255));

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);

	waitKey();
	destroyAllWindows();
}

void MatOp3()
{
	Mat img1 = imread("C:/work/img/cat.bmp");

	if (img1.empty()) {
		cerr << "Image load filed!" << endl;
		return;
	}

	Mat img2 = img1(Rect(220, 120, 340, 240));
	Mat img3 = img1(Rect(220, 120, 340, 240)).clone();

	img2 = ~img2;

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);

	waitKey();
	destroyAllWindows();
}

void MatOp4()
{
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);

	for (int j = 0; j < mat1.rows; j++) {
		for (int i = 0; i < mat1.cols; i++) {
			mat1.at<uchar>(j, i)++;
		}
	}
	for (int j = 0; j < mat1.rows; j++) {
		uchar* p = mat1.ptr<uchar>(j);
		for (int i = 0; i < mat1.cols; i++) {
			p[i]++;
		}
	}

	for (MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); ++it) {
		(*it)++;
	}

	cout << "mat1:\n" << mat1 << endl;
}

void MatOp5()
{
	Mat img1 = imread("C:/work/img/lenna.bmp");

	cout << "Width : " << img1.cols << endl;
	cout << "Height : " << img1.rows << endl;
	cout << "Channels : " << img1.channels() << endl;

	if (img1.type() == CV_8UC1)
		cout << "img1 is a grayscale image." << endl;
	else if (img1.type() == CV_8UC3)
		cout << "img1 is a truecolor image." << endl;

	float data[] = { 2.f, 1.414f, 3.f, 1.732f };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;
}

void MatOp6()
{
	float data[] = { 1, 1, 2, 3 };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;

	Mat mat2 = mat1.inv();
	cout << "mat2:\n" << mat2 << endl;

	cout << "mat1.t():\n" << mat1.t() << endl;
	cout << "mat1 + 3 :\n" << mat1 + 3 << endl;
}


int main() {
	//MatOp1();
	//MatOp2();
	//MatOp3();
	//MatOp4();
	//MatOp5();
	MatOp6();

	return 0;
}

*/