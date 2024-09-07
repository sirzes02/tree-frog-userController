#pragma once
#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UsersObject;
class QJsonArray;

class T_MODEL_EXPORT Users : public TAbstractModel
{
public:
    Users();
    Users(const Users &other);
    Users(const UsersObject &object);
    ~Users();

    int id() const;
    QString email() const;
    void setEmail(const QString &email);
    QString password() const;
    void setPassword(const QString &password);
    QString createdAt() const;
    QString updatedAt() const;
    int lockRevision() const;
    Users &operator=(const Users &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save() override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Users create(const QString &email, const QString &password);
    static Users create(const QVariantMap &values);
    static Users get(int id);
    static Users get(int id, int lockRevision);
    static Users getByEmail(QString &email);
    static int count();
    static QList<Users> getAll();
    static QJsonArray getAllJson(const QStringList &properties = QStringList());

private:
    QSharedDataPointer<UsersObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend T_MODEL_EXPORT QDataStream &operator<<(QDataStream &ds, const Users &model);
    friend T_MODEL_EXPORT QDataStream &operator>>(QDataStream &ds, Users &model);
};

Q_DECLARE_METATYPE(Users)
Q_DECLARE_METATYPE(QList<Users>)
