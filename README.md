# Smart-Delivery-Planning-Fractional-Knapsack
A menu-driven C program for solving the Fractional Knapsack problem using the Greedy Method.

## Overview

The program helps a delivery company maximize the value of packages loaded into a vehicle with limited capacity. Each package has a value and weight, and fractions of packages can be selected when required.

The program calculates the Value/Weight ratio of each package, sorts the packages in decreasing order using Merge Sort, and selects packages based on the highest ratio.

## Features

* Enter package details
* Calculate Value/Weight ratios
* Sort packages by ratio
* Find maximum achievable value
* Display selected packages and fractions
* Display total weight used

## How It Works

Packages with higher Value/Weight ratios are selected first. Complete packages are selected whenever possible. If the remaining capacity is not enough for a complete package, the required fraction of that package is selected.

## Complexity

Ratio calculation: O(n)
Merge Sort: O(n log n)
Package selection: O(n)

Overall time complexity: O(n log n)

## Project File

`Smart_Delivery_Planning.c`
