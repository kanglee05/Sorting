#ifndef TEAM_LAB_SORTING_H
#define TEAM_LAB_SORTING_H
#include "linkedlist.h"
#include "population.h"
#include <iostream>
#include <vector>
using namespace std;

// Function to perform selection sort on a vector
template <class data_type>
void selection_sort(vector<data_type> &p_vector, bool under_one) {
  int size = p_vector.size();
  for (int i = 0; i < size; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (!under_one) {
        if (p_vector[j].get_population() < p_vector[min].get_population()) {
          min = j;
        }
      } else {
        if (p_vector[j].get_population_age_one() <
            p_vector[min].get_population_age_one()) {
          min = j;
        }
      }
    }
    swap(p_vector[i], p_vector[min]);
  }
}

void run_selection(vector<Population> p_vector) {
  using namespace chrono;
  high_resolution_clock::time_point t1 = high_resolution_clock::now();

  selection_sort(p_vector, true);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  cout << "Selection Sort for vector took me: " << time_span.count() << " seconds.";
  cout << endl;
}

// Function to perform selection sort on a linked list
template <class data_type>
void selection_sort_list(List<data_type> &p_list, bool under_one) {
    Iterator<data_type> current = p_list.begin();
//While there are still nodes to iterate over
    while (current.get_position() != nullptr) {
        Iterator<data_type> iter = current;
        iter.next(); //move to the next node
        Iterator<data_type> min = current; //assuming the current node as the minimum

      //Iterate through the remaining element to find the minimum. Compare the population of the nodes
        while (iter.get_position() != nullptr) {
            if (!under_one && iter.get().get_population() < min.get().get_population()) {
                min = iter;
            }
            else if (under_one && iter.get().get_population_age_one() < min.get().get_population_age_one()){
                min = iter;
            }
            iter.next(); // Move to the next node
        }

      // Swap data of minimum node with the current node
      if (current.get_position() != min.get_position()) {
          data_type temp = current.get();
          // Assign min's data to the current node's data field
          current.get_position()->set_data(min.get());
          // Assign current's original data to the min node's data field
          min.get_position()->set_data(temp);
      }

        current.next(); // Move to the next node
    }
}

void run_selection_list(List<Population> p_list) {
  using namespace chrono;
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  selection_sort_list(p_list, true);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  cout << "Selection Sort for linked list took me: " << time_span.count() << " seconds.";
  cout << endl;
}

// merge sort
void merge(vector<Population> &p_vector, int left, int mid, int right,
           bool under1) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  vector<Population> left_subarray(n1);
  vector<Population> right_subarray(n2);

  for (int i = 0; i < n1; i++) {
    left_subarray[i] = p_vector[left + i];
  }
  for (int j = 0; j < n2; j++) {
    right_subarray[j] = p_vector[mid + 1 + j];
  }
  int i = 0;
  int j = 0;
  int k = left;
  while (i < n1 && j < n2) {
    if (!under1) {
      if (left_subarray[i].get_population() <
          right_subarray[j].get_population()) {
        p_vector[k] = left_subarray[i];
        i++;
      } else {
        p_vector[k] = right_subarray[j];
        j++;
      }
      k++;
    } else {
      if (left_subarray[i].get_population_age_one() <
          right_subarray[j].get_population_age_one()) {
        p_vector[k] = left_subarray[i];
        i++;
      } else {
        p_vector[k] = right_subarray[j];
        j++;
      }
      k++;
    }
  }
  while (i < n1) {
    p_vector[k] = left_subarray[i];
    i++;
    k++;
  }
  while (j < n2) {
    p_vector[k] = right_subarray[j];
    j++;
    k++;
  }
}

// Function to perform merge sort on a vector
void merge_sort(vector<Population> &p_vector, int left, int right,
                bool under1) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    merge_sort(p_vector, left, mid, under1);
    merge_sort(p_vector, mid + 1, right, under1);
    merge(p_vector, left, mid, right, under1);
  }
}

void run_merge(vector<Population> p_vector) {
  using namespace chrono;
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  merge_sort(p_vector, 0, p_vector.size() - 1, true);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  cout << "Merge Sort took me: " << time_span.count() << " seconds.";
  cout << endl;
}

#endif
