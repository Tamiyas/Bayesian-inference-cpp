#include "ROCCurve.hpp"

void ROCCurve::plotCurve(const std::string& fileName, int iter)
{
  DoubleVec FPRList;
  DoubleVec CDRList;
  auto start = std::chrono::system_clock::now();
  std::string progress;
  for(int theta = 0; theta != 101; ++theta){
    double thresh = theta * 0.01;
    examData.clear();
    for(int i = 0; i != iter; ++i){
      stat->reset();
      recognition(thresh);
    }
    FPRList.push_back(FPR());
    CDRList.push_back(CDR());
    std::cout << theta + 1 << "終了" << std::endl;
  }
  auto end = std::chrono::system_clock::now();
  auto sec = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
  std::cout << "処理時間: " << sec << " [sec]" << std::endl;
  writeToTSV(fileName, FPRList, CDRList);
}

void ROCCurve::recognition(double thresh)
{
  bool result = stat->calculate() > thresh;
  const IntVec& xVec = stat->getXVec();
  IntVec correct = {1, 1};
  if(xVec == correct)  examData.detected(result);
  else examData.notDetected(result);
}

double ROCCurve::FPR()
{
  return static_cast<double>(examData.FP) / static_cast<double>(examData.notX11);
}

double ROCCurve::CDR()
{
  return static_cast<double>(examData.CD) / static_cast<double>(examData.x11);
}

void ROCCurve::writeToTSV(const std::string& fileName,
                          const DoubleVec& FPRList, const DoubleVec& CDRList)
{
  std::ofstream ofs(fileName);
  if(!ofs)  return;
  if(FPRList.empty() || FPRList.size() != CDRList.size())  return;
  for(size_t i = 0; i != FPRList.size(); ++i){
    ofs << FPRList[i] << "," << CDRList[i] << std::endl;
  }
}
