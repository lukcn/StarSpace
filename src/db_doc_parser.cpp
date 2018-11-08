#include "db_doc_parser.h"
#include "utils/normalize.h"
#include <string>
#include <vector>
#include <fstream>

#include <boost/algorithm/string.hpp>

using namespace std;

namespace starspace {

DBLayerDataParser::DBLayerDataParser(
    std::shared_ptr<LayerDataHandler> db,
    std::shared_ptr<Dictionary> dict,
    std::shared_ptr<Args> args,
    bool checkEnabled)
: LayerDataParser(dict, args, checkEnabled) {
  this->db = db;
};

bool DBLayerDataParser::parse(std::string& line, ParseResults& rslt, const std::string& sep) {
  vector<string> docIds;
  boost::split(docIds, line, boost::is_any_of(string(sep)));

  for (unsigned int i = 0; i < docIds.size(); i++) {
    int docId = stoi(docIds[i]);
    auto& doc = db->getParseResults(docId);
    if (doc.RHSFeatures.size() > 0) {
      rslt.RHSFeatures.push_back(doc.RHSFeatures[0]);
    }
  }
  return check(rslt);
}

} // namespace starspace
