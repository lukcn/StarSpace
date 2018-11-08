#pragma once

#include "dict.h"
#include "doc_data.h"
#include "doc_parser.h"
#include <string>
#include <vector>

namespace starspace {

class DBLayerDataParser : public LayerDataParser {
public:
  DBLayerDataParser(
    std::shared_ptr<LayerDataHandler> db,
    std::shared_ptr<Dictionary> dict,
    std::shared_ptr<Args> args,
    bool checkEnabled = true);

    bool parse(
        std::string& line,
        ParseResults& rslt,
        const std::string& sep=" ") override;

private:
  std::shared_ptr<LayerDataHandler> db;
};

}
