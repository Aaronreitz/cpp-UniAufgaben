#include <iostream>
#include <limits> // Für die Grenzwerte von Datentypen

using namespace std;

// Funktion zur Berechnung der Länge der Collatz-Folge ohne Überlaufüberprüfung
int col_length(long long i)
{
    int length = 1;
    while (i > 1)
    {
        if (i % 2 == 0)
        {
            i = i / 2;
        }
        else
        {
            i = 3 * i + 1;
        }
        length++;
    }
    return length;
}

// Funktion zur Berechnung der Collatz-Folge mit Überlaufprüfung
int col_with_limit(long long i, long long limit)
{
    while (i > 1)
    {
        if (i > limit)
        {
            return -1; // Überlauf, der Wertebereich wurde überschritten
        }

        if (i % 2 == 0)
        {
            i = i / 2;
        }
        else
        {
            i = 3 * i + 1;
        }
    }
    return 1; // Kein Überlauf
}

int main()
{
    int range = 1000000; // Obere Grenze des Zahlenraums, von dem Collatzfolgen gestartet werden sollen

    // Überprüfung, ab welcher Zahl der short-Bereich überschritten wird
    for (int i = 1; i <= range; i++)
    {
        if (col_with_limit(i, numeric_limits<short>::max()) == -1)
        {
            cout << "Die Zahl " << i << " erzeugt eine Zahl in der Collatz-Folge, die den Wertebereich von short ueberschreitet." << endl;
            break;
        }
    }
    // Überprüfung, ab welcher Zahl der int-Bereich überschritten wird
    for (int i = 1; i <= range; i++)
    {
        if (col_with_limit(i, numeric_limits<int>::max()) == -1)
        {
            cout << "Die Zahl " << i << " erzeugt eine Zahl in der Collatz-Folge, die den Wertebereich von int ueberschreitet." << endl;
            break;
        }
    }

    // Berechne die längste Collatz-Folge für Zahlen von 1 bis limit
    int maxlength = 0; // Länge der längsten Collatz-Folge
    long long maxcol = 1; // Startzahl der längsten Collatz-Folge
    for (long long i = 1; i <= range; i++)
    {
        int length = col_length(i);
        if (length > maxlength)
        {
            maxlength = length;
            maxcol = i;
        }
    }

    cout << "Von 1 bis " << range << " hat die Zahl " << maxcol
         << " die laengste Collatzfolge mit " << maxlength << " Collatzschritten." << endl;

    return 0;
}

