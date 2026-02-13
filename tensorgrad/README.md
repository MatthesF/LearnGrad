# tensorgrad (C++)

This folder is the next stage after `micrograd`.

Goal: build tensor-based autograd in C++ from scratch, then use it for larger models.

Planned steps:
- implement a Tensor type
- support elementwise ops and matrix multiplication
- support broadcasting
- build reverse-mode autograd for tensors
