//
// Created by eddi on 23. 12. 4.
//

#ifndef CLASS_TEST_UISERVICECREATEHANDLER_H
#define CLASS_TEST_UISERVICECREATEHANDLER_H

class UiServiceCreateHandler {
private:
    std::string title;
    std::string writer;
    std::string content;
public:
    UiServiceCreateHandler();
    std::string getTitle();
    std::string getWriter();
    std::string getContent();
    std::string getCreatPost();


    ~UiServiceCreateHandler();
};

#endif //CLASS_TEST_UISERVICECREATEHANDLER_H
