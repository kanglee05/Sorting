#include <iostream>
#include <vector>
#include "population.h"
#include "sorting.h"
#include "linkedlist.h"
using namespace std;
//Final Team Lab (Final Version)
//Name: Ching-Chieh(Nina) Chiu, Sahid, Kang Lee

int main() {

    vector<Population> p_vector;
    List<Population> p_list;
    Population p;
    p.read_file("population.txt", p_vector); // Read the file and save to the vector
    p.read_file_list("population_list.txt", p_list); // Read the file and save to the linked list

    string invite;
    int choice;

    cout << "Hello! This program allows you to explore selection sorting and perform removal action"
            "on vector and linked list with population data" << "\n"
         << "Do you want to use our program? (Y/N)" << endl;

    cin >> invite;
    if (invite == "Y"){
        while(true){
            choice = choice_prompt();
            switch (choice){
                case 1:{
                    string sorting_criteria;
                    cout << "Select sorting criteria (population or population under 1), enter population or under1: ";
                    cin >> sorting_criteria;
                    if (sorting_criteria == "population") {
                        // vector
                        selection_sort(p_vector, false);
                        cout << "Selection sort to vector" << endl;
                        p.print_sorted_list(p_vector);

                        // linked list
                        selection_sort_list(p_list,false);
                        cout << "Selection sort to linked list" << endl;
                        p.print_sorted_list_link(p_list);

                        break;

                    } else if (sorting_criteria == "under1") {
                        // vector
                        selection_sort(p_vector, true);
                        cout << "Selection sort to vector" << endl;
                        p.print_sorted_list(p_vector);

                        // linked list
                        cout << "Selection sort to linked list" << endl;
                        selection_sort_list(p_list,true);
                        p.print_sorted_list_link(p_list);

                        break;
                    }
                    break;
                }
                case 2:{
                    // Compare the time of selection sort (vector vs. linked list)
                    run_selection(p_vector);
                    run_selection_list(p_list);

                    break;
                }
                case 3:{
                    // Remove country by name
                    string country;
                    cout << "Which country would you like to remove? ";
                    cin >> country;
                    p.remove_country_vector(p_vector, country);
                    cout << endl;
                    cout << endl;
                    p.remove_country_list(p_list, country);
                    cout << endl;

                    break;
                }

                case 4:{
                    p.save_file("save_population.txt", p_vector);
                    p.save_file_list("save_population_list.txt", p_list);
                    return 0;

                }
                default:
                    cout << "Invalid choice. Please try again" << endl;
                    break;
            }
        }

    } else{
        cout << "Thank you, Bye!" << endl;
    }

}