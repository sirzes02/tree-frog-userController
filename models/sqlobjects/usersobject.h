#pragma once
#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UsersObject : public TSqlObject, public QSharedData {
public:
    int id {0};
    QString email;
    QString password;
    QString created_at;
    QString updated_at;
    int lock_revision {0};

    enum PropertyIndex {
        Id = 0,
        Email,
        Password,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("users"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString email READ getemail WRITE setemail)
    T_DEFINE_PROPERTY(QString, email)
    Q_PROPERTY(QString password READ getpassword WRITE setpassword)
    T_DEFINE_PROPERTY(QString, password)
    Q_PROPERTY(QString created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QString, created_at)
    Q_PROPERTY(QString updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QString, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

