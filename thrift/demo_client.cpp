#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "UserStorage.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

int main() {
  boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  UserStorageClient client(protocol);

  try {
    transport->open();

    UserProfile user;
    user.id = 1;
    user.name = "oneUser";
    user.blurb = "hix";

    client.store(user);

    UserProfile user2;
    client.getUser(user2, 1);
    printf("user.id = %d user.name = %s user.blurb = %s\n", 
        user2.id, user2.name.c_str(), user2.blurb.c_str());

    transport->close();
  } catch (TException& tx) {
    cout << "ERROR: " << tx.what() << endl;
  }
}
