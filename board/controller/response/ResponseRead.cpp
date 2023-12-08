//
// Created by eddi on 23. 12. 8.
//

#include "ResponseRead.h"

ResponseRead::ResponseRead(std::string _title, std::string _writer, std::string _content)
: title(_title), writer(_writer), content(_content){}

std::string ResponseRead::getTitle() {
    return title;
}

std::string ResponseRead::getWriter() {
    return writer;
}

std::string ResponseRead::getContent() {
    return content;
}
