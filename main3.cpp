#include <bits/stdc++.h>

bool test(const std::function<void(const std::vector<int> &, std::vector<int> &)>& f, const std::vector<int> &a, std::vector<int> &b, const std::vector<int>& expected) {
    f(a, b);
    if (expected != b) {
        std::cout << "expected: ";
        for (auto e : expected) {
            std::cout << e << ' ';
        }
        std::cout << "\nresult  : ";
        for (auto i : b) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    } else {
        std::cout << "YES!\n";
    }
    return expected == b;
}

void join(const std::vector<int> &from, std::vector<int> &to) {
    size_t t_ptr = to.size() - 1, f_ptr = from.size() - 1, i_ptr = from.size() + to.size() - 1;
    to.resize(to.size() + from.size());
    while (f_ptr != size_t (-1)) {
        if (to[t_ptr] > from[f_ptr]) {
            to[i_ptr] = to[t_ptr];
            t_ptr--;
        } else {
            to[i_ptr] = from[f_ptr];
            f_ptr--;
        }
        i_ptr--;
    }
}

int main() {
    std::vector<int> f = {1, 4, 6, 8};
    std::vector<int> t = {2, 3, 6, 7, 10};
    test(join, f, t, {1, 2, 3, 4, 6, 6, 7, 8, 10});
    f = {3, 5, 7};
    t = {4, 6};
    test(join, f, t, {3, 4, 5, 6, 7});
    return 0;
}

