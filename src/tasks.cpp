// Copyright 2025 UNN-CS

#include "circle.h"
#include "tasks.h"

#include <cmath>

double earthGapAfterRopeExtension(double earthRadiusKm,
                                   double addedLengthMeters) {
  double r = earthRadiusKm * 1000.0;

  Circle c(r);

  double newFerence = c.getFerence() + addedLengthMeters;
  c.setFerence(newFerence);

  double newR = c.getRadius();

  return newR - r;
}

double poolProjectCost() {
  double poolRadius = 3.0;
  double pathWidth = 1.0;

  Circle pool(poolRadius);
  Circle outer(poolRadius + pathWidth);

  double concreteArea = outer.getArea() - pool.getArea();
  double fenceLength = outer.getFerence();

  double cost = concreteArea * 1000.0 + fenceLength * 2000.0;

  return cost;
}
