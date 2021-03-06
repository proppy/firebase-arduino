#include "modem/commands.h"

namespace firebase {
namespace modem {

bool RemoveCommand::execute(const String& command,
                            InputStream* in, OutputStream* out) {
  if (in == nullptr || out == nullptr) {
    return false;
  }

  if (command != "REMOVE") {
    return false;
  }

  String path = in->readLine();
  std::unique_ptr<FirebaseRemove> get(fbase().removePtr(path));

  if (get->error()) {
    out->print("-FAIL ");
    out->println(get->error().message());
    return false;
  }

  out->println("+OK");
  return true;
}

}  // modem
}  // firebase
