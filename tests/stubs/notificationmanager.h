#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <QObject>
#include <CommHistory/Event>
#include <CommHistory/Group>
#include <qcontact.h>
QTM_USE_NAMESPACE

namespace CommHistory {
    class GroupModel;
}

QTM_BEGIN_NAMESPACE
class QContactManager;
QTM_END_NAMESPACE

namespace RTComLogger {

class NotificationManager : public QObject
{
    Q_OBJECT
public:
    explicit NotificationManager(QObject *parent = 0);

    static NotificationManager* instance();
    void showNotification(const CommHistory::Event& event,
                          const QString &channelTargetId = QString(),
                          CommHistory::Group::ChatType chatType = CommHistory::Group::ChatTypeP2P);

    void removeMissedCallNotifications(const QString &localId,
                                       const QString &remoteId);

    CommHistory::GroupModel* groupModel();
    void showVoicemailNotification(int count);
    QContactManager* contactManager();


    int voicemailNotifications;
    struct Notification {
        CommHistory::Event event;
        QString channelTargetId;
        CommHistory::Group::ChatType chatType;
    };
    QList<Notification> postedNotifications;

    static NotificationManager* m_pInstance;
    QContactManager *m_pContactManager;
    CommHistory::GroupModel *m_GroupModel;
};

}
#endif // NOTIFICATIONMANAGER_H
