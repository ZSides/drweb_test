#include <bits/stdc++.h>

bool test(const std::function<void(const std::vector<int> &, std::vector<int> &)>& f, const std::vector<int> &a, std::vector<int> &b, const std::vector<int>& expected) {
    return expected == b;
}

void join(const std::vector<int> &from, std::vector<int> &to) {
    int tsz = to.size(), fsz = from.size();
    to.resize(tsz + fsz);
    for (int i = tsz + fsz - 1; i >= 0; --i) {
        to[i] = to[i - tsz + 1];
    }
    int t_ptr = fsz, f_ptr = 0, c_ptr = 0;
    while ((t_ptr < tsz + fsz) && (f_ptr < fsz)) {
        if (from[f_ptr] < to[t_ptr]) {
            to[c_ptr] = from[f_ptr];
            f_ptr++;
        } else {
            to[c_ptr] = to[t_ptr];
            t_ptr++;
        }
        c_ptr++;
    }
}

int main() {
    std::vector<int> f = {1, 4, 6, 8};
    std::vector<int> t = {2, 3, 6, 7, 10};
    std::cout << (test(join, f, t, {1, 2, 3, 4, 6, 6, 7, 8, 10}) ? 'y' : 'n') << '\n';
    return 0;
}
