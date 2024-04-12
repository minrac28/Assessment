#include <iostream>
#include <vector>

using namespace std;

const int TOTAL_SEATS = 80;
const int ROW_SIZE = 7;
const int LAST_ROW_SIZE = 3;

// Function to display the seats
void displaySeats(const vector<bool> &seats)
{
    cout << "Seat Availability: \n";
    for (int i = 0; i < TOTAL_SEATS; ++i)
    {
        if (seats[i])
        {
            cout << "X ";
        }
        else
        {
            cout << i + 1 << " ";
        }
        if ((i + 1) % ROW_SIZE == 0)
        {
            cout << endl;
        }
    }
}

// Function to book seats
void bookSeats(vector<bool> &seats, int numSeats)
{
    int booked = 0;
    for (int i = 0; i < TOTAL_SEATS; ++i)
    {
        if (!seats[i])
        {
            int j = i;
            int count = 0;
            while (j < TOTAL_SEATS && !seats[j] && count < numSeats)
            {
                ++j;
                ++count;
            }
            if (count == numSeats)
            {
                for (int k = i; k < j; ++k)
                {
                    seats[k] = true;
                    ++booked;
                }
                cout << "Booked seats: ";
                for (int k = i; k < j; ++k)
                {
                    cout << k + 1 << " ";
                }
                cout << endl;
                break;
            }
            else
            {
                i = j;
            }
        }
    }
    if (booked < numSeats)
    {
        cout << "Sorry, required number of seats not available.\n";
    }
}

int main()
{
    vector<bool> seats(TOTAL_SEATS, false);
    int numSeats;
    char choice;
    do
    {
        cout << "Enter the number of seats to book: ";
        cin >> numSeats;
        bookSeats(seats, numSeats);
        displaySeats(seats);
        cout << "Do you want to book more seats? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
