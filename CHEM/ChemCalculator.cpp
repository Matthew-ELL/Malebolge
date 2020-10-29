#include <iostream>
using namespace std;

double atm_to_bar (double);
double atm_to_torr (double);
double bar_to_torr (double);
double bar_to_atm (double);
double torr_to_bar (double);
double torr_to_atm (double);
double get_R (string);
double pressure_converter (double, string, string);
double volume_converter (double, string);
double temperature_converter (double, string);
void gas_law();
void mv1_to_mv2();
void dillution();

int main() {
	int choice;
    do {
    cout << "Welcome to the Chemistry Calculator" << endl;
    cout << "   1: Equations    2: Unit Conversions" << endl;
    cin >> choice;
    if (choice == 1) {
        cout << "Which Equation would you like to use?" << endl;
        cout << "   1: Gas Law    2: M1V1 = M2V2" << endl;
        cin >> choice;
        if (choice == 1) {
            gas_law();
        } else if (choice == 2) {
            mv1_to_mv2();
        }
    } else if (choice == 2) {
        cout << "What would you like to convert?" << endl;
        cout << "   1: Pressure 2: Other" << endl;
        cin >> choice;
        if (choice == 1) {
            string i_unit, f_unit;
            double pressure;
            cout << "What are the initial units for pressure? ";
            cin >> i_unit;
            cout << "What are the final units for pressure? ";
            cin >> f_unit;
            cout << "What is the pressure? ";
            cin >> pressure;
            cout << pressure << " " << i_unit << " gets converted to " << pressure_converter(pressure, i_unit, f_unit) << " " << f_unit << endl;
        } else {
            
        }
    } else {
        cout << "INVALID CHOICE" << endl;
    }
    
    } while (choice != 0);
    
	return 0;
}

double atm_to_bar (double p) {
    p *= (101325.0/100000);
    return p;
};

double atm_to_torr (double p) {
    p *= (760);
    return p;
};

double bar_to_torr (double p) {
    p *= (100000*760/101325.0);
    return p;
};

double bar_to_atm (double p) {
    p *= (100000/101325.0);
    return p;
};

double torr_to_bar (double p) {
    p /= (100000*760/101325.0);
    return p;
};

double torr_to_atm (double p) {
    p /= (760);
    return p;
};

double get_R (string unit) {
    double R;
    if (unit == "atm") {
        R = 0.082057366;
    } else if (unit == "J") {
        R = 8.314462618;
    } else if (unit == "torr") {
        R = 62.36359822;
    } else if (unit == "bar") {
        R = 0.08314462618;
    } else {
        cout << "INVALID UNIT" << endl;
    }
    return R;
};

double pressure_converter (double p, string initial_unit, string final_unit) {
    if (initial_unit == "atm") {
        if (final_unit == "bar") {
            p = atm_to_bar(p);
        } else if (final_unit == "torr") {
            p = atm_to_torr(p);
        } else {
            cout << "INVALID UNITS" << endl;
        }
    } else if (initial_unit == "torr") {
        if (final_unit == "atm") {
            p = torr_to_atm(p);
        } else if (final_unit == "bar") {
            p = torr_to_bar(p);
        } else {
            cout << "INVALID UNITS" << endl;
        }
    } else if (initial_unit == "bar") {
        if (final_unit == "atm") {
            p = bar_to_atm(p);
        } else if (final_unit == "torr") {
            p = bar_to_torr(p);
        } else {
            cout << "INVALID UNITS" << endl;
        }
    } else {
        cout << "INVALID UNIT GIVEN" << endl;
    }
    return p;
};

double volume_converter (double v, string unit) {
    if (unit == "mL")
        v /= 1000;
    return v;
};

double temperature_converter (double t, string unit) {
    if (unit == "C") 
        t += 273.15;
    return t;
};

void gas_law() {
    int selection {1};
    double pressure;
    double volume;
    double temperature;
    double moles;
    double R;
    string units = "BLANK";
    do {
    cout << "What would you like to calculate?" << endl;
    cout << "   1: Pressure     2: Volume" << endl;
    cout << "   3: Temperature  4: Moles" << endl;
    cin >> selection;
    if (selection == 1) {
        cout << "What units are we using for volume? ";
        cin >> units;
        cout << "What is the volume in " << units << "? ";
        cin >> volume;
        volume = volume_converter(volume, units);
        cout << "What units are we using for temperature? ";
        cin >> units;
        cout << "What is the temperature? ";
        cin >> temperature;
        temperature = temperature_converter(temperature, units);
        cout << "How many moles are there? ";
        cin >> moles;
        cout << "What units are we using for pressure? ";
        cin >> units;
        R = get_R(units);
        pressure = (moles * R * temperature / volume);
        cout << "The pressure is " << pressure << " " << units << endl;
    } else if (selection == 2) {
        cout << "What units are we using for pressure? ";
        cin >> units;
        cout << "What is the pressure? ";
        cin >> pressure;
        R = get_R(units);
        cout << "What units are we using for temperature? ";
        cin >> units;
        cout << "What is the temperature? ";
        cin >> temperature;
        temperature = temperature_converter(temperature, units);
        cout << "How many moles are there? ";
        cin >> moles;
        cout << "What units are we using for volume? ";
        cin >> units;
        volume = (moles * R * temperature / pressure);
        if (units == "mL") {
            volume *= 1000;
        }
        cout << "The volume is " << volume << " " << units << endl;
    } else if (selection == 3) {
        cout << "What units are we using for volume? ";
        cin >> units;
        cout << "What is the volume in " << units << "? ";
        cin >> volume;
        volume = volume_converter(volume, units);
        cout << "How many moles are there? ";
        cin >> moles;
        cout << "What units are we using for pressure? ";
        cin >> units;
        cout << "What is the pressure? ";
        cin >> pressure;
        R = get_R(units);
        cout << "What units are we using for temperature? ";
        cin >> units;
        temperature = (pressure * volume / (R * moles));
        temperature = temperature_converter(temperature, units);
        cout << "The temperature is " << temperature << " " << units << endl;
    } else if (selection == 4) {
        cout << "What units are we using for volume? ";
        cin >> units;
        cout << "What is the volume in " << units << "? ";
        cin >> volume;
        volume = volume_converter(volume, units);
        cout << "What units are we using for temperature? ";
        cin >> units;
        cout << "What is the temperature? ";
        cin >> temperature;
        temperature = temperature_converter(temperature, units);
        cout << "What units are we using for pressure? ";
        cin >> units;
        cout << "What is the pressure? ";
        cin >> pressure;
        R = get_R(units);
        moles = (pressure * volume / (temperature * R));
        cout << "There are " << moles << " moles" << endl;
    } else { cout << "INVALID" << endl;};
    } while (selection != 0);
};

void mv1_to_mv2() {
    double m1;
    double m2;
    double v1;
    double v2;
    string units;
    int choice;
    cout << "What are you looking for?" << endl;
    cout << "   1: Volume   2: Concentration" << endl;
    cin >> choice;
    if (choice == 1) {
        cout << "What units are we using for volume? ";
        cin >> units;
        cout << "What is the volume 1 in " << units << "? ";
        cin >> v1;
        cout << "What is the concentration 1? ";
        cin >> m1;
        cout << "What is the concentration 2? ";
        cin >> m2;
        v2 = (m1 * v1 / m2);
        cout << "The unknown volume is " << v2 << " " << units << endl;
    } else if (choice == 2) {
        cout << "What units are we using for volume? ";
        cin >> units;
        cout << "What is the volume 1 in " << units << "? ";
        cin >> v1;
        cout << "What is the volume 2 in " << units << "? ";
        cin >> v2;
        cout << "What is the concentration 1? ";
        cin >> m1;
        m2 = (m1 * v1 / v2);
        cout << "The unknown concentration is " << m2 << " M" << endl;
    } else {
        cout << "INVALID CHOICE" << endl;
    }
    
};


