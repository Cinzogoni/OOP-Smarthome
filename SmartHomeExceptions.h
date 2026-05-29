#ifndef SMART_HOME_EXCEPTION_H
#define SMART_HOME_EXCEPTION_H

#include <exception>

class UnauthorizedAccessException : public exception {
    string msg;
public:
    UnauthorizedAccessException(const string& device)
        : msg("[CANH BAO BAO MAT] Truy cap trai phep vao thiet bi: " + device) {}
    const char* what() const noexcept override { return msg.c_str(); }
};
 
class FeedbackLoopException : public exception {
public:
    const char* what() const noexcept override {
        return "[LOI HE THONG] Vong lap phan hoi phat hien! He thong dung khan cap.";
    }
};

#endif