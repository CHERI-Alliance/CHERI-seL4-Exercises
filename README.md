<!-- ANCHOR: cover -->

# Adversarial CHERI Exercises and Missions on CHERI-seL4 microkernel and CHERI-Microkit

Robert N. M. Watson (University of Cambridge), Brooks Davis (SRI
International), Wes Filardo (Microsoft Research), Jessica Clarke (University of
Cambridge), John Baldwin (Ararat River Consulting), and Hesham Almatary
(Capabilities Limited).

This repository contains a series of skills development and adversarial
exercises for [CHERI](http://cheri-cpu.org), specifically aimed at the
CHERI-RISC-V implementation, running on an experimental CHERI-seL4 microkernel
and its CHERI-Microkit userspace framework.

## Acknowledgements

The authors gratefully acknowledge Reuben Broadfoot, Lawrence Esswood, Brett
Gutstein, Joe Kiniry, Alex Richardson, Austin Roach, and Daniel Zimmerman for
their feedback and support in developing these exercises.

*Some portions of this document remain a work-in-progress.  Feedback and
contributions are welcomed.  Please see our [GitHub
Repository](https://github.com/CHERI-Alliance/CHERI-seL4-Exercises) for the source
code and an issue tracker.*

<!-- ANCHOR_END: cover -->

## Building

Building the book from the Markdown sources requires
[mdBook](https://github.com/rust-lang/mdBook). Once installed, `mdbook build`
will build the static HTML files in the `book/` directory, whilst `mdbook
serve` will build and serve them at `http://localhost:3000`. Please refer to
the mdBook documentation for futher options.
