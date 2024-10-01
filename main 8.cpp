#include "/Users/macbook/Desktop/C++/stdc++.h"

using namespace std;

int num_of_phone = 0, check_phone = 1;
map<string, int> num_call, time_call;
bool check(string number)
{
    if (number.size() > 10)
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (number[i] < '0' || number[i] > '9')
            return false;
    }
    return true;
}
int trans(string start_call, string end_call)
{
    int s;
    int a[] = {36000, 3600, 0, 600, 60, 0, 10, 1};
    for (int i = 0; i < 8; i++)
    {
        s += a[i] * (end_call[i] - start_call[i]);
    }
    return s;
}
void input()
{
    string type, from_number, to_number, date, start_time, end_time;
    do
    {
        cin >> type;
        if (type == "#")
            break;
        cin >> from_number >> to_number >> date >> start_time >> end_time;
        if (check(from_number) && check(to_number))
            num_of_phone++;
        else
            check_phone = 0;
        num_call[from_number]++;
        time_call[from_number] += trans(start_time, end_time);
    } while (true);
}
void solve()
{
    string type, tel;
    do
    {
        cin>>type;
        if(type=="#") break;
        if (type == "?check_phone_number")
        {
            cout << check_phone << endl;
        }
        else if (type == "?number_total_calls")
            cout << num_of_phone << endl;
        else if (type == "?number_calls_from")
        {
            cin >> tel;
            cout << num_call[tel] << endl;
        }
        else
        {
            cin >> tel;
            cout << time_call[tel] << endl;
        }
    }while(true);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
