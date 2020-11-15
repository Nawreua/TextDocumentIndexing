# TextDocumentIndexing

A small indexer tool

# Usage

```
$ ./indexer [PATH]
```

PATH is the directory in which the indexer will look for text files, as in
files ending with '.txt'.

Once the indexing is finished, the user will be prompted for a word to look for
in the index.

# Build

Normal build: src/indexer

```sh
$ make
```

Static build: indexer

```sh
$ make static
```

Tests build: tests/tests\_\*

```sh
$ make tests
```

# Dependencies

* C++17
* GCC
* Make

# Initial subject

Write a program that takes a directory path on the command line.

This program must then browse this directory and all its subdirectories
to find all text files (.txt extension).

For each text file found, perform a memory indexing of the words contained
in this file.

Once this indexing is completed, the program must ask for a word and return
the list of files containing this word.

The program will be in C++ (compiler of your choice).
Do not use a third party library (STL, BOOST, etc.).

Design the structure for maximum efficiency, to be scalable
and easily maintainable.

The sources must be commented efficiently.

The total development time is 1 day. To be done alone, of course.
