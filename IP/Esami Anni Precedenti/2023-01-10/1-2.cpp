#include <iostream>
#include <vector>
using namespace std;

struct indirizzo {
  string via;
  int civ;
  int CAP;
  string city;
};

struct cliente {
  string cognome;
  string nome;
  indirizzo addr;
};

bool sameCityZone(cliente c1, cliente c2) {
  if (c1.addr.city == c2.addr.city && c1.addr.CAP == c2.addr.CAP)
    return true;
  return false;
}

void updateAddress(cliente &client);

void enqueue(vector<cliente> &queue, cliente client);
void dequeue(vector<cliente> &queue);
cliente front(vector<cliente> queue);

void dequeue(vector<cliente> &queue) {
  if (queue.size() < 1) {
    cout << "Empty queue." << endl;
  } else {
    for (unsigned int i = 0; i < (queue.size() - 1); i++) {
      queue[i]=queue[i+1];
    }
    queue.pop_back();
  }
}

void enqueue(vector<cliente> &queue, cliente client) {
  queue.push_back(client);
}



int main() {
  vector<cliente> clientQueue;
  cliente c1;
  c1.nome = "a";
  enqueue(clientQueue, c1);
  c1.nome = "h";
  enqueue(clientQueue, c1);
  c1.nome = "l";
  enqueue(clientQueue, c1);
  c1.nome = "p";
  enqueue(clientQueue, c1);

  for (unsigned int i=0; i<clientQueue.size();i++) {
    cout << clientQueue.at(i).nome << endl;
  }
  cout << endl;
  dequeue(clientQueue);

  for (unsigned int i=0; i<clientQueue.size();i++) {
    cout << clientQueue.at(i).nome << endl;
  }
  dequeue(clientQueue);
  dequeue(clientQueue);
  dequeue(clientQueue);
  dequeue(clientQueue);
}
