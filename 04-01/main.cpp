#include "PhoneNotifier.h"
#include "MailNotifier.h"
#include "AlarmNotifier.h"

int main() {
    Notifier *notifiers[3];

    notifiers[0] = new PhoneNotifier();
    notifiers[1] = new MailNotifier();
    notifiers[2] = new AlarmNotifier();

    for (int i = 0; i < 3; i++) {
        notifiers[i]->Notify();
    }

    for (int i = 0; i < 3; i++) {
        delete notifiers[i];
    }

    return 0;
}
