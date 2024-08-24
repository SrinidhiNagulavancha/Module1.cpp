#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Compare (const pair<int, int>& a, const pair<int, int>& b) {
}
if (a.second == b.second)
return a. first <b.first;
return a.second < b.second;
}
int main() {
int n;
cin >> n;
vector<pair<int, int>> users (n);
for (int i = 0; i < n; ++i) {
cin >> users[i].first >> users[i].second;
}
int t;
cin >>t;
for (int i = 0; i < t; ++i) {
int fuser, tuser, amount;
cin >>fuser >> tuser >> amount;
auto fiter = find_if(users.begin(), users.end(),
[fuser] (const pair<int, int>& user) { return user.first == fuser; });
auto titer = find_if(users.begin(), users.end(),
[tuser] (const pair<int, int>& user) { return user.first == tuser; });
if (fiter = users.end() && titer != users.end() && fiter->second >= amount){
fiter->second -= amount;
titer->second += amount;
cout << "Success" << endl;
} else {
cout << "Failure" << endl;
}
}
cout << endl;
sort (users.begin(), users.end(), Compare);
for (const auto& user : users) {
cout << user.first << " " << user.second << endl;
}
return 0;
}
