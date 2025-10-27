# Memory Arena Allocator
This is a simple yet powerful arena-based memory allocator I built to understand how memory management works. It's like creating my own mini malloc!

## Overview
This project implements a memory allocator that uses an arena. Memory is allocated with fast allocations.

## How it works
The allocator maintains a large block of memory called an "arena". When memory is requested, the allocator finds a free chunk of memory within the arena and returns a pointer to it.

## Implementation Details
- Uses mmap with MAP_PRIVATE | MAP_ANONYMOUS flags to allocate memory

- Default arena size: 4096 bytes (one page)

Building
```gcc -o allocator allocator.c```
```./allocator```
