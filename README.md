# Overview

This repo contains some useful header files when developing applications with C. Most of the headers contain useful macro definitions to simplify implementing various features. Some aid specifically in improving cross platform features.

## Asserts

This file contains a macro (`static_assert`) for performing compile time  assertions.


## Exports

This file contains a set of macros for controlling the visibility of symbols. It provides three extra levels of visibility to the standard C visibility `api_export`, `debug_export` and `library_local`. These, allong with the standard C `static` visibility should cover all api symbol visibility needs.

## Platform

Code to determine what platform is being used for compilation. Performs the checks required for the various platforms and defines a standardised set of macros. This should make platform specific pieces of code easier to manange.
