#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define nl "\n"
using namespace std;

int main()
{

    char arr[5][5] =
    {
        {'L', 'G', 'D', 'B', 'A'},
        {'Q', 'M', 'H', 'E', 'C'},
        {'U', 'R', 'N', 'I', 'F'},
        {'X', 'V', 'S', 'O', 'K'},
        {'Z', 'Y', 'W', 'T', 'P'}
    };

    cout << "2D Array:" << nl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << nl;
    }
    ll first, second, first2, second2;
    string str, str1, str2;
    cout << "Enter the PlainText:";
    cin >> str;
    cout << "Message: " << str << nl;


    transform(str.begin(), str.end(), str.begin(), ::toupper);
    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    vector<string> store;


    for (int i = 0; i < str.length();)
    {
        if (str[i] != str[i + 1] && (i + 1 < str.length()))
        {
            string pair;
            pair += str[i];
            pair += str[i + 1];
            store.push_back(pair);
            i += 2;
        }
        else
        {
            string pair;
            pair += str[i];
            pair += 'X';
            store.push_back(pair);
            i++;
        }
    }

    cout << "PlainText pairs: ";
    for (const auto &pair : store)
    {
        cout << pair << " ";
    }
    cout << nl;



    for (ll k = 0; k < store.size(); k++)
    {
        char first_char = store[k][0];
        char second_char = store[k][1];


        pair<ll, ll> first_pos, second_pos;
        for (ll i = 0; i < 5; i++)
        {
            for (ll j = 0; j < 5; j++)
            {
                if (arr[i][j] == first_char)
                    first_pos = {i, j};
                if (arr[i][j] == second_char)
                    second_pos = {i, j};
            }
        }


        if (first_pos.first == second_pos.first)
        {
            str2.push_back(arr[first_pos.first][(first_pos.second + 1) % 5]);
            str2.push_back(arr[second_pos.first][(second_pos.second + 1) % 5]);
        }
        else if (first_pos.second == second_pos.second)
        {
            str2.push_back(arr[(first_pos.first + 1) % 5][first_pos.second]);
            str2.push_back(arr[(second_pos.first + 1) % 5][second_pos.second]);
        }
        else
        {
            str2.push_back(arr[first_pos.first][second_pos.second]);
            str2.push_back(arr[second_pos.first][first_pos.second]);
        }
    }

    cout << "Encrypted Message: " << str2 << nl;


    str1.clear();
    for (ll k = 0; k < store.size(); k++)
    {
        char first_char = str2[2 * k];
        char second_char = str2[2 * k + 1];

        pair<ll, ll> first_pos, second_pos;
        for (ll i = 0; i < 5; i++)
        {
            for (ll j = 0; j < 5; j++)
            {
                if (arr[i][j] == first_char)
                    first_pos = {i, j};
                if (arr[i][j] == second_char)
                    second_pos = {i, j};
            }
        }

        if (first_pos.first == second_pos.first)
        {
            str1.push_back(arr[first_pos.first][(first_pos.second - 1 + 5) % 5]);
            str1.push_back(arr[second_pos.first][(second_pos.second - 1 + 5) % 5]);
        }
        else if (first_pos.second == second_pos.second)
        {
            str1.push_back(arr[(first_pos.first - 1 + 5) % 5][first_pos.second]);
            str1.push_back(arr[(second_pos.first - 1 + 5) % 5][second_pos.second]);
        }
        else
        {
            str1.push_back(arr[first_pos.first][second_pos.second]);
            str1.push_back(arr[second_pos.first][first_pos.second]);
        }
    }

    cout << "Decrypted Message: " << str1 << nl;

    return 0;
}

