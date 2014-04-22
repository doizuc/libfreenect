#include "libfreenect_cv.h"

IplImage *freenect_sync_get_depth_cv(int index, freenect_depth_format fmt)
{
	static IplImage *image = 0;
	static char *data = 0;
	if (!image) image = cvCreateImageHeader(cvSize(640,480), 16, 1);
	unsigned int timestamp;
	if (freenect_sync_get_depth((void**)&data, &timestamp, index, fmt))
	    return NULL;
	cvSetData(image, data, 640*2);
	return image;
}

IplImage *freenect_sync_get_rgb_cv(int index, freenect_video_format fmt)
{
	static IplImage *image = 0;
	static char *data = 0;
	if (!image) image = cvCreateImageHeader(cvSize(640,480), 8, 3);
	unsigned int timestamp;
	if (freenect_sync_get_video((void**)&data, &timestamp, index, fmt))
	    return NULL;
	cvSetData(image, data, 640*3);
	return image;
}


