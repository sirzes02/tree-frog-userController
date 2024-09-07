#pragma once
#include <TGlobal>
#include <QJsonObject>

class THttpRequest;
class TSession;

class T_MODEL_EXPORT ApiUsersService
{
public:
    QJsonObject index();
    QJsonObject get(int id);
    QJsonObject create(THttpRequest &request);
    QJsonObject save(THttpRequest &request, int id);
    QJsonObject remove(int id);
};
