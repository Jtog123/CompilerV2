ILOC - an acryonym derived from "Intermediate Language for an Optimizing Compiler"
// COMP 342, Principles of Compilers
Think of ILOC as the assembly language for a simple RISC machine.

Each operation has a set of operands and a set of results.   

The operation has five parts: 
	- an opcode
	- a list of operands
	- a separator
	- a list of results
	- an optional comment
	
To store the sum of registers 1 and 2 into register 3, the programmer might write:
add r1, r2 => r3    // example instruction

Engineering a Compiler, Keith D. Cooper and Linda Torczon
