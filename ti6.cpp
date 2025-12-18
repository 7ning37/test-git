#include <iostream>
using namespace std;
int main()
{
    int count = 0;
    for (int i = 100; i <= 999; i++)
    {
        int c = i % 10;
        if (i % 3 == 0 && c == 9)
        {
            count++;
            cout << i << " ";

            if (count % 8 == 0)
            {
                cout << endl;
            }
        }
    }
    cout << "number:" << count << endl;
    return 0;
}