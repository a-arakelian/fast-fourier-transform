#include "complex.cpp"
typedef Complex complex;

class DFT {
    private:

    /*
    Input (int x) must be an value that represents a power of 2,
    binarylog returns the exponent of that power of 2.
    */
    static int binarylog(int x) {
        int n = 0;
        while(x != 1){
            x >>=1;
            ++n;
        }
        return n;
    }

    /*
    binarypow takes an integer input value x,
    and returns the result of raising 2 to the power of x.
    */
    static int binarypow(const int& x) {
        int a = 1;
        return a <<=x;
    }

    /*
    binaryswap takes two integer input values: x and l
    binaryswap then returns an integer value
    that is obtained by taking the
    binary representation of n,
    and reversing the order of the last l-1 bits
    of that binary representation.
    */
    static int binaryswap(const int& x, int l){
       --l;
        int swaped = 0;
        for(int k = l; k >= 0; --k) {
            if(x & (1 << k)) {
                swaped += (1 << (l-k));
            }
        }
        return swaped;
    }

    /*
    permutate takes a pointer to a massive of complex numbers
    and the size of the massive as inputs.
    permutate perform a permutation on the input massive
    based on the following principle:
    for each index i in the massive, the value at index i is
    replaced with the value at index binaryswap(i, size).
    */
    static void permutate(complex *p, const int& size) {
        complex A[size];
        int l = binarylog(size);
        for(int n = 0; n < size; ++n) {
            int k = binaryswap(n, l);
            A[n] = *(p + k);
        }
        for(int n = 0; n < size; ++n) {
            *(p + n) = A[n];
        }
    }

    /*
    compute_dft takes a pointer to a massive of complex numbers
    that has already been permuted, the size of the massive,
    and a boolean value "forward" as input parameters.
    The function compute_dft is a modified implementation of the Cooley-Tukey algorithm
    for calculating the Discrete Fourier Transform (DFT)
    of a given massive of complex numbers.
    Unlike the traditional recursive implementation,
    this function works iteratively by using a binary tree structure
    that represents the division of the input massive into smaller submassives.
    The depth of the current calculation is controlled by the "cascade" parameter,
    which determines which level of the binary tree is being processed. 
    */
    static void compute_dft(complex *p, const int& size, bool forward = true) {
        // Imaginary unity & +/- pi
        const complex i(0., 1.);
        const complex pi = forward ? 3.141592653589793 : -3.141592653589793;
        int l = binarylog(size);
        for(int cascade = l; cascade > 0; --cascade) {
            int n_blocks = binarypow(cascade - 1);
            int block_size =  binarypow(l-cascade + 1);
            // frequency step
            const complex w = (-2. * pi * i) / static_cast<double>(block_size);
            for(int block = 0; block < n_blocks; ++ block) {
                int start_index = block * block_size;
                for(int n = 0; n < block_size/2; ++n) {
                    complex odd_n = p[start_index + n];
                    complex even_n = p[start_index + block_size/2 + n];
                    p[start_index + n] = odd_n + cexp(w * static_cast<double>(n)) * even_n;
                    p[start_index + block_size/2 + n] = odd_n - cexp(w * static_cast<double>(n)) * even_n;
                }
            }
        }
        if(!forward) scale(p, size);
    }

    /*
    scale takes a pointer to a massive of complex numbers and its size as inputs.
    The function is rescaleing the elements of the input massive
    by dividing each element by the size of the massive.
    */
    static void scale(complex *p, const int& size) {
        for(int n = 0; n < size; ++n) {
            p[n] /= static_cast<double>(size);
        }
    }
    public:
    static bool forward(complex *p, const int& size) {
        if((size == 0) || ((size & (size - 1)) != 0)) { return false; }
        permutate(p, size);
        compute_dft(p, size);
        return true;
    }
    static bool inverse(complex *p, const int& size) {
        if((size == 0) || ((size & (size - 1)) != 0)) { return false; }
        permutate(p, size);
        compute_dft(p, size, false);
        return true;
    }
};