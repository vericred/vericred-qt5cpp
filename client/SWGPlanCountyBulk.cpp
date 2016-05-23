
#include "SWGPlanCountyBulk.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGPlanCountyBulk::SWGPlanCountyBulk(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPlanCountyBulk::SWGPlanCountyBulk() {
    init();
}

SWGPlanCountyBulk::~SWGPlanCountyBulk() {
    this->cleanup();
}

void
SWGPlanCountyBulk::init() {
    id = NULL;
plan_id = NULL;
county_id = NULL;
}

void
SWGPlanCountyBulk::cleanup() {
    


}

SWGPlanCountyBulk*
SWGPlanCountyBulk::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPlanCountyBulk::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "qint32", "");
setValue(&plan_id, pJson["plan_id"], "qint32", "");
setValue(&county_id, pJson["county_id"], "qint32", "");
}

QString
SWGPlanCountyBulk::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGPlanCountyBulk::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("id", QJsonValue(id));
obj->insert("plan_id", QJsonValue(plan_id));
obj->insert("county_id", QJsonValue(county_id));

    return obj;
}

qint32
SWGPlanCountyBulk::getId() {
    return id;
}
void
SWGPlanCountyBulk::setId(qint32 id) {
    this->id = id;
}

qint32
SWGPlanCountyBulk::getPlanId() {
    return plan_id;
}
void
SWGPlanCountyBulk::setPlanId(qint32 plan_id) {
    this->plan_id = plan_id;
}

qint32
SWGPlanCountyBulk::getCountyId() {
    return county_id;
}
void
SWGPlanCountyBulk::setCountyId(qint32 county_id) {
    this->county_id = county_id;
}



} /* namespace Swagger */

