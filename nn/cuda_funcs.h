#ifndef _CUDA_FUNCS_H
#define _CUDA_FUNCS_H

#include "nn.h"
//#include "delaunay.h"

//namespace cuda_funcs{

// necessary for the triangle struct
#include "delaunay.h"

#ifdef __cplusplus
extern "C" {

//void cuda_nnpi_normalize_weights(nnpi *nn);
//int cuda__get_circle(delaunay* d, point* p, int nt);
//void cuda_set_delaunay(delaunay* d);
//void check_delaunay();
//void cuda_set_circles(circle* c, int count);
//void cuda_test_get_global_circles(circle* c, int count);

//void cuda_delaunay_circles_find(delaunay* d, point* p, int* n, int** out);


//int cuda_delaunay_circles_find_all(double pts[][2], int npts, double* cx, double* cy, double* cr, int n_cir);
int* cuda_delaunay_circles_find_all(delaunay* d, point* p, int npts);
void cuda_delaunay_circles_find_all_tricircles(delaunay* d, point* p, int npts, int **matches, int **nmatches);
void cuda_find_neighboring_delaunay(double ntris, int* circle_ids, int* n_point_triangles, int** point_triangles,
                                               triangle* triangles, double* ptx, double* pty, int npts, double* cx, double* cy, double* cr,
                                               int* n_out, int** v_out);
void cuda_sibson_weights(nnpi* nn, point* p, int** tids);
}
#else
//
//void cuda_nnpi_normalize_weights(nnpi *nn);
//int cuda__get_circle(delaunay* d, point* p, int nt);
//void cuda_set_delaunay(delaunay* d);
//void check_delaunay();
//void cuda_set_circles(circle* c, int count);
//void cuda_test_get_global_circles(circle* c, int count);
//void cuda_delaunay_circles_find(delaunay* d, point* p, int* n, int** out);

//int cuda_delaunay_circles_find_all(double pts[][2], int npts, double* cx, double* cy, double* cr, int n_cir);
int* cuda_delaunay_circles_find_all(delaunay* d, point* p, int npts);
void cuda_delaunay_circles_find_all_tricircles(delaunay* d, point* p, int npts, int **matches, int **nmatches);
void cuda_find_neighboring_delaunay(double ntris, int* circle_ids, int* n_point_triangles, int** point_triangles,
                                    triangle* triangles, double* ptx, double* pty, int npts, double* cx, double* cy, double* cr,
                                    int* n_out, int** v_out);
void cuda_sibson_weights(nnpi* nn, point* p, int** tids);

#endif



//// The ifdef checks are necessary to prevent name mangling between C and C++ (CUDA)
//#ifdef __cplusplus
//    extern "C" {
//
//        #include "nn.h"
//        __global__ void cuda_nnpi_normalize_weights(nnpi *nn);
//    }
//#else
//    #include "nn.h"
//    void cuda_nnpi_normalize_weights(nnpi *nn);
//    #endif

#endif