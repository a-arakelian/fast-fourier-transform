# Fast Fourier Transform Algorithm in C++

This project contains an implementation of a non-recursive algorithm for fast [Fourier transform](https://en.wikipedia.org/wiki/Discrete_Fourier_transform#:~:text=In%20mathematics%2C%20the%20discrete%20Fourier,complex%2Dvalued%20function%20of%20frequency.) in C++. The algorithm is based on the [Cooley-Tukey algorithm](https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm), but with modifications to improve performance.

### Table of Contents:

-  [Motivation](#motivation)
-  [Functionality](#functionality)
-  [Algorithm Description](#algorithm-description)
-  [Future Improvements](#future-improvements)


### Motivation

As an exercise to consolidate and practice what I learned in C++, I decided to write an algorithm for fast Fourier transform. I saved the code on GitHub and made it publicly accessible, in the hope that it may be useful to others for training or reference.

### Functionality

At the moment, the algorithm can perform Fourier transform of one-dimensional sequences with the number of elements equal to some power of two. Additionally, it can do inverse transform under the same conditions.

### Algorithm Description

The fast Fourier transform algorithm is based on the Cooley-Tukey algorithm, which suggests a recursive implementation. However, the recursive nature of the algorithm has a negative effect on performance. Therefore, to optimize for speed, I implemented a non-recursive algorithm instead.

### Future Improvements

In the future, I plan to parallelize the algorithm and add a detailed description of its implementation.
<<<<<<< HEAD

=======
>>>>>>> c2555e98dd5c73262cbe4fd368bf9b25e000a76e
