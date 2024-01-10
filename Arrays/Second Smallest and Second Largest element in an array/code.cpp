#include <vector>
#include <climits>

std::vector<int> getSecondOrderElements(int n, std::vector<int> a) {
    int second_large = INT_MIN;
    int large = INT_MIN;
    int small = INT_MAX;
    int second_small = INT_MAX;
    std::vector<int> arr;

    for (int i = 0; i < n; i++) {
        if (a[i] > large) {
            second_large = large;
            large = a[i];
        } else if (a[i] > second_large && a[i] != large) {
            second_large = a[i];
        }

        if (a[i] < small) {
            second_small = small;
            small = a[i];
        } else if (a[i] < second_small && a[i] != small) {
            second_small = a[i];
        }
    }

    arr.push_back(second_large);
    arr.push_back(second_small);

    return arr;
}
