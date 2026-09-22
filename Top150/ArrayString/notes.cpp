// vector

vector<int> v(n);                          // n zeros
vector<int> v(n, -1);                      // n copies of -1
vector<int> v = {1, 2, 3};
vector<vector<int>> dp(m, vector<int>(n)); // m × n matrix

v.resize(n);          // change size, new ints are 0
v.resize(n, -1);      // new elements are -1
v.assign(n, 5);       // REPLACE contents with n copies of 5
fill(v.begin(), v.end(), 0); // keep same size, change all to 0
v.clear();            // size becomes 0

