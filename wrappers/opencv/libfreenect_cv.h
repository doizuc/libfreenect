#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "libfreenect.h"
#include "libfreenect_sync.h"
#include <opencv/cv.h>

	IplImage *freenect_sync_get_depth_cv(int index, freenect_depth_format fmt);
	IplImage *freenect_sync_get_rgb_cv(int index, freenect_video_format fmt);

#ifdef __cplusplus
}
#endif
