#include <H5Cpp.h>
#include <Rcpp.h>

#ifndef __Group_h__
#define __Group_h__
// File functions
Rcpp::XPtr<H5::Group> CreateGroup(Rcpp::XPtr<H5::CommonFG> file, std::string groupname);
Rcpp::XPtr<H5::Group> OpenGroup(Rcpp::XPtr<H5::CommonFG> file, std::string groupname);
bool CloseGroup(Rcpp::XPtr<H5::Group> group);
#endif // __File_h__