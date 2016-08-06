/*
 * fft.cpp
 *
 *  Created on: Jun 28, 2016
 *      Author: asm
 */


#include <stdio.h>
#include <math.h>
#include "../../../headers/algorithms.hpp"

using namespace DataStructures;

void InternalFFT(
    Vector<Complex>input_signal,
    double basic_freq,
    Vector<Complex>& coefs);


void InternalFFT(
    Vector<Complex>input_signal,
    double basic_freq,
    Vector<Complex>& coefs){

    int N = input_signal.Size();

    if(N == 1){
        coefs.Insert(input_signal[0]);
        return;
    }

    Vector<Complex> odd_input;
    Vector<Complex> even_input;

    for(int i=0; i < N; i++){
        if(i%2) odd_input.Insert(input_signal[i]);
        else even_input.Insert(input_signal[i]);
    }

    Vector<Complex> coefs_e;
    Vector<Complex> coefs_o;

    // recrursive
    InternalFFT(even_input,basic_freq, coefs_e);
    InternalFFT(odd_input, basic_freq, coefs_o);

    // caculating coefs_even, coefs_odd
    Complex c;

    int s = coefs_e.Size();
    for(int i=0; i < s*2; i++){
        Complex factor = (
                Complex(
                    cos(-2*(i%s)*basic_freq),
                    sin(-2*(i%s)*basic_freq)))
                    *((i>=s)?-1.0:1.0);

        c = coefs_e[i%s] + coefs_o[i%s]*factor;
        coefs.Insert(c);
    }

    return;

}

namespace Algorithms{
    namespace MathComp{
        void SlowDTFS(Vector<double>input_signal, Vector<Complex>& coefs){
            coefs.Clear();
            int N = input_signal.Size();
            double funda_freq = 2*M_PI/N;

            for(int i=0; i < N; i++){
                Complex c = {};
                for(int j=0; j < N; j++){
                    c.real += cos(-i*funda_freq*j);
                    c.img += sin(-i*funda_freq*j);
                    coefs.Insert(c);
                }
            }

            return;
        }

        void FFT(Vector<double>input_signal, Vector<Complex>& coefs){
            int N = input_signal.Size();
            int N_rescaling = pow(2.0, floor(log2(N))+1);

            Vector<Complex>padding_input;

            for(int i=0; i < N_rescaling; i++){
                if(i<N) padding_input.Insert(Complex(input_signal[i], 0.0));
                else padding_input.Insert(Complex(0.0, 0.0));
            }


            double basic_freq = (2*M_PI)/N_rescaling;
            InternalFFT(padding_input, basic_freq, coefs);

            return;

        }
    }
}

