#include "ModelData.hpp"

ModelData::ModelData(const IntVec& nList_, const DoubleVec& sigmaList_)
  : nList(nList_), sigmaList(sigmaList_)
{
  prob = {{0.6, 0.1}, {0.1, 0.2}};
  xVec = createXVec();
  y2DVec = createY2DVec();
}

const IntVec ModelData::createXVec()
{
  // メルセンヌツイスタ
  std::mt19937 mt{ std::random_device{}() };
  std::uniform_real_distribution<> dist(0.0, 1.0);

  double prob = dist(mt);
  if(0.0 <= prob && prob < 0.6)  return {0, 0};
  if(0.6 <= prob && prob < 0.7)  return {0, 1};
  if(0.7 <= prob && prob < 0.8)  return {1, 0};
  if(0.8 <= prob && prob < 1.0)  return {1, 1};

  return {0, 0};
}

const Double2DVec ModelData::createY2DVec()
{
  if(xVec.empty() == true)  xVec = createXVec();
  // メルセンヌツイスタ
  std::mt19937 mt{ std::random_device{}() };
  int count = 0;
  Double2DVec yVec;
  for(const auto& num : nList){
    std::normal_distribution<> dist(static_cast<double>(xVec[count]),
                                    sigmaList[count] * sigmaList[count]);
    DoubleVec v;
    for(int i = 0; i != num; ++i)  v.push_back(dist(mt));
    yVec.push_back(v);
    ++count;
  }

  return yVec;
}

double ModelData::pr(int x1, int x2)
{
  return prob[x1][x2];
}

double ModelData::prX1(int x1)
{
  double result = 0.0;
  for(size_t x2 = 0; x2 != 2; ++x2)
    result += prob[x1][x2];
  return result;
}

double ModelData::prX2(int x2)
{
  double result = 0.0;
  for(size_t x1 = 0; x1 != 2; ++x1)
    result += prob[x1][x2];
  return result;
}

void ModelData::printXVec()
{
  std::cout << "[ ";
  for(const auto& x : xVec)  std::cout << x << " ";
  std::cout << "]" << std::endl;
}

void ModelData::printY2DVec()
{
  std::cout << "[ ";
  for(const auto& yVec : y2DVec){
    std::cout << "[";
    for(const auto& y : yVec)  std::cout << y << " ";
    std::cout << "] ";
  }
  std::cout << "]" << std::endl;
}

void ModelData::reset()
{
  xVec   = createXVec();
  y2DVec = createY2DVec();
}
