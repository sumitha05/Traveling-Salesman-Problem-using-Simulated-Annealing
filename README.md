# Travelling-Sales-Man-Problem
This C++ program implements a Simulated Annealing algorithm to solve the Traveling Salesman Problem (TSP). Given a set of cities and the distances between them, the goal is to find the shortest possible route that visits each city exactly once and returns to the starting city.
# Simulated Annealing for Traveling Salesman Problem (TSP)

This project implements the Simulated Annealing (SA) algorithm to find an optimal or near-optimal solution to the Traveling Salesman Problem (TSP) using C++. This project involves using STL, algorithms, and file I/O operations in C++ to achieve the solution.

## Problem Description

The Traveling Salesman Problem (TSP) is a classic optimization problem where, given a set of cities and the travel costs (distances) between each pair of them, the objective is to find the cheapest way to visit all cities exactly once and return to the starting city. This project uses the Simulated Annealing metaheuristic to approximate an optimal solution due to the high computational complexity of the problem.

### Simulated Annealing

Simulated Annealing (SA) is a probabilistic optimization technique inspired by the annealing process in metallurgy. The algorithm seeks an optimal solution by randomly swapping cities and accepting changes based on probability. Over time, this probability decreases, allowing the algorithm to converge to a solution.

## Project Overview

- **Programming Language**: C++
- **Algorithm Used**: Simulated Annealing
- **Libraries Used**: Standard Template Library (STL), Algorithm library, File I/O
- **Dataset**: VLSI TSP dataset from [University of Waterloo TSP Library](http://www.math.uwaterloo.ca/tsp/vlsi/index.html)

## Dataset

This project uses VLSI TSP instances from the University of Waterloo. The instances range from 131 cities to over 744,000 cities. Each instance file contains city coordinates, and the distances between cities are calculated as Euclidean distances.

## Input

- TSP instances in `.tsp` file format from the VLSI TSP dataset. Each file contains city coordinates that specify their positions in a 2D plane.
- The Euclidean distance between cities \( X \) and \( Y \) is calculated as:
  
  \[
  \text{distance} = \text{round}(\sqrt{(x2 - x1)^2 + (y2 - y1)^2})
  \]

## Output

- The algorithm will output:
  - The final cost of the TSP tour.
  - The sequence of cities (optimal path) that minimizes the travel cost.

## Algorithm Details

1. **Initialization**:
   - Start with an initial random solution \( S \), where all cities are in a random order.

2. **Neighbor Solution Generation**:
   - Generate a neighboring solution \( S' \) by swapping the positions of two randomly selected cities.

3. **Acceptance Criteria**:
   - If the new solution \( S' \) has a lower cost than \( S \), it is accepted.
   - If \( S' \) has a higher cost, it may still be accepted based on a probability that decreases over time, allowing for an exploration of the solution space.

4. **Cooling Schedule**:
   - The acceptance probability decreases as the number of iterations increases, simulating a cooling process.

5. **Iterations**:
   - The algorithm runs for a specified number of iterations (e.g., 10,000) to find an optimal or near-optimal solution.

## Installation

1. **Clone the repository**:<br>
<pre><code>
   git clone (github link)
  </code></pre>
2. **Compile the C++ program**:<br>
<pre><code>
   g++ -o tsp_simulated_annealing tsp_simulated_annealing.cpp
  </code></pre>
3. **Run the program**:<br>
<pre><code>
   ./tsp_simulated_annealing <path_to_tsp_instance_file>
  </code></pre>
4. **Usage Example**:<br>
<pre><code>
   ./tsp_simulated_annealing data/xqf131.tsp
  </code></pre>
5. **Output Format**:<br>
   Cost: Final achieved cost of the tour.
   Solution: Sequence of cities representing the order of traversal.
6. **References**:<br>
   *Simulated Annealing on Wikipedia*:<br> https://en.wikipedia.org/wiki/Simulated_annealing<br>
   *University of Waterloo TSP Library*:<br> https://www.math.uwaterloo.ca/tsp/vlsi/index.html


