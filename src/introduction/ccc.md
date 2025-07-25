# Helper scripts

Because the command line required to compile exercises is quite unwieldy, we've created a wrapper script to help out, shown below.  If you've checked out this repository it's present in `tools/ccc`.  The usage is:
```
ccc <arch> [...]

Supported architectures:
	aarch64         - conventional AArch64
	morello-hybrid  - AArch64 Morello supporting CHERI
	morello-purecap - AArch64 Morello pure-capability
	riscv64         - conventional RISC-V 64-bit
	riscv64-hybrid  - RISC-V 64-bit supporting CHERI
	riscv64-purecap - RISC-V 64-bit pure-capability
```
and it can be used in place of your compiler.

For the exercises in this book you will use the `riscv64` and `riscv64-purecap` architectures.  The `riscv64-hybrid` architecture instantiates appropriately annotated pointers as capabilities leaving the rest as conventional integer addresses, but is not used here.

If you have built a compiler and sysroot using `cheribuild` in the default location (`~/cheri`) then it should work out of the box.  If you've configured a different location you can set the `CHERIBUILD_SDK` environment variable to point to to the location of your SDK.  Alternatively, you can set the `CLANG` variable to point to the respective location.
```sh
{{#include ../../tools/ccc}}
```

The second script is to generate a bootable image and run it on QEMU; it's present in `tools/run_qemu`. The usage is:
```
run_qemu <image.elf | image.img>
```

If you pass it an ELF file generated by `ccc`, it will wrap it, along with the CHERI-seL4 kernel, CHERI-Microkit libraries, loader, monitor, etc. to give you a bootable image and run it directly on QEMU by passing it as a -kernel image. The following is the script's content:

```sh
{{#include ../../tools/run_qemu}}
```

This `run_qemu` script uses another `gen_image` script that generates a bootable CHERI-Microkit image as shown below:
```sh
{{#include ../../tools/gen_image}}
```

Thus, over these exercises, you'll usually be using mostly using just two scripts (given you either include them in your $PATH, or use relative/absolute paths when running them):
```
# ccc riscv64-purecap exercise_c_files.c -o exercise.elf
# run_qemu exercise.elf
```
