#include "File.h"

using namespace H5;
using namespace Rcpp;
using namespace std;


bool file_exist (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

// [[Rcpp::export]]
XPtr<H5File> OpenFile(string filePath, string mode) {
  map<std::string, unsigned int> filemodes;
  filemodes["r"] = H5F_ACC_RDONLY;
  filemodes["r+"] = H5F_ACC_RDWR;
  filemodes["w"] = H5F_ACC_TRUNC;
  filemodes["w-"] = H5F_ACC_EXCL;
  if(file_exist(filePath)) {
    filemodes["a"] = H5F_ACC_RDWR;
  } else {
    filemodes["a"] = H5F_ACC_EXCL;
  }

  if (filemodes.find(mode) == filemodes.end()) {
    throw Rcpp::exception("Given file mode not found");
  }

  H5File *file = new H5File(filePath, filemodes[mode]);
  return XPtr<H5File>(file);
}


// [[Rcpp::export]]
bool CloseFile(XPtr<H5File> file) {
  file->close();
  return TRUE;
}


