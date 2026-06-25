                                                                        //Searching

                                                                    //Linear Search 
//Search student roll 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    vector<int> roll(n);

    cout << "Enter roll numbers:\n";
    for (int i = 0; i < n; i++)
        cin >> roll[i];

    int key;
    cout << "Enter roll number to search: ";
    cin >> key;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (roll[i] == key) {
            cout << "Roll number found at position " << i + 1;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Roll number not found.";

    return 0;
}

//Search product name
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    vector<string> product(n);

    cout << "Enter product names:\n";
    for (int i = 0; i < n; i++)
        cin >> product[i];

    string key;
    cout << "Enter product to search: ";
    cin >> key;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (product[i] == key) {
            cout << "Product found at position " << i + 1;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Product not found.";

    return 0;
}
//Search highest  marks 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    vector<int> marks(n);

    cout << "Enter marks:\n";
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    int key;
    cout << "Enter mark to search: ";
    cin >> key;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (marks[i] == key) {
            cout << "Marks found for student " << i + 1;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Marks not found.";

    return 0;
}

                                                                        //Binary search


#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    int key = 40;

    int index = binarySearch(arr, key);

    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found";
}