# Travelling-Sales-Man-Problem
This C++ program uses a Simulated Annealing algorithm to tackle the Traveling Salesman Problem (TSP). The TSP seeks the shortest possible route that visits a series of cities exactly once each and returns to the starting point. Given the coordinates of the cities, the program calculates distances between them and iteratively searches for an optimal tour by minimizing the total travel cost through a probabilistic optimization approach.
# Simulated Annealing for Traveling Salesman Problem (TSP)

This project uses C++ to implement the Simulated Annealing (SA) algorithm, aiming to find an optimal or near-optimal solution to the Traveling Salesman Problem (TSP). It leverages the Standard Template Library (STL), various algorithms, and file I/O operations to effectively manage data, perform calculations, and handle input/output, resulting in an efficient and organized solution to the TSP.

## Problem Description

The Traveling Salesman Problem (TSP) is a well-known optimization challenge where, given a set of cities and the travel distances between each pair, the goal is to find the most cost-effective route that visits each city exactly once and returns to the starting point. Due to the problem's high computational complexity, this project employs the Simulated Annealing metaheuristic, an optimization technique that helps approximate an optimal solution by exploring the solution space probabilistically, making it effective for large, complex datasets.

### Simulated Annealing

Simulated Annealing (SA) is a probabilistic optimization method inspired by the annealing process used in metallurgy. The algorithm aims to find an optimal solution by randomly swapping cities within a tour and determining whether to accept these changes based on a probability function. This acceptance probability decreases over time, simulating the cooling process of metals. As the algorithm progresses, it gradually focuses on refining the solution, allowing it to converge toward a high-quality solution while still exploring the solution space to avoid getting trapped in local optima.

## Project Overview

- **Programming Language**: C++
- **Algorithm Used**: Simulated Annealing
- **Libraries Used**: Standard Template Library (STL), Algorithm library, File I/O
- **Dataset**: VLSI TSP dataset from [University of Waterloo TSP Library](http://www.math.uwaterloo.ca/tsp/vlsi/index.html)


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
   g++ tsp_sa.cpp -o tsp_sa
   </code></pre>
3. **Run the program**:<br>
   <pre><code>
   ./tsp_sa <path_to_tsp_instance_file>
   </code></pre>
4. **Usage Example**:<br>
   <pre><code>
   ./tsp_sa xqf131.tsp
   </code></pre>
5. **Output Format**:<br>
   Cost: Final achieved cost of the tour.
   Solution: Sequence of cities representing the order of traversal.
6. **References**:<br>
   *Simulated Annealing on Wikipedia*:<br> https://en.wikipedia.org/wiki/Simulated_annealing<br>
   *University of Waterloo TSP Library*:<br> https://www.math.uwaterloo.ca/tsp/vlsi/index.html

<h2 id="contributers">Contributor</h2>

<div align="center">
  <strong>
    <a href="https://github.com/sumitha05">Sumitha S</a> &emsp;
  </strong>
</div>
