#include "TimesNewRoman/TimesNewRoman.h"

#include "ili9341/ili9341.h"

uint8_t tnr_A[64] = {
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0, 
    0, 0, 0, 1, 1, 1, 0, 0, 
    0, 0, 1, 0, 1, 1, 0, 0, 
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 1, 0, 0, 0, 1, 1, 0, 
    0, 1, 0, 0, 0, 1, 1, 0, 
    1, 1, 1, 0, 1, 1, 1, 1};

struct TimeNewRoman_font A = {.h=8, .w=8, .tnr=tnr_A};

uint8_t tnr_B[56] = {
    1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 0, 0, 1, 1,
    0, 1, 1, 0, 0, 1, 1,
    0, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 0, 0, 1, 1,
    0, 1, 1, 0, 0, 1, 1,
    0, 1, 1, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 0};

struct TimeNewRoman_font B = {.h=8, .w=7, .tnr=tnr_B};

uint8_t tnr_C[56] = {
    0, 0, 1, 1, 1, 0, 1,
    0, 1, 1, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 1,
    1, 1, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 1,
    0, 0, 1, 1, 1, 1, 0,};

struct TimeNewRoman_font C = {.h=8, .w=7, .tnr=tnr_C};

uint8_t tnr_D[64] = {
    1, 1, 1, 1, 1, 1, 0, 0,
    0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 1, 0, 0, 0, 1, 1,
    0, 1, 1, 0, 0, 0, 1, 1,
    0, 1, 1, 0, 0, 0, 1, 1,
    0, 1, 1, 0, 0, 0, 1, 1,
    0, 1, 1, 0, 0, 1, 1, 0,
    1, 1, 1, 1, 1, 1, 0, 0,};

struct TimeNewRoman_font D = {.h=8, .w=8, .tnr=tnr_D};

uint8_t tnr_E[56] = {
    1, 1, 1, 1, 1, 1, 1,
    0, 1, 1, 0, 0, 1, 1,
    0, 1, 1, 0, 1, 0, 1,
    0, 1, 1, 1, 1, 0, 0,
    0, 1, 1, 0, 1, 0, 0,
    0, 1, 1, 0, 0, 0, 1,
    0, 1, 1, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 1,};

struct TimeNewRoman_font E = {.h=8, .w=7, .tnr=tnr_E};

uint8_t tnr_F[56] = {
    1, 1, 1, 1, 1, 1, 1,
    0, 1, 1, 0, 0, 1, 1,
    0, 1, 1, 0, 1, 0, 1,
    0, 1, 1, 1, 1, 0, 0,
    0, 1, 1, 0, 1, 0, 0,
    0, 1, 1, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 0,
    1, 1, 1, 1, 0, 0, 0,};

struct TimeNewRoman_font F = {.h=8, .w=7, .tnr=tnr_F};

uint8_t tnr_G[64] = {
    0, 0, 1, 1, 1, 0, 1, 0,
    0, 1, 1, 0, 0, 1, 1, 0,
    1, 1, 0, 0, 0, 0, 1, 0,
    1, 1, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 1, 1, 1, 1,
    0, 1, 1, 0, 0, 1, 1, 0,
    0, 0, 1, 1, 1, 1, 0, 0,};

struct TimeNewRoman_font G = {.h=8, .w=8, .tnr=tnr_G};

uint8_t tnr_H[72] = {
    1, 1, 1, 1, 0, 1, 1, 1, 1,
    0, 1, 1, 0, 0, 0, 1, 1, 0,
    0, 1, 1, 0, 0, 0, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 0, 0, 0, 1, 1, 0,
    0, 1, 1, 0, 0, 0, 1, 1, 0,
    0, 1, 1, 0, 0, 0, 1, 1, 0,
    1, 1, 1, 1, 0, 1, 1, 1, 1,};

struct TimeNewRoman_font H = {.h=8, .w=9, .tnr=tnr_H};

uint8_t tnr_I[32] = {
    1, 1, 1, 1,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    1, 1, 1, 1,};

struct TimeNewRoman_font I = {.h=8, .w=4, .tnr=tnr_I};

uint8_t tnr_J[48] = {
    0, 0, 1, 1, 1, 1,
    0, 0, 0, 1, 1, 0,
    0, 0, 0, 1, 1, 0,
    0, 0, 0, 1, 1, 0,
    0, 0, 0, 1, 1, 0,
    1, 1, 0, 1, 1, 0,
    1, 1, 0, 1, 1, 0,
    0, 1, 1, 1, 0, 0,};

struct TimeNewRoman_font J = {.h=8, .w=6, .tnr=tnr_J};

uint8_t tnr_K[64] = {
    1, 1, 1, 1, 0, 1, 1, 1,
    0, 1, 1, 0, 0, 1, 0, 0,
    0, 1, 1, 0, 1, 0, 0, 0,
    0, 1, 1, 1, 1, 0, 0, 0,
    0, 1, 1, 1, 1, 0, 0, 0,
    0, 1, 1, 0, 1, 1, 0, 0,
    0, 1, 1, 0, 0, 1, 1, 0,
    1, 1, 1, 1, 0, 1, 1, 1,};

struct TimeNewRoman_font K = {.h=8, .w=8, .tnr=tnr_K};

uint8_t tnr_L[56] = {
    1, 1, 1, 1, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 1,
    0, 1, 1, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 1,};

struct TimeNewRoman_font L = {.h=8, .w=7, .tnr=tnr_L};

uint8_t tnr_M[80] = {
    1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
    0, 1, 1, 1, 0, 0, 1, 1, 1, 0,
    0, 1, 1, 1, 0, 0, 1, 1, 1, 0,
    0, 1, 0, 1, 1, 1, 0, 1, 1, 0,
    0, 1, 0, 1, 1, 1, 0, 1, 1, 0,
    0, 1, 0, 1, 1, 1, 0, 1, 1, 0,
    0, 1, 0, 0, 1, 0, 0, 1, 1, 0,
    1, 1, 1, 0, 1, 0, 1, 1, 1, 1,};

struct TimeNewRoman_font M = {.h=8, .w=10, .tnr=tnr_M};

uint8_t tnr_N[64] = {
    1, 1, 1, 0, 0, 1, 1, 1,
    0, 1, 1, 1, 0, 0, 1, 0,
    0, 1, 0, 1, 1, 0, 1, 0,
    0, 1, 0, 1, 1, 0, 1, 0,
    0, 1, 0, 0, 1, 1, 1, 0,
    0, 1, 0, 0, 0, 1, 1, 0,
    0, 1, 0, 0, 0, 1, 1, 0,
    1, 1, 1, 0, 0, 0, 1, 1,};

struct TimeNewRoman_font N = {.h=8, .w=8, .tnr=tnr_N};

uint8_t tnr_O[64] = {
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 1, 1, 0, 0, 1, 1, 0,
    1, 1, 0, 0, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 1, 1,
    0, 1, 1, 0, 0, 1, 1, 0,
    0, 0, 1, 1, 1, 1, 0, 0,};

struct TimeNewRoman_font O = {.h=8, .w=8, .tnr=tnr_O};

uint8_t tnr_P[56] = {
    1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 0, 0, 1, 1,
    0, 1, 1, 0, 0, 1, 1,
    0, 1, 1, 0, 0, 1, 1,
    0, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 0,
    1, 1, 1, 1, 0, 0, 0,};

struct TimeNewRoman_font P = {.h=8, .w=7, .tnr=tnr_P};

uint8_t tnr_Q[80] = {
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 1, 1, 0, 0, 1, 1, 0,
    1, 1, 0, 0, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 1, 1,
    0, 1, 1, 0, 0, 1, 1, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 1,};

struct TimeNewRoman_font Q = {.h=10, .w=8, .tnr=tnr_Q};

uint8_t tnr_R[72] = {
    1, 1, 1, 1, 1, 1, 0, 0, 0,
    0, 1, 1, 0, 0, 1, 1, 0, 0,
    0, 1, 1, 0, 0, 1, 1, 0, 0,
    0, 1, 1, 1, 1, 1, 0, 0, 0,
    0, 1, 1, 0, 0, 1, 1, 0, 0,
    0, 1, 1, 0, 0, 1, 1, 0, 0,
    0, 1, 1, 0, 0, 0, 1, 1, 0,
    1, 1, 1, 1, 0, 0, 1, 1, 1,};

struct TimeNewRoman_font R = {.h=8, .w=9, .tnr=tnr_R};

uint8_t tnr_S[64] = {
    0, 1, 1, 0, 1,
    1, 1, 0, 1, 1,
    1, 1, 0, 0, 0,
    1, 1, 1, 1, 0,
    0, 1, 1, 1, 1,
    0, 0, 0, 1, 1,
    1, 1, 0, 1, 1,
    1, 0, 1, 1, 0,};

struct TimeNewRoman_font S = {.h=8, .w=5, .tnr=tnr_S};

uint8_t tnr_T[64] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 0, 1, 1, 0, 1, 1,
    1, 0, 0, 1, 1, 0, 0, 1,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,};

struct TimeNewRoman_font T = {.h=8, .w=8, .tnr=tnr_T};

uint8_t tnr_U[64] = {
    1, 1, 1, 1, 0, 1, 1, 1,
    0, 1, 1, 0, 0, 0, 1, 0,
    0, 1, 1, 0, 0, 0, 1, 0,
    0, 1, 1, 0, 0, 0, 1, 0,
    0, 1, 1, 0, 0, 0, 1, 0,
    0, 1, 1, 0, 0, 0, 1, 0,
    0, 1, 1, 0, 0, 0, 1, 0,
    0, 0, 1, 1, 1, 1, 0, 0,};

struct TimeNewRoman_font U = {.h=8, .w=8, .tnr=tnr_U};

uint8_t tnr_V[64] = {
    1, 1, 1, 1, 0, 1, 1, 1,
    0, 1, 1, 0, 0, 0, 1, 0,
    0, 1, 1, 0, 0, 0, 1, 0,
    0, 0, 1, 1, 0, 1, 0, 0,
    0, 0, 1, 1, 0, 1, 0, 0,
    0, 0, 1, 1, 0, 1, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,};

struct TimeNewRoman_font V = {.h=8, .w=8, .tnr=tnr_V};

uint8_t tnr_W[96] = {
    1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
    0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0,
    0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,
    0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0,
    0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0,};

struct TimeNewRoman_font W = {.h=8, .w=12, .tnr=tnr_W};

uint8_t tnr_X[56] = {
    1, 1, 1, 1, 0, 1, 1,
    0, 1, 1, 0, 0, 1, 0,
    0, 0, 1, 1, 1, 0, 0,
    0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0,
    0, 0, 1, 1, 1, 0, 0,
    0, 1, 0, 0, 1, 1, 0,
    1, 1, 0, 0, 1, 1, 1,};

struct TimeNewRoman_font X = {.h=8, .w=7, .tnr=tnr_X};

uint8_t tnr_Y[64] = {
    1, 1, 1, 1, 0, 1, 1, 1,
    0, 1, 1, 0, 0, 0, 1, 0,
    0, 0, 1, 1, 0, 1, 0, 0,
    0, 0, 1, 1, 0, 1, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,};

struct TimeNewRoman_font Y = {.h=8, .w=8, .tnr=tnr_Y};

uint8_t tnr_Z[56] = {
    1, 1, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 1, 1, 0,
    1, 0, 0, 1, 1, 0, 0,
    0, 0, 0, 1, 1, 0, 0,
    0, 0, 1, 1, 0, 0, 0,
    0, 0, 1, 1, 0, 0, 1,
    0, 1, 1, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 1,};

struct TimeNewRoman_font Z = {.h=8, .w=7, .tnr=tnr_Z};

uint8_t tnr_0[40] = {
    0, 1, 1, 1, 0,
    1, 1, 0, 1, 1,
    1, 1, 0, 1, 1,
    1, 1, 0, 1, 1,
    1, 1, 0, 1, 1,
    1, 1, 0, 1, 1,
    1, 1, 0, 1, 1,
    0, 1, 1, 1, 0,};

struct TimeNewRoman_font num_0 = {.h=8, .w=5, .tnr=tnr_0};

uint8_t tnr_1[32] = {
    1, 1, 1, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    1, 1, 1, 1,};

struct TimeNewRoman_font num_1 = {.h=8, .w=4, .tnr=tnr_1};

uint8_t tnr_2[40] = {
    0, 1, 1, 1, 0,
    1, 1, 1, 1, 1,
    1, 0, 0, 1, 1,
    0, 0, 0, 1, 0,
    0, 0, 0, 1, 0,
    0, 1, 1, 0, 0,
    0, 1, 1, 1, 1,
    1, 1, 1, 1, 1,};

struct TimeNewRoman_font num_2 = {.h=8, .w=5, .tnr=tnr_2};

uint8_t tnr_3[40] = {
    0, 1, 1, 1, 0,
    1, 0, 0, 1, 1,
    0, 0, 0, 1, 1,
    0, 0, 1, 1, 0,
    0, 0, 0, 1, 1,
    0, 0, 0, 1, 1,
    1, 0, 0, 1, 1,
    0, 1, 1, 1, 0,};

struct TimeNewRoman_font num_3 = {.h=8, .w=5, .tnr=tnr_3};

uint8_t tnr_4[48] = {
    0, 0, 0, 0, 1, 0,
    0, 0, 0, 1, 1, 0,
    0, 0, 1, 0, 1, 0,
    0, 1, 0, 0, 1, 0,
    1, 0, 0, 0, 1, 0,
    1, 1, 1, 1, 1, 1,
    0, 0, 0, 1, 1, 0,
    0, 0, 0, 1, 1, 0,};

struct TimeNewRoman_font num_4 = {.h=8, .w=6, .tnr=tnr_4};

uint8_t tnr_5[40] = {
    0, 1, 1, 1, 1,
    0, 1, 1, 1, 0,
    0, 1, 0, 0, 0,
    1, 1, 1, 1, 0,
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    1, 1, 0, 1, 0,
    1, 1, 1, 0, 0,};

struct TimeNewRoman_font num_5 = {.h=8, .w=5, .tnr=tnr_5};

uint8_t tnr_6[40] = {
    0, 0, 0, 1, 1,
    0, 1, 1, 0, 0,
    0, 1, 0, 0, 0,
    1, 1, 1, 1, 0,
    1, 1, 0, 1, 1,
    1, 1, 0, 1, 1,
    1, 1, 0, 1, 1,
    0, 1, 1, 1, 0,};

struct TimeNewRoman_font num_6 = {.h=8, .w=5, .tnr=tnr_6};

uint8_t tnr_7[40] = {
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    0, 0, 0, 1, 0,
    0, 0, 0, 1, 0,
    0, 0, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,};

struct TimeNewRoman_font num_7 = {.h=8, .w=5, .tnr=tnr_7};

uint8_t tnr_8[40] = {
    0, 1, 1, 1, 0,
    1, 1, 0, 1, 1,
    1, 1, 0, 1, 1,
    0, 1, 1, 1, 0,
    0, 1, 1, 1, 0,
    1, 1, 0, 1, 1,
    1, 1, 0, 1, 1,
    0, 1, 1, 1, 0,};

struct TimeNewRoman_font num_8 = {.h=8, .w=5, .tnr=tnr_8};

uint8_t tnr_9[40] = {
    0, 1, 1, 1, 0,
    1, 1, 0, 1, 1,
    1, 1, 0, 1, 1,
    1, 1, 0, 1, 1,
    0, 1, 1, 1, 1,
    0, 0, 0, 1, 0,
    0, 0, 1, 1, 0,
    1, 1, 0, 0, 0,};

struct TimeNewRoman_font num_9 = {.h=8, .w=5, .tnr=tnr_9};

uint8_t pnt[16] = {
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    1, 1,
    1, 1,};

struct TimeNewRoman_font point = {.h=8, .w=2, .tnr=pnt};

uint8_t cmm[20] = {
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    1, 1,
    1, 1,
    0, 1,
    1, 0,};

struct TimeNewRoman_font common = {.h=10, .w=2, .tnr=cmm};

uint8_t tpnt[16] = {
    0, 0,
    0, 0,
    1, 1,
    1, 1,
    0, 0,
    1, 1,
    1, 1,
    0, 0,};

struct TimeNewRoman_font two_point = {.h=8, .w=2, .tnr=tpnt};

uint8_t qll[32] = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,};

struct TimeNewRoman_font equally = {.h=8, .w=4, .tnr=qll};

uint8_t prc[64] = {
    0, 1, 0, 0, 0, 0, 1, 0,
    1, 0, 1, 0, 0, 1, 0, 0,
    1, 0, 1, 0, 1, 0, 0, 0,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    0, 0, 0, 1, 0, 1, 0, 1,
    0, 0, 1, 0, 0, 1, 0, 1,
    0, 1, 0, 0, 0, 0, 1, 0,};

struct TimeNewRoman_font percent = {.h=8, .w=8, .tnr=prc};

void letter_to_buffer(struct TimeNewRoman_font letter, uint16_t x, uint16_t y, uint8_t* buffer)
{
    uint8_t let_size[letter.w*letter.h];
    for (int i = 0; i < letter.w*letter.h; i++) {
        let_size[i] = ("%d", letter.tnr[i]);
    }
    int n = 0;
    for (int i = y*SCREEN_WIDTH*2; i < (SCREEN_WIDTH*y*2) + (letter.h*SCREEN_WIDTH*2); i+=SCREEN_WIDTH*2)
    {
        for (int j = x * 2; j < (x * 2) + (letter.w*2); j+=2)
        {
            if (let_size[n]) {
                buffer[i+j] = let_size[n] * 100;
                buffer[i+j+1] = let_size[n] * 100;
            }
            n++;
        }
    }
}

uint16_t enter_a_letter(char letter, uint16_t x, uint16_t y, uint8_t* buffer)
{
    if (letter == 'A') {
        letter_to_buffer(A, x, y, buffer);
        return A.w;
    }
    else if (letter == 'B') {
        letter_to_buffer(B, x, y, buffer);
        return B.w;
    }
    else if (letter == 'C') {
        letter_to_buffer(C, x, y, buffer);
        return C.w;
    }
    else if (letter == 'D') {
        letter_to_buffer(D, x, y, buffer);
        return D.w;
    }
    else if (letter == 'E') {
        letter_to_buffer(E, x, y, buffer);
        return E.w;
    }
    else if (letter == 'F') {
        letter_to_buffer(F, x, y, buffer);
        return F.w;
    }
    else if (letter == 'G') {
        letter_to_buffer(G, x, y, buffer);
        return G.w;
    }
    else if (letter == 'H') {
        letter_to_buffer(H, x, y, buffer);
        return H.w;
    }
    else if (letter == 'I') {
        letter_to_buffer(I, x, y, buffer);
        return I.w;
    }
    else if (letter == 'J') {
        letter_to_buffer(J, x, y, buffer);
        return J.w;
    }
    else if (letter == 'K') {
        letter_to_buffer(K, x, y, buffer);
        return K.w;
    }
    else if (letter == 'L') {
        letter_to_buffer(L, x, y, buffer);
        return L.w;
    }
    else if (letter == 'M') {
        letter_to_buffer(M, x, y, buffer);
        return M.w;
    }
    else if (letter == 'N') {
        letter_to_buffer(N, x, y, buffer);
        return N.w;
    }
    else if (letter == 'O') {
        letter_to_buffer(O, x, y, buffer);
        return O.w;
    }
    else if (letter == 'P') {
        letter_to_buffer(P, x, y, buffer);
        return P.w;
    }
    else if (letter == 'Q') {
        letter_to_buffer(Q, x, y, buffer);
        return Q.w;
    }
    else if (letter == 'R') {
        letter_to_buffer(R, x, y, buffer);
        return R.w;
    }
    else if (letter == 'S') {
        letter_to_buffer(S, x, y, buffer);
        return S.w;
    }
    else if (letter == 'T') {
        letter_to_buffer(T, x, y, buffer);
        return T.w;
    }
    else if (letter == 'U') {
        letter_to_buffer(U, x, y, buffer);
        return U.w;
    }
    else if (letter == 'V') {
        letter_to_buffer(V, x, y, buffer);
        return V.w;
    }
    else if (letter == 'W') {
        letter_to_buffer(W, x, y, buffer);
        return W.w;
    }
    else if (letter == 'X') {
        letter_to_buffer(X, x, y, buffer);
        return X.w;
    }
    else if (letter == 'Y') {
        letter_to_buffer(Y, x, y, buffer);
        return Y.w;
    }
    else if (letter == 'Z') {
        letter_to_buffer(Z, x, y, buffer);
        return Z.w;
    }
    else if (letter == '0') {
        letter_to_buffer(num_0, x, y, buffer);
        return num_0.w;
    }
    else if (letter == '1') {
        letter_to_buffer(num_1, x, y, buffer);
        return num_1.w;
    }
    else if (letter == '2') {
        letter_to_buffer(num_2, x, y, buffer);
        return num_2.w;
    }
    else if (letter == '3') {
        letter_to_buffer(num_3, x, y, buffer);
        return num_3.w;
    }
    else if (letter == '4') {
        letter_to_buffer(num_4, x, y, buffer);
        return num_4.w;
    }
    else if (letter == '5') {
        letter_to_buffer(num_5, x, y, buffer);
        return num_5.w;
    }
    else if (letter == '6') {
        letter_to_buffer(num_6, x, y, buffer);
        return num_6.w;
    }
    else if (letter == '7') {
        letter_to_buffer(num_7, x, y, buffer);
        return num_7.w;
    }
    else if (letter == '8') {
        letter_to_buffer(num_8, x, y, buffer);
        return num_8.w;
    }
    else if (letter == '9') {
        letter_to_buffer(num_9, x, y, buffer);
        return num_9.w;
    }

    else if (letter == '.') {
        letter_to_buffer(point, x, y, buffer);
        return point.w;
    }
    else if (letter == ',') {
        letter_to_buffer(common, x, y, buffer);
        return common.w;
    }
    else if (letter == ':') {
        letter_to_buffer(two_point, x, y, buffer);
        return two_point.w;
    }
    else if (letter == '=') {
        letter_to_buffer(equally, x, y, buffer);
        return equally.w;
    }
    else if (letter == '%') {
        letter_to_buffer(percent, x, y, buffer);
        return percent.w;
    }
}

void enter_a_text(char text[], uint16_t x, uint16_t y, uint8_t* buffer)
{
    uint16_t delta_x = x;
    uint16_t delta_y = y;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '\n') 
        {
            delta_y += 10;
            delta_x = x;
        }
        else if (text[i] == ' ') {
            delta_x += 9;
        }
        else {
            delta_x += enter_a_letter(text[i], delta_x, delta_y, buffer) + 1;
        }

        if ((delta_x + 12) >= SCREEN_WIDTH) {
            delta_x = 0;
            delta_y += 10;
        }
    }
}
