#include <iostream>
using namespace std;

void improvedSelection(int a[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left, maxIndex = right;

        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIndex]) minIndex = i;
            if (a[i] > a[maxIndex]) maxIndex = i;
        }

        int t = a[left]; a[left] = a[minIndex]; a[minIndex] = t;

        if (maxIndex == left) maxIndex = minIndex;

        t = a[right]; a[right] = a[maxIndex]; a[maxIndex] = t;

        left++;
        right--;
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    improvedSelection(a, n);
    for (int x : a) cout << x << " ";
}