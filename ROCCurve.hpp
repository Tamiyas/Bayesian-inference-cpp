#ifndef ROC_CURVE_H
#define ROC_CURVE_H
#include "Statistics.hpp"
#include <memory>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>

struct ExamData {
  int x11;
  int notX11;
  int FP;
  int CD;
  ExamData() : x11(0), notX11(0), FP(0), CD(0) { }
  void clear() { x11 = notX11 = FP = CD = 0; }
  void detected(bool result) { ++x11; if(result){ ++CD; } }
  void notDetected(bool result) { ++notX11; if(result){ ++FP; } }
};

class ROCCurve {
  private:
    std::unique_ptr<Statistics> stat;
    ExamData examData;
  public:
    ROCCurve(std::unique_ptr<Statistics>&& stat_)
      : stat(std::move(stat_)) { }
    void plotCurve(const std::string& fileName, int iter = 100000);
    void writeToTSV(const std::string& fileName, const DoubleVec& FPRList, const DoubleVec& CDRList);
    void recognition(double thresh);
    double FPR();
    double CDR();
};


#endif
