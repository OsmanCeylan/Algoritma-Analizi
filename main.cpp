#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

int* find_queue(const queue<int *> q, int item){
    queue<int* > copy = q;
    if (copy.empty()){
        cout << "Kuyruk Bos" << endl;
        return NULL;
    }
    else{
        while (!copy.empty()){
            if (item == *copy.front()){
                cout << "Kuyrukta " << item << " bulundu" << endl;
                return copy.front();
            }
            copy.pop();
        }
        cout << "Kuyrukta bu eleman yok" << endl;
    }
}

void print_queue(const queue<int* > q)
{
  queue<int* > copy = q;
  if (copy.empty()){
      cout << "Kuyruk Bos" << endl;
      return;
  }
  else{
      while (!copy.empty()){
          cout << *copy.front() << " ";
          copy.pop();
      }
      cout << endl;
  }
}

bool add_to_queue(queue<int *> *q, int item)
{
    int before_push= q->size();
    int after_push;
    q->push(new int(item));
    after_push=q->size();

    if (before_push<after_push) return true;
    return false;
}

bool delete_from_queue(queue<int *> *q){
    int before_push= q->size();
    int after_push;
    q->pop();
    after_push=q->size();

    if (before_push>after_push) return true;
    return false;
}

void screen(queue<int *> q){
    cout << "           ********************************************************" << endl;
    cout << "           **    1 - EKLEME                  2 - ARAMA           **" << endl;
    cout << "           **    3 - SIL                     4 - CIK (Ctrl+C)    **" << endl;
    cout << "           ********************************************************" << endl;
    cout << "           ********************************************************" << endl;
    cout << "           **    ----------------- LISTE --------------------    **" << endl;
    cout << "           ";
    print_queue(q);
    cout << "           ********************************************************" << endl;
}

void selection(queue<int *> *q, bool *quit){
    char k;
    int number;
    cin >> k;
    switch (k){
        case '1':
            cout << "Numara gir: ";
            cin >> number;
            add_to_queue(q, number);
            system("clear");
            break;

        case '2':
            cout << "Numara gir: ";
            cin >> number;
            find_queue(*q, number);
            break;

        case '3':
            delete_from_queue(q);
            system("clear");
        break;

        case '4':
           *quit=true;
           break;

        default:
            system("clear");
            break;

    }
}

int main(){

    queue<int* > my_queue;                                      // POINTER OF INTEGER QUEUE
    bool quit=false;

    while (!quit){
        screen(my_queue);
        selection(&my_queue, &quit);
    }

    return 0;
}
