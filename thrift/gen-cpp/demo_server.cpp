#include "UserStorage.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include <map>

using namespace std;

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class UserStorageHandler : virtual public UserStorageIf {
 public:
  UserStorageHandler() {
    // Your initialization goes here
  }

  void store(const UserProfile& user) {
    // Your implementation goes here
    printf("store\n");

    log[user.id] = user;
  }

  void getUser(UserProfile& _return, const int32_t uid) {
    // Your implementation goes here
    printf("getUser\n");

    _return = log[uid];
  }

 protected:
  map<int32_t, UserProfile> log;

};

int main(int argc, char **argv) {
  int port = 9090;
  boost::shared_ptr<UserStorageHandler> handler(new UserStorageHandler());
  boost::shared_ptr<TProcessor> processor(new UserStorageProcessor(handler));
  boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  boost::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
