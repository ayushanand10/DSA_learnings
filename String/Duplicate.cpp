#include <iostream>
using namespace std;

int main()
{
    char s[] = "ayushanand";
    int h = 0, c = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        c = 1;
        c = c << (s[i] - 97);
        if ((c & h) > 0)
            cout << s[i] << " is duplicate" << endl;
        else
            h = c | h;
    }

    return 0;
}