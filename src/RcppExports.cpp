// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// getmagiceye
NumericMatrix getmagiceye(NumericMatrix x, NumericMatrix y, double shift);
RcppExport SEXP magiceyer_getmagiceye(SEXP xSEXP, SEXP ySEXP, SEXP shiftSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type x(xSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type y(ySEXP);
    Rcpp::traits::input_parameter< double >::type shift(shiftSEXP);
    rcpp_result_gen = Rcpp::wrap(getmagiceye(x, y, shift));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"magiceyer_getmagiceye", (DL_FUNC) &magiceyer_getmagiceye, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_magiceyer(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}