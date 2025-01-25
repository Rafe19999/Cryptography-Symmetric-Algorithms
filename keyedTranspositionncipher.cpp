#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string plaintext = "ENEMYATTACKSTONIGHT";
    cout << "The Plaintext is: " << "Enemy Attacks Tonight" << endl;

    int k;
    cout << "Enter the key size: ";
    cin >> k;

    int n = plaintext.length();
    int rows = ceil((double)n / k);

    char arr[rows][k];

    int index = 0;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < k; c++)
        {
            if (index < n)
            {
                arr[r][c] = plaintext[index++];
            }
            else
            {
                arr[r][c] = 'Z';
            }
        }
    }

    cout << "Matrix representation:" << endl;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < k; c++)
        {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }


    for (int r = 0; r < rows; r++)
    {
        char temp = arr[r][0];
        arr[r][0] = arr[r][2];
        arr[r][2] = temp;

    }
    for (int r = 0; r < rows; r++)
    {
        char temp = arr[r][1];
        arr[r][1] = arr[r][2];
        arr[r][2] = temp;
    }

    for (int r = 0; r < rows; r++)
    {
        char temp = arr[r][2];
        arr[r][2] = arr[r][3];
        arr[r][3] = temp;
    }
    for (int r = 0; r < rows; r++)
    {
        char temp = arr[r][4];
        arr[r][4] = arr[r][3];
        arr[r][3] = temp;
    }
    cout << "\nMatrix representation after interchanging the columns:" << endl;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < k; c++)
        {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }

    string cipher;
    for (int c = 0; c < k; c++)
    {
        for (int r = 0; r < rows; r++)
        {
            cipher += arr[r][c];
        }
    }

    cout<<"The ciphertext is: "<<cipher<<endl;

   for (int r = 0; r < rows; r++)
    {
        char temp = arr[r][1];
        arr[r][1] = arr[r][0];
        arr[r][0] = temp;

    }
    for (int r = 0; r < rows; r++)
    {
        char temp = arr[r][4];
        arr[r][4] = arr[r][1];
        arr[r][1] = temp;

    }
   for (int r = 0; r < rows; r++)
    {
        char temp = arr[r][4];
        arr[r][4] = arr[r][2];
        arr[r][2] = temp;

    }
    for (int r = 0; r < rows; r++)
    {
        char temp = arr[r][4];
        arr[r][4] = arr[r][3];
        arr[r][3] = temp;

    }
cout << "\nMatrix representation after interchanging the columns after encryption:" << endl;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < k; c++)
        {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }

    string plain;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < k; c++)
        {
            plain += arr[r][c];
        }
    }

    cout<<"The plain is: "<<plain<<endl;
    return 0;
}
