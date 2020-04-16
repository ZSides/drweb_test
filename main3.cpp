#include <bits/stdc++.h>

void join(const std::vector<int> &from, std::vector<int> &to) {
    to.resize(to.size() + from.size());
    auto f_ptr = from.rbegin();
    auto t_ptr = to.rbegin() + from.size(), i_ptr = to.rbegin();
    while (f_ptr != from.rend()) {
        if (*t_ptr > *f_ptr) {
            *i_ptr = *t_ptr;
            t_ptr++;
        } else {
            *i_ptr = *f_ptr;
            f_ptr++;
        }
        i_ptr++;
    }
}

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

int main() {
    std::vector<int> f = {1, 4, 6, 8};
    std::vector<int> t = {2, 3, 6, 7, 10};
    test(join, f, t, {1, 2, 3, 4, 6, 6, 7, 8, 10});
    f = {3, 5, 7};
    t = {4, 6};
    test(join, f, t, {3, 4, 5, 6, 7});
    f = {};
    t = {-6, -4};
    test(join, f, t, {-6, -4});
    f = {3, 5, 7};
    t = {};
    test(join, f, t, {3, 5, 7});
    f = {};
    t = {};
    test(join, f, t, {});
    return 0;
}

