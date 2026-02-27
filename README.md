\# Fixed-Point Math Library for STM32F411RE



A comprehensive fixed-point arithmetic library for embedded DSP applications on resource-constrained microcontrollers.



\## Overview

This library implements Q15 fixed-point arithmetic optimized for the STM32F411RE (ARM Cortex-M4). It provides portable C implementations alongside ARM inline assembly optimized versions for maximum performance.



\## Features

\- Q15 fixed-point arithmetic (add, sub, mul, div) with saturation

\- ARM Cortex-M4 inline assembly optimized operations

\- Compile-time switching between portable and ARM optimized builds

\- FIR filter implementation

\- Full test suite with edge case coverage



\## Project Structure

\- `Inc/` — Header files

\- `Src/` — Source files

\- `Src/Tests/` — Test suite

\- `Startup/` — STM32 startup files



\## Target Hardware

STM32F411RE Nucleo Board (ARM Cortex-M4 @ 100MHz)



\## Build

Open in STM32CubeIDE and build normally. Set `USE\_ARM\_OPTIMIZED` in `fp\_math.h` to switch between implementations.



\## Status

Benchmarking pending — board arriving soon.

