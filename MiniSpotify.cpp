// Mini-Spotify (simple + input validation)
// Arrays + switch only. Re-asks on invalid numeric input.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// safely read an int in [lo, hi]; keeps re-asking on bad input
int readChoice(int lo, int hi) {
    int x;
    while (true) {
        if (cin >> x && x >= lo && x <= hi) return x;
        cout << "Invalid input. Enter a number from " << lo << " to " << hi << ": ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    srand((unsigned)time(nullptr));

    const string happy[]   = {"Sunrise Drive — Nova Keys", "Senyum Pagi — Angin Selatan", "Golden Hour Ride — Retro Avenue"};
    const string sad[]     = {"Rain Window — Blue Rooms", "Selimah — Al Qamar", "Sea of Glass — Deep Harbour"};
    const string workout[] = {"Thunder Steps — Iron Mile", "Heat Sprint — Voltage Crew", "Neon Pulse — City Runner"};
    const string chill[]   = {"Night Rooftops — Lo-Fi Patterns", "Bayang Tenang — Rasa Senja", "Desert Moon — Layali"};

    const string pop[]    = {"Sunrise Drive — Nova Keys", "Senyum Pagi — Angin Selatan"};
    const string rock[]   = {"Golden Hour Ride — Retro Avenue", "Heat Sprint — Voltage Crew"};
    const string arabic[] = {"Selimah — Al Qamar", "Desert Moon — Layali"};

    while (true) {
        cout << "\n=== Mini-Spotify (Simple) ===\n"
             << "1) Recommend by Mood\n"
             << "2) Recommend by Mood + Genre\n"
             << "3) Surprise Me\n"
             << "0) Exit\n"
             << "Select: ";

        int menu = readChoice(0, 3); // <- re-asks until valid

        if (menu == 0) { cout << "Goodbye!\n"; break; }

        if (menu == 3) {
            int bucket = rand() % 4;
            const string* list; int n = 3;
            if (bucket == 0)      list = happy;
            else if (bucket == 1) list = sad;
            else if (bucket == 2) list = workout;
            else                  list = chill;
            cout << "🎵 " << list[rand() % n] << "\n";
            continue;
        }

        cout << "\nChoose a mood:\n"
             << "1) Happy\n2) Sad\n3) Workout\n4) Chill\n> ";
        int mood = readChoice(1, 4);

        if (menu == 1) {
            const string* list; int n = 3;
            switch (mood) {
                case 1: list = happy; break;
                case 2: list = sad; break;
                case 3: list = workout; break;
                default: list = chill; break;
            }
            cout << "\nYour pick (mood):\n";
            cout << "🎵 " << list[rand() % n] << "\n";
        } else {
            cout << "\nChoose a genre:\n"
                 << "1) Pop\n2) Rock\n3) Arabic\n> ";
            int g = readChoice(1, 3);

            const string* glist; int gn = 3;
            if (g == 1)      glist = pop;
            else if (g == 2) glist = rock;
            else             glist = arabic;

            // simple fallback example: if Sad + Rock, pretend mismatch and fallback to mood
            bool likelyMismatch = (mood == 2 && g == 2);
            if (likelyMismatch) {
                const string* list; int n = 3;
                switch (mood) {
                    case 1: list = happy; break;
                    case 2: list = sad; break;
                    case 3: list = workout; break;
                    default: list = chill; break;
                }
                cout << "\nNo perfect match; fallback to mood:\n";
                cout << "🎵 " << list[rand() % n] << "\n";
            } else {
                cout << "\nYour pick (genre focus):\n";
                cout << "🎵 " << glist[rand() % gn] << "\n";
            }
        }
    }
    return 0;
}
