#include<bits/stdc++.h>
#include<string.h>
using namespace std;
/*
If referred page is already present, increment hit count.
If not present, find if a page that is never referenced in future. 
If such a page exists, replace this page with new page. 
If no such page exists, find a page that is referenced farthest in future.
Replace this page with new page.*/
double opt(vector<int> vecmr, int Numoffiles, int ffff=0)
{double ffffcount=0;
vector<int> vecoc;
for(int i=0;i<vecmr.size();i++)
{if(ffff)cout<<vecmr[i]<<": [";
if(find(vecoc.begin() , vecoc.end(), vecmr[i]) == vecoc.end()){
if(vecoc.size()==Numoffiles){
int p=0;
int pages_remain = 0;
vector<int>::iterator it;
vector<int>::iterator maximum_item = vecmr.begin();
for(int j=0;j<vecoc.size();j++){
it=find(vecmr.begin() + i, vecmr.end(), vecoc[j]);
if(it > maximum_item){
maximum_item = it;
pages_remain = j;}
}
vecoc.erase(vecoc.begin() + pages_remain);
vecoc.push_back(vecmr[i]);
for(int j=0;j<Numoffiles;j++)
{if(j<vecoc.size() && ffff){cout<<vecoc[j];}
else
if(ffff)
cout<<" ";
if(j<(Numoffiles-1) && ffff)
cout<<" | ";
else if(j==Numoffiles-1){
if(ffff)
cout<<"] F"<<endl;
ffffcount++;
}}}
else{
vecoc.push_back(vecmr[i]);
if(ffff){
for(int j=0;j<Numoffiles;j++){
if(j<vecoc.size()){
cout<<vecoc[j];}
else
cout<<" ";
if(j<(Numoffiles-1))
cout<<" | ";
else
{cout<<"]"<<endl;}
}}}}
else{
if(ffff){
for(int j=0;j<Numoffiles;j++)
{if(j<vecoc.size()){
cout<<vecoc[j];}
else
cout<<" ";
if(j<(Numoffiles-1))cout<<" | ";
else{
cout<<"]"<<endl;
}}}}}
return ffffcount;
}

//Whenever a new page is referred and not present in memory, 
//page fault occurs and Operating System replaces one of the existing pages with newly needed page. 
//Different page replacement algorithms suggest different ways to decide which page to replace.
// The target for all algorithms is to reduce number of page faults.
double lru(vector<int> vecmr, int Numoffiles, int ffff_p=0){
double missinlru = 0;
list<int> lru;
map<int, list<int>::iterator> mp;
int ffff=0;
// // Start from initial page

for(int i=0;i<vecmr.size();i++){
 // Check if the set can hold more pages
if(mp.find(vecmr[i])==mp.end()){
if(lru.size()==Numoffiles){
// Insert it into set if not present 
// already which represents page fault 
ffff=1;
int last = lru.back();
lru.pop_back();
mp.erase(last);
}}
// If the set is full then need to perform lru 
// i.e. remove the least recently used page 
// and insert the current page 
else{
ffff=0;
lru.erase(mp[vecmr[i]]);}
lru.push_front(vecmr[i]);
mp[vecmr[i]]=lru.begin();
/*we basically need to replace the page with
minimum index.
Replace the found page with current page.
Increment page faults.
Update index of current page.*/
list<int>::iterator itr = --lru.end();
if(ffff_p)cout<<vecmr[i]<<": [";
for(int j=0;j<Numoffiles;j++){
if(j<lru.size() && ffff_p){
cout<<*itr;
itr--;}
else
if(ffff_p)
cout<<" ";
if(j<(Numoffiles-1) && ffff_p)
cout<<" | ";
else if(j==Numoffiles-1){
if(ffff){
if(ffff_p)
cout<<"] F\n";
missinlru++;}
else
if(ffff_p)
cout<<"]\n";
}}}
return missinlru;
}


double fifo(vector<int> vecmr, int Numoffiles, int ffff=0)
{double missinfifo = 0;
vector<int> fifo;
//On a page fault, the frame that has been in memory the longest is replaced.
/*To keeps track of all pages in the memory in a queue, oldest page is in the front of the queue.
When a page needs to be replaced page in the front of the queue is selected for removal.
That first element of vector fifo.begin() is always longest element reside in memory.
*/
for(int i=0;i<vecmr.size();i++){//loop till last page ie memory reference size
if(fifo.size()==Numoffiles){//// Check if the set can hold more pages 
vector<int>::iterator itr = find(fifo.begin(),fifo.end(), vecmr[i]);
if(itr==fifo.end()){// Insert it into set if not present already which represents page fault 
fifo.erase(fifo.begin());
//Pop the first page from the queue 
fifo.push_back(vecmr[i]);
// insert the current page
if(ffff)
cout<<vecmr[i]<<": [";
if(ffff){
for(int j=0;j<Numoffiles;j++){
cout<<fifo[j];
if(j<(Numoffiles-1))cout<<" | ";
else
cout<<"] F\n";
}}//increment in page faults
missinfifo++;
}
else{
if(ffff){
cout<<vecmr[i]<<": [";
for(int j=0;j<Numoffiles;j++){
if(j<fifo.size())// Check if the set can hold more pages
cout<<fifo[j];
else
cout<<"  ";
if(j<(Numoffiles-1))
cout<<" | ";
else
cout<<"]\n";
}}}}
// If the set is full then need to perform FIFO 
// i.e. remove the first page of the queue from 
// set and queue both and insert the current page
else{
if(find(fifo.begin(),fifo.end(), vecmr[i]) == fifo.end())
//Insert it into set if not present
fifo.push_back(vecmr[i]);
// insert the current page
if(ffff){
cout<<vecmr[i]<<": [";
for(int j=0;j<Numoffiles;j++){
if(j<fifo.size())
cout<<fifo[j];
else{cout<<" ";}
if(j<(Numoffiles-1))
cout<<" | ";
else
cout<<"]\n";
}}}}
return missinfifo;
}

int main(int argc, char const *argv[])
{if(argc < 4){//if argc are less then 4. then command is in wrong format so print right format in console Pmissinfifo mem_ref algo  
cout<<"You_have_to_give_argument_ while_execution_of_the_file_in_given below_format!!!\n";
cout<<"[1]_Total_numbers_of_Physical_Memory_Frames!!!.\n";
cout<<"[2]_An_Input_File's_name_from_where_memory_reference_was_stored!!!.\n";
cout<<"[3]_Type_of_Page-Replacement-Algorithms!!_i.e.(FIFO,LRU,OPT)\n";
return 0;}
ifstream IF;
IF.open(argv[2]);//extracting memory reference
if(!IF){//if invalid or no file exist then exit.
cout<<"Error_in_file_opening\n";
return 0;}
int Numoffiles = stoi(argv[1]);//number of pages and convert string to integer
string PGRA = argv[3];
if(Numoffiles > 100){//contraint files<=100
cout<<"Total number of physical frames should not be greater than 100.\n";
return 0;}
if(PGRA!="fifo" && PGRA!="opt" && PGRA!="lru"){
cout<<"Give Correct page replacement algorithm.\n";
return 0;}
vector<int> vecmr;
int x;
while(IF>>x)
vecmr.push_back(x);
if(PGRA=="fifo"){//if argv[3] is fifo
double missbyfifo = fifo(vecmr, Numoffiles, 1);//number of miss or page faults =miss rate (page faults divided by number of (references)
if(vecmr.size() > Numoffiles)
cout<<fixed << setprecision(2)<<"Miss Rate(FIFO) = "<<(int)missbyfifo<<"/"<<(vecmr.size()-Numoffiles)<<" = "<<(missbyfifo/(vecmr.size()-Numoffiles))*100<<"%"<<endl;
else
cout<<fixed << setprecision(2)<<"Miss Rate(FIFO) = 0%"<<endl;
}
else if(PGRA=="opt"){
double missbyopt = opt(vecmr, Numoffiles, 1);
if(vecmr.size() > Numoffiles)//number of miss or page faults =miss rate (page faults divided by number of (references)
cout<<fixed << setprecision(2)<<"Miss Rate(OPT) = "<<(int)missbyopt<<"/"<<(vecmr.size()-Numoffiles)<<" = "<<(missbyopt/(vecmr.size()-Numoffiles))*100<<"%"<<endl;
else
cout<<fixed << setprecision(2)<<"Miss Rate(OPT) = 0%"<<endl;
}
else if(PGRA=="lru"){
double missbylru = lru(vecmr, Numoffiles, 1);
if(vecmr.size() > Numoffiles)//number of miss or page faults=miss rate (page faults divided by number of (references)
cout<<fixed << setprecision(2)<<"Miss Rate(LRU) = "<<(int)missbylru<<"/"<<(vecmr.size()-Numoffiles)<<" = "<<(missbylru/(vecmr.size()-Numoffiles))*100<<"%"<<endl;
else //if 
cout<<fixed << setprecision(2)<<"Miss Rate(LRU) = 0%"<<endl;
}
else
{cout<<"Give correct page replacement algorithm"<<endl;}
IF.close();
return 0;
}
