#pragma once
/**************************************************************
This page contains the Radix-2 in time domain FFT(IFFT)
code, Radix-2 in frequence domain FFT(IFFT) code and Split-Radix
FFT(IFFT) code accompany with their basic complex functions and
other functions.
=============================================================
File Name: fft.h

Build:  05/09/2017 Full Version1.0, by SiQi.Wang

Copyright (C) 2016-2017 Harbin Engineering University

Your use of these functions and any output files,any of
the foregoing and any associated documentation or information
are expressly subject to the terms and conditions of the
Agreement,or other applicable license agreement. Without
limitation, that your use is for the sole purpose. Please
refer to the applicable agreement for further details.
**************************************************************/

#define pi (3.141592) 

//-->define the Length of FFT 
#define TD_Length	(8) 
#define	FD_Length	(8) 

//-->define "complex" datatype 
typedef struct
{
	double re; //real part of a complex number 
	double im; //image part of a complex number 
}complex;

//--set value for complex data------------------------- 
extern complex complex_set_value(double data_re, double data_im);

//--printf complex data value(only available on PC) 
void complex_printf(complex data);

//--printf complex sequence(only available on PC) 
void complex_sequence_printf(complex *seq, int tN);

//--printf real sequence(only available on PC) 
void real_sequence_printf(double *seq, int tN);

//--printf complex sequence with its magnitude 
//(only available on PC) 
void complex_abs_sequence_printf(complex *seq, int tN);

//--complex abs---------------------------------------- 
extern double complex_abs(complex data);

//--Calculate length-N DFT by Radix-2 decimation-in-time 
extern void FFT_Radix_t2(complex *ptTD, int tTN, complex *tFD, int tFN);

//--Calculate length-N DFT by Radix-2 decimation-in-frequence 
extern void FFT_Radix_f2(complex *ptTD, int tTN, complex *tFD, int tFN);

//--Calculate length-N DFT by Split-Radix algorithms 
extern void SRFFT(complex *ptTD, int tTN, complex *tFD, int tFN);

//--Calculate length-N IDFT by Radix-2 decimation-in-time 
extern void IFFT_Radix_t2(complex *tFD, complex *tTD, int tN);

//--Calculate length-N IDFT by Radix-2 decimation-in-frequence 
extern void IFFT_Radix_f2(complex *tFD, complex *tTD, int tN);

//--Calculate length-N IDFT by Split-Radix algorithms 
extern void SRIFFT(complex *tFD, complex *tTD, int tN);