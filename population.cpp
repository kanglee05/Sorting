#include "population.h"
#include "linkedlist.h"
#include <chrono>

void Population:: read_file(string filename, vector<Population>& p_vector) {
    ifstream ifs(filename);
    if (ifs.fail()) {
        cout << "Failed to open file (for vector)" << endl;
    } else {
        cout << "File opened (for vector)" << endl;

        // Read and discard the first line
        string header;
        getline(ifs, header);

        string line;
        while(getline(ifs, line)){
            istringstream iss(line);

            // Variables to store data from the line
            string country_name;
            int year;
            long long population;
            long long population_age_one;
            long long population_age_twenties;


            getline(iss, country_name, ',');
            iss >> year;
            iss.ignore(); // Ignore the comma
            iss >> population;
            iss.ignore();
            iss >> population_age_one;
            iss.ignore();
            iss >> population_age_twenties;


            Population p;
            p.country_name = country_name;
            p.year = year;
            p.population = population;
            p.population_age_one = population_age_one;
            p.population_age_twenties = population_age_twenties;

            // Add the Population object to the vector
            p_vector.push_back(p);
        }
        ifs.close();
    }
}


void Population:: save_file(string filename, vector<Population>& p_vector){
    ofstream ofs;
    ofs.open(filename);

    ofs << "Country name,Year,Population,Population of children under the age of 1,Population aged 20 to 29 years" << endl;

    for(int i = 0; i < p_vector.size(); i++){
        ofs << p_vector[i].country_name << ","
            << p_vector[i].year << ","
            << p_vector[i].population << ","
            << p_vector[i].population_age_one << ","
            << p_vector[i].population_age_twenties << endl;
    }
    cout << "File updated (for vector)" << endl;
    ofs.close();

}

//Print the entire vector
void Population:: print(vector<Population> p_vector){
    cout << left << setw(60) << "Country"
         << setw(10) << "Year"
         << setw(20) << "Population"
         << setw(20) << "Population Age One"
         << setw(20) << "Population Age Twenties" << endl;

    for (int i = 0; i < p_vector.size(); i++)
    {
        cout << left << setw(60) << p_vector[i].country_name
             << setw(10) << p_vector[i].year
             << setw(20) << p_vector[i].population
             << setw(20) << p_vector[i].population_age_one
             << setw(20) << p_vector[i].population_age_twenties << endl;

    }

}


void Population:: print_table(vector<Population> p_vector, bool top, int volume){
    cout << left << setw(60) << "Country"
         << setw(10) << "Year"
         << setw(20) << "Population"
         << setw(20) << "Population Age One"
         << setw(20) << "Population Age Twenties" << endl;

    if(top) {
        for (int i = 0; i < volume; i++) {
            cout << left << setw(60) << p_vector[i].country_name
                 << setw(10) << p_vector[i].year
                 << setw(20) << p_vector[i].population
                 << setw(20) << p_vector[i].population_age_one
                 << setw(20) << p_vector[i].population_age_twenties << endl;
        }
    } else{
        int start_index = p_vector.size() - volume;
        for (int i = start_index; i < p_vector.size(); i++) {
            cout << left << setw(60) << p_vector[i].country_name
                 << setw(10) << p_vector[i].year
                 << setw(20) << p_vector[i].population
                 << setw(20) << p_vector[i].population_age_one
                 << setw(20) << p_vector[i].population_age_twenties << endl;

        }

    }
}



void Population:: print_sorted_list(vector<Population> p_vector) {
    cout << "Select quantity of sorted list (top10, top20, bottom10, bottom20): ";
    string print_choice;
    cin >> print_choice;

    if (print_choice == "top10") {
        print_table(p_vector, true, 10);
    } else if (print_choice == "top20") {
        print_table(p_vector, true, 20);
    } else if (print_choice == "bottom10") {
        print_table(p_vector, false, 10);
    } else {
        print_table(p_vector, false, 20);
    }
}


bool getInt(int &input) {
    if (!(cin >> input)) {
        cin.clear();
        string g;
        getline(cin, g);
        return false;
    }
    return true;
}

int choice_prompt() {
    cout << "------------------------------ \n"
         << "1. Selection Sort\n"
         << "2. Sorting Time\n"
         << "3. Remove country by name\n"
            "4. Save and Exit\n"
         << "------------------------------ \n"
         << "Please enter your choice: ";
    int choice;
    getInt(choice);
    return choice;
}


long long Population::get_population() const{
    return this->population;
}

long long Population::get_population_age_one() const {
    return this->population_age_one;
}

string Population::get_country_name() const {
    return this->country_name;
}

//functions with linked list
void Population:: read_file_list(string filename, List<Population>& p_list) {
    ifstream ifs(filename);
    if (ifs.fail()) {
        cout << "Failed to open file (for linked list)" << endl;
    } else {

        cout << "File opened (for linked list)" << endl;

        // Read and discard the first line
        string header;
        getline(ifs, header);

        string line;
        while (getline(ifs, line)) {
            istringstream iss(line);

            // Variables to store data from the line
            string country_name;
            int year;
            long long population;
            long long population_age_one;
            long long population_age_twenties;

            getline(iss, country_name, ',');
            iss >> year;
            iss.ignore(); // Ignore the comma
            iss >> population;
            iss.ignore();
            iss >> population_age_one;
            iss.ignore();
            iss >> population_age_twenties;

            Population p;
            p.country_name = country_name;
            p.year = year;
            p.population = population;
            p.population_age_one = population_age_one;
            p.population_age_twenties = population_age_twenties;


            Iterator<Population> iter = p_list.begin();
            while (!iter.equals(p_list.end()) && iter.get().country_name < country_name) {
                iter.next();
            }
            // Insert the Population object
            p_list.insert(iter, p);

        }
        ifs.close();
    }
}

void Population::print_table_list(List<Population>& p_list, bool top, int volume) {
    cout << left << setw(60) << "Country"
         << setw(10) << "Year"
         << setw(20) << "Population"
         << setw(20) << "Population Age One"
         << setw(20) << "Population Age Twenties" << endl;

    Iterator<Population> iter;
    int count = 0;
    if (top) {
        iter = p_list.begin(); // Start from the beginning
        while (!iter.equals(p_list.end()) && count < volume) {
            cout << left << setw(60) << iter.get().country_name
                 << setw(10) << iter.get().year
                 << setw(20) << iter.get().population
                 << setw(20) << iter.get().population_age_one
                 << setw(20) << iter.get().population_age_twenties << endl;
            iter.next();
            count++;
        }
    } else {
        iter = p_list.end(); // Start from the end
        while (!iter.equals(p_list.begin()) && count < volume) {
            cout << left << setw(60) << iter.get().country_name
                 << setw(10) << iter.get().year
                 << setw(20) << iter.get().population
                 << setw(20) << iter.get().population_age_one
                 << setw(20) << iter.get().population_age_twenties << endl;
            iter.previous(); // Move to the previous node
            count++;
        }
    }

}

void Population:: print_sorted_list_link(List<Population>& p_list) {
    cout << "Select quantity of sorted list (top10, top20, bottom10, bottom20): ";
    string print_choice;
    cin >> print_choice;

    if (print_choice == "top10") {
        print_table_list(p_list, true, 10);
    } else if (print_choice == "top20") {
        print_table_list(p_list, true, 20);
    } else if (print_choice == "bottom10") {
        print_table_list(p_list, false, 10);
    } else {
        print_table_list(p_list, false, 20);
    }
}

void Population::print_entire_list(List<Population>& p_list) {
    cout << left << setw(60) << "Country"
         << setw(10) << "Year"
         << setw(20) << "Population"
         << setw(20) << "Population Age One"
         << setw(20) << "Population Age Twenties" << endl;

    Iterator<Population> iter = p_list.begin();
    while (!iter.equals(p_list.end())) {
        cout << left << setw(60) << iter.get().country_name
             << setw(10) << iter.get().year
             << setw(20) << iter.get().population
             << setw(20) << iter.get().population_age_one
             << setw(20) << iter.get().population_age_twenties << endl;

        iter.next(); // Move to the next element
    }
}

void Population::save_file_list(string filename, List<Population>& p_list) {
    ofstream ofs(filename);

    if (!ofs.is_open()) {
        cerr << "Error: Unable to open file (for linked list) " << filename << endl;
        return;
    }

    ofs << "Country name,Year,Population,Population of children under the age of 1,Population aged 20 to 29 years" << endl;

    Iterator<Population> iter = p_list.begin();
    while (!iter.equals(p_list.end())) {
        ofs << iter.get().country_name << ","
            << iter.get().year << ","
            << iter.get().population << ","
            << iter.get().population_age_one << ","
            << iter.get().population_age_twenties << endl;
        iter.next();
    }

    cout << "File updated (for linked list)" << endl;
    ofs.close();
}

void Population::remove_country_vector(vector<Population>& p_vector, string country) {
    using namespace chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock:: now();

    for (int i = 0; i < p_vector.size(); i++) {
        if (p_vector[i].get_country_name() == country) {
            p_vector.erase(p_vector.begin() + i);
            break;
        }
    }

    high_resolution_clock::time_point t2 = high_resolution_clock:: now();
    duration<double> time_span = duration_cast<duration<double> > (t2 - t1);
    cout << "Country '" << country << "' was removed from the vector." << endl;
    cout << "Vector removal took: " << time_span.count() << " seconds.";
    cout << endl;
}