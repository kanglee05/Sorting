#ifndef TEAM_LAB_POPULATION_H
#define TEAM_LAB_POPULATION_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <chrono>
#include "linkedlist.h"
using namespace std;


class Population{
public:
    //getter
    long long get_population() const;
    long long get_population_age_one() const;
    string get_country_name() const;

    //functions with vector
    void read_file(string filename, vector<Population>& p_vector);
    void save_file(string filename, vector<Population>& p_vector);
    void print(vector<Population> p_vector);
    void print_table(vector<Population> p_vector, bool top, int volume);
    void print_sorted_list(vector<Population> p_vector);

    //functions with linked list
    void read_file_list(string filename, List<Population>& p_list);
    void print_entire_list(List<Population>& p_list);
    void print_table_list(List<Population>& p_list, bool top, int volume);
    void print_sorted_list_link(List<Population>& p_list);
    void save_file_list(string filename, List<Population>& p_list);
    void remove_country_vector(vector<Population>& p_vector, string country);

    template<typename T>
    void remove_country_list(List<T>& p_list, const string country) {
        using namespace chrono;
        high_resolution_clock::time_point t1 = high_resolution_clock:: now();

        Iterator<T> iter = p_list.begin();
        while (iter.get_position() != nullptr) {
            if (iter.get().get_country_name() == country) {
                iter = p_list.erase(iter);
                cout << "Country '" << country << "' removed from the linked list." << endl;
                break;
            }
            iter.next();
        }

        high_resolution_clock::time_point t2 = high_resolution_clock:: now();
        duration<double> time_span = duration_cast<duration<double> > (t2 - t1);
        cout << "Linked List removal took: " << time_span.count() << " seconds.";
        cout << endl;
    }

private:
    string country_name;
    int year;
    long long population;
    long long  population_age_one;
    long long population_age_twenties;

};

bool getInt(int &input);
int choice_prompt();
int print_prompt();


#endif //TEAM_LAB_POPULATION_H
