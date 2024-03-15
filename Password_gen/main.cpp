#include <bits/stdc++.h>
#include <string>
using namespace std;

class Password_gen
{

private:
    string pass;

    int sum(int x)
    {
        int sum = 0;
        while (x > 0)
        {
            sum += (x % 10);
            x /= 10;
        }
        return sum;
    }

    int count(int y)
    {
        int c = 0;
        while (y > 0)
        {
            y /= 10;
            c++;
        }
        return c;
    }

    // charater 1-generation logic for password
    int char1_gen(int room_no)
    {
        int pass_char_1 = sum(room_no);
        while (count(pass_char_1) > 1)
        {
            pass_char_1 = sum(pass_char_1);
        }
        if (pass_char_1 == 0)
        {
            return '2';
        }
        else if (pass_char_1 % 2 == 0)
        {
            return pass_char_1 + '0';
        }
        else if (pass_char_1 % 2 != 0)
        {
            return pass_char_1 - 1 + '0';
        }
        return '0';
    }

    // charater 2-generation logic for password
    char char2_gen(char last_name)
    {
        return last_name;
    }

    // charater 3-generation logic for password

    char char3_gen(vector<char> arr, int room_no)
    {
        char char_3;
        int last_dig = room_no % 10;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == last_dig)
            {
                char_3 = arr[i - 1];
            }
        }
        return char_3;
    }

    // charater 4-generation logic for password
    char char4_gen(int room_no)
    {
        char char_4;
        char_4 = (room_no / 10) % 10 + '0';
        return char_4;
    }

public:
    string pass_gen(int room_no, char last_name, vector<char> &arr)
    {
        // Generate each character for the password string and the password size must only be 4
        int char1 = char1_gen(room_no);
        pass += char1;
        char char2 = char2_gen(last_name);
        pass += char2;
        char char3 = char3_gen(arr, room_no);
        pass += char3;
        char char4 = char4_gen(room_no);
        pass += char4;

        if (pass.length() == 4)
            return pass;
        else
            return "Error in generating password";
    }
};

int main()
{

    // Get the Users First Name,Last name,Room-No;

    cout << "******************Wifi Password Generator**********************" << endl;
    string First_name;
    cout << "Enter your First name: ";
    cin >> First_name;

    string lastName;
    cout << "Enter your Last name: ";
    cin >> lastName;
    char last_name;
    last_name = lastName[0];

    int room_no;
    cout << "Enter Room_No: ";
    cin >> room_no;
    // Range of the room_no
    if (room_no >= 100 && room_no <= 999)
    {
        vector<char> arr{'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
        string password;

        // creating object for the password generator class
        Password_gen p;

        // accessing pass-gen method using the object
        password = p.pass_gen(room_no, last_name, arr);

        cout << "Your WiFi passowrd is "
             << " " << password << endl;
    }
    else
    {
        cout << "Room no should only be a 3 digit number" << endl;
    }

    cout << "******************Wifi Password Generator**********************" << endl;

    return 0;
}
