#include <Rcpp.h>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//
//' Generate autosterograms
//'
//' @param x depth matrix
//' @param y pattern matrix
//' @param shift shift for magic eye
//' @return matrix of autosterograms
// [[Rcpp::export]]
NumericMatrix getmagiceye(NumericMatrix x, NumericMatrix y,double shift){
        int nrow = x.nrow(), ncol = x.ncol();
        int nrowy = y.nrow(), ncoly = y.ncol();
        NumericMatrix z(nrow,ncol);
        for (int i = 0; i < nrow; i++) {
                for(int j = 0; j < ncol; j++){
                        if (j < ncoly) {
                                z(i,j) = y(i%nrowy,j);
                        }else{
                                int shift0 = x(i,j) * ncoly*shift;
                                z(i,j) = z(i,j-ncoly+shift0);
                        }
                }
        }
        return z;
}
