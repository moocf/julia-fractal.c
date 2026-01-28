In this project, we demonstrate how to find the **histogram** of an image, which acts as a graphical representation of the tonal distribution in a digital image, in the **C programming language**.

You can clone this repository with `git clone <repo url>`. Then, install the required dependencies (here, `tigr.c`) with `npm i` in *command prompt*/terminal. You can use `clang` for compiling the C code, once you install *LLVM* on your system. The script to compile and run the code is `build.sh`. You can run it in the terminal with `bash build.sh`.

<br>

### Task

The code has a **sequential** implementation of *histogram computation*. You are to implement **parallel** histogram computation using OpenMP. Time the speedup achieved by the parallel implementation over the sequential one. Test with large images to see sensible speedups - small workloads do not benefit from parallelism. You can place the image files in the `images/` folder, and pass it as a command line argument while compiling/running the code, as `bash build.sh images/large_image.png`. As *tigr* does not support all PNG formats, you can try converting any image (bmp/png/jpg) to a compatible PNG using online converters, such as [JPG2PNG](https://jpg2png.com/).

We will use a **leaderboard** to track the best speedups across all submissions.

<br>

### Screenshots

![](https://github.com/user-attachments/assets/15c63a1e-275d-48ba-a3e3-8b3bb960f2cd)

![](https://github.com/user-attachments/assets/9b94bcef-a669-47db-8f35-dd6f52d8d2e0)

![](https://github.com/user-attachments/assets/72e75be7-3c24-46b4-84e6-1ff883f09aad)

<br>
<br>


[![ORG](https://img.shields.io/badge/org-moocf-green?logo=Org)](https://moocf.github.io)
![](https://ga-beacon.deno.dev/G-RC63DPBH3P:SH3Eq-NoQ9mwgYeHWxu7cw/github.com/moocf/image-histogram.c)
