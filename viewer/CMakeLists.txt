cmake_minimum_required(VERSION 3.28.3)
project(viewer)

add_library(viewer
        source/reader.c
        include/reader.h
)
