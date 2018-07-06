#ifndef MODEL_DATA_H
#define MODEL_DATA_H
#include <vector>
#include <random>
#include <iostream>

using IntVec = std::vector<int>;
using DoubleVec = std::vector<double>;
using Int2DVec = std::vector<std::vector<int>>;
using Double2DVec = std::vector<std::vector<double>>;

struct ModelData {
  IntVec      nList;
  DoubleVec   sigmaList;
  Double2DVec prob;
  IntVec      xVec;
  Double2DVec y2DVec;
  ModelData(const IntVec& nList_, const DoubleVec& sigmaList_);
  const IntVec createXVec();
  const Double2DVec createY2DVec();
  double pr(int x1, int x2);
  double prX1(int x1);
  double prX2(int x2);
  void reset();
  void printXVec();
  void printY2DVec();
};

#endif
