This project demonstrates how to render **Julia fractals**—geometrical shapes with intricate, self-similar structures—using the **C programming language** and **OpenMP** for parallelism. The fractal is visualized and displayed in a window using the [tigr.c](https://github.com/erkkah/tigr) graphics library.

```bash
# You can clone this repository with:
$ git clone <repo url>

# Navigate into the project directory:
$ cd julia-fractal.c

# Then, install the required dependencies (here, `tigr.c`) with:
$ npm install

# Finally, build and run the project:
$ bash build.sh

# The build script uses `clang` with OpenMP support to compile the code.
# The generated executable `a` is then run to display the Julia fractal.
```

<br>

## Task

The current code provides a **sequential** implementation of Julia fractal rendering. Your task is to parallelize the rendering using OpenMP. Measure and report the speedup achieved by the parallel implementation compared to the sequential one.

We will use a **leaderboard** to track the best speedups across all submissions.

<br>

## Screenshots

![](https://github.com/user-attachments/assets/7c1093a1-5566-42ef-8a3f-a3e19511457e)

![](https://github.com/user-attachments/assets/66ed165d-f038-4c93-917a-15b9cef8de0f)

![](https://github.com/user-attachments/assets/6607491c-8f06-4c62-b10d-b161c6e9e5fc)

<br>
<br>


[![ORG](https://img.shields.io/badge/org-moocf-green?logo=Org)](https://moocf.github.io)
![](https://ga-beacon.deno.dev/G-RC63DPBH3P:SH3Eq-NoQ9mwgYeHWxu7cw/github.com/moocf/julia-fractal.c)
