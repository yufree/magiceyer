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

// [[Rcpp::export]]
NumericMatrix getmagiceye(NumericMatrix x, NumericMatrix y, double shift){
        int nrow = x.nrow(), ncol = x.ncol();
        int nrowp = y.nrow(), ncolp = y.ncol();
        for (int i = 0; i < nrow; i++) {
                for(int j = 0; j < ncol; j++){
                        if (j < ncolp) {
                                x(i,j) = y(i % nrowp,j);
                        }else{
                                int shift0 = x(i,j) * shift;
                                x(i,j) = x(i, j - ncolp + shift0);
                        }
                }
        }
        return x;
}

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//

/*** R
library(imager)
data(img)
d <- dim(img)
mask <- matrix(as.numeric(img),d[1],d[2])
i <- as.cimg(mask,dim=c(d[1],d[2],d[3],1))
plot(i)

c1 <- matrix(runif(128*64,0,1),128,64)
o <- getmagiceye(mask, c1, shift = 5)
o <- as.cimg(o,dim=c(d[1],d[2],d[3],1))
plot(o)

*/
