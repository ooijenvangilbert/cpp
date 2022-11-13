#include <stdio.h>

#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
    // if (argc != 2)
    // {
    //     printf("usage : DisplayImage.out <Image_path>\n");
    //     return -1;
    // }

    // Mat image;
    // image = imread(argv[1],1);

    // if (!image.data)
    // {
    //     printf("No image data \n");
    //     return -1;
    // }

    VideoCapture capture(4); // 0 = internal webcam, 4 = usb cam.
    if (!capture.isOpened())
    {
        printf("No capture found");
        return -1;
    }

    Mat image;
    while(true)
    {
        capture >> image;

        namedWindow("Display image", WINDOW_AUTOSIZE);
        imshow("Display image", image);

        int keyboard = waitKey(30);
        if (keyboard == 'q' || keyboard == 27)
        {
            break;
        }
    }
    return 0;
}