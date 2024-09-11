/*
Author: Yilun Ma
Assignment: HW5
Date due: 06-27
I pledge that I have completed this assignment without the use of AI tools or collaborating with anyone else,
in conformance with the NYU School of Engineering Policies and Procedures on Academic Misconduct.
*/
#include <iostream>
#include <vector>
#include<string>

using namespace std;

//Task 1: Base Class Notification
class Notification {
public:
    Notification(const string& message);
    virtual void send();
protected:
    string message;
};

//Task 2: Derived Classes
//Email
class EmailNotification:public Notification {
public:
    //Constructor
    EmailNotification(const string& message);
    //override send
    void send() override;
};

//SMS
class SMSNotification:public Notification {
public:
    //Constructor
    SMSNotification(const string& message);
    //override send
    void send() override;
};

//Task 3: Notification Manager Class
class NotificationManager {
public:
    //Constructor
    NotificationManager();

    //addNotification
    void addNotification(Notification* notification);

    //sendAll
    void sendAll();

    //Deconstructor:
    ~NotificationManager();
private:
    vector<Notification*> notifications;
};
int main() {
    //instances
    NotificationManager manager;
    EmailNotification* email_notification = new EmailNotification("Email from Aaron");
    SMSNotification* sms_notification = new SMSNotification("SMS from Jason");
    manager.addNotification(email_notification);
    manager.addNotification(sms_notification);
    manager.sendAll();

    return 0;
}

//Constructors:
Notification::Notification(const string& message):message(message) {
}

EmailNotification::EmailNotification(const string &message):Notification(message) {

}

SMSNotification::SMSNotification(const string &message):Notification(message) {

}

NotificationManager::NotificationManager() {

}



//send
void Notification::send() {

}

void EmailNotification::send() {
    cout << "Sending email: " << message << endl;
}

void SMSNotification::send() {
    cout << "Sending SMS: " << message << endl;
}

//Notification Manager
void NotificationManager::sendAll(){
    for(Notification*& notification:notifications) {
        notification->send();
    }
}

void NotificationManager::addNotification(Notification* notification) {
    //Notification* new_notif = new Notification(* notification);
    notifications.push_back(notification);
}

NotificationManager::~NotificationManager() {
    for(Notification* notification&:notifications ) {
        delete notification;
    }
}






