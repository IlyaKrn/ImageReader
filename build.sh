#!/bin/bash
cmake -G "Unix Makefiles" -B ./build
cd build
make
sudo ./main /home/ilyakrn/Рабочий\ стол/test.txt
