// TO DO, vedi indicazioni in network.h
#include "network.h"
#include <string>

const string emptyPayload = "#######";

struct halfVertex {
  string payload;
  halfVertex* next;
};

struct vertex {
  string payload;
  vertex* next;
  halfVertex* friends;
};

typedef vertex* adjList;
typedef halfVertex* friendsList;

struct network::st_Network {
  adjList users;
  adjList groups;
};
//in groups, il primo elemento è l'owner

network::Network network::createEmptyNetwork() {
  Network newNet = new st_Network;
  newNet->users->payload = "";
  newNet->users->friends = nullptr;
  return newNet;
}
