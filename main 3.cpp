//Description
//Write a C program to perform some queries on a telco data (comming from stdin) with the following format:
//The first block of data consists of lines (terminated by a line containing #), each line (number of lines can be up to 100000) is under the form:
//        call <from_number> <to_number> <date> <from_time> <end_time>
//which is a call from the phone number <from_number> to a phone number <to_number> on <date>, and starting at time-point <from_time>, terminating at time-point <end_time>
//from_number> and <to_number> are string of 10 characters (a phone number is correct if it contains only digits 0,1,...,9, otherwise, the phone number is incorrect)
//date> is under the form YYYY-MM-DD (for example 2022-10-21)
//from_time> and <to_time> are under the form hh:mm:ss (for example, 10:07:23)
// 
//The second block consists of queries (terminated by a line containing #), each query in a line (number of lines can be up to 100000) and belongs to one of the following types:
//?check_phone_number: print to stdout (in a new line) value 1 if no phone number is incorrect
//?number_calls_from <phone_number>: print to stdout (in a new line) the number of times a call is made from <phone_number>
//?number_total_calls: print to stdout (in a new line) the total number of calls of the data
//?count_time_calls_from <phone_number>: print to stdout (in a new line) the total time duration (in seconds) the calls are made from <phone_number>

#include "/Users/macbook/Desktop/C++/stdc++.h"
using namespace std;
map <string,int> mp,mp_time;
string request;
int check = 1,total_calls = 0;;
int count_time(string to_time,string from_time){
    int sum = 0;
    int a[] = {36000, 3600, 0, 600, 60, 0, 10, 1};
    for (int i=0;i<8;i++){
        sum += a[i]*(to_time[i] - from_time[i]);
    }
    return sum;
}
bool check_phone(string s){
    if (s.length()!=10) return false;
    for (char x : s) if ((x<'0')||(x>'9')) return false;
    return true;
}
void inputValue(){
    string from_number,to_number,date,from_time,to_time;
    while (cin>>request && request.compare("call") == 0) {
        cin>>from_number>>to_number>>date>>from_time>>to_time;
        total_calls ++;
        mp[from_number] ++;
        mp_time[from_number] += count_time(to_time,from_time);
        if (!check_phone(to_number) || !check_phone(from_number)) check = 0;
    }
}
int main(int argc, const char * argv[]) {
    inputValue();
    while (cin>>request && request.compare("#") != 0) {
        if (request.compare("?check_phone_number") == 0) cout<<check<<endl;
        else if (request.compare("?number_calls_from") == 0){
            string phone_number;
            cin>>phone_number;
            cout<<mp[phone_number]<<endl;
        }
        else if (request.compare("?number_total_calls") == 0) cout<<total_calls<<endl;
        else {
            string phone_number;
            cin>>phone_number;
            cout<<mp_time[phone_number]<<endl;
        }
    }
    return 0;
}
