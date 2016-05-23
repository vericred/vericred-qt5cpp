
#include "SWGRequestPlanFindApplicant.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGRequestPlanFindApplicant::SWGRequestPlanFindApplicant(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRequestPlanFindApplicant::SWGRequestPlanFindApplicant() {
    init();
}

SWGRequestPlanFindApplicant::~SWGRequestPlanFindApplicant() {
    this->cleanup();
}

void
SWGRequestPlanFindApplicant::init() {
    age = NULL;
}

void
SWGRequestPlanFindApplicant::cleanup() {
    
}

SWGRequestPlanFindApplicant*
SWGRequestPlanFindApplicant::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRequestPlanFindApplicant::fromJsonObject(QJsonObject &pJson) {
    setValue(&age, pJson["age"], "qint32", "");
}

QString
SWGRequestPlanFindApplicant::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGRequestPlanFindApplicant::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("age", QJsonValue(age));

    return obj;
}

qint32
SWGRequestPlanFindApplicant::getAge() {
    return age;
}
void
SWGRequestPlanFindApplicant::setAge(qint32 age) {
    this->age = age;
}



} /* namespace Swagger */

