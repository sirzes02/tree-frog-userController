#pragma once
#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT ApiUsersController : public ApplicationController
{
    Q_OBJECT
public slots:
    void index();
    void get(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};
