# Fast Fourier Transform
This repository contains two implementations of the [fast Fourier transform](http://www.librow.com/articles/article-10) (FFT) algorithm: one written manually in `C++`, and one using [`OpenCV`](https://opencv.org/)'s built-in FFT functions. The FFT is a fundamental algorithm in signal processing and is used for a wide range of applications such as image processing, audio processing, and data compression.

The manual implementation uses the [Cooley-Tukey algorithm](https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm), which is a recursive, divide-and-conquer approach to computing the FFT. The implementation includes functions for both 1D and 2D FFTs, and can handle arrays of any size that are powers of two.

The OpenCV implementation uses the built-in `dft()` function, which performs the FFT on an OpenCV `Mat` object. This implementation also includes functions for both 1D and 2D FFTs, and can handle Mat objects of any size.

Both implementations include examples of how to apply the FFT to a color image, including separate transforms for each color channel. The resulting transforms are split into real and imaginary parts, which can be visualized separately.

Finally, both implementations also include an example of how to perform an inverse FFT to recover the original image from its transform. This allows for a comparison of the results between the two implementations and with the original image.

Overall, this repository provides a useful resource for anyone looking to implement the FFT algorithm in their own projects, whether they prefer a manual implementation or a more convenient built-in function from OpenCV.
