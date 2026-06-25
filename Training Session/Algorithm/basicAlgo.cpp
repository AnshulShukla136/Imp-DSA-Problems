// Searching

// Linear Search
// Search student roll
#include <bits/stdc++.h>
using namespace std;

int main()
{
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

    for (int i = 0; i < n; i++)
    {
        if (roll[i] == key)
        {
            cout << "Roll number found at position " << i + 1;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Roll number not found.";

    return 0;
}

// Search product name
#include <bits/stdc++.h>
using namespace std;

int main()
{
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

    for (int i = 0; i < n; i++)
    {
        if (product[i] == key)
        {
            cout << "Product found at position " << i + 1;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Product not found.";

    return 0;
}
// Search highest  marks
#include <bits/stdc++.h>
using namespace std;

int main()
{
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

    for (int i = 0; i < n; i++)
    {
        if (marks[i] == key)
        {
            cout << "Marks found for student " << i + 1;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Marks not found.";

    return 0;
}

// Binary search

// Search Student roll no.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> roll(n);

    cout << "Enter sorted roll numbers:\n";
    for (int i = 0; i < n; i++)
        cin >> roll[i];

    int key;
    cout << "Enter roll number to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (roll[mid] == key)
        {
            cout << "Roll number found at position " << mid + 1;
            found = true;
            break;
        }
        else if (roll[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (!found)
        cout << "Roll number not found.";

    return 0;
}

// search a product id
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of product IDs: ";
    cin >> n;

    vector<int> id(n);

    cout << "Enter sorted product IDs:\n";
    for (int i = 0; i < n; i++)
        cin >> id[i];

    int key;
    cout << "Enter Product ID to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (id[mid] == key)
        {
            cout << "Product ID found at position " << mid + 1;
            found = true;
            break;
        }
        else if (id[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (!found)
        cout << "Product ID not found.";

    return 0;
}

// search student marks

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> marks(n);

    cout << "Enter sorted marks:\n";
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    int key;
    cout << "Enter marks to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (marks[mid] == key)
        {
            cout << "Marks found at position " << mid + 1;
            found = true;
            break;
        }
        else if (marks[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (!found)
        cout << "Marks not found.";

    return 0;
}