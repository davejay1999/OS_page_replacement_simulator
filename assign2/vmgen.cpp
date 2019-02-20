#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{if(argc<4){//if invalid or no file exist then exit.
cout<<"You_have_to_give_argumennts_for_execution_of_the_file_in_given_below_format!!\n";
cout<<"[1]_The_lengthofseq_of_page_references_(max-100)!!\n";
cout<<"[2]_The_size_of_the_sequence!!\n";
cout<<"[3]_The_name_of_the_file_that_will_generated\n";
return 0;}
fstream CRF;
CRF.open(argv[3], ios::out);
if(!CRF){//if invalid or no file create then exit.
cout<<"Error in creating file!!!"; 
return 0;}
else{
cout<<"File is Created Succesfully\n";} 
int lengthofseq = stoi(argv[1]);
if(lengthofseq > 100){////contraint length in seq<=100
cout<<"The lengthofseq of page references should not be more than 100\n";
return 0;}
int sizeofseq = stoi(argv[2]);//string to int
int qwe = 0;
int randomvar;
for(int i=0;i<sizeofseq;i++){
if(i==0){
srand(time(0));
randomvar = rand()%lengthofseq;//generation of random int.
CRF<<randomvar<<" ";
qwe = randomvar;}
else{
randomvar = rand()%lengthofseq;
while(randomvar==qwe){
randomvar = rand()%lengthofseq;}
CRF<<randomvar;//entering seq number in CRF
if(i<sizeofseq-1)CRF<<" ";
qwe = randomvar;
}}
CRF.close();
return 0;
}
