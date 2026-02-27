# Fixed-Point Math Library for STM32F411RE

A comprehensive fixed-point arithmetic library for embedded DSP applications
on resource-constrained microcontrollers.

## Overview
This library implements Q15 fixed-point arithmetic optimized for the STM32F411RE 
(ARM Cortex-M4). It provides portable C implementations alongside ARM inline 
assembly optimized versions, with a complete FIR filter implementation and 
benchmarking results against CMSIS-DSP.

## Features
- Q15 fixed-point arithmetic (add, sub, mul, div) with overflow saturation
- ARM Cortex-M4 inline assembly optimized operations using SSAT, MUL, SDIV
- Compile-time switching between portable and ARM optimized builds
- Circular buffer based FIR filter implementation
- Full test suite with boundary and edge case coverage

## Project Structure
```
FIXED_POINT_DSP/
├── Inc/                    # Header files
│   ├── fixed_point.h       # Types, limits, Q15 conversion macro
│   ├── fp_math.h           # Math declarations + ARM/generic switch
│   ├── fp_dsp.h            # FIR filter struct and declarations
│   └── test_fp_math.h      # Test suite declarations
├── Src/                    # Source files
│   ├── fp_math.c           # Portable C implementation
│   ├── fp_math_arm.c       # ARM inline assembly implementation
│   ├── fp_dsp.c            # FIR filter implementation
│   ├── main.c              # Entry point
│   └── Tests/
│       └── TESTS_FP_MATH.c # Full test suite
└── Startup/                # STM32 startup files
```

## Target Hardware
STM32F411RE Nucleo Board — ARM Cortex-M4 @ 100MHz with DSP extensions

## Benchmark Results
All measurements in CPU cycles on STM32F411RE @ 100MHz.

| Operation | Portable C | ARM Assembly | CMSIS-DSP |
|-----------|-----------|--------------|-----------|
| fp_add    | 8 cycles  | 3 cycles     | 3 cycles  |
| fp_sub    | 8 cycles  | 3 cycles     | 3 cycles  |
| fp_mul    | 12 cycles | 4 cycles     | 4 cycles  |
| fp_div    | 18 cycles | 6 cycles     | 7 cycles  |
| FIR (64 taps) | 820 cycles | 290 cycles | 285 cycles |

ARM assembly achieves ~3x speedup over portable C, matching CMSIS-DSP performance.

## Build Instructions
1. Open in STM32CubeIDE
2. Build project (Ctrl+B)
3. To switch between implementations, toggle `#define USE_ARM_OPTIMIZED` in `fp_math.h`

## Testing
Tests run automatically on startup and output PASS/FAIL over UART at 115200 baud.
All 16 test cases pass across add, sub, mul, div operations.

## License
MIT License