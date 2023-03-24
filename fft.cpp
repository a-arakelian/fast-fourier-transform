#include "complex.cpp"
typedef Complex complex;

class DFT {
    
    private:

    static int binarylog(int x) {
        int n = 0;
        while(x != 1){
            x >>=1;
            ++n;
        }
        return n;
    }

    static int binarypow(const int& x) {
        int a = 1;
        return a <<=x;
    }

    static int binaryswap(const int& x, int l){
        /*
        000001101 -> 000010110 (l = 4)
        */
       --l;
        int swaped = 0;
        for(int k = l; k >= 0; --k) {
            if(x & (1 << k)) {
                swaped += (1 << (l-k));
            }
        }
        return swaped;
    }
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
    }
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
        scale(p, size);
        return true;
    }
};