#ifndef __OPENCV_INCLUDES__
#define __OPENCV_INCLUDES__

#  include <own/cvdefs.hpp>
#  include <own/types.hpp>  // cv::gapi::own::Rect/Size/Point
#  include <own/scalar.hpp> // cv::gapi::own::Scalar
#  include <own/mat.hpp>
// replacement of cv's structures:
namespace cv {
    using Rect    = gapi::own::Rect;
    using Size    = gapi::own::Size;
    using Point   = gapi::own::Point;
    using Point2f = gapi::own::Point2f;
    using Scalar  = gapi::own::Scalar;
    using Mat     = gapi::own::Mat;
}  // namespace cv

#endif