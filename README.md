# CDN Task

This repository contains three small tasks around DNS routing, wildcard matching, and a Lua/C extension. The codebase was reorganized to be easier to build, easier to read, and more presentable as a portfolio-style submission.

## Repository Structure

- `CDN_DNS/` - longest-prefix IPv6 routing using a bitwise trie
- `Wildcard_DNS/` - wildcard hostname matching using a trie-based matcher
- `Lua_Bonus/` - simple Lua extension example in C

## Build

The project now has a top-level CMake entry point, so both C tasks can be built in one command.

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

You can still build each task independently from its own `src/` directory if needed.

## 1. Wildcard DNS

### Goal

Match domain names against wildcard patterns such as:

- `*.net`
- `*.co.uk`
- `a.*.c.d`
- `g.h.i.*`

### Approach

The matcher now works on DNS labels instead of raw characters. Patterns are compiled into structures that reflect how hostnames are actually matched:

- reversed trie for patterns like `*.co.uk`
- forward trie for patterns like `g.h.i.*`
- structured prefix/suffix checks for patterns like `a.*.c.d`

### Why a Trie

- DNS matching is naturally label-oriented, not character-oriented
- suffix and prefix wildcards benefit from trie sharing
- the new model uses much less memory than a 256-way node per character
- wildcard semantics are clearer and closer to the actual problem domain

### Notes

The implementation was cleaned up to use a label-based matcher, stricter compiler warnings, clearer test output, and a more maintainable build setup.

## 2. CDN DNS

### Goal

Resolve IPv6 addresses to the best PoP using longest-prefix match, which is the standard routing rule for overlapping network prefixes.

### Approach

This task uses a binary trie over 128 IPv6 bits:

- `0` goes to the left child
- `1` goes to the right child
- every terminal route stores a PoP and its prefix length

During lookup, the algorithm walks the address bit by bit and remembers the deepest valid route seen so far.

### Complexity

- Route insertion: `O(prefix_length)`
- Lookup: `O(128)`, effectively constant for IPv6
- Memory: proportional to the number of created trie nodes

### Improvements Made

- removed the hardcoded record limit from the parser
- added validation for malformed routing records
- improved memory allocation checks
- replaced raw byte-array demo queries with readable IPv6 strings
- made the CLI accept a routing-data path
- improved output formatting with a summary section
- added a smoke test through CTest

## 3. Lua Bonus

The Lua bonus directory contains a native extension example and a Lua script that uses it. It is left separate from the CMake flow because it serves as an isolated bonus exercise rather than part of the DNS executables.

## Design Rationale

The two DNS tasks use trie-based structures for the same reason: both problems are dominated by repeated prefix-style matching.

- `Wildcard_DNS` works on hostname patterns
- `CDN_DNS` works on IPv6 bit prefixes

Although the stored data differs, the underlying idea is the same: structure the search space so matching work scales with the query itself rather than with the full number of stored records.

## Running the Binaries

```bash
./build/CDN_DNS CDN_DNS/build/routing-data.txt
./build/Wildcard_DNS
```

`CDN_DNS` also tries a few common default locations for `routing-data.txt`, so it can run without arguments when started from the repository root or an expected build directory.
