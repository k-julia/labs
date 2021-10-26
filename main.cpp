#include <iostream>
using namespace std;

struct list {
  string surname;
  list* prev;
  list* next;
};
list* first = 0;
list* last = 0;

void print_list() {
  if (first == 0) {
    cout << "The list is empty";
  } else {
    list* q = first;
    if (last == first) {
      cout << q->surname << endl;
    }
    while (q != 0) {
      cout << q->surname << endl;
      q = q->next;
    }
  }
}

void insert_first(string surname) {
  list* q = new list;
  q->surname = surname;
  q->next = 0;
  q->prev = 0;
  if (first == 0) {
    first = q;
    last = q;
  } else {
    q->next = first;
    first = q;
    q->next->prev = q;
  }
}

void insert_last(string surname) {
  list* q = new list;
  q->surname = surname;
  q->next = 0;
  q->prev = 0;
  if (first == 0) {
    first = q;
    last = q;
  } else {
    last->next = q;
    q->prev = last;
    last = q;
  }
}

void insert_sort(string surname) {
  if (first == 0 || surname <= first->surname) {
    return insert_first(surname);
  }
  if (surname >= last->surname) {
    return insert_last(surname);
  }
  list* q = new list;
  list* p = first;
  q->surname = surname;
  while (p->next->surname <= surname) {
    p = p->next;
  }
  q->next = p->next;
  q->prev = p;
  p->next->prev = q;
  p->next = q;
}

int finding(string f) {
  if (first == 0) {
    cout << "The list is empty";
    return 0;
  }
  list* q = first;
  while (q != 0) {
    if (q->surname == f) {
      cout << q << endl;
      return 0;
    }
    q = q->next;
  }
  cout << "Not in the list";
}

void delete_first() {
  list* q = first;
  first->next->prev = 0;
  first = first->next;
  delete q;
}
void delete_last() {
  list* q = last;
  last->prev->next = 0;
  last = last->prev;
  delete q;
}
void find_and_delete(string surname) {
  if (first == 0) {
    cout << "The list is empty";
    return;
  }
  list* q = first;
  while (q != 0) {
    if (q->surname == surname) {
      break;
    }
    q = q->next;
  }
  if (q == 0) {
    cout << "Not in the list";
    return;
  }
  if (q == first) {
    return delete_first();
  }
  if (q == last) {
    return delete_last();
  }
  q->prev->next = q->next;
  q->next->prev = q->prev;
  delete q;
}

int main() {
  string surname;
  cout << "Enter the list of the surnames (enter stop to end):" << endl;
  while (surname != "stop") {
    string input;
    cin >> input;
    if (input == "stop") {
      last->next = 0;
      break;
    }
    surname = input;
    list* q = new list;
    q->surname = surname;
    if (first == 0) {
      first = q;
      q->next = 0;
      q->prev = 0;
    } else {
      last->next = q;
      q->prev = last;
    }
    last = q;
  }
  int action = 0;
  while (action != 8) {
    cout << "Choose the operation:" << endl << "1 - Insert first element"
         << endl << "2 - Insert last element" << endl
         << "3 - Insert to the sort list" << endl << "4 - Find the element"
         << endl << "5 - Delete first element"
         << endl << "6 - Delete last element" << endl
         << "7 - Find and delete the element" << endl
         << "8 - End and print the list" << endl;
    int k;
    cin >> k;
    action = k;
    if(action == 1){
      cout << "Enter the element:" << endl;
      string s;
      cin >> s;
      insert_first(s);
    }
    if(action == 2){
      cout << "Enter the element:" << endl;
      string s;
      cin >> s;
      insert_last(s);
    }
    if(action == 3){
      cout << "Enter the element:" << endl;
      string s;
      cin >> s;
      insert_sort(s);
    }
    if(action == 4){
      cout << "Enter the element to find :" << endl;
      string s;
      cin >> s;
      finding(s);
    }
    if(action == 5){
      delete_first();
    }
    if(action == 6){
      delete_last();
    }
    if(action == 7){
      cout << "Enter the word to delete:" << endl;
      string s;
      cin >> s;
      find_and_delete(s);
    }
    if(action == 8){
      print_list();
      break;
    }
  }
  return 0;
}
