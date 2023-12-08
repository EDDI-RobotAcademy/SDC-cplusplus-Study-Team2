//
// Created by eddi on 23. 12. 8.
//

#include "RequestToWrite.h"

RequestToWrite::RequestToWrite(std::string _title, std::string _writer, std::string _content)
: title(_title), writer(_writer), content(_content){}

BoardRequestFormWrite RequestToWrite::requestForService() {
    BoardRequestFormWrite request(title, writer, content);
    return request;
}
