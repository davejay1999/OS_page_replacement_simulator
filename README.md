# OS_page_replacement_simulator
In this assignment, you will write a program that simulates the virtual memory page replacement algorithms: Optimal (OPT), Least Recently Used (LRU) and First-In-FirstOut (FIFO). This assignment contains three separate programs: a page replacement simulator vmsim, a page reference generator vmgen, and a page statistics program vmstats that produces a consolidated data file used for performance plots


JAY DAVE-201601224
Readme file
OS_Programming_Assignment_2:page_replacement_simulator
Files included in this folder is:
1)vmsim.cpp (virtual memory simulator)
2)vmgen.cpp (virtual memory generator)
3)vmstats.cpp (virtual memory statistics)
Procedure:
1.Compile all Files using following commands
g++ vmgen.cpp -o vmsim
g++ vmstats.cpp -o vmstats
g++ vmsim.cpp -o vmsim
2.Run vmgen.cpp file to generate vmrefs.dat file (which contains sequence of integer)
By using following command
“./vmgen 10 200 vmrefs.dat” (without quotes)
3.It generate file name vmrefs.dat having desired length of integer sequence which indicate
page index/page number which is randomly selected from 0 and (range-1)
4.Then run vmsim.cpp file for simulation using following command
“./vmsim 5 vmrefs.dat lru/fifo/opt” (without quotes and choose onr from lru fifo or opt)
5.Then run vmstats.cpp file using following command
“./vmstats 5 40 10 vmrefs.dat” (without quotes)
