// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"

static constexpr double EPS = 1e-6;

TEST(CircleTest, RadiusToFerenceArea) {
    Circle c(1.0);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI, EPS);
    EXPECT_NEAR(c.getArea(), M_PI, EPS);
}

TEST(CircleTest, FerenceToRadius) {
    Circle c;
    c.setFerence(2 * M_PI);
    EXPECT_NEAR(c.getRadius(), 1.0, EPS);
}

TEST(CircleTest, AreaToRadius) {
    Circle c;
    c.setArea(M_PI);
    EXPECT_NEAR(c.getRadius(), 1.0, EPS);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0);
    EXPECT_NEAR(c.getArea(), 0, EPS);
    EXPECT_NEAR(c.getFerence(), 0, EPS);
}

TEST(CircleTest, LargeRadius) {
    Circle c(100);
    EXPECT_NEAR(c.getArea(), M_PI * 10000, EPS);
}

TEST(CircleTest, SetRadiusUpdates) {
    Circle c(2);
    c.setRadius(3);
    EXPECT_NEAR(c.getArea(), M_PI * 9, EPS);
}

TEST(CircleTest, SetFerenceConsistency) {
    Circle c;
    c.setFerence(10);
    EXPECT_NEAR(c.getFerence(), 10, EPS);
}

TEST(CircleTest, SetAreaConsistency) {
    Circle c;
    c.setArea(50);
    EXPECT_NEAR(c.getArea(), 50, EPS);
}

TEST(TaskTest, EarthGapPositive) {
    double gap = earthGapAfterRopeExtension(6378.1, 1.0);
    EXPECT_GT(gap, 0);
}

TEST(TaskTest, EarthGapSmall) {
    double gap = earthGapAfterRopeExtension(6378.1, 1.0);
    EXPECT_NEAR(gap, 1.0 / (2 * M_PI), 1e-6);
}

TEST(TaskTest, PoolCostPositive) {
    EXPECT_GT(poolProjectCost(), 0);
}

TEST(CircleStress, ManyUpdates) {
    Circle c(1);
    for (int i = 1; i < 100; i++) {
        c.setRadius(i);
        EXPECT_GT(c.getArea(), 0);
    }
}

TEST(CircleConsistency, RadiusFromAreaBackCheck) {
    Circle c;
    c.setArea(10);
    double r = c.getRadius();
    EXPECT_NEAR(c.getArea(), M_PI * r * r, EPS);
}


TEST(CircleExtra1, CheckFerenceFormula) {
    Circle c(5);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 5, EPS);
}

TEST(CircleExtra2, AreaAfterFerenceSet) {
    Circle c;
    c.setFerence(2 * M_PI * 2);
    EXPECT_NEAR(c.getArea(), M_PI * 4, EPS);
}

TEST(CircleExtra3, EarthLargeScale) {
    double gap = earthGapAfterRopeExtension(1000, 10);
    EXPECT_GT(gap, 0);
}

TEST(CircleExtra4, PoolRadiusCheck) {
    Circle c(3);
    EXPECT_NEAR(c.getRadius(), 3, EPS);
}

TEST(CircleExtra5, PoolAreaNonZero) {
    EXPECT_GT(poolProjectCost(), 0);
}

TEST(CircleExtra6, AreaRadiusRelation) {
    Circle c(4);
    EXPECT_NEAR(c.getArea(), M_PI * 16, EPS);
}

TEST(CircleExtra7, FerenceRadiusRelation) {
    Circle c(4);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 4, EPS);
}

TEST(CircleExtra8, ZeroArea) {
    Circle c;
    c.setArea(0);
    EXPECT_NEAR(c.getRadius(), 0, EPS);
}

TEST(CircleExtra9, SymmetryCheck) {
    Circle c1(7);
    Circle c2;
    c2.setArea(c1.getArea());
    EXPECT_NEAR(c1.getRadius(), c2.getRadius(), EPS);
}

TEST(CircleExtra10, StabilityTest) {
    Circle c(1);
    for (int i = 0; i < 50; i++) {
        c.setRadius(1);
    }
    EXPECT_NEAR(c.getRadius(), 1, EPS);
}
