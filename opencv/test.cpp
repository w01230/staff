/*
 * This is test program for opencv
 *
 *
 * John Wang@2017/01/16
 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
	Mat opencv=imread("opencv.jpg");
	namedWindow("opencv");
	imshow("opencv", opencv);
	waitKey();

	return 0;
}
