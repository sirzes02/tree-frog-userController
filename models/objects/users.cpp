#include <TreeFrogModel>
#include "users.h"
#include "sqlobjects/usersobject.h"

Users::Users() : TAbstractModel(),
                 d(new UsersObject())
{
    // set the initial parameters
}

Users::Users(const Users &other) : TAbstractModel(),
                                   d(other.d)
{
}

Users::Users(const UsersObject &object) : TAbstractModel(),
                                          d(new UsersObject(object))
{
}

Users::~Users()
{
    // If the reference count becomes 0,
    // the shared data object 'UsersObject' is deleted.
}

int Users::id() const
{
    return d->id;
}

QString Users::email() const
{
    return d->email;
}

void Users::setEmail(const QString &email)
{
    d->email = email;
}

QString Users::password() const
{
    return d->password;
}

void Users::setPassword(const QString &password)
{
    d->password = password;
}

QString Users::createdAt() const
{
    return d->created_at;
}

QString Users::updatedAt() const
{
    return d->updated_at;
}

int Users::lockRevision() const
{
    return d->lock_revision;
}

Users &Users::operator=(const Users &other)
{
    d = other.d; // increments the reference count of the data
    return *this;
}

Users Users::create(const QString &email, const QString &password)
{
    UsersObject obj;
    obj.email = email;
    obj.password = password;
    if (!obj.create())
    {
        return Users();
    }
    return Users(obj);
}

Users Users::create(const QVariantMap &values)
{
    Users model;
    model.setProperties(values);
    if (!model.d->create())
    {
        model.d->clear();
    }
    return model;
}

Users Users::get(int id)
{
    TSqlORMapper<UsersObject> mapper;
    return Users(mapper.findByPrimaryKey(id));
}

Users Users::get(int id, int lockRevision)
{
    TSqlORMapper<UsersObject> mapper;
    TCriteria cri;
    cri.add(UsersObject::Id, id);
    cri.add(UsersObject::LockRevision, lockRevision);
    return Users(mapper.findFirst(cri));
}

Users Users::getByEmail(QString &email)
{
    TSqlORMapper<UsersObject> mapper;
    TCriteria cri;
    cri.add(UsersObject::Email, email);
    return Users(mapper.findFirst(cri));
}

int Users::count()
{
    TSqlORMapper<UsersObject> mapper;
    return mapper.findCount();
}

QList<Users> Users::getAll()
{
    return tfGetModelListByCriteria<Users, UsersObject>(TCriteria());
}

QJsonArray Users::getAllJson(const QStringList &properties)
{
    return tfConvertToJsonArray(getAll(), properties);
}

TModelObject *Users::modelData()
{
    return d.data();
}

const TModelObject *Users::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Users &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Users &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}
