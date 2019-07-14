/**************************************************************
This page contains the Radix-2 in time domain FFT(IFFT)
code, Radix-2 in frequence domain FFT(IFFT) code and Split-Radix
FFT(IFFT) code accompany with their basic complex functions and
other functions.
=============================================================
File Name: fft.c

Build:  05/09/2017 Full Version1.0, by SiQi.Wang

Copyright (C) 2016-2017 Harbin Engineering University

Your use of these functions and any output files,any of
the foregoing and any associated documentation or information
are expressly subject to the terms and conditions of the
Agreement,or other applicable license agreement. Without
limitation, that your use is for the sole purpose. Please
refer to the applicable agreement for further details.
**************************************************************/

#include "stdafx.h"
#include <conio.h>   
#include <stdio.h>   
#include <string.h>   
#include <stdlib.h>   
#include <math.h>   
#include "fft.h"   

/***************Function Decleration********************/
//--<Bottom Functions>   
//--set value for complex data-------------------------   
complex complex_set_value(double data_re, double data_im);

//--printf complex data value(only available on PC)   
void complex_printf(complex data);

//--printf complex sequence(only available on PC)   
void complex_sequence_printf(complex *seq, int tN);

//--printf real sequence(only available on PC)   
void real_sequence_printf(double *seq, int tN);

//--printf complex sequence with its magnitude   
//(only available on PC)   
void complex_abs_sequence_printf(complex *seq, int tN);

//--complex addition-----------------------------   
complex complex_add(complex addend_1, complex addend_2);

//--complex subtract-----------------------------   
complex complex_sub(complex minuend, complex subtrahend);

//--complex multiply------------------------------------------   
complex complex_mul(complex multiplicator_1, complex multiplicator_2);

//--complex abs----------------------------------   
double complex_abs(complex data);


//--<Functions for FFT>   
//--calculate phase factor-----------------------   
complex phase_factor(int n, int k, int tFN);

//--calculate power-----------------------   
int cal_power(int data, int radix);

//--calculate the location for bit reverse   
int bit_reverse_location(int data, int power);

//--bit reverse-------------------------------   
void bit_reverse(complex *seq, int tFN, int power);

//--block state update for SRFFT-------------------------------   
void updata_block(int **history_block_size, int *history_block);


//--<FFT Functions>   
//--Calculate length-N DFT by Radix-2 decimation-in-time   
void FFT_Radix_t2(complex *ptTD, int tTN, complex *tFD, int tFN);

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




/**********************Bottom Function*************************/
//--set value for complex data-------------------------   
complex complex_set_value(double data_re, double data_im)
{
	complex temp;
	temp.re = data_re;
	temp.im = data_im;
	return (temp);
}

//--printf complex data value(only available on PC)   
void complex_printf(complex data)
{
	//print the complex value on screen as (data.re)+j(data.im)   
	printf("(%f)+j(%f)\n", data.re, data.im);
}

//--printf complex sequence(only available on PC)   
void complex_sequence_printf(complex *seq, int tN)
{
	int i;
	for (i = 0; i<tN; i++)
	{
		printf("%d:", i);
	//	printf_s("  %f  ", seq[i]);
		complex_printf(seq[i]);
	}
}

//--printf real sequence(only available on PC)   
void real_sequence_printf(double *seq, int tN)
{
	int i;
	for (i = 0; i<tN; i++)
	{
		printf("%d:", i);
		printf("  %f  \n", seq[i]);
	}
}

//--printf complex sequence with its magnitude   
//(only available on PC)   
void complex_abs_sequence_printf(complex *seq, int tN)
{
	int i;
	for (i = 0; i<tN; i++)
	{
		printf("%d:", i);
		printf("  %f  ", complex_abs(seq[i]));
		complex_printf(seq[i]);
	}
}

/********************************************************
*Function Name: complex_add
*Function:      calculate complex addition: sum = addend_1 + addend_2
*Iuput:         addend_1,addend_2(they must both be complex type)
*Output:        sum(the output will also be complex type)
*Return:
*Create Date:   05/08/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
//--define complex addition-----------------------------   
complex complex_add(complex addend_1, complex addend_2)
{
	complex sum;
	sum.re = addend_1.re + addend_2.re;
	sum.im = addend_1.im + addend_2.im;
	return (sum);
}

/********************************************************
*Function Name: complex_sub
*Function:      calculate complex subtract:
difference = minuend - subtrahend;
*Iuput:         minuend,subtrahend(they must both be complex type)
*Output:        difference(the output will also be complex type)
*Return:
*Create Date:   05/08/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
//--define complex subtract-----------------------------   
complex complex_sub(complex minuend, complex subtrahend)
{
	complex difference;
	difference.re = minuend.re - subtrahend.re;
	difference.im = minuend.im - subtrahend.im;
	return (difference);
}

/********************************************************
*Function Name: complex_mul
*Function:      calculate complex multiply:
result = multiplicator_1 * multiplicator_2
*Iuput:         multiplicator_1, multiplicator_2
(they must both be complex type)
*Output:        result(the output will also be complex type)
*Return:
*Create Date:   05/08/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
//--define complex multiply-----------------------------------------------------------------------   
complex complex_mul(complex multiplicator_1, complex multiplicator_2)
{
	complex result;
	result.re = multiplicator_1.re * multiplicator_2.re - multiplicator_1.im * multiplicator_2.im;
	result.im = multiplicator_1.re * multiplicator_2.im + multiplicator_1.im * multiplicator_2.re;
	return (result);
}

/********************************************************
*Function Name: complex_abs
*Function:      calculate magnitude of a complex data
result = |data|
*Iuput:         data(complex type)
*Output:
*Return:        result(the output will also be double type)
*Create Date:   05/08/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
//--define complex abs----------------------------------   
double complex_abs(complex data)
{
	return (sqrt(data.re * data.re + data.im * data.im));
}

//--calculate power-----------------------   
int cal_power(int data, int radix)
{
	int power = 0;
	while (data>1)
	{
		data = data / radix;
		power++;
	}
	return (power);
}



/********************Function for FFT************************/

/********************************************************
*Function Name: phase_factor
*Function:      calculate the value of folloing phase factor:
phase_factor_exp = exp(-j*2*pi*n*k/tFN)
*Iuput:         n,k,tFN
(they must all be int type)
*Output:        phase_factor_exp(the output will be complex type)
*Return:
*Create Date:   05/08/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
//--calculate phase factor-----------------------   
complex phase_factor(int n, int k, int tFN)
{
	complex phase_factor_exp;
	phase_factor_exp.re = (cos(-2 * pi * n * k / tFN));
	phase_factor_exp.im = (sin(-2 * pi * n * k / tFN));
	return (phase_factor_exp);
}

//--expand sequence--------------------------------------   
complex *expand(complex *ptTD, int tTN, int tFN)
{
	int i;
	complex *tTD;
	//apply new space for expanded sequence   
	tTD = (complex *)malloc(tFN * sizeof(complex));
	//expand sequence   
	for (i = 0; i<tFN; i++)
	{
		if (i<tTN) { tTD[i] = ptTD[i]; }
		else { tTD[i] = complex_set_value(0, 0); }
	}
	return (tTD);
}
/********************************************************
*Function Name: bit_reverse_location
*Function:      calculate the bit reverse value of data
when the length is power of 2
*Iuput:         data,power
(they must all be int type)
*Output:
*Return:        location(value after bit reverse)
*Create Date:   05/08/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
//--calculate the location for bit reverse-----   
int bit_reverse_location(int data, int power)
{
	int location = 0;
	int shift_detect = 0x01;
	int i;
	for (i = 0; i<power; i++)
	{
		location = location << 1;
		if (data & shift_detect)
		{
			location = location + 1;
		}
		shift_detect = shift_detect << 1;
	}
	return(location);
}

/********************************************************
*Function Name: bit_reverse
*Function:      complete bit reverse operation for seq
*Iuput:         seq(array,each element of which must be complex)
tFN(length of the sequence)
power(power of 2)
*Output:
*Return:
*Create Date:   05/08/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
//--bit reverse-------------------------------   
void bit_reverse(complex *seq, int tFN, int power)
{
	int i;
	complex *seq_inverse;

	seq_inverse = (complex *)malloc(tFN * sizeof(complex));
	for (i = 0; i<tFN; i++)
	{
		seq_inverse[i] = seq[bit_reverse_location(i, power)];
	}

	for (i = 0; i<tFN; i++)
	{
		seq[i] = seq_inverse[i];
	}

	free(seq_inverse);
}
/********************************************************
*Function Name: updata_block
*Function:      update block state for SRFFT
*Iuput:         **history_block_size(address of block_size diagram)
*history_block(quantity of blocks)
*Output:
*Return:
*Create Date:   05/08/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
//--block state update for SRFFT-------------------------------   
void updata_block(int **history_block_size, int *history_block)
{
	int i, j;
	int new_block, *new_block_size;
	int temp;

	new_block = *history_block * 3;
	new_block_size = (int *)malloc(new_block * sizeof(int));
	for (i = 0, j = 0; i<(*history_block); i++)
	{
		if ((*history_block_size)[i]>2)
		{
			temp = (*history_block_size)[i] / 4;
			{new_block_size[j] = temp * 2;  j++; }
			{new_block_size[j] = temp;      j++; }
			{new_block_size[j] = temp;      j++; }
		}
		else if ((*history_block_size)[i] == 2)
		{
			{new_block_size[j] = 1; j++; }
			{new_block_size[j] = 1; j++; }
			{new_block_size[j] = 0; j++; }
		}
		else if ((*history_block_size)[i] == 1)
		{
			{new_block_size[j] = 1; j++; }
			{new_block_size[j] = 0; j++; }
			{new_block_size[j] = 0; j++; }
		}
		else if ((*history_block_size)[i] == 0)
		{
			{new_block_size[j] = 0; j++; }
			{new_block_size[j] = 0; j++; }
			{new_block_size[j] = 0; j++; }
		}
	}
	free((*history_block_size));
	(*history_block_size) = new_block_size;
	(*history_block) = new_block;
}

/*********************FFT Functions**********************/

/********************************************************
*Function Name: FFT_Radix_t2
*Function:      Calculate length-N discrete fourier transform
by Cooly-Turkey FFT algorithms,which based on
Radix-2 decimation-in-time.
*Iuput:         tTD[](time domain data)
tFD[](array for frequence domain)
tFN(length of the FFT)
*Output:
*Return:
*Create Date:   05/08/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
void FFT_Radix_t2(complex *ptTD, int tTN, complex *tFD, int tFN)
{
	int i, j, k, l, power;
	int block, block_size;
	int tab_1, tab_2;
	complex *tTD;
	complex temp;

	block_size = 2;
	block = tFN / block_size;
	power = cal_power(tFN, 2);
	//expand sequence   
	tTD = expand(ptTD, tTN, tFN);
	//bit-reverse the tTD   
	bit_reverse(tTD, tFN, power);

	//calculate tFN points FFT   
	for (i = 0; i<power; i++)
	{
		for (j = 0; j<block; j++)
		{
			for (k = 0; k<block_size / 2; k++)
			{
				//the current pair of elements to calculate   
				tab_1 = j * block_size + k;
				tab_2 = tab_1 + block_size / 2;
				//calculate the basic butterfly   
				temp = complex_mul(tTD[tab_2], phase_factor(1, k, block_size));
				tFD[tab_1] = complex_add(tTD[tab_1], temp);
				tFD[tab_2] = complex_sub(tTD[tab_1], temp);
			}
		}
		block = block >> 1;
		block_size = block_size << 1;
		for (l = 0; l<tFN; l++)
		{
			tTD[l] = tFD[l];
		}
	}
	free(tTD);
}

/********************************************************
*Function Name: FFT_Radix_f2
*Function:      Calculate length-N discrete fourier transform
based on Radix-2 decimation-in-frequence.
*Iuput:         tTD[](time domain data)
tFD[](array for frequence domain data)
tFN(length of the FFT)
*Output:
*Return:
*Create Date:   05/08/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
void FFT_Radix_f2(complex *ptTD, int tTN, complex *tFD, int tFN)
{
	int i, j, k, l, power;
	int block, block_size;
	int tab_1, tab_2;
	complex *tTD;
	complex temp;

	block_size = tFN;
	block = tFN / block_size;
	power = cal_power(tFN, 2);

	//expand sequence   
	tTD = expand(ptTD, tTN, tFN);

	//calculate tFN points FFT   
	for (i = 0; i<power; i++)
	{
		for (j = 0; j<block; j++)
		{
			for (k = 0; k < block_size / 2; k++)
			{
				//the current pair of elements to calculate   
				tab_1 = j * block_size + k;
				tab_2 = tab_1 + block_size / 2;
				//calculate the basic butterfly   
				temp = complex_sub(tTD[tab_1], tTD[tab_2]);
				tFD[tab_1] = complex_add(tTD[tab_1], tTD[tab_2]);
				tFD[tab_2] = complex_mul(temp, phase_factor(1, k, block_size));
			}
		}
		block = block << 1;
		block_size = block_size >> 1;
		for (l = 0; l<tFN; l++)
		{
			tTD[l] = tFD[l];
		}
	}
	//bit-reverse the tFD   
	bit_reverse(tFD, tFN, power);
	free(tTD);
}

/********************************************************
*Function Name: SRFFT
*Function:      Calculate length-N discrete fourier transform
by Duhamel's split-radix algorithms(1986,IEEE)
*Iuput:         tTD[](time domain data)
tFD[](array for frequence domain)
tFN(length of the FFT)
*Output:
*Return:
*Create Date:   05/08/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
void SRFFT(complex *ptTD, int tTN, complex *tFD, int tFN)
{
	int *block_size;
	int block = 1;
	int power;
	int i, j, k, l;
	int tab_1, tab_2, tab_3, tab_4;
	int process_counter;

	complex *tTD;
	complex temp_1, temp_2;
	power = cal_power(tFN, 2);
	block_size = (int *)malloc(sizeof(int));
	*block_size = tFN;

	//expand sequence   
	tTD = expand(ptTD, tTN, tFN);

	//calculate tFN points IFFT   
	for (i = 0; i<power; i++)
	{
		process_counter = 0;
		for (j = 0; j<block; j++)
		{
			if (block_size[j]>2)
			{
				//by SRFFT   
				for (k = 0; k<block_size[j] / 4; k++)
				{
					//the current pair of elements to calculate   
					tab_1 = process_counter + k;
					tab_2 = tab_1 + block_size[j] / 4;
					tab_3 = tab_2 + block_size[j] / 4;
					tab_4 = tab_3 + block_size[j] / 4;
					//calculate the basic butterfly ("L" shaped)   
					tFD[tab_1] = complex_add(tTD[tab_1], tTD[tab_3]);
					tFD[tab_2] = complex_add(tTD[tab_2], tTD[tab_4]);

					temp_1 = complex_sub(tTD[tab_1], tTD[tab_3]);
					temp_2 = complex_mul(complex_sub(tTD[tab_2], tTD[tab_4]), complex_set_value(0, 1));
					tFD[tab_3] = complex_mul(complex_sub(temp_1, temp_2), phase_factor(1, k, block_size[j]));
					tFD[tab_4] = complex_mul(complex_add(temp_1, temp_2), phase_factor(1, 3 * k, block_size[j]));
				}
			}
			//by Radix-2 FFT to end last stage   
			else if (block_size[j] == 2)
			{
				//the current pair of elements to calculate   
				tab_1 = process_counter;
				tab_2 = tab_1 + 1;
				//calculate the basic butterfly ("X" shaped)   
				tFD[tab_1] = complex_add(tTD[tab_1], tTD[tab_2]);
				tFD[tab_2] = complex_sub(tTD[tab_1], tTD[tab_2]);
			}
			else if (block_size[j]<2)
			{
			}  //finished,nothing to do   

			process_counter = process_counter + block_size[j];
		}
		//block state update for SRFFT   
		updata_block(&block_size, &block);
		for (l = 0; l<tFN; l++)
		{
			tTD[l] = tFD[l];
		}
	}
	//bit-reverse the tFD   
	bit_reverse(tFD, tFN, power);
	free(tTD);
}


/*********************IFFT Functions**********************/

/********************************************************
*Function Name: IFFT_Radix_t2
*Function:      Calculate length-N inverse discrete fourier
transform by Cooly-Turkey FFT algorithms,
which based on Radix-2 decimation-in-time.
*Iuput:         tFD[](frequence domain data)
tTD[](array for time domain data)
tN(length of the IFFT)
*Output:
*Return:
*Create Date:   05/09/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
void IFFT_Radix_t2(complex *ptFD, complex *tTD, int tN)
{
	int i, j, k, l, power;
	int block, block_size;
	int tab_1, tab_2;
	complex *tFD;
	complex temp;

	//copy input sequence to tFD   
	tFD = (complex *)malloc(tN * sizeof(complex));
	for (i = 0; i<tN; i++)
	{
		tFD[i] = ptFD[i];
	}

	block_size = 2;
	block = tN / block_size;
	power = cal_power(tN, 2);

	//bit-reverse the tFD   
	bit_reverse(tFD, tN, power);

	//calculate tN points IFFT   
	for (i = 0; i<power; i++)
	{
		for (j = 0; j<block; j++)
		{
			for (k = 0; k<block_size / 2; k++)
			{
				//the current pair of elements to calculate   
				tab_1 = j * block_size + k;
				tab_2 = tab_1 + block_size / 2;
				//calculate the basic butterfly   
				temp = complex_mul(tFD[tab_2], phase_factor(-1, k, block_size));
				tTD[tab_1] = complex_add(tFD[tab_1], temp);
				tTD[tab_2] = complex_sub(tFD[tab_1], temp);
			}
		}
		block = block >> 1;
		block_size = block_size << 1;
		for (l = 0; l<tN; l++)
		{
			tFD[l] = tTD[l];
		}
	}

	//result divide by tN   
	temp = complex_set_value((1.0 / tN), 0);
	for (l = 0; l<tN; l++)
	{
		tTD[l] = complex_mul(tTD[l], temp);
	}

	free(tFD);
}
/********************************************************
*Function Name: IFFT_Radix_f2
*Function:      Calculate length-N inverse discrete fourier
transform based on Radix-2 decimation-in-frequence.
*Iuput:         tFD[](frequence domain data)
tTD[](array for time domain data)
tN(length of the FFT)
*Output:
*Return:
*Create Date:   05/09/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
void IFFT_Radix_f2(complex *ptFD, complex *tTD, int tN)
{
	int i, j, k, l, power;
	int block, block_size;
	int tab_1, tab_2;
	complex *tFD;
	complex temp;

	//copy input sequence to tFD   
	tFD = (complex *)malloc(tN * sizeof(complex));
	for (i = 0; i<tN; i++)
	{
		tFD[i] = ptFD[i];
	}

	block_size = tN;
	block = tN / block_size;
	power = cal_power(tN, 2);

	//calculate tN points IFFT   
	for (i = 0; i<power; i++)
	{
		for (j = 0; j<block; j++)
		{
			for (k = 0; k<block_size / 2; k++)
			{
				//the current pair of elements to calculate   
				tab_1 = j * block_size + k;
				tab_2 = tab_1 + block_size / 2;
				//calculate the basic butterfly   
				temp = complex_sub(tFD[tab_1], tFD[tab_2]);
				tTD[tab_1] = complex_add(tFD[tab_1], tFD[tab_2]);
				tTD[tab_2] = complex_mul(temp, phase_factor(-1, k, block_size));
			}
		}
		block = block << 1;
		block_size = block_size >> 1;
		for (l = 0; l<tN; l++)
		{
			tFD[l] = tTD[l];
		}
	}
	bit_reverse(tTD, tN, power);

	//result divide by tN   
	temp = complex_set_value((1.0 / tN), 0);
	for (l = 0; l<tN; l++)
	{
		tTD[l] = complex_mul(tTD[l], temp);
	}

	free(tFD);
}

/********************************************************
*Function Name: SRIFFT
*Function:      Calculate length-N inverse discrete fourier
transform by Duhamel's split-radix algorithms
(1986,IEEE)
*Iuput:         tFD[](frequence domain data)
tTD[](array for time domain data)
tN(length of the FFT)
*Output:
*Return:
*Create Date:   05/09/2017
*Create By:		SiQi.Wang
*Modify Date:
********************************************************/
void SRIFFT(complex *ptFD, complex *tTD, int tN)
{
	int *block_size;
	int block = 1;
	int power;
	int i, j, k, l;
	int tab_1, tab_2, tab_3, tab_4;
	int process_counter;
	complex temp_1, temp_2, temp;
	complex *tFD;

	//copy input sequence to tFD   
	tFD = (complex *)malloc(tN * sizeof(complex));
	for (i = 0; i<tN; i++)
	{
		tFD[i] = ptFD[i];
	}

	power = cal_power(tN, 2);
	block_size = (int *)malloc(sizeof(int));
	*block_size = tN;

	//calculate tN points IFFT   
	for (i = 0; i<power; i++)
	{
		process_counter = 0;
		for (j = 0; j<block; j++)
		{
			//by SRIFFT   
			if (block_size[j]>2)
			{
				for (k = 0; k<block_size[j] / 4; k++)
				{
					//the current pair of elements to calculate   
					tab_1 = process_counter + k;
					tab_2 = tab_1 + block_size[j] / 4;
					tab_3 = tab_2 + block_size[j] / 4;
					tab_4 = tab_3 + block_size[j] / 4;
					//calculate the basic butterfly ("L" shaped)   
					tTD[tab_1] = complex_add(tFD[tab_1], tFD[tab_3]);
					tTD[tab_2] = complex_add(tFD[tab_2], tFD[tab_4]);

					temp_1 = complex_sub(tFD[tab_1], tFD[tab_3]);
					temp_2 = complex_mul(complex_sub(tFD[tab_2], tFD[tab_4]), complex_set_value(0, 1));
					tTD[tab_3] = complex_mul(complex_add(temp_1, temp_2), phase_factor(-1, k, block_size[j]));
					tTD[tab_4] = complex_mul(complex_sub(temp_1, temp_2), phase_factor(-1, 3 * k, block_size[j]));
				}
			}
			//by Radix-2 IFFT to end last stage   
			else if (block_size[j] == 2)
			{
				//the current pair of elements to calculate   
				tab_1 = process_counter;
				tab_2 = tab_1 + 1;
				//calculate the basic butterfly ("X" shaped)   
				tTD[tab_1] = complex_add(tFD[tab_1], tFD[tab_2]);
				tTD[tab_2] = complex_sub(tFD[tab_1], tFD[tab_2]);
			}
			else if (block_size[j]<2)
			{
			}  //finished,nothing to do   
			process_counter = process_counter + block_size[j];
		}
		//block state update for SRIFFT   
		updata_block(&block_size, &block);
		for (l = 0; l<tN; l++)
		{
			tFD[l] = tTD[l];
		}
	}
	//bit-reverse the tTD   
	bit_reverse(tTD, tN, power);

	//result divide by tN   
	temp = complex_set_value((1.0 / tN), 0);
	for (l = 0; l<tN; l++)
	{
		tTD[l] = complex_mul(tTD[l], temp);
	}

	free(tFD);
}