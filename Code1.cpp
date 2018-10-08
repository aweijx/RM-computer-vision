// code4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>


using namespace std;
using namespace cv;

int main() {
	//打开视频文件
	VideoCapture capture("rom.mp4");
	//检查视频是否成功打开
	if (!capture.isOpened())
		return 1;
	//获取帧率
	double rate = capture.get(CV_CAP_PROP_FPS);
	bool stop(false);
	Mat frame; //当前视频帧
	namedWindow("Extracted Frame");
	//每一帧的延迟
	//视频的帧率相对应
	int delay = 1000 / rate;
	//遍历每一帧
	while (!stop)
	{//尝试读取下一帧
		if (!capture.read(frame))
			break;
	}
	imshow("Extracted Frame", frame);
	//引入延迟
	//也可通过按键停止
	if (waitKey(delay) >= 0)
		stop = true;
	//关闭视频文件
	//将由析构函数调用，因此非必需
	capture.release();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
