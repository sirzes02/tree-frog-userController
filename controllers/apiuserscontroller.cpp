#include "apiuserscontroller.h"
#include "apiusersservice.h"
#include "uservalidator.h"

static ApiUsersService service;

void ApiUsersController::index()
{
    renderJson(service.index());
}

void ApiUsersController::get(const QString &id)
{
    renderJson(service.get(id.toInt()));
}

void ApiUsersController::create()
{
    QJsonObject jsonResponse;

    if (request().method() == Tf::Post)
    {
        QVariantMap user = request().jsonData().toVariant().toMap();
        UserValidator userValidator;

        if (!userValidator.validate(user))
        {
            jsonResponse.insert("error", QJsonArray::fromStringList(userValidator.errorMessages()));
            setStatusCode(Tf::BadRequest);
        }
        else
        {
            jsonResponse = service.create(request());
        }
    }
    else
    {
        setStatusCode(Tf::BadRequest);
    }

    renderJson(jsonResponse);
}

void ApiUsersController::save(const QString &id)
{
    if (request().method() == Tf::Patch)
    {
        renderJson(service.save(request(), id.toInt()));
    }
    else
    {
        setStatusCode(Tf::BadRequest);
        renderJson(QJsonObject());
    }
}

void ApiUsersController::remove(const QString &id)
{
    if (request().method() == Tf::Delete)
    {
        renderJson(service.remove(id.toInt()));
    }
    else
    {
        setStatusCode(Tf::BadRequest);
        renderJson(QJsonObject());
    }
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ApiUsersController)