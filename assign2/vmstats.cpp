#include<bits/stdc++.h>
using namespace std;
double opt(vector<int> vecmr, int nooffile, int FFF=0){
double missinopt=0;
vector<int> vecoc;
for(int i=0;i<vecmr.size();i++){
if(FFF)
cout<<vecmr[i]<<": [";
if(find(vecoc.begin() , vecoc.end(), vecmr[i]) == vecoc.end()){
if(vecoc.size()==nooffile){
int p=0;
int pageremain = 0;
vector<int>::iterator it;
vector<int>::iterator maximumit = vecmr.begin();
for(int j=0;j<vecoc.size();j++){
it=find(vecmr.begin() + i, vecmr.end(), vecoc[j]);
if(it > maximumit){
maximumit = it;
pageremain = j;}
}
vecoc.erase(vecoc.begin() + pageremain);
vecoc.push_back(vecmr[i]);
for(int j=0;j<nooffile;j++){
if(j<vecoc.size() && FFF){
cout<<vecoc[j];}
else
if(FFF)
cout<<" ";
if(j<(nooffile-1) && FFF)cout<<" | ";
else if(j==nooffile-1){
if(FFF)
cout<<"] F"<<endl;
missinopt++;
}}}	
else{
vecoc.push_back(vecmr[i]);
if(FFF)
{
for(int j=0;j<nooffile;j++)
{if(j<vecoc.size())
{cout<<vecoc[j];
}
else
cout<<" ";
if(j<(nooffile-1))
cout<<" | ";
else
{cout<<"]"<<endl;}
}}}}
else
{
if(FFF)
{
for(int j=0;j<nooffile;j++)
{
if(j<vecoc.size())
{
cout<<vecoc[j];
}
else
cout<<" ";
if(j<(nooffile-1))
cout<<" | ";
else
{
cout<<"]"<<endl;
}}}}}
return missinopt;
}


double lru(vector<int> vecmr, int nooffile, int fffp=0)
{
double missinlru = 0;
list<int> lru;
map<int, list<int>::iterator> mp;
int FFF=0;
for(int i=0;i<vecmr.size();i++)
{
if(mp.find(vecmr[i])==mp.end())
{
if(lru.size()==nooffile)
{
FFF=1;
int last = lru.back();
lru.pop_back();
mp.erase(last);
}
}
else
{
FFF=0;
lru.erase(mp[vecmr[i]]);
}
lru.push_front(vecmr[i]);
mp[vecmr[i]]=lru.begin();
list<int>::iterator itr = --lru.end();
if(fffp)
cout<<vecmr[i]<<": [";
for(int j=0;j<nooffile;j++)
{
if(j<lru.size() && fffp)
{
cout<<*itr;
itr--;
}
else
if(fffp)
cout<<" ";
if(j<(nooffile-1) && fffp)
cout<<" | ";
else if(j==nooffile-1)
{
if(FFF)
{
if(fffp)
cout<<"] F\n";
missinlru++;
}
else
if(fffp)
cout<<"]\n";
}}}
return missinlru;
}


double fifo(vector<int> vecmr, int nooffile, int FFF=0)
{
double missinfifo = 0;
vector<int> fifo;
for(int i=0;i<vecmr.size();i++)
{if(fifo.size()==nooffile)
{
vector<int>::iterator itr = find(fifo.begin(),fifo.end(), vecmr[i]);
if(itr==fifo.end())
{fifo.erase(fifo.begin());
fifo.push_back(vecmr[i]);
if(FFF)
cout<<vecmr[i]<<": [";
if(FFF)
{
for(int j=0;j<nooffile;j++)
{
cout<<fifo[j];
if(j<(nooffile-1))
cout<<" | ";
else
cout<<"] F\n";
}}
missinfifo++;
}
else
{if(FFF)
{
cout<<vecmr[i]<<": [";
for(int j=0;j<nooffile;j++)
{
if(j<fifo.size())
cout<<fifo[j];
else
cout<<"  ";
if(j<(nooffile-1))
cout<<" | ";
else
cout<<"]\n";
}}}}
else
{
if(find(fifo.begin(),fifo.end(), vecmr[i]) == fifo.end())
fifo.push_back(vecmr[i]);
if(FFF)
{cout<<vecmr[i]<<": [";
for(int j=0;j<nooffile;j++)
{
if(j<fifo.size())
cout<<fifo[j];
else
{cout<<" ";}
if(j<(nooffile-1))
cout<<" | ";
else
cout<<"]\n";
}}}}
return missinfifo;
}

int main(int argc, char const *argv[])
{
std::cout << std::fixed << std::setprecision(2);
if(argc < 5)
{
cout<<"You_have_to_give_argument_ while_execution_of_the_file_in_given below_format!!!\n";
cout<<"[1]_The_minimum_number_of_frames_(no_less_than_2)!!\n";
cout<<"[2]_The_maximum_number_of_frames_(no_more_than_100)!!\n";
cout<<"[3]_The_frame_number_increment_(positive)!!\n";
cout<<"[4]_The_input_filename_containing_the_references!!\n";
return 0;
}
ifstream IF;
IF.open(argv[4]);
fstream CRF;
CRF.open("vmrates.dat", ios::out);
int nooffile;
int head,end,inc;
head = stoi(argv[1]);
if(head<2){
cout<<"Give Correct minimum number of frames (no less than 2).\n";
return 0;
}
end = stoi(argv[2]);
if(end > 100){
cout<<"Give Correct maximum number of frames (no more than 100).\n";
return 0;
}
inc = stoi(argv[3]);
if(inc < 0)
{cout<<"Give Correct frame number increment (positive).\n";
return 0;
}
if(!IF){
cout<<"Error in opening file..\n";
return 0;
}
if(!CRF){
cout<<"Error in Creating file..\n";
return 0;
}
for(int i=head;i<=end;i+=inc)
CRF<<i<<" ";
CRF<<"\n";
vector<int> vecmr;
int x;
while(IF>>x)
vecmr.push_back(x);
for(int i=head;i<=end;i+=inc){
nooffile = i;
double missbyopt = opt(vecmr, nooffile);
if(vecmr.size() > nooffile){
cout<<fixed << setprecision(2)<<"OPT, "<<nooffile<<" frames: Miss rate = "<<(int)missbyopt<<"/"<<vecmr.size()-nooffile<<" = "<<(missbyopt/(vecmr.size()-nooffile))*100<<"%"<<endl;
CRF<<fixed << setprecision(2)<<(missbyopt/(vecmr.size()-nooffile))*100<<" ";
}
else{
cout<<fixed << setprecision(2)<<"OPT, "<<nooffile<<" frames: Miss rate = "<<"0"<<"%"<<endl;
CRF<<fixed << setprecision(2)<<"0"<<" ";
}
}
cout<<"\n";
CRF<<"\n";
for(int i=head;i<=end;i+=inc){
nooffile = i;
double missbylru = lru(vecmr, nooffile);
if(vecmr.size() > nooffile){
cout<<fixed << setprecision(2)<<"LRU, "<<nooffile<<" frames: Miss rate = "<<(int)missbylru<<"/"<<vecmr.size()-nooffile<<" = "<<(missbylru/(vecmr.size()-nooffile))*100<<"%"<<endl;
CRF<<fixed << setprecision(2)<<(missbylru/(vecmr.size()-nooffile))*100<<" ";
}
else{
cout<<fixed << setprecision(2)<<"LRU, "<<nooffile<<" frames: Miss rate = "<<"0"<<"%"<<endl;
CRF<<fixed << setprecision(2)<<"0"<<" ";
}}
cout<<"\n";
CRF<<"\n";
for(int i=head;i<=end;i+=inc){
nooffile = i;
double missbyfifo = fifo(vecmr, nooffile);
if(vecmr.size() > nooffile){
cout<<fixed << setprecision(2)<<"FIFO, "<<nooffile<<" frames: Miss rate = "<<(int)missbyfifo<<"/"<<vecmr.size()-nooffile<<" = "<<(missbyfifo/(vecmr.size()-nooffile))*100<<"%"<<endl;
CRF<<fixed << setprecision(2)<<(missbyfifo/(vecmr.size()-nooffile))*100<<" ";
}
else{
cout<<fixed << setprecision(2)<<"FIFO "<<nooffile<<" frames: Miss rate = "<<"0"<<"%"<<endl;
CRF<<fixed << setprecision(2)<<"0"<<" ";
}}
IF.close();
CRF.close();
}
