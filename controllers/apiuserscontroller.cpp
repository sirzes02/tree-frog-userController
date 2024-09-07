#include "apiuserscontroller.h"
#include "apiusersservice.h"

static ApiUsersService service;

void ApiUsersController::index()
{
    QJsonObject json = service.index();
    renderJson(json);
}

void ApiUsersController::get(const QString &id)
{
    QJsonObject json = service.get(id.toInt());
    renderJson(json);
}

void ApiUsersController::create()
{
    QJsonObject json;

    switch (request().method())
    {
    case Tf::Post:
        json = service.create(request());
        break;
    default:
        setStatusCode(Tf::BadRequest);
        break;
    }
    renderJson(json);
}

void ApiUsersController::save(const QString &id)
{
    QJsonObject json;

    switch (request().method())
    {
    case Tf::Post:
        json = service.save(request(), id.toInt());
        break;
    default:
        setStatusCode(Tf::BadRequest);
        break;
    }
    renderJson(json);
}

void ApiUsersController::remove(const QString &id)
{
    QJsonObject json;

    switch (request().method())
    {
    case Tf::Post:
        json = service.remove(id.toInt());
        break;
    default:
        setStatusCode(Tf::BadRequest);
        return;
    }
    renderJson(json);
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ApiUsersController)
