#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur til trætyper
struct TreeType {
    string navn;
    double prisStikling;
    double forventetTab;
};

int main() {
    // Indtast dimensionerne på det ønskede areal
    double længde, bredde;
    cout << "Indtast længden af arealet (meter): ";
    cin >> længde;
    cout << "Indtast bredden af arealet (meter): ";
    cin >> bredde;

    // Definer trætyper
    TreeType træTyper[3] = {
        {"Ædelgran", 5.0, 0.1},
        {"Nordmannsgran", 8.0, 0.15},
        {"Rødgran", 4.0, 0.2}
    };

    // Indtast antal træer af hver type
    vector<int> antalTræer(3);
    for (int i = 0; i < 3; i++) {
        cout << "Indtast antal " << træTyper[i].navn << ": ";
        cin >> antalTræer[i];
    }

    // Beregn antallet af træer, der kan plantes på arealet
    double areal = længde * bredde;
    int samletAntalTræer = 0;

    for (int i = 0; i < 3; i++) {
        samletAntalTræer += antalTræer[i];
    }

    // Beregn omkostninger og forventet afkast
    double omkostningStiklinger = 0.0;
    double omkostningBeplantning = areal * 10.0; // Pris pr. m2 for beplantning
    double omkostningBearbejdning = areal * 20.0; // Pris pr. m2 for bearbejdning
    double forventetTab = 0.0;

    for (int i = 0; i < 3; i++) {
        omkostningStiklinger += antalTræer[i] * træTyper[i].prisStikling;
        forventetTab += antalTræer[i] * (træTyper[i].prisStikling * træTyper[i].forventetTab);
    }

    // Beregn det forventede afkast baseret på de faktiske omkostninger og tab
    double forventetAfkast = -omkostningStiklinger - omkostningBeplantning - omkostningBearbejdning - forventetTab;

    // Vis resultater
    cout << "\nResultater:\n";
    cout << "Antal træer, der kan plantes på arealet: " << samletAntalTræer << endl;
    cout << "Samlede omkostninger:\n";
    cout << " => Omkostning for stiklinger: " << omkostningStiklinger << " kr\n";
    cout << " => Omkostning for beplantning: " << omkostningBeplantning << " kr\n";
    cout << " => Omkostning for bearbejdning: " << omkostningBearbejdning << " kr\n";
    cout << "Forventet afkast af træerne: " << forventetAfkast << " kr\n";
}
