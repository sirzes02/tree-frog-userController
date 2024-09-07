#include "apiusersservice.h"
#include "objects/users.h"
#include <TreeFrogModel>

QJsonObject ApiUsersService::index()
{
    QList<Users> usersList = Users::getAll();
    QJsonObject json = {{"data", tfConvertToJsonArray(usersList)}};

    return json;
}

QJsonObject ApiUsersService::get(int id)
{
    Users users = Users::get(id);
    QJsonObject json = {{"data", users.toJsonObject()}};

    return json;
}

QJsonObject ApiUsersService::create(THttpRequest &request)
{
    QJsonObject json;
    QVariantMap users = request.jsonData().toVariant().toMap();
    Users model = Users::create(users);

    if (model.isNull())
    {
        json.insert("error", QJsonObject({{"message", "Internal Server Error"}}));
    }
    else
    {
        json.insert("data", model.toJsonObject());
    }

    return json;
}

QJsonObject ApiUsersService::save(THttpRequest &request, int id)
{
    QJsonObject json;
    Users model = Users::get(id);

    if (model.isNull())
    {
        json.insert("error", QJsonObject({{"message", "Not found"}}));
        return json;
    }

    QJsonDocument users = request.jsonData();
    model.setProperties(users);

    if (!model.save())
    {
        json.insert("error", QJsonObject({{"message", "Internal Server Error"}}));
    }
    else
    {
        json.insert("data", model.toJsonObject());
    }

    return json;
}

QJsonObject ApiUsersService::remove(int id)
{
    QJsonObject json;
    Users users = Users::get(id);

    if (users.remove())
    {
        json.insert("status", "OK");
    }

    return json;
}
