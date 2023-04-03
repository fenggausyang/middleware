#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	//读取一张手写数字图片(28,28)
	Mat image = cv::imread("/home/carnong/OpenCVmnist/number/7.jpg", 0);
	Mat img_show = image.clone();
	//更换数据类型有uchar->float32
	image.convertTo(image, CV_32F);
	//归一化
	image = image / 255.0;
	//(1,784)
	image = image.reshape(1, 1);
	
	//加载ann模型
	cv::Ptr<cv::ml::ANN_MLP> ann= cv::ml::StatModel::load<cv::ml::ANN_MLP>("/home/carnong/OpenCVmnist/build/mnist_ann.xml");
	//预测图片
	Mat pre_out;
	float ret = ann->predict(image,pre_out);
	double maxVal = 0;
	cv::Point maxPoint;
	cv::minMaxLoc(pre_out, NULL, &maxVal, NULL, &maxPoint);
	int max_index = maxPoint.x;
	cout << "图像上的数字为：" << max_index << " 置信度为：" << maxVal << endl;

	cv::imshow("img", img_show);
	cv::waitKey(0);
	getchar();
	return 0;
}